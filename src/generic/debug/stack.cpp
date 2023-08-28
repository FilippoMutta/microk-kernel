#include <stdint.h>
#include <stddef.h>
#include <debug/stack.hpp>
#include <sys/panic.hpp>
#include <sys/symbol.hpp>
#include <sys/printk.hpp>

uintptr_t __stack_chk_guard = 0;

__attribute__((noreturn))
extern "C" void __stack_chk_fail() {
	OOPS("Stack smashing detected in the kernel");
}

/* Assume, as is often the case, that RBP is the first thing pushed. If not, we are in trouble. */
struct StackFrame {
	StackFrame *RBP;
	uint64_t RIP;
}__attribute__((packed));

void UnwindStack(int MaxFrames) {
	StackFrame *stk;
	stk = (StackFrame*)__builtin_frame_address(0);
	PRINTK::PrintK("Stack trace:\r\n");
	for(unsigned int frame = 0; stk && frame < MaxFrames; ++frame) {
		// Unwind to previous stack frame
		const Symbol *symbol = LookupSymbol(stk->RIP);
		if (symbol != NULL) {
			PRINTK::PrintK("  0x%x   %s\r\n", stk->RIP, symbol->name);
		} else {
			PRINTK::PrintK("  0x%x   <unknown>\r\n", stk->RIP);
		}

		if(stk->RBP == NULL) break;
		stk = stk->RBP;
	}
}
