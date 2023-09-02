#include <mm/vmm.hpp>
#include <init/kinfo.hpp>
#include <arch/x64/mm/vmm.hpp>
#include <sys/printk.hpp>

namespace VMM {
void InitVMM() {
	KInfo *info = GetInfo();

	info->KernelVirtualSpace = NewKernelVirtualSpace();

	LoadVirtualSpace(info->KernelVirtualSpace);

	PRINTK::PrintK("Virtual memory subsystem initialized.\r\n");

}

VirtualSpace *NewModuleVirtualSpace() {
	KInfo *info = GetInfo();

	VirtualSpace *space = NewVirtualSpace();

	/* We go through every entry in the memory map and map it in virtual memory */
	for (size_t i = 0; i < info->MemoryMapEntryCount; i++) {
		MEM::MMapEntry entry = info->MemoryMap[i];

		if (entry.type == MEMMAP_BAD_MEMORY ||
		    entry.type == MEMMAP_RESERVED ||
		    entry.type == MEMMAP_USABLE) continue;

		/* We find the base and the top by rounding to the closest page boundary */
		uintptr_t base = entry.base - (entry.base % PAGE_SIZE);
		uintptr_t top = base + entry.length + (entry.length % PAGE_SIZE);

		/* If it's kernel code, we will map its special location, otherwise we do the lower half and higher half mappings. */
		/* We use the kernel base to be sure we are not mapping module code over the kernel code. */
		if (entry.type == MEMMAP_KERNEL_AND_MODULES && entry.base == info->KernelPhysicalBase) {
			for (uintptr_t t = base; t < top; t += PAGE_SIZE){
				space->MapMemory((void*)t, (void*)(info->KernelVirtualBase + t - info->KernelPhysicalBase), VMM_PRESENT | VMM_READWRITE | VMM_GLOBAL);

			}
		} else if (entry.type == MEMMAP_ACPI_RECLAIMABLE || entry.type == MEMMAP_ACPI_NVS) {
			for (uintptr_t t = base; t < top; t += PAGE_SIZE) {
				space->MapMemory((void*)t, (void*)(t + info->HigherHalfMapping), VMM_PRESENT | VMM_USER);
			}
		} else {
			for (uintptr_t t = base; t < top; t += PAGE_SIZE) {
				space->MapMemory((void*)t, (void*)(t + info->HigherHalfMapping), VMM_PRESENT | VMM_READWRITE | VMM_GLOBAL);
			}
		}
	}

#ifdef CONFIG_ARCH_x86_64
	for (uintptr_t t = PAGE_SIZE; t < info->KernelStack; t+=PAGE_SIZE) {
		space->MapMemory((void*)t, (void*)t, VMM_PRESENT | VMM_READWRITE | VMM_GLOBAL);
	}
#endif

	return space;
}

VirtualSpace *NewKernelVirtualSpace() {
	KInfo *info = GetInfo();

	VirtualSpace *space = NewVirtualSpace();
	
	/* We go through every entry in the memory map and map it in virtual memory */
	for (size_t i = 0; i < info->MemoryMapEntryCount; i++) {
		MEM::MMapEntry entry = info->MemoryMap[i];

		/* We will skip any memory that is not usable by our kernel, to make the process faster */
		if (entry.type == MEMMAP_BAD_MEMORY ||
		    entry.type == MEMMAP_RESERVED) continue;

		/* We find the base and the top by rounding to the closest page boundary */
		uintptr_t base = entry.base - (entry.base % PAGE_SIZE);
		uintptr_t top = base + entry.length + (entry.length % PAGE_SIZE);

		/* If it's kernel code, we will map its special location, otherwise we do the lower half and higher half mappings. */
		/* We use the kernel base to be sure we are not mapping module code over the kernel code. */
		if (entry.type == MEMMAP_KERNEL_AND_MODULES && entry.base == info->KernelPhysicalBase) {
			for (uintptr_t t = base; t < top; t += PAGE_SIZE){
				space->MapMemory((void*)t, (void*)(info->KernelVirtualBase + t - info->KernelPhysicalBase), VMM_PRESENT | VMM_READWRITE | VMM_GLOBAL);

			}
		} else {
			for (uintptr_t t = base; t < top; t += PAGE_SIZE){
				space->MapMemory((void*)t, (void*)t, VMM_PRESENT | VMM_READWRITE);
				space->MapMemory((void*)t, (void*)(t + info->HigherHalfMapping), VMM_PRESENT | VMM_READWRITE);
			}
		}
	}

#ifdef CONFIG_ARCH_x86_64
	for (uintptr_t t = PAGE_SIZE; t < info->KernelStack; t+=PAGE_SIZE) {
		space->MapMemory((void*)t, (void*)t, VMM_PRESENT | VMM_READWRITE | VMM_GLOBAL);
	}
#endif

	return space;
}

VirtualSpace *NewVirtualSpace() {
#if defined(ARCH_x64)
	return x86_64::NewVirtualSpace();
#elif defined(ARCH_aarch64)
	PRINTK::PrintK("TODO: Implement arm virtual memory.\r\n");
	return NULL;
#endif
}

void LoadVirtualSpace(VMM::VirtualSpace *space) {
#if defined(ARCH_x64)
	x86_64::LoadVirtualSpace(space);
#elif defined(ARCH_aarch64)
	(void)space;
	return;
#endif
}

void MapMemory(VirtualSpace *space, void *physicalMemory, void *virtualMemory) {
	space->MapMemory(physicalMemory, virtualMemory, VMM_PRESENT | VMM_READWRITE | VMM_USER);
}
	
void MapMemory(VirtualSpace *space, void *physicalMemory, void *virtualMemory, size_t flags) {
	space->MapMemory(physicalMemory, virtualMemory, flags);

}
}
