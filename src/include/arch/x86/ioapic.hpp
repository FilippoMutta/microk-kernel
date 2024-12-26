#pragma once
#include <cdefs.h>

#define IOAPIC_ID	0x00
#define IOAPIC_VER	0x01
#define IOAPIC_ARB	0x02
#define IOAPIC_REDTBL(n)	(0x10 + 2 * n)
#define IOAPIC_REDTLB_MASKED 0x10000

namespace x86 {
	struct IOAPIC {
		u32 ID;
		u32 MaxIRQ;

		uptr Base;
		uptr MappedAddress;
	};

	int InitializeIOAPIC(IOAPIC *ioapic, u32 id, uptr address);
}
