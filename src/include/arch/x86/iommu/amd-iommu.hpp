#pragma once
#include <cdefs.h>

#define IOMMU_BASE          0xFD00000000
#define IOMMU_INTERRUPT     0xFDF8000000
#define IOMMU_LEGACY_PIC    0xFDF9000000
#define IOMMU_SYSTEM_MGMT   0xFDF9100000
#define IOMMU_ADDRESS_TRANS 0xFDFB000000
#define IOMMU_IO_SPACE      0xFDFC000000
#define IOMMU_CONFIGURATION 0xFDFE000000
#define IOMMU_EXT_CONFIG    0xFE00000000

namespace x86 {
	void InitializeAMDIOMMU(uptr addr, u8 capabilityOff);
}
