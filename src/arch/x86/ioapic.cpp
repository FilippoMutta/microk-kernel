#include <arch/x86/ioapic.hpp>
#include <printk.hpp>
#include <arch/x86/cpu.hpp>
#include <kinfo.hpp>
#include <vmm.hpp>
#include <pmm.hpp>
#include <capability.hpp>

namespace x86 {
void WriteIOAPIC(IOAPIC *ioapic, u8 offset, u32 val) {
    /* tell IOREGSEL where we want to write to */
    *(volatile u32*)(ioapic->MappedAddress) = offset;
    /* write the value to IOWIN */
    *(volatile u32*)(ioapic->MappedAddress + 0x10) = val; 
}
 
u32 ReadIOAPIC(IOAPIC *ioapic, u8 offset) {
    /* tell IOREGSEL where we want to read from */
    *(volatile u32*)(ioapic->MappedAddress) = offset;
    /* return the data from IOWIN */
    return *(volatile u32*)(ioapic->MappedAddress + 0x10);
}

int InitializeIOAPIC(IOAPIC *ioapic, u32 id, uptr address) {
	KInfo *info = GetInfo();

	ioapic->Base = address;
	ioapic->ID = id;
	ioapic->MappedAddress = VMM::PhysicalToVirtual(ioapic->Base);
	VMM::MMap(info->KernelVirtualSpace, ioapic->Base, ioapic->MappedAddress, PAGE_SIZE, VMM_FLAGS_READ | VMM_FLAGS_WRITE | VMM_FLAGS_NOEXEC);
	PMM::CheckSpace(info->RootCSpace, DEFAULT_CHECK_SPACE);
	CAPABILITY::GenerateCapability(info->RootCSpace, MMIO_MEMORY, ioapic->Base, ACCESS | READ | WRITE);

	ioapic->MaxIRQ = (ReadIOAPIC(ioapic, IOAPIC_VER) >> 16) + 1;

	PRINTK::PrintK(PRINTK_DEBUG "IOAPIC with ID 0x%x at 0x%x\r\n"
				    "Can handle %d IRQs\r\n",
		       ioapic->ID,
		       ioapic->Base, ioapic->MaxIRQ);

	for (usize idx = 0; idx < ioapic->MaxIRQ; ++idx) {
			WriteIOAPIC(ioapic, IOAPIC_REDTBL(idx), IOAPIC_REDTLB_MASKED | (0x20 + idx));
			WriteIOAPIC(ioapic, IOAPIC_REDTBL(idx) + 1, 0);
	}

	return 0;
}
}
