#include <arch/x86/vm/svm.hpp>
#include <arch/x86/cpu.hpp>
#include <arch/x86/object.hpp>
#include <arch/x86/gdt.hpp>
#include <vmm.hpp>
#include <pmm.hpp>
#include <syscall.hpp>
#include <printk.hpp>

namespace x86 {
namespace SVM {

int InitializeVMCB(VMData *vcpu, uptr rip, uptr rsp, uptr rflags, uptr cr3) {
	VMCB *guestVmcb = (VMCB*)vcpu->GuestVMCB;
	VMCB *hostSave = (VMCB*)vcpu->HostSave;
	VMCB *hostVmcb = (VMCB*)vcpu->HostVMCB;
	VMCB *sharedVmcb = (VMCB*)vcpu->SharedPage;

	guestVmcb->Control.Intercepts[INTERCEPT_EXCEPTION] |= 0xFFFFFFFF;
	// CONTROL
	guestVmcb->Control.Intercepts[INTERCEPT_WORD3] |= INTERCEPT_MSR_PROT |
					             INTERCEPT_CPUID;

	guestVmcb->Control.Intercepts[INTERCEPT_WORD4] |= INTERCEPT_VMRUN |
						     INTERCEPT_VMMCALL;
	guestVmcb->Control.asid = 1;

	guestVmcb->Control.MSRPMBasePa = VMM::VirtualToPhysical((uptr)sharedVmcb);

//	guestVmcb->Control.NestedCtl |= 0 ; // NESTED_CTL_NP_ENABLE;
//	guestVmcb->Control.NestedCR3 = cr3;
	

	// SAVE
	guestVmcb->Save.CR0 = GetCR0();
	guestVmcb->Save.CR2 = GetCR2();
	guestVmcb->Save.CR3 = cr3;// GetCR3();
	guestVmcb->Save.CR4 = GetCR4();
	
	guestVmcb->Save.CPL = 3;

	u32 msrLo = 0, msrHi = 0;
	GetMSR(MSR_EFER, &msrLo, &msrHi);
	guestVmcb->Save.EFER = ((u64)msrHi << 32) | msrLo;

	guestVmcb->Save.RSP = rsp;
	guestVmcb->Save.RIP = rip;
	guestVmcb->Save.RFLAGS = rflags; 
 	GetMSR(MSR_PAT, &msrLo, &msrHi);
	guestVmcb->Save.GPAT = ((u64)msrHi << 32) | msrLo;

	_DTR gdtr;
	GetGDTR(&gdtr);
	guestVmcb->Save.GDTR.Base = gdtr.Base;
	guestVmcb->Save.GDTR.Limit = gdtr.Limit;

	//guestVmcb->Save.KernelGSBase = 

	_DTR idtr;
	GetIDTR(&idtr);
	guestVmcb->Save.IDTR.Base = idtr.Base;
	guestVmcb->Save.IDTR.Limit = idtr.Limit;

	usize ES = GetES() + 0x8 * 2;
	usize CS = GetCS() + 0x8 * 2;
	usize SS = GetSS() + 0x8 * 2;
	usize DS = GetDS() + 0x8 * 2;
	usize FS = GetFS() + 0x8 * 2;
	usize GS = GetGS() + 0x8 * 2;

	guestVmcb->Save.ES.Selector = ES;
	guestVmcb->Save.CS.Selector = CS;
	guestVmcb->Save.SS.Selector = SS;
	guestVmcb->Save.DS.Selector = DS;
	guestVmcb->Save.FS.Selector = FS;
	guestVmcb->Save.GS.Selector = GS;

	guestVmcb->Save.ES.Limit = GetLimit((GDT*)gdtr.Base, ES);
	guestVmcb->Save.CS.Limit = GetLimit((GDT*)gdtr.Base, CS);
	guestVmcb->Save.SS.Limit = GetLimit((GDT*)gdtr.Base, SS);
	guestVmcb->Save.DS.Limit = GetLimit((GDT*)gdtr.Base, DS);
	guestVmcb->Save.FS.Limit = GetLimit((GDT*)gdtr.Base, FS);
	guestVmcb->Save.GS.Limit = GetLimit((GDT*)gdtr.Base, GS);

	guestVmcb->Save.ES.Base = GetBase((GDT*)gdtr.Base, ES);
	guestVmcb->Save.CS.Base = GetBase((GDT*)gdtr.Base, CS);
	guestVmcb->Save.SS.Base = GetBase((GDT*)gdtr.Base, SS);
	guestVmcb->Save.DS.Base = GetBase((GDT*)gdtr.Base, DS);
	guestVmcb->Save.FS.Base = GetBase((GDT*)gdtr.Base, FS);
	guestVmcb->Save.GS.Base = GetBase((GDT*)gdtr.Base, GS);

	guestVmcb->Save.ES.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, ES) << 8 ) | GetGranularity((GDT*)gdtr.Base, ES);
	guestVmcb->Save.CS.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, CS) << 8 ) | GetGranularity((GDT*)gdtr.Base, CS);
	guestVmcb->Save.SS.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, SS) << 8 ) | GetGranularity((GDT*)gdtr.Base, SS);
	guestVmcb->Save.DS.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, DS) << 8 ) | GetGranularity((GDT*)gdtr.Base, DS);
	guestVmcb->Save.FS.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, FS) << 8 ) | GetGranularity((GDT*)gdtr.Base, FS);
	guestVmcb->Save.GS.Attrib = ((u16)GetAccess((GDT*)gdtr.Base, GS) << 8 ) | GetGranularity((GDT*)gdtr.Base, GS);

	SaveVM(VMM::VirtualToPhysical((uptr)guestVmcb));

	msrLo = VMM::VirtualToPhysical((uptr)hostSave) & 0xFFFFFFFF;
	msrHi = (VMM::VirtualToPhysical((uptr)hostSave) >> 32) & 0xFFFFFFFF;
	SetMSR(MSR_VM_HSAVE_PA, msrLo, msrHi);

	SaveVM(VMM::VirtualToPhysical((uptr)hostVmcb));
	
	return 0;
}

void LoadVM(uptr statePhysAddr) {
	__asm__ __volatile__("vmload %[statePhysAddr]" : : [statePhysAddr] "a"(statePhysAddr) : "memory");
}

void SaveVM(uptr statePhysAddr) {
	__asm__ __volatile__("vmsave %[statePhysAddr]" : : [statePhysAddr] "a"(statePhysAddr) : "memory");
}

}
}

extern "C" void HandleVMExit(uptr addr, x86::GeneralRegisters *context) {
	using namespace x86;
	using namespace x86::SVM;

	VMCB *vmcb = (VMCB*)VMM::PhysicalToVirtual(addr);

	//PRINTK::PrintK(PRINTK_DEBUG "Hello, VMEXIT: 0x%x\r\n", vmcb->Control.ExitCode);
	switch(vmcb->Control.ExitCode) {
		case _CPUID: {
			PRINTK::PrintK(PRINTK_DEBUG "CPUID: %d\r\n", vmcb->Save.RAX);
			// Example: Emulate CPUID instruction
			uint32_t eax, ebx, ecx, edx;
			if (vmcb->Save.RAX == 0x40000000) {
				eax = 0x40000001; // Maximum input value for hypervisor CPUID leaves
			        const char *hypervisorName = "MicroKosm   "; // 12 characters
			        Memcpy((u32*)&ebx, hypervisorName, 4);
			        Memcpy((u32*)&ecx, hypervisorName + 4, 4);
			        Memcpy((u32*)&edx, hypervisorName + 8, 4);
			} else {
				__asm__ __volatile__("cpuid"
						: "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
						: "a"(vmcb->Save.RAX), "c"(context->RCX));
			}

			vmcb->Save.RAX = eax;
			context->RBX = ebx;
			context->RCX = ecx;
			context->RDX = edx;
			vmcb->Save.RIP += 2;
			}
			break;
		case _VMMCALL:
			//PRINTK::PrintK(PRINTK_DEBUG "VMMCALL: 0x%x\r\n", vmcb->Save.RAX);
			SyscallMain(vmcb->Save.RAX, context->RDI, context->RSI, context->RDX, context->R8, context->R9, context->R10);
			vmcb->Save.RIP += 3;
			break;
		case _CR3_WRITE:
			PRINTK::PrintK("Change cr3: 0x%x\r\n", vmcb->Control.ExitInfo1);
			while(true) { }
		case _INTR:
			PRINTK::PrintK(PRINTK_DEBUG "Interrupt physical\r\n");
			while(true) { }
		case _INIT:				
			PRINTK::PrintK(PRINTK_DEBUG "Interrupt virtual\r\n");
			while(true) { }
		case _VINTR:
			PRINTK::PrintK(PRINTK_DEBUG "Interrupt virtual\r\n");
			while(true) { }
		case _IOIO:					
			PRINTK::PrintK(PRINTK_DEBUG "Disallowed IO\r\n");
			while(true) { }
		case _NPF:
			PRINTK::PrintK(PRINTK_DEBUG "Nested page fault\r\n");
			while(true) { }
		default:
			PRINTK::PrintK(PRINTK_DEBUG "Unknown error\r\n");
			while(true) { }
	}

	vmcb->Control.ExitCode = 0;
}

