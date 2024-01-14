#pragma once
#include <cstdint.hpp>
#include <object.hpp>

namespace SCHED {
	Scheduler *InitializeCPUScheduler(Domain *domain);

	void AddThread(Scheduler *scheduler, ThreadControlBlock *tcb);
	void RemoveThread(Scheduler *scheduler, ThreadControlBlock *tcb);
	ThreadControlBlock *Recalculate(Scheduler *scheduler);
}
