#include <arch/x86/apic.hpp>
#include <printk.hpp>
#include <arch/x86/cpu.hpp>
#include <kinfo.hpp>
#include <vmm.hpp>

#define MSR_APIC_FLAG_IS_BSP        (1 << 8)
#define MSR_APIC_FLAG_x2APIC_ENABLE (1 << 10)
#define MSR_APIC_FLAG_xAPIC_ENABLE  (1 << 11)

namespace x86 {
/* Function that reads the specified x2APIC MSR register */
inline __attribute__((always_inline))
void ReadX2APIC(usize registerSelector, u32 *lo, u32 *hi) {
	GetMSR(MSR_x2APIC_BEGIN + registerSelector, lo, hi);
}

/* Function that reads the high and low bits of the specified xAPIC MMIO register */
inline __attribute__((always_inline))
void ReadXAPIC(APIC *device, usize registerSelector, u32 *lo, u32 *hi) {
	volatile u32 *apicRegister = (volatile u32*)(device->MappedAddress + registerSelector);

	*lo = *apicRegister;
	*hi = *(apicRegister + 1);
}

/* Function that reads the low bits of the specified xAPIC MMIO register */
inline __attribute__((always_inline))
void ReadXAPIC(APIC *device, usize registerSelector, u32 *lo) {
	volatile u32 *apicRegister = (volatile u32*)(device->MappedAddress + registerSelector);

	*lo = *apicRegister;
}

/* Function that writes a u64 into the specified x2APIC MSR register */
inline __attribute__((always_inline))
void WriteX2APIC(usize registerSelector, u32 lo, u32 hi) {
	SetMSR(MSR_x2APIC_BEGIN + registerSelector, lo, hi);
}

/* Function that writes the high and low bits into the specified xAPIC MMIO register */
inline __attribute__((always_inline))
void WriteXAPIC(APIC *device, usize registerSelector, u32 lo, u32 hi) {
	volatile u32 *apicRegister = (volatile u32*)(device->MappedAddress + registerSelector);

	*apicRegister = lo;
	*(apicRegister + 1) = hi;
}

/* Function that writes the low bits into the specified xAPIC MMIO register */
inline __attribute__((always_inline))
void WriteXAPIC(APIC *device, usize registerSelector, u32 lo) {
	volatile u32 *apicRegister = (volatile u32*)(device->MappedAddress + registerSelector);

	*apicRegister = lo;
}

void ReadAPIC(APIC *device, usize registerSelector, u32 *lo, u32 *hi) {
	if (device->x2APICMode) {
		/* Check if the MSR is in bounds */
		if (registerSelector > X2APIC_MAX_REGISTER) {
			return;
		}

		if (hi != NULL) {
			ReadX2APIC(registerSelector, lo, hi);
		} else {
			u32 ignore;
			ReadX2APIC(registerSelector, lo, &ignore);
		}
	} else {
		/* Check wether the register is available in xAPIC mode */
		if (registerSelector > XAPIC_MAX_REGISTER) {
			return;
		}

		/* xAPIC MMIO registers are 10x the corresponding MSRs for the x2APIC */
		registerSelector *= 10;

		if (hi != NULL) {
			ReadXAPIC(device, registerSelector, lo, hi);
		} else {
			ReadXAPIC(device, registerSelector, lo);
		}
	}
}

void WriteAPIC(APIC *device, usize registerSelector, u32 lo, u32 hi) {
	if (device->x2APICMode) {
		/* Check if the MSR is in bounds */
		if (registerSelector > X2APIC_MAX_REGISTER) {
			return;
		}

		WriteX2APIC(registerSelector, lo, hi);
	} else {
		/* Check wether the register is available in xAPIC mode */
		if (registerSelector > XAPIC_MAX_REGISTER) {
			return;
		}

		/* xAPIC MMIO registers are 10x the corresponding MSRs for the x2APIC */
		registerSelector *= 10;

		if (hi != 0) {
			WriteXAPIC(device, registerSelector, lo, hi);
		} else {
			WriteXAPIC(device, registerSelector, lo);
		}
	}
}

inline __attribute__((always_inline))
bool IsAPICBSP() {
	u32 eax, edx;
	GetMSR(MSR_APIC_BASE, &eax, &edx);
	
	return (eax & MSR_APIC_FLAG_IS_BSP);
}

inline __attribute__((always_inline))
uptr GetAPICBase() {
	u32 eax, edx;
	GetMSR(MSR_APIC_BASE, &eax, &edx);

	return (eax & 0xfffff000) | (((uptr)edx & 0x0f) << 32);
}

inline __attribute__((always_inline))
void SetAPICBase(uptr apic, usize flags) {
	u32 eax = (apic & 0xfffff0000) | flags;
	u32 edx = (apic >> 32) & 0x0f;

	SetMSR(MSR_APIC_BASE, eax, edx);
}


int InitializeAPIC(APIC *apic) {
	KInfo *info = GetInfo();

	apic->x2APICMode = false;

	apic->Base = GetAPICBase();
	apic->MappedAddress = VMM::PhysicalToVirtual(apic->Base);
	// TODO
	VMM::MMap(info->KernelVirtualSpace, apic->Base, apic->MappedAddress, PAGE_SIZE, VMM_FLAGS_READ | VMM_FLAGS_WRITE | VMM_FLAGS_NOEXEC);
	//MEM::MEMBLOCK::AddRegion(info->PhysicalMemoryChunks, apic->Base, PAGE_SIZE, MEMMAP_KERNEL_DEVICE);
	
	apic->ProcessorIsBSP = IsAPICBSP();

	if (apic->x2APICMode) {
		SetAPICBase(apic->Base, MSR_APIC_FLAG_xAPIC_ENABLE | MSR_APIC_FLAG_x2APIC_ENABLE);
	} else {
		SetAPICBase(apic->Base, MSR_APIC_FLAG_xAPIC_ENABLE);
	}

	ReadAPIC(apic, APIC_REGISTER_LAPIC_ID, &apic->ID, NULL);
	
	PRINTK::PrintK(PRINTK_DEBUG "%s with ID 0x%x (%s) at 0x%x\r\n",
		       apic->x2APICMode ? "x2APIC" : "xAPIC",
		       apic->ID,
		       apic->ProcessorIsBSP ? "BSP" : "Not a BSP",
		       apic->Base);

	u8 timerVector = 32;
	u32 timer = timerVector | APIC_LVT_TIMER_TSCDEADLINE | APIC_LVT_TIMER_MASK;
	u32 spuriousVector = 33 | 0x100;

	WriteAPIC(apic, APIC_REGISTER_THREAD_PRIORITY, 0x1, 0);
	WriteAPIC(apic, APIC_REGISTER_SPURIOUS_INTERRUPT_VECTOR, spuriousVector, 0);

	WriteAPIC(apic, APIC_REGISTER_TIMER_INITIAL_COUNT, -1, 0);
	WriteAPIC(apic, APIC_REGISTER_TIMER_DIVIDE_CONFIGURATION, APIC_LVT_TIMER_DIVIDE_1, 0);
	WriteAPIC(apic, APIC_REGISTER_LVT_TIMER_REGISTER, timer, 0);

	u32 ignore;
	ReadAPIC(apic, APIC_REGISTER_TIMER_CURRENT_COUNT, &ignore, NULL);

	ReadAPIC(apic, APIC_REGISTER_LVT_TIMER_REGISTER, &timer, NULL);
	timer &= ~APIC_LVT_TIMER_MASK;
	WriteAPIC(apic, APIC_REGISTER_LVT_TIMER_REGISTER, timer, 0);
	
	PRINTK::PrintK(PRINTK_DEBUG "APIC enabled.\r\n");

	/*
	u64 tsc = __builtin_ia32_rdtsc() + 0x100000000;
	SetMSR(MSR_TSC_DEADLINE, tsc & 0xFFFFFFFF, tsc >> 32);

	while(true);

	WriteXAPIC(apic, xAPIC_REGISTER_EOI, 0);
	*/

	(void)info;

	return 0;
}

int DeinitializeAPIC(APIC *apic, ...) {
	(void)apic;
	return 0;
}

}
