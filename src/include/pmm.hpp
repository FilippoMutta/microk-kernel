#pragma once
#include <memory.hpp>
#include <capability.hpp>

namespace PMM {
	struct PhysicalMemoryManagerStruct {
		Capability *UntypedArea;

		bool IsActive;
	};

	void Init(Capability *untypedArea);
	void CheckSpace(CapabilitySpace *cspace, usize count);
	void Deinit();

	void *RequestPage();
	void *RequestVirtualPage();
	void *RequestPages(usize length);
}
