#include <mm/pmm.hpp>
#include <mm/memory.hpp>
#include <arch/x64/mm/pageindexer.hpp>
#include <arch/x64/mm/pagetable.hpp>
#include <stdint.h>

PageTableManager *GlobalPageTableManager;

PageTableManager::PageTableManager(PageTable *PML4Address){
	this->PML4 = PML4Address;
}

void PageTableManager::MapMemory(void *physicalMemory, void *virtualMemory, uint64_t flags){
	PageMapIndexer indexer = PageMapIndexer((uint64_t)virtualMemory);
	PageDirectoryEntry PDE;

	PDE = PML4->entries[indexer.PDP_i];
	PageTable* PDP;
	if (!PDE.GetFlag(PT_Flag::Present)) {
		PDP = (PageTable*)PMM::RequestPage();
		memset(PDP, 0, 0x1000);
		PDE.SetAddress((uint64_t)PDP >> 12);
		PDE.SetFlag(PT_Flag::Present, true);
		PDE.SetFlag(PT_Flag::ReadWrite, true);
		PDE.SetFlag(PT_Flag::UserSuper, true);
		PDE.SetFlag(PT_Flag::Global, true);
		PML4->entries[indexer.PDP_i] = PDE;
	} else {
		PDP = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
	}

	PDE = PDP->entries[indexer.PD_i];
	PageTable* PD;
	if (!PDE.GetFlag(PT_Flag::Present)) {
		PD = (PageTable*)PMM::RequestPage();
		memset(PD, 0, 0x1000);
		PDE.SetAddress((uint64_t)PD >> 12);
		PDE.SetFlag(PT_Flag::Present, true);
		PDE.SetFlag(PT_Flag::ReadWrite, true);
		PDE.SetFlag(PT_Flag::UserSuper, true);
		PDE.SetFlag(PT_Flag::Global, true);
		PDP->entries[indexer.PD_i] = PDE;
	} else {
		PD = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
	}

	PDE = PD->entries[indexer.PT_i];
	PageTable* PT;
	if (!PDE.GetFlag(PT_Flag::Present)) {
		PT = (PageTable*)PMM::RequestPage();
		memset(PT, 0, 0x1000);
		PDE.SetAddress((uint64_t)PT >> 12);
		PDE.SetFlag(PT_Flag::Present, true);
		PDE.SetFlag(PT_Flag::ReadWrite, true);
		PDE.SetFlag(PT_Flag::UserSuper, true);
		PDE.SetFlag(PT_Flag::Global, true);
		PD->entries[indexer.PT_i] = PDE;
	} else {
		PT = (PageTable*)((uint64_t)PDE.GetAddress() << 12);
	}

	PDE = PT->entries[indexer.P_i];
	PDE.SetAddress((uint64_t)physicalMemory >> 12);
	PDE.SetFlag(PT_Flag::Present, true);
	PDE.SetFlag(PT_Flag::ReadWrite, true);
	PDE.SetFlag(PT_Flag::UserSuper, true);
	PDE.SetFlag(PT_Flag::Global, true);

	PT->entries[indexer.P_i] = PDE;

	// TODO: Manage TLB
	// asm volatile("invlpg (%0)" ::"r" (virtualMemory) : "memory");
}
	
void PageTableManager::UnmapMemory(void *virtualMemory) {

}
