#pragma once
#include <sys/locks.hpp>
#include <init/kinfo.hpp>

namespace PROC {
	inline PROC::ProcessBase *GetProcess() {
		KInfo *info = GetInfo();

		SpinlockLock(&info->KernelScheduler->SchedulerLock);
		PROC::ProcessBase *proc = (PROC::ProcessBase*)info->KernelScheduler->CurrentThread->Thread->Parent;
		SpinlockUnlock(&info->KernelScheduler->SchedulerLock);

		return proc;
	}

	inline VMM::VirtualSpace *GetVirtualSpace(PROC::ProcessBase *proc) {
		KInfo *info = GetInfo();

		SpinlockLock(&info->KernelScheduler->SchedulerLock);
		VMM::VirtualSpace *procSpace = proc->VirtualMemorySpace;
		SpinlockUnlock(&info->KernelScheduler->SchedulerLock);

		return procSpace;
	}

	inline VMM::PageList *GetPageList(PROC::ProcessBase *proc) {
		KInfo *info = GetInfo();

		SpinlockLock(&info->KernelScheduler->SchedulerLock);
		VMM::PageList *procList = proc->ExecutablePageList;
		SpinlockUnlock(&info->KernelScheduler->SchedulerLock);

		return procList;
	}
}
