#include <hypercall.hpp>
#include <kinfo.hpp>
#include <printk.hpp>
#include <capability.hpp>
#include <panic.hpp>
#include <cdefs.h>

extern "C" void HypercallMain(usize hypercallNumber, usize firstArgument, usize secondArgument, usize thirdArgument, usize fourthArgument, usize fithArgument, usize sixthArgument) {
	KInfo *info = GetInfo();
	// TODO
	CapabilitySpace *cspace = &info->CurrentContainer->CSpace;
	VirtualSpace vspace = info->CurrentContainer->MemorySpace;
	(void)cspace;
	(void)vspace;

	switch (hypercallNumber) {
		case HYPERCALL_VECTOR_START_CONTAINER:
			break;
		case HYPERCALL_VECTOR_STOP_CONTAINER:
			break;
		case HYPERCALL_VECTOR_CREATE_CONTAINER:
			break;
		case HYPERCALL_VECTOR_CLONE_CONTAINER:
			break;
		case HYPERCALL_VECTOR_DESTROY_CONTAINER:
			break;
		default:
			break;
	}
}

