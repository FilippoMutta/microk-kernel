#include <syscall.hpp>
#include <kinfo.hpp>
#include <printk.hpp>
#include <capability.hpp>
#include <panic.hpp>
#include <cdefs.h>

inline __attribute__((always_inline))
usize GetVirtualArgs(ThreadControlBlock *tcb, usize index) {
	if (index * sizeof(usize) >= VIRTUAL_REGISTERS_SIZE) {
		return 0;
	}

	return ((usize*)tcb->VirtualRegisters)[index];
}

inline __attribute__((always_inline))
void SyscallCapCtl(ThreadControlBlock *tcb, usize firstArgument, usize secondArgument, usize thirdArgument, usize fourthArgument, usize fithArgument, usize sixthArgument) {
	CapabilityNode *nodePtr = tcb->RootCNode;

	if (nodePtr == NULL) {
		/* Task isn't allowed to use capabilities */
		OOPS("Not allowed");
		return;
	}

	Capability *cspaceCap = &nodePtr->Slots[CSPACE_SLOT];
	CapabilitySpace *cspace = (CapabilitySpace*)cspaceCap->Object;

	usize operation = firstArgument;
	Capability *nodeCap = (Capability*)secondArgument;
	usize nodeSlot = thirdArgument;

	if (nodeCap == NULL) {
		PRINTK::PrintK(PRINTK_DEBUG "Using root node\r\n");
	} else {
		/* If the address of nodeCap is invalid, a page fault will occur, killing the running process */
		nodePtr = CAPABILITY::ResolveCNode(nodeCap);
		if (CAPABILITY::IsNodeInSpace(cspace, nodePtr) != 0) {
			return;
		}
	}

	if (CAPABILITY::IsCapabilityInNode(nodePtr, nodeSlot)) {
		OOPS("Invalid CAP addressing");
		return;
	}

	switch (operation) {
		case SYSCALL_CAPCTL_GET_PTR: {
			uptr *newPtr = (uptr*)fourthArgument;
			Capability *capability = &nodePtr->Slots[nodeSlot];

			if (capability->Type == OBJECT_TYPE::RESERVED_SLOT) {
				OOPS("Addressing reserved CAP slot");
				*newPtr = 0;
				return;
			}

			if ((capability->AccessRights & CAPABILITY_RIGHTS::ACCESS) == 0) {
				OOPS("Addressing non-accessible CAP slot");
				*newPtr = 0;
				return;
			}

			*newPtr = (uptr)capability;
			}
			break;
		case SYSCALL_CAPCTL_GET_UT: {
			UntypedHeader *newPtr = (UntypedHeader*)fourthArgument;
			Capability *capability = &nodePtr->Slots[nodeSlot];
		
			if (capability->Type != OBJECT_TYPE::UNTYPED) {
				*(usize*)newPtr = -1;
				return;
			}

			if ((capability->AccessRights & CAPABILITY_RIGHTS::ACCESS) == 0) {
				OOPS("Addressing non-addressable CAP slot");
				*(usize*)newPtr = -1;
				return;
			}

			UntypedHeader *header = (UntypedHeader*)VMM::PhysicalToVirtual(capability->Object);
			*newPtr = *header;
			}
			break;
		case SYSCALL_CAPCTL_ADD_CNODE: {
			Capability *capability = &nodePtr->Slots[nodeSlot];
		
			CapabilityNode *newNodePtr = CAPABILITY::ResolveCNode(capability);
			if (CAPABILITY::IsNodeInSpace(cspace, newNodePtr) != 0) {
				return;
			}


			if ((capability->AccessRights & CAPABILITY_RIGHTS::ACCESS) == 0) {
				OOPS("Addressing non-seeable CAP slot");
				return;
			}

			CAPABILITY::AddCNode(cspace, newNodePtr); 

			}
			break;
		case SYSCALL_CAPCTL_SPLIT: {
			usize splitSize = fourthArgument;
			Capability *newNodeCap = (Capability*)fithArgument;
			usize *newSlot = (usize*)sixthArgument;
			usize count = GetVirtualArgs(tcb, 7);

			CapabilityNode *newNodePtr = CAPABILITY::ResolveCNode(newNodeCap);
			if (CAPABILITY::IsNodeInSpace(cspace, newNodePtr) != 0) {
				return;
			}

			Capability *ut = &nodePtr->Slots[nodeSlot];
	
			if (ut->Type != OBJECT_TYPE::UNTYPED) {
				OOPS("Splitting non-ut cap");
				*newSlot = -1;
				return;
			}
	
			if ((ut->AccessRights & CAPABILITY_RIGHTS::ACCESS) == 0) {
				OOPS("Addressing non-seeable CAP slot");
				return;
			}

			Capability *capability = CAPABILITY::Split(newNodePtr, ut, splitSize, count);
			*newSlot = CAPABILITY::GetCapabilitySlot(newNodePtr, capability);
			}
			break;
		case SYSCALL_CAPCTL_RETYPE: {
			OBJECT_TYPE type = (OBJECT_TYPE)fourthArgument;
			Capability *newNodeCap = (Capability*)fithArgument;
			usize *newSlot = (usize*)sixthArgument;
			u16 accessRights = GetVirtualArgs(tcb, 7);

			CapabilityNode *newNodePtr = CAPABILITY::ResolveCNode(newNodeCap);
			if (CAPABILITY::IsNodeInSpace(cspace, newNodePtr) != 0) {
				return;
			}

			Capability *ut = &nodePtr->Slots[nodeSlot];

			if (ut->Type != OBJECT_TYPE::UNTYPED) {
				OOPS("Retyping non-ut cap");
				return;
			}

			if ((ut->AccessRights & CAPABILITY_RIGHTS::ACCESS) == 0) {
				OOPS("Addressing non-seeable CAP slot");
				return;
			}

			Capability *capability = CAPABILITY::Retype(newNodePtr, ut, type, accessRights);
			*newSlot = CAPABILITY::GetCapabilitySlot(newNodePtr, capability);
			}
			break;
		case SYSCALL_CAPCTL_DEBUG: {
			CAPABILITY::DumpCNode(nodePtr);
			}
			break;
		default:
			break;
	}
}

inline __attribute__((always_inline))
void SyscallArchCtl(ThreadControlBlock *tcb, usize firstArgument, usize secondArgument, usize thirdArgument, usize fourthArgument, usize fithArgument, usize sixthArgument) {
	usize operation = firstArgument;
	int *result = (int*)secondArgument;
	
	/* MAPPING SIMPLIFIED FOR TESTING PURPOSES */
	switch (operation) {
		case SYSCALL_ARCHCTL_MAP_INTERMEDIATE: {
			usize level = thirdArgument;
			uptr frame = fourthArgument;
			uptr virt = fithArgument;
			usize flags = VMM::ConvertUserFlags(sixthArgument);
			*result = VMM::MapIntermediateLevel(tcb->MemorySpace, level, frame, virt, flags);
			}
			break;
		case SYSCALL_ARCHCTL_MAP_PAGE: {
			uptr phys = thirdArgument;
			uptr virt = fourthArgument;
			usize flags = VMM::ConvertUserFlags(fithArgument);
			*result = VMM::MapPage(tcb->MemorySpace, phys, virt, flags);
			}
			break;
		default:
			break;
	}

}

extern "C" void SyscallMain(usize syscallNumber, usize firstArgument, usize secondArgument, usize thirdArgument, usize fourthArgument, usize fithArgument, usize sixthArgument) {
	KInfo *info = GetInfo();
	ThreadControlBlock *tcb = info->RootTCB;

	switch (syscallNumber) {
		case SYSCALL_VECTOR_DEBUG: {
			usize value = firstArgument;
			usize type = secondArgument;
			switch(type) {
				case 's':
					PRINTK::PrintK(PRINTK_DEBUG "%s", (const char*)value);
					break;
				case 'c': {
					char str[2];
					str[0] = value;
					str[1] = '\0';
					PRINTK::PrintK(PRINTK_DEBUG "%s", (const char*)str);
					}
					break;
				case 'd':
					PRINTK::PrintK(PRINTK_DEBUG "%d", (long)value);
					break;
				case 'x':
					PRINTK::PrintK(PRINTK_DEBUG "%x", value);
					break;
				default:
					break;
			}
			}
			break;

		case SYSCALL_VECTOR_CAPCTL:
			SyscallCapCtl(tcb, firstArgument, secondArgument, thirdArgument, fourthArgument, fithArgument, sixthArgument);
			break;
		case SYSCALL_VECTOR_ARCHCTL:
			SyscallArchCtl(tcb, firstArgument, secondArgument, thirdArgument, fourthArgument, fithArgument, sixthArgument);
			break;
		case SYSCALL_VECTOR_YEILD:
			break;
		case SYSCALL_VECTOR_CALL:
			break;
		case SYSCALL_VECTOR_REPLYRECV:
			break;
		default:
			break;
	}
}
