#include <dev/cpu.hpp>
#include <sys/printk.hpp>
#include <mm/bootmem.hpp>
#include <init/kinfo.hpp>

#if defined(ARCH_x64)
#include <arch/x64/main.hpp>
#include <arch/x64/cpu/cpu.hpp>
#elif defined(ARCH_aarch64)
#include <arch/aarch64/main.hpp>
#endif

namespace DEV::CPU {
TopologyStructure *CreateTopologyStructure(TopologyStructure *parent, u32 id) {
	TopologyStructure *structure = new TopologyStructure;

	PRINTK::PrintK(PRINTK_DEBUG MODULE_NAME "Creating topology structure #%d under parent #%d\r\n", id, parent->ID);

	structure->ID = id;
	structure->Parent = parent;
	structure->Children.First = structure->Children.Last = NULL;

	TopologyStructure *oldLastChild = parent->Children.Last;
	oldLastChild->Next = structure;
	structure->Previous = oldLastChild;
	parent->Children.Last = structure;

	return structure;
}

TopologyStructure *ProgressToNextLevel(TopologyStructure *parent, u32 id) {
	TopologyStructure *current = parent->Children.First;

	if (current == NULL) return NULL;

	do {
		if (current->ID == id) return current;

		current = current->Next;
	} while (current != parent->Children.Last);

	return NULL;
}

int InitializeBootCPU() {
	/* Hierarchy:
	 *  - Machine (current PC)
	 *  - Domain (NUMA)
	 *  - Core (physical)
	 *  - Thread (hyperthreading)
	 */

	TopologyStructure *defaultMachine = (TopologyStructure*)BOOTMEM::Malloc(sizeof(TopologyStructure));
	TopologyStructure *defaultDomain = (TopologyStructure*)BOOTMEM::Malloc(sizeof(TopologyStructure));
	TopologyStructure *defaultCore = (TopologyStructure*)BOOTMEM::Malloc(sizeof(TopologyStructure));
	TopologyStructure *defaultThread = (TopologyStructure*)BOOTMEM::Malloc(sizeof(TopologyStructure));

	defaultMachine->ID = 0;
	defaultMachine->Parent = NULL;
	defaultMachine->Next = NULL;
	defaultMachine->Previous = NULL;
	defaultMachine->Children.First = defaultMachine->Children.Last = defaultDomain;

	defaultDomain->ID = 0;
	defaultDomain->Parent = defaultMachine;
	defaultDomain->Next = NULL;
	defaultDomain->Previous = NULL;
	defaultDomain->Children.First = defaultDomain->Children.Last = defaultCore;

	defaultCore->ID = 0;
	defaultCore->Parent = defaultDomain;
	defaultCore->Next = NULL;
	defaultCore->Previous = NULL;
	defaultCore->Children.First = defaultCore->Children.Last = defaultThread;

	defaultThread->ID = 0;
	defaultThread->Parent = defaultCore;
	defaultThread->Next = NULL;
	defaultThread->Previous = NULL;
	defaultThread->Children.First = defaultThread->Children.Last = NULL;

	KInfo *info = GetInfo();
	info->DefaultMachine = defaultMachine;
	info->BootCore = defaultCore;

	/* Initializing early architecture-specific devices */
#if defined(ARCH_x64)
	x86_64::BootCPUInit();
#endif

	return 0;
}

}
