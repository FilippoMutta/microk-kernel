#pragma once
#include <cdefs.h>

#if defined(ARCH_x64)
#include <arch/x64/main.hpp>
#include <arch/x64/cpu/cpu.hpp>
#elif defined(ARCH_aarch64)
#include <arch/aarch64/main.hpp>
#endif

namespace ARCH {
	inline __attribute__((always_inline))
	int SetupArch() {
		#if defined(ARCH_x64)
			x86_64::Init();
		#elif defined(ARCH_aarch64)
			AArch64::Init();
		#endif
		
		return 0;
	}
	
	inline __attribute__((always_inline))
	uptr GetCurrentStackPointer() {
		#if defined(ARCH_x64)
			return x86_64::GetCurrentStackPointer();
		#elif defined(ARCH_aarch64)
			return AArch64::GetCurrentStackPointer();
		#endif

		return -1;
	}
}

