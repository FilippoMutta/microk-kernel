#include <arch/x64/mm/vmm.hpp>
#include <init/kinfo.hpp>
#include <mm/pmm.hpp>

#include <sys/printk.hpp>

inline __attribute__((always_inline))
uptr AllocatePage() {
	uptr address = (uptr)PMM::RequestPage();
	Memset((void*)VMM::PhysicalToVirtual(address), 0 , PAGE_SIZE);
	return address;
}

inline __attribute__((always_inline))
volatile u64 *GetNextLevel(volatile u64 *topLevel, usize idx, bool allocate) {
	if ((topLevel[idx] & (1 << x86_64::PT_Flag::Present)) != 0) {
		return (volatile u64*)(VMM::PhysicalToVirtual(PTE_GET_ADDR(topLevel[idx])));
	}

	if (!allocate) {
		return NULL;
	}

	uptr newPage = AllocatePage();
	if(newPage == 0) return NULL;

	topLevel[idx] = newPage | VMM_FLAGS_USER_GENERIC;
	return (volatile u64*)VMM::PhysicalToVirtual(newPage);
}


namespace x86_64 {
uptr NewVirtualSpace() {
	/* We create a new empty page directory */
	uptr table = AllocatePage();
	table = VMM::PhysicalToVirtual(table);

	return table;
}


void LoadVirtualSpace(uptr topLevel) {
	/* This loads the page directory into memory */
	asm volatile ("mov %0, %%cr3" : : "r" (VMM::VirtualToPhysical(topLevel)) : "memory");
}

int MapPage(uptr rootPageTable, uptr phys, uptr virt, usize flags) {
	usize pml4Entry = (virt & (0x1ffull << 39)) >> 39;
	usize pml3Entry = (virt & (0x1ffull << 30)) >> 30;
	usize pml2Entry = (virt & (0x1ffull << 21)) >> 21;
	usize pml1Entry = (virt & (0x1ffull << 12)) >> 12;

	volatile u64 *pml4 = (volatile u64*)rootPageTable;
	volatile u64 *pml3 = GetNextLevel(pml4, pml4Entry, true);
	if (pml3 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml2 = GetNextLevel(pml3, pml3Entry, true);
	if (pml2 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml1 = GetNextLevel(pml2, pml2Entry, true);
	if (pml1 == NULL) {
		return -ENOTPRESENT;
	}

	if ((pml1[pml1Entry] & (1 << PT_Flag::Present)) != 0) {
		return -EINVALID;
	}

	pml1[pml1Entry] = phys | flags;

	return 0;
}

int FlagPage(uptr rootPageTable, uptr virt, usize flags) {
	usize pml4Entry = (virt & (0x1ffull << 39)) >> 39;
	usize pml3Entry = (virt & (0x1ffull << 30)) >> 30;
	usize pml2Entry = (virt & (0x1ffull << 21)) >> 21;
	usize pml1Entry = (virt & (0x1ffull << 12)) >> 12;

	volatile u64 *pml4 = (volatile u64*)rootPageTable;
	volatile u64 *pml3 = GetNextLevel(pml4, pml4Entry, false);
	if (pml3 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml2 = GetNextLevel(pml3, pml3Entry, false);
	if (pml2 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml1 = GetNextLevel(pml2, pml2Entry, false);
	if (pml1 == NULL) {
		return -ENOTPRESENT;
	}

	if ((pml1[pml1Entry] & (1 << PT_Flag::Present)) == 0) {
		return -EINVALID;
	}

	pml1[pml1Entry] = PTE_GET_ADDR(pml1[pml1Entry]) | flags;

	return 0;
}

int UnmapPage(uptr rootPageTable, uptr virt) {
	usize pml4Entry = (virt & (0x1ffull << 39)) >> 39;
	usize pml3Entry = (virt & (0x1ffull << 30)) >> 30;
	usize pml2Entry = (virt & (0x1ffull << 21)) >> 21;
	usize pml1Entry = (virt & (0x1ffull << 12)) >> 12;

	volatile u64 *pml4 = (volatile u64*)rootPageTable;

	volatile u64 *pml3 = GetNextLevel(pml4, pml4Entry, false);
	if (pml3 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml2 = GetNextLevel(pml3, pml3Entry, false);
	if (pml2 == NULL) {
		return -ENOTPRESENT;
	}

	volatile u64 *pml1 = GetNextLevel(pml2, pml2Entry, false);
	if (pml1 == NULL) {
		return -ENOTPRESENT;
	}

	if ((pml1[pml1Entry] & (1 << PT_Flag::Present)) == 0) {
		return -EINVALID;
	}

	pml1[pml1Entry] = 0;

	return 0;
}

volatile u64 *FindMappedPTE(uptr rootPageTable, uptr virt, bool allocate) {
	usize pml4Entry = (virt & (0x1ffull << 39)) >> 39;
	usize pml3Entry = (virt & (0x1ffull << 30)) >> 30;
	usize pml2Entry = (virt & (0x1ffull << 21)) >> 21;
	usize pml1Entry = (virt & (0x1ffull << 12)) >> 12;

	volatile u64 *pml4 = (volatile u64*)rootPageTable;

	volatile u64 *pml3 = GetNextLevel(pml4, pml4Entry, allocate);
	if (pml3 == NULL) {
		return NULL;
	}

	volatile u64 *pml2 = GetNextLevel(pml3, pml3Entry, allocate);
	if (pml2 == NULL) {
		return NULL;
	}

	volatile u64 *pml1 = GetNextLevel(pml2, pml2Entry, allocate);
	if (pml1 == NULL) {
		return NULL;
	}

	return &pml1[pml1Entry];
}

uptr FindMappedPage(uptr rootPageTable, uintptr_t virt) {
	volatile u64 *pte = FindMappedPTE(rootPageTable, virt, false);

	if (pte == NULL || (PTE_GET_FLAGS(*pte) & (1 << PT_Flag::Present)) == 0) {
		return -1;
	}

	return PTE_GET_ADDR(*pte);
}
}
