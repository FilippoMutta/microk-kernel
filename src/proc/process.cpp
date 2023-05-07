#include <proc/process.hpp>
#include <mm/memory.hpp>
#include <arch/x64/cpu/stack.hpp>

#include <sys/printk.hpp>
#include <mm/pmm.hpp>

namespace PROC {
static uint64_t CurrentPID;

static inline uint64_t RequestPID() {
	CurrentPID++;

	return CurrentPID;
}

static inline uint64_t RequestTID(Process *process) {
	process->LastTID++;

	return process->LastTID;
}

Process *CreateProcess(ProcessType type, VMM::VirtualSpace *vms) {
	Process *newProcess = new Process;
	newProcess->PID = RequestPID();
	newProcess->State = P_READY;
	newProcess->Type = type;

	newProcess->VirtualMemorySpace = vms;

	newProcess->LastTID = 0;
	newProcess->ThreadNumber = 0;
	newProcess->MainThread = NULL;

	switch(type) {
		case PT_KERNEL:
			break;
		case PT_USER:
			break;
		case PT_VM:
			break;
		case PT_REALTIME:
			break;
	}

	return newProcess;
}

void DeleteProcess(Process *process) {

}

Thread *CreateThread(Process *process, uintptr_t entrypoint) {
	Thread *newThread = new Thread;

	newThread->TID = RequestTID(process);
	newThread->Owner = process;
	newThread->Entrypoint = entrypoint;
	newThread->State = P_READY;
	
	void *stackAddress = Malloc(512 * 1024);
	newThread->Stack = stackAddress + ((uint64_t)stackAddress % 16);

	InitializeStack(newThread, entrypoint);
	
	process->Threads.Push(newThread);
	process->ThreadNumber++;

	if (process->MainThread == NULL) process->MainThread = newThread;

	return process->Threads.Get(process->ThreadNumber - 1);
}

void DeleteThread(Thread *thread) {
	if (thread == NULL) return;

}
}
