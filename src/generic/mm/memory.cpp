#include <mm/memory.hpp>
#include <sys/printk.hpp>
#include <sys/panic.hpp>
#include <mm/pmm.hpp>
#include <mm/vmm.hpp>
#include <mm/bootmem.hpp>
#include <mm/slab.hpp>
#include <mm/heap.hpp>
#include <init/kinfo.hpp>

void *Malloc(usize size) {
	PRINTK::PrintK(PRINTK_DEBUG "Generic malloc called for size %d\r\n", size);

	KInfo *info = GetInfo();

	if (info->KernelHeap != NULL) {
		return MEM::HEAP::Alloc(info->KernelHeap, size);
	} else if(BOOTMEM::BootmemIsActive()) {
		return BOOTMEM::Malloc(size);
	}

	return NULL;
}

void Free(void *ptr) {
	KInfo *info = GetInfo();

	if (info->KernelHeap != NULL) {
		return MEM::HEAP::Free(info->KernelHeap, ptr);
	}
}

void Free(void *ptr, usize size) {
	KInfo *info = GetInfo();

	if (info->KernelHeap != NULL) {
		return MEM::HEAP::Free(info->KernelHeap, ptr, size);
	}
}
	
static bool OOMInvoked = false;

namespace MEM {
void InvokeOOM() {
	PANIC("Out of memory");

	if (OOMInvoked) {
		/* Recursive OOM calls are illegal and mean the system has nowhere enough memory for its operation */
		PANIC("Out of memory");
		
	}

	PRINTK::PrintK(PRINTK_DEBUG "OOM invoked, system is out of memory.\r\n");

	/* We should first try compressing memory */ 
	OOMInvoked = false;
	return;

	/* If we really have no memory left, then we must flush all caches and free unused slabs */ 
	OOMInvoked = false;
	return;

	/* If it's not enogh, we will be killing various processes with the lowest priority */
	OOMInvoked = false;
	return;

	/* If all processes are killed, and we still have no free memory, that means the systemhas
	 * has too little RAM for operation or that there is a bug in the kernel
	 */

	PANIC("Out of memory");
}

void Init() {
	KInfo *info = GetInfo();

	/* Give correct type descriptors to the memory regions */
	CatalogueKernelMemory();

	/* Detect which memory regions are physically contiguous */
	DetectContinuousMemoryRegions();

	/* Enabling the page frame allocator */
	PMM::InitPageFrameAllocator();

	/* Initialize the slab allocator */
	info->KernelSlabAllocator = SLAB::InitializeAllocator();

	/* Initialize global kernel slab caches */
	info->VirtualSpaceCache = SLAB::InitializeSlabCache(info->KernelSlabAllocator, sizeof(VMM::VirtualSpace));
	info->MemblockAllocatorCache = SLAB::InitializeSlabCache(info->KernelSlabAllocator, sizeof(MEMBLOCK::MemblockAllocator));
	info->MemblockRegionCache = SLAB::InitializeSlabCache(info->KernelSlabAllocator, sizeof(MEMBLOCK::MemblockRegion));
	info->TopologyStructureCache = SLAB::InitializeSlabCache(info->KernelSlabAllocator, sizeof(DEV::CPU::TopologyStructure));
	info->SchedulerCache = SLAB::InitializeSlabCache(info->KernelSlabAllocator, sizeof(PROC::Scheduler));

	/* Initializing virtual memory */
	VMM::InitVMM();
	
	/* Free bootloader-used memory that is no longer needed */
	FreeBootMemory();

	/* Initializing the heap */
	info->KernelHeap = HEAP::InitializeHeap(info->KernelSlabAllocator);

	/* With the heap initialized, disable new bootmem allocations */
	BOOTMEM::DeactivateBootmem();

	PRINTK::PrintK(PRINTK_DEBUG MODULE_NAME "Physical Memory Map:\r\n");

	for (MEM::MEMBLOCK::MemblockRegion *current = (MEM::MEMBLOCK::MemblockRegion*)info->PhysicalMemoryChunks->Regions.Head;
	     current != NULL;
	     current = (MEM::MEMBLOCK::MemblockRegion*)current->Next) {
		PRINTK::PrintK(PRINTK_DEBUG " [0x%x - 0x%x] -> %s\r\n",
				current->Base,
				current->Base + current->Length,
				MemoryTypeToString(current->Type));
	}
}

void CatalogueKernelMemory() {
	KInfo *info = GetInfo();

	PRINTK::PrintK(PRINTK_DEBUG MODULE_NAME 
			"Total kernel size: [0x%x - 0x%x] -> %d bytes\r\n"
			"        Essential: [0x%x - 0x%x] -> %d bytes\r\n"
			"             Text: [0x%x - 0x%x] -> %d bytes\r\n"
			"           ROData: [0x%x - 0x%x] -> %d bytes\r\n"
			"             Data: [0x%x - 0x%x] -> %d bytes\r\n"
			"          Dynamic: [0x%x - 0x%x] -> %d bytes\r\n"
			"              BSS: [0x%x - 0x%x] -> %d bytes\r\n",
			&__KernelBinaryEssentialStart, &__KernelBinaryBSSEnd, (&__KernelBinaryBSSEnd - &__KernelBinaryEssentialStart),
			&__KernelBinaryEssentialStart, &__KernelBinaryEssentialEnd, (&__KernelBinaryEssentialEnd - &__KernelBinaryEssentialStart),
			&__KernelBinaryTextStart, &__KernelBinaryTextEnd, (&__KernelBinaryTextEnd - &__KernelBinaryTextStart),
			&__KernelBinaryRODataStart, &__KernelBinaryRODataEnd, (&__KernelBinaryRODataEnd - &__KernelBinaryRODataStart),
			&__KernelBinaryDataStart, &__KernelBinaryDataEnd, (&__KernelBinaryDataEnd - &__KernelBinaryDataStart),
			&__KernelBinaryDynamicStart, &__KernelBinaryDynamicEnd, (&__KernelBinaryDynamicEnd - &__KernelBinaryDynamicStart),
			&__KernelBinaryBSSStart, &__KernelBinaryBSSEnd, (&__KernelBinaryBSSEnd - &__KernelBinaryBSSStart)
			);

	uptr essentialStartAddr = (uptr)&__KernelBinaryEssentialStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr essentialEndAddr = (uptr)&__KernelBinaryEssentialEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	uptr textStartAddr = (uptr)&__KernelBinaryTextStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr textEndAddr = (uptr)&__KernelBinaryTextEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	uptr rodataStartAddr = (uptr)&__KernelBinaryRODataStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr rodataEndAddr = (uptr)&__KernelBinaryRODataEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	uptr dataStartAddr = (uptr)&__KernelBinaryDataStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr dataEndAddr = (uptr)&__KernelBinaryDataEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	uptr dynamicStartAddr = (uptr)&__KernelBinaryDynamicStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr dynamicEndAddr = (uptr)&__KernelBinaryDynamicEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	uptr bssStartAddr = (uptr)&__KernelBinaryBSSStart - info->KernelVirtualBase + info->KernelPhysicalBase;
	uptr bssEndAddr = (uptr)&__KernelBinaryBSSEnd - info->KernelVirtualBase + info->KernelPhysicalBase;

	ROUND_DOWN_TO_PAGE(essentialStartAddr);
	ROUND_DOWN_TO_PAGE(textStartAddr);
	ROUND_DOWN_TO_PAGE(rodataStartAddr);
	ROUND_DOWN_TO_PAGE(dataStartAddr);
	ROUND_DOWN_TO_PAGE(dynamicStartAddr);
	ROUND_DOWN_TO_PAGE(bssStartAddr);

	ROUND_UP_TO_PAGE(essentialEndAddr);
	ROUND_UP_TO_PAGE(textEndAddr);
	ROUND_UP_TO_PAGE(rodataEndAddr);
	ROUND_UP_TO_PAGE(dataEndAddr);
	ROUND_UP_TO_PAGE(dynamicEndAddr);
	ROUND_UP_TO_PAGE(bssEndAddr);


	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, essentialStartAddr, essentialEndAddr - essentialStartAddr, MEMMAP_KERNEL_ESSENTIALS);
	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, textStartAddr, textEndAddr - textStartAddr, MEMMAP_KERNEL_TEXT);
	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, rodataStartAddr, rodataEndAddr - rodataStartAddr, MEMMAP_KERNEL_RODATA);
	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, dataStartAddr, dataEndAddr - dataStartAddr, MEMMAP_KERNEL_DATA);
	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, dynamicStartAddr, dynamicEndAddr - dynamicStartAddr, MEMMAP_KERNEL_DYNAMIC);
	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, bssStartAddr, bssEndAddr - bssStartAddr, MEMMAP_KERNEL_BSS);
	
	PRINTK::PrintK(PRINTK_DEBUG "Kernel file at 0x%x\r\n", info->KernelFileAddress);
	ROUND_UP_TO_PAGE(info->KernelFileSize);

	MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, VMM::VirtualToPhysical(info->KernelFileAddress), info->KernelFileSize, MEMMAP_KERNEL_FILE);
}

void DetectContinuousMemoryRegions() {
	KInfo *info = GetInfo();

	uptr base = 0;
	usize length = 0;

	PRINTK::PrintK(PRINTK_DEBUG MODULE_NAME "Contiguous regions:\r\n");
	for (MEM::MEMBLOCK::MemblockRegion *current = (MEM::MEMBLOCK::MemblockRegion*)info->PhysicalMemoryChunks->Regions.Head;
	     current != NULL;
	     current = (MEM::MEMBLOCK::MemblockRegion*)current->Next) {

		if (current->Base > base + length) {
			if (base != 0) {
				char *intro;

				if (base < 0x100000) {
					intro = "DMA";
				} else if (base < 0x100000000) {
					intro = "DMA32";
				} else {
					intro = "Normal";
				}

				PRINTK::PrintK(PRINTK_DEBUG " %s Memory Area: [0x%x - 0x%x]\r\n",
					intro,
					base,
					base + length);
			}

			base = current->Base;
			length = 0;
		}
			
		length += current->Length;
	}

	char *intro;

	if (base < 0x100000) {
		intro = "DMA";
	} else if (base < 0x100000000) {
		intro = "DMA32";
	} else {
		intro = "Normal";
	}

	PRINTK::PrintK(PRINTK_DEBUG " %s Memory Area: [0x%x - 0x%x]\r\n",
			intro,
			base,
			base + length);
}

void FreeBootMemory() {
	KInfo *info = GetInfo();

	for (MEM::MEMBLOCK::MemblockRegion *current = (MEM::MEMBLOCK::MemblockRegion*)info->PhysicalMemoryChunks->Regions.Head;
	     current != NULL;
	     current = (MEM::MEMBLOCK::MemblockRegion*)current->Next) {

		if (current->Type == MEMMAP_BOOTLOADER_RECLAIMABLE) {
			PRINTK::PrintK(PRINTK_DEBUG " Freeing boot data: [0x%x - 0x%x]\r\n",
				       current->Base, current->Base + current->Length);

			current->Type = MEMMAP_USABLE;

			Memclr((void*)VMM::PhysicalToVirtual(current->Base), current->Length);
			PMM::FreePages((void*)current->Base, current->Length / PAGE_SIZE);
		}
	}

}
}
