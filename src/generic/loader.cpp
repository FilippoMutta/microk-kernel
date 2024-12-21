#include <elf.h>
#include <elf64.h>
#include <loader.hpp>
#include <printk.hpp>
#include <memory.hpp>
#include <string.hpp>
#include <panic.hpp>
#include <stdarg.h>
#include <pmm.hpp>
#include <vmm.hpp>
#include <cpu.hpp>
#include <kinfo.hpp>
#include <capability.hpp>

#if defined(__x86_64__)
#include <arch/x86/cpu.hpp>
#include <arch/x86/vm/vm.hpp>
#include <arch/x86/vm/svm.hpp>
#endif

namespace LOADER {
static bool VerifyELF(Elf64_Ehdr *elfHeader);
static int LoadProgramHeaders(Container *container, u8 *data, usize size, Elf64_Ehdr *elfHeader, uptr *highestAddress);
static usize LoadContainer(Container *container, Elf64_Ehdr *elfHeader, uptr highestAddress);

Container *LoadContainer(Container *container, u8 *data, usize size) {
	KInfo *info = GetInfo();
	(void)info;
	Elf64_Ehdr *elfHeader = (Elf64_Ehdr*)data;

	if(VerifyELF(elfHeader)) {
		PRINTK::PrintK(PRINTK_DEBUG "Valid ELF header.\r\n");

		info->RootContainer->MemorySpace = VMM::NewVirtualSpace((uptr)PMM::RequestVirtualPage());
		VMM::PrepareUserVirtualSpace(info->RootContainer->MemorySpace);
		PRINTK::PrintK(PRINTK_DEBUG "Ready to load ELF.\r\n");

		uptr highestAddress = 0;
		LoadProgramHeaders(container, data, size, elfHeader, &highestAddress);
		PRINTK::PrintK(PRINTK_DEBUG "Elf loaded.\r\n");

		LoadContainer(container, elfHeader, highestAddress);

		return container;
	} else {
		OOPS("Invalid ELF file");
		return container;
	}
}

static bool VerifyELF(Elf64_Ehdr *elfHeader) {
	if (elfHeader->e_ident[EI_MAG0] != ELFMAG0 ||
	    elfHeader->e_ident[EI_MAG1] != ELFMAG1 ||
	    elfHeader->e_ident[EI_MAG2] != ELFMAG2 ||
	    elfHeader->e_ident[EI_MAG3] != ELFMAG3) {
		/* Invalid ELF magic */
		return false;
	}

	if (elfHeader->e_ident[EI_CLASS] != ELFCLASS64) {
		/* Invalid machine type */
		return false;
	}

	if (elfHeader->e_type != ET_EXEC) {
		/* Not a classic executble file */
		return false;
	}

	return true;
}

static int LoadProgramHeaders(Container *container, u8 *data, usize size, Elf64_Ehdr *elfHeader, uptr *highestAddress) {
	(void)size;
	usize programHeaderSize = elfHeader->e_phentsize;
	usize programHeaderOffset = elfHeader->e_phoff;
	usize programHeaderNumber = elfHeader->e_phnum;

	Elf64_Phdr *programHeader;

	for (usize i = 0; i < programHeaderNumber; i++) {
		programHeader = (Elf64_Phdr*)(data + programHeaderOffset + programHeaderSize * i);

		if (programHeader->p_type != PT_LOAD) continue;

		uptr virtAddr = programHeader->p_vaddr;
		usize memSize = programHeader->p_memsz;

		if (*highestAddress == 0) {
			container->LowestKernelAddress = virtAddr;
		}

		if (*highestAddress < virtAddr + memSize) {
			*highestAddress = virtAddr + memSize;
			ROUND_UP_TO_PAGE(*highestAddress);
		}

		uptr fileOffset = (uptr)data + programHeader->p_offset;
		usize fileSize = programHeader->p_filesz;

		usize flags;

		switch (programHeader->p_flags) {
			case PF_R: /* ROData */
				flags = VMM_FLAGS_USER | VMM_FLAGS_READ | VMM_FLAGS_NOEXEC;
				break;
			case PF_R | PF_X: /* Text */
				flags = VMM_FLAGS_USER | VMM_FLAGS_READ;
				break;
			case PF_R | PF_W: /* Data or BSS */
				flags = VMM_FLAGS_USER | VMM_FLAGS_READ | VMM_FLAGS_WRITE | VMM_FLAGS_NOEXEC;
				break;
			default: /* Unknown section, just skip */
				continue;
		}
				
		VMM::VMCopyAlloc(container->MemorySpace, virtAddr, memSize, flags, fileOffset, virtAddr, fileSize);
	}

	return 0;
}


static usize LoadContainer(Container *container, Elf64_Ehdr *elfHeader, uptr highestAddress) { 
	KInfo *info = GetInfo();

	usize sectionHeaderSize = elfHeader->e_shentsize;
	usize sectionHeaderOffset = elfHeader->e_shoff;
	usize sectionHeaderNumber = elfHeader->e_shnum;

	Elf64_Shdr *sectionHeader;
	Elf64_Shdr *nameHeader = (Elf64_Shdr*)((uptr)elfHeader + sectionHeaderOffset + sectionHeaderSize * elfHeader->e_shstrndx);
	char *nameTable = (char*)((uptr)elfHeader + nameHeader->sh_offset);

	for (usize i = 0; i < sectionHeaderNumber; i++) {
		sectionHeader = (Elf64_Shdr*)((uptr)elfHeader + sectionHeaderOffset + sectionHeaderSize * i);

		if (sectionHeader->sh_name == SHN_UNDEF) continue;

		char *name = nameTable + sectionHeader->sh_name;
		PRINTK::PrintK(PRINTK_DEBUG "Section %s\r\n", name);

		if (Strncmp(name, ".microkosm_bindings", 255) == 0) {
			ContainerBindings *fileOffset = (ContainerBindings*)((uptr)elfHeader + sectionHeader->sh_offset);
			container->Bindings = *fileOffset;
		}
	}

	VMM::MapPage(container->MemorySpace, VMM::VirtualToPhysical((uptr)info->_ContainerInfo), highestAddress, VMM_FLAGS_USER | VMM_FLAGS_READ);
	info->ContainerInfoAddr = highestAddress;

	highestAddress += PAGE_SIZE;

	/* Allocate the space for the stack and map it in
	 * the virtual space for init
	 */
	VMM::VMAlloc(container->MemorySpace, highestAddress, INIT_INITIAL_STACK_SIZE, VMM_FLAGS_READ | VMM_FLAGS_WRITE | VMM_FLAGS_NOEXEC | VMM_FLAGS_USER);

	/* Find the stack base after the highestAddress,
	 * making sure to reserve enough space for eventual expansion
	 */
	highestAddress += INIT_INITIAL_STACK_SIZE;
	
	container->HighestKernelAddress = highestAddress;





#if defined(__x86_64__)
	// TODO
	container->VCPU = (VirtualCPU*)PMM::RequestPage();
	using namespace x86;

	VMData *vmdata = (VMData*)PMM::RequestPages(sizeof(VMData) / PAGE_SIZE);
	container->VCPU->Data = vmdata;
	Memclr(vmdata, sizeof(VMData));
	vmdata->Self = vmdata;

	PMM::Deinit();

	SVM::InitializeVMCB(vmdata, elfHeader->e_entry, highestAddress, GetRFLAGS(), VMM::VirtualToPhysical(container->MemorySpace));
	SVMLaunchVM(GetRSP(), VMM::VirtualToPhysical((uptr)vmdata->GuestVMCB));
#endif


	return 0;
}
}
