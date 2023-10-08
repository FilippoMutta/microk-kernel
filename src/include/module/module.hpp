#pragma once
#include <stdint.h>
#include <proc/process.hpp>

namespace MODULE {

	class Module {
	public:
		Module(uint32_t vendorID, uint32_t productID, PROC::ProcessBase *proc);

		uint32_t GetVendor() { return VendorID; }
		uint32_t GetProduct() { return ProductID; }
		PROC::ProcessBase *GetProcess() { return Process; }
	private:
		uint32_t VendorID;
		uint32_t ProductID;

		PROC::ProcessBase *Process;
	};
}
