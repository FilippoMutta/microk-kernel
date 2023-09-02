#include <sys/symbol.hpp>
const uint64_t symbolCount = 595;
const Symbol symbols[] = {
   {{0xffffffff80000000}, {"SyscallEntry"}}, 
   {{0xffffffff80000000}, {"syscall_start"}}, 
   {{0xffffffff80000050}, {"StartSyscallStack"}}, 
   {{0xffffffff80000060}, {"SyscallStack"}}, 
   {{0xffffffff80020060}, {"syscall_end"}}, 
   {{0xffffffff80021060}, {"EfiMain"}}, 
   {{0xffffffff8002107c}, {"LimineEntry"}}, 
   {{0xffffffff800214c6}, {"__stack_chk_fail"}}, 
   {{0xffffffff800214e9}, {"_Z11UnwindStacki"}}, 
   {{0xffffffff8002158e}, {"_ZN10UARTDevice4InitE11SerialPorts"}}, 
   {{0xffffffff80021680}, {"_ZN10UARTDevice15isTransmitEmptyEv"}}, 
   {{0xffffffff80021698}, {"_ZN10UARTDevice7PutCharEc"}}, 
   {{0xffffffff800216ca}, {"_ZN10UARTDevice6PutStrEPKc"}}, 
   {{0xffffffff80021712}, {"_ZN10UARTDevice14serialReceivedEv"}}, 
   {{0xffffffff8002172a}, {"_ZN10UARTDevice7GetCharEv"}}, 
   {{0xffffffff80021762}, {"_ZN10UARTDevice5IoctlEmz"}}, 
   {{0xffffffff80021868}, {"_ZN10UARTDeviceD1Ev"}}, 
   {{0xffffffff80021868}, {"_ZN10UARTDeviceD2Ev"}}, 
   {{0xffffffff80021878}, {"_ZN10UARTDeviceD0Ev"}}, 
   {{0xffffffff80021896}, {"_Z9ParseArgsv"}}, 
   {{0xffffffff8002194e}, {"_Z8InitInfov"}}, 
   {{0xffffffff80021977}, {"_Z7GetInfov"}}, 
   {{0xffffffff8002197f}, {"_Z15EarlyKernelInitv"}}, 
   {{0xffffffff80021999}, {"_Z11PrintBannerv"}}, 
   {{0xffffffff80021a42}, {"_Z11KernelStartv"}}, 
   {{0xffffffff80021bac}, {"_ZN7BOOTMEM17DeactivateBootmemEv"}}, 
   {{0xffffffff80021bb4}, {"_ZN7BOOTMEM15BootmemIsActiveEv"}}, 
   {{0xffffffff80021bbc}, {"_ZN7BOOTMEM6MallocEm"}}, 
   {{0xffffffff80021c08}, {"_ZN7BOOTMEM4FreeEPv"}}, 
   {{0xffffffff80021c09}, {"_ZN7BOOTMEM7GetFreeEv"}}, 
   {{0xffffffff80021c15}, {"_ZN7BOOTMEM8GetTotalEv"}}, 
   {{0xffffffff80021c1c}, {"_Z41__static_initialization_and_destruction_0v"}}, 
   {{0xffffffff80021c3a}, {"_ZN13HeapSegHeader14CombineForwardEv"}}, 
   {{0xffffffff80021c82}, {"_ZN13HeapSegHeader15CombineBackwardEv"}}, 
   {{0xffffffff80021c9e}, {"_ZN13HeapSegHeader5SplitEm"}}, 
   {{0xffffffff80021d16}, {"_ZN4HEAP12IsHeapActiveEv"}}, 
   {{0xffffffff80021d1e}, {"_ZN4HEAP7GetFreeEv"}}, 
   {{0xffffffff80021d26}, {"_ZN4HEAP8GetTotalEv"}}, 
   {{0xffffffff80021d2e}, {"_ZN4HEAP14InitializeHeapEPvm"}}, 
   {{0xffffffff80021def}, {"_ZN4HEAP4FreeEPv"}}, 
   {{0xffffffff80021e4e}, {"_ZN4HEAP10ExpandHeapEm"}}, 
   {{0xffffffff80021f3e}, {"_ZN4HEAP6MallocEm"}}, 
   {{0xffffffff80022010}, {"_GLOBAL__sub_I__ZN13HeapSegHeader14CombineForwardEv"}}, 
   {{0xffffffff8002201c}, {"_ZN8SpinLock6UnlockEv"}}, 
   {{0xffffffff80022022}, {"_ZN8SpinLock8IsLockedEv"}}, 
   {{0xffffffff80022028}, {"_ZN8SpinLock4LockEv"}}, 
   {{0xffffffff8002205a}, {"memcmp"}}, 
   {{0xffffffff80022085}, {"memcpy"}}, 
   {{0xffffffff800220a2}, {"_Z6Mallocm"}}, 
   {{0xffffffff800220df}, {"_Z4FreePv"}}, 
   {{0xffffffff800220ea}, {"_Znwm"}}, 
   {{0xffffffff80022127}, {"_Znam"}}, 
   {{0xffffffff80022164}, {"_ZdlPv"}}, 
   {{0xffffffff8002216f}, {"_ZdlPvm"}}, 
   {{0xffffffff8002217a}, {"_ZdaPv"}}, 
   {{0xffffffff80022185}, {"_ZdaPvm"}}, 
   {{0xffffffff80022190}, {"_ZN3MEM10DisplayRamEv"}}, 
   {{0xffffffff800222e0}, {"_ZN3MEM4InitEv"}}, 
   {{0xffffffff800222eb}, {"memset"}}, 
   {{0xffffffff80022303}, {"_ZL10InitBitmapmPv"}}, 
   {{0xffffffff8002232f}, {"_ZL13UnreservePagePv"}}, 
   {{0xffffffff80022398}, {"_ZL14UnreservePagesPvm"}}, 
   {{0xffffffff800223d5}, {"_ZL11ReservePagePv"}}, 
   {{0xffffffff8002242e}, {"_ZL12ReservePagesPvm"}}, 
   {{0xffffffff8002246b}, {"_ZN3PMM22InitPageFrameAllocatorEv"}}, 
   {{0xffffffff800225c8}, {"_ZN3PMM8FreePageEPv"}}, 
   {{0xffffffff80022638}, {"_ZN3PMM8LockPageEPv"}}, 
   {{0xffffffff8002269d}, {"_ZN3PMM11RequestPageEv"}}, 
   {{0xffffffff80022719}, {"_ZN3PMM9FreePagesEPvm"}}, 
   {{0xffffffff80022756}, {"_ZN3PMM9LockPagesEPvm"}}, 
   {{0xffffffff80022793}, {"_ZN3PMM12RequestPagesEm"}}, 
   {{0xffffffff80022841}, {"_ZN3PMM10GetFreeMemEv"}}, 
   {{0xffffffff80022849}, {"_ZN3PMM10GetUsedMemEv"}}, 
   {{0xffffffff80022851}, {"_ZN3PMM14GetReservedMemEv"}}, 
   {{0xffffffff80022859}, {"_Z6strlenPKc"}}, 
   {{0xffffffff8002286b}, {"_Z6strcpyPcPKc"}}, 
   {{0xffffffff800228a0}, {"_Z6strcmpPKcS0_"}}, 
   {{0xffffffff800228e3}, {"_Z8is_delimcPc"}}, 
   {{0xffffffff800228fc}, {"_Z6strtokPcS_"}}, 
   {{0xffffffff80022995}, {"_Z4itoaPcix"}}, 
   {{0xffffffff80022a2e}, {"_Z4atoiPc"}}, 
   {{0xffffffff80022a59}, {"_ZN3VMM15NewVirtualSpaceEv"}}, 
   {{0xffffffff80022a64}, {"_ZN3VMM21NewModuleVirtualSpaceEv"}}, 
   {{0xffffffff80022bca}, {"_ZN3VMM21NewKernelVirtualSpaceEv"}}, 
   {{0xffffffff80022d02}, {"_ZN3VMM16LoadVirtualSpaceEPNS_12VirtualSpaceE"}}, 
   {{0xffffffff80022d0d}, {"_ZN3VMM7InitVMMEv"}}, 
   {{0xffffffff80022d46}, {"_ZN3VMM9MapMemoryEPNS_12VirtualSpaceEPvS2_"}}, 
   {{0xffffffff80022d57}, {"_ZN3VMM9MapMemoryEPNS_12VirtualSpaceEPvS2_m"}}, 
   {{0xffffffff80022d64}, {"_ZN6MODULE13BufferManagerC1Ev"}}, 
   {{0xffffffff80022d64}, {"_ZN6MODULE13BufferManagerC2Ev"}}, 
   {{0xffffffff80022d9a}, {"_ZN6MODULE13BufferManager8FindNodeEjPPNS_10BufferNodeEPb"}}, 
   {{0xffffffff80022dd4}, {"_ZN6MODULE13BufferManager7AddNodeEPNS_6BufferE"}}, 
   {{0xffffffff80022e3e}, {"_ZN6MODULE13BufferManager10RemoveNodeEj"}}, 
   {{0xffffffff80022eb6}, {"_ZN6MODULE13BufferManager12CreateBufferEjjNS_10BufferTypeEm"}}, 
   {{0xffffffff80022f66}, {"_ZN6MODULE13BufferManager9GetBufferEj"}}, 
   {{0xffffffff80022fb0}, {"_ZN6MODULE13BufferManager9MapBufferEjjjPN3VMM12VirtualSpaceEm"}}, 
   {{0xffffffff800230d6}, {"_ZN6MODULE13BufferManager12DeleteBufferEPNS_6BufferE"}}, 
   {{0xffffffff80023138}, {"_ZN6MODULE13BufferManager10LockBufferEPNS_6BufferE"}}, 
   {{0xffffffff80023176}, {"_ZN6MODULE13BufferManager12UnlockBufferEPNS_6BufferE"}}, 
   {{0xffffffff8002319e}, {"_ZN6MODULE14ComposeMessageEPNS_7MessageEjjm"}}, 
   {{0xffffffff80023224}, {"_ZN6MODULE6ModuleC1EjjPN4PROC11ProcessBaseE"}}, 
   {{0xffffffff80023224}, {"_ZN6MODULE6ModuleC2EjjPN4PROC11ProcessBaseE"}}, 
   {{0xffffffff8002322e}, {"_ZN6MODULE7ManagerC1Ev"}}, 
   {{0xffffffff8002322e}, {"_ZN6MODULE7ManagerC2Ev"}}, 
   {{0xffffffff8002325c}, {"_ZN6MODULE7Manager8FindNodeEjjPPNS_10ModuleNodeEPb"}}, 
   {{0xffffffff800232ac}, {"_ZN6MODULE7Manager7AddNodeEjj"}}, 
   {{0xffffffff80023310}, {"_ZN6MODULE7Manager10RemoveNodeEjj"}}, 
   {{0xffffffff80023388}, {"_ZN6MODULE7Manager14RegisterModuleEPN4PROC11ProcessBaseEjj"}}, 
   {{0xffffffff80023408}, {"_ZN6MODULE7Manager9GetModuleEjj"}}, 
   {{0xffffffff8002344e}, {"_ZN6MODULE7Manager9GetModuleEm"}}, 
   {{0xffffffff8002347c}, {"_ZN6MODULE7Manager16UnregisterModuleEjj"}}, 
   {{0xffffffff80023488}, {"_ZN6MODULE14SectionManagerC1Ev"}}, 
   {{0xffffffff80023488}, {"_ZN6MODULE14SectionManagerC2Ev"}}, 
   {{0xffffffff800234c6}, {"_ZN6MODULE14SectionManager8FindNodeEPKcjjPPNS_11SectionNodeEPb"}}, 
   {{0xffffffff8002358c}, {"_ZN6MODULE14SectionManager7AddNodeEPKcjj"}}, 
   {{0xffffffff8002360a}, {"_ZN6MODULE14SectionManager10RemoveNodeEPKcjj"}}, 
   {{0xffffffff8002366e}, {"_ZN6MODULE14SectionManager21RegisterSectionDriverEPKcjj"}}, 
   {{0xffffffff800236dc}, {"_ZN6MODULE14SectionManager16GetSectionDriverEPKcPjS3_"}}, 
   {{0xffffffff80023754}, {"_ZN6MODULE14SectionManager23UnregisterSectionDriverEPKcjj"}}, 
   {{0xffffffff8002375f}, {"_ZN4PROCL14GetHighestFreeEv"}}, 
   {{0xffffffff8002376a}, {"_ZN4PROCL10RequestTIDEPNS_11ProcessBaseE"}}, 
   {{0xffffffff8002378e}, {"_ZN4PROCL26CreateExecutableUnitHeaderEPNS_11ProcessBaseENS_18ExecutableUnitTypeEbht"}}, 
   {{0xffffffff80023a9b}, {"_ZN4PROC13CreateProcessEPNS_11ProcessBaseENS_18ExecutableUnitTypeEPN3VMM12VirtualSpaceEht"}}, 
   {{0xffffffff80023b3b}, {"_ZN4PROC13DeleteProcessEPNS_11ProcessBaseE"}}, 
   {{0xffffffff80023b7c}, {"_ZN4PROC12CreateThreadEPNS_11ProcessBaseEmmht"}}, 
   {{0xffffffff80023d51}, {"_ZN4PROC10FindThreadEPNS_11ProcessBaseEm"}}, 
   {{0xffffffff80023d70}, {"_ZN4PROC12DeleteThreadEPNS_10ThreadBaseE"}}, 
   {{0xffffffff80023db1}, {"_ZN4PROC22SetExecutableUnitStateEPNS_20ExecutableUnitHeaderENS_19ExecutableUnitStateE"}}, 
   {{0xffffffff80023dc5}, {"_ZN4PROC19InitializeSchedulerEm"}}, 
   {{0xffffffff80023e66}, {"_ZN4PROC21DeinitializeSchedulerEPNS_9SchedulerE"}}, 
   {{0xffffffff80023f14}, {"_ZN4PROC16AddThreadToQueueEPNS_9SchedulerEmPNS_10ThreadBaseE"}}, 
   {{0xffffffff80024003}, {"_ZN4PROC21RemoveThreadFromQueueEPNS_9SchedulerEmmm"}}, 
   {{0xffffffff8002413b}, {"_ZN4PROC18GetThreadFromQueueEPNS_9SchedulerEmmm"}}, 
   {{0xffffffff800241f6}, {"_ZN4PROC9GetThreadEPNS_9SchedulerEmm"}}, 
   {{0xffffffff800242a5}, {"_ZN4PROC20RecalculateSchedulerEPNS_9SchedulerE"}}, 
   {{0xffffffff800243cf}, {"_ZN4PROC20PrintSchedulerStatusEPNS_9SchedulerE"}}, 
   {{0xffffffff800244bc}, {"_ZN6Bitmap3GetEm"}}, 
   {{0xffffffff800244f8}, {"_ZN6BitmapixEm"}}, 
   {{0xffffffff80024504}, {"_ZN6Bitmap3SetEmb"}}, 
   {{0xffffffff80024556}, {"_Z18LoadProgramHeadersPhmP10Elf64_EhdrPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff8002477d}, {"_Z11LoadProcessP10Elf64_EhdrPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80024806}, {"_Z7LoadELFPhm"}}, 
   {{0xffffffff80024856}, {"_ZN4FILE4OpenEPcPm"}}, 
   {{0xffffffff800249ed}, {"__cxa_guard_acquire"}}, 
   {{0xffffffff800249f7}, {"__cxa_guard_release"}}, 
   {{0xffffffff800249fb}, {"__cxa_guard_abort"}}, 
   {{0xffffffff800249fc}, {"__cxa_pure_virtual"}}, 
   {{0xffffffff80024a13}, {"__cxa_atexit"}}, 
   {{0xffffffff80024a56}, {"__cxa_finalize"}}, 
   {{0xffffffff80024aeb}, {"_Z16RequestInterruptj"}}, 
   {{0xffffffff80024aee}, {"_Z18LoadExecutableFilePhm"}}, 
   {{0xffffffff80024b35}, {"_Z12TryLockMutexPb"}}, 
   {{0xffffffff80024b47}, {"_Z17SpinlockLockMutexPb"}}, 
   {{0xffffffff80024b58}, {"_Z11UnlockMutexPb"}}, 
   {{0xffffffff80024b5c}, {"_Z5PanicPKcS0_S0_j"}}, 
   {{0xffffffff80024b91}, {"_Z4OopsPKcS0_S0_j"}}, 
   {{0xffffffff80024bc6}, {"_Z41__static_initialization_and_destruction_0v"}}, 
   {{0xffffffff80024be4}, {"_ZN6PRINTK11FlushBufferEv"}}, 
   {{0xffffffff80024c23}, {"_ZN6PRINTK7PutCharEc"}}, 
   {{0xffffffff80024c8b}, {"_ZN6PRINTK6PutStrEPc"}}, 
   {{0xffffffff80024cb4}, {"_ZN6PRINTK7VPrintKEPcP13__va_list_tag"}}, 
   {{0xffffffff80024e34}, {"_ZN6PRINTK6PrintKEPcz"}}, 
   {{0xffffffff80024e91}, {"_ZN6PRINTK9EarlyInitEv"}}, 
   {{0xffffffff80024efb}, {"_GLOBAL__sub_I_KernelPort"}}, 
   {{0xffffffff80024f06}, {"_Z11LoadShebangPhm"}}, 
   {{0xffffffff80024f0e}, {"_Z12LookupSymbolPKc"}}, 
   {{0xffffffff80024f61}, {"_Z12LookupSymbolm"}}, 
   {{0xffffffff80024fbd}, {"_ZL10GetProcessv"}}, 
   {{0xffffffff80024ffb}, {"_ZL15GetVirtualSpacePN4PROC11UserProcessE"}}, 
   {{0xffffffff80025034}, {"_Z11AddOverridem"}}, 
   {{0xffffffff80025035}, {"_Z13CheckOverridem"}}, 
   {{0xffffffff8002503b}, {"_Z11RunOverridem"}}, 
   {{0xffffffff80025041}, {"_Z24HandleSyscallDebugPrintKPKc"}}, 
   {{0xffffffff80025060}, {"_Z26HandleSyscallMemoryGetinfom"}}, 
   {{0xffffffff800250bf}, {"_Z26HandleSyscallMemoryVmallocmmm"}}, 
   {{0xffffffff800251d1}, {"_Z25HandleSyscallMemoryPallocPmm"}}, 
   {{0xffffffff80025243}, {"_Z25HandleSyscallMemoryVmfreemm"}}, 
   {{0xffffffff80025338}, {"_Z23HandleSyscallMemoryMmapmmmm"}}, 
   {{0xffffffff80025403}, {"_Z24HandleSyscallMemoryUnmapmm"}}, 
   {{0xffffffff800254c5}, {"_Z24HandleSyscallMemoryInOutmbmPmh"}}, 
   {{0xffffffff80025660}, {"_Z21HandleSyscallProcExecmm"}}, 
   {{0xffffffff800257a0}, {"_Z21HandleSyscallProcForkm"}}, 
   {{0xffffffff800257a6}, {"_Z23HandleSyscallProcReturnmm"}}, 
   {{0xffffffff800257ed}, {"_Z21HandleSyscallProcExitmm"}}, 
   {{0xffffffff80025821}, {"_Z21HandleSyscallProcWaitm"}}, 
   {{0xffffffff80025827}, {"_Z21HandleSyscallProcKillm"}}, 
   {{0xffffffff8002582d}, {"_Z27HandleSyscallModuleRegistermm"}}, 
   {{0xffffffff80025898}, {"_Z29HandleSyscallModuleUnregisterv"}}, 
   {{0xffffffff80025907}, {"_Z31HandleSyscallModuleBufferCreatemmPj"}}, 
   {{0xffffffff8002599e}, {"_Z28HandleSyscallModuleBufferMapmj"}}, 
   {{0xffffffff80025a32}, {"_Z30HandleSyscallModuleBufferUnmapmj"}}, 
   {{0xffffffff80025a38}, {"_Z31HandleSyscallModuleBufferDeletej"}}, 
   {{0xffffffff80025a3e}, {"_Z33HandleSyscallModuleMessageHandlerm"}}, 
   {{0xffffffff80025a6c}, {"_Z30HandleSyscallModuleMessageSendjjPvm"}}, 
   {{0xffffffff80025ca4}, {"_Z34HandleSyscallModuleSectionRegisterPKc"}}, 
   {{0xffffffff80025d87}, {"_Z29HandleSyscallModuleSectionGetPKcPjS1_"}}, 
   {{0xffffffff80025e43}, {"_Z36HandleSyscallModuleSectionUnregisterPKc"}}, 
   {{0xffffffff80025f04}, {"_Z21HandleSyscallFileOpenPcPmS0_"}}, 
   {{0xffffffff80025f96}, {"_Z21HandleSyscallFileReadPcmm"}}, 
   {{0xffffffff80026042}, {"_Z22HandleSyscallFileWritem"}}, 
   {{0xffffffff80026048}, {"_Z22HandleSyscallFileClosem"}}, 
   {{0xffffffff8002604e}, {"_Z25HandleSyscallKernOverridem"}}, 
   {{0xffffffff80026054}, {"HandleSyscall"}}, 
   {{0xffffffff800263b4}, {"_ZL10EnableSMIDv"}}, 
   {{0xffffffff80026471}, {"_ZN6x86_647CPUInitEv"}}, 
   {{0xffffffff800264b9}, {"_ZN6x86_6412GetCPUVendorEv"}}, 
   {{0xffffffff80026569}, {"_ZN6x86_647TSSInitEm"}}, 
   {{0xffffffff80026603}, {"_ZN6x86_647LoadGDTEm"}}, 
   {{0xffffffff80026646}, {"_Z15InitializeStackPvm"}}, 
   {{0xffffffff80026655}, {"_ZN6x86_6411GetAPICBaseEv"}}, 
   {{0xffffffff80026676}, {"_ZN6x86_6411SetAPICBaseEm"}}, 
   {{0xffffffff80026690}, {"_ZN6x86_6417WriteAPICRegisterEtj"}}, 
   {{0xffffffff800266ad}, {"_ZN6x86_6416ReadAPICRegisterEt"}}, 
   {{0xffffffff800266c9}, {"_ZN6x86_6412SetAPICTimerEm"}}, 
   {{0xffffffff800266d1}, {"_ZN6x86_648WaitAPICEv"}}, 
   {{0xffffffff800266e7}, {"_ZN6x86_6410EnableAPICEv"}}, 
   {{0xffffffff80026794}, {"_ZN6x86_6411SendAPICEOIEv"}}, 
   {{0xffffffff800267a9}, {"_Z20CalibrateTSCWithHPETmPm"}}, 
   {{0xffffffff8002687a}, {"_ZN6x86_646IOAPICC1Em"}}, 
   {{0xffffffff8002687a}, {"_ZN6x86_646IOAPICC2Em"}}, 
   {{0xffffffff8002688e}, {"_ZN6x86_646IOAPIC10ReadIOAPICEj"}}, 
   {{0xffffffff8002689c}, {"_ZN6x86_646IOAPIC11WriteIOAPICEjj"}}, 
   {{0xffffffff800268aa}, {"_ZN6x86_646IOAPIC5IoctlEmz"}}, 
   {{0xffffffff80026984}, {"_ZN6x86_646IOAPICD1Ev"}}, 
   {{0xffffffff80026984}, {"_ZN6x86_646IOAPICD2Ev"}}, 
   {{0xffffffff80026994}, {"_ZN6x86_646IOAPICD0Ev"}}, 
   {{0xffffffff800269b2}, {"_ZN6x86_6410HandleMADTEP10MADTHeader"}}, 
   {{0xffffffff80026b04}, {"_ZN6x86_6410HandleSRATEP9SDTHeader"}}, 
   {{0xffffffff80026b48}, {"_ZN6x86_6410HandleHPETEP10HPETHeader"}}, 
   {{0xffffffff80026c57}, {"_ZN6x86_6411InitDevicesEv"}}, 
   {{0xffffffff80026d68}, {"_ZN6x86_643PIT5IoctlEmz"}}, 
   {{0xffffffff80026dbe}, {"_ZN6x86_643PITC1Ev"}}, 
   {{0xffffffff80026dbe}, {"_ZN6x86_643PITC2Ev"}}, 
   {{0xffffffff80026dce}, {"_ZN6x86_643PITD1Ev"}}, 
   {{0xffffffff80026dce}, {"_ZN6x86_643PITD2Ev"}}, 
   {{0xffffffff80026dde}, {"_ZN6x86_643PITD0Ev"}}, 
   {{0xffffffff80026dfc}, {"_ZL16IDTSetDescriptorhPvh"}}, 
   {{0xffffffff80026e44}, {"_ZL10GetProcessv"}}, 
   {{0xffffffff80026e82}, {"_ZL15GetVirtualSpacePN4PROC11UserProcessE"}}, 
   {{0xffffffff80026ebb}, {"_ZN6x86_647IDTInitEv"}}, 
   {{0xffffffff80026f39}, {"InterruptHandler"}}, 
   {{0xffffffff80027238}, {"_ZN6x86_644OutBEth"}}, 
   {{0xffffffff8002723e}, {"_ZN6x86_644OutWEtt"}}, 
   {{0xffffffff80027245}, {"_ZN6x86_644OutDEtj"}}, 
   {{0xffffffff8002724b}, {"_ZN6x86_643InBEt"}}, 
   {{0xffffffff8002724f}, {"_ZN6x86_643InWEt"}}, 
   {{0xffffffff80027254}, {"_ZN6x86_643InDEt"}}, 
   {{0xffffffff80027258}, {"_ZN6x86_646IoWaitEv"}}, 
   {{0xffffffff8002726d}, {"_ZN6x86_649EarlyInitEv"}}, 
   {{0xffffffff800272c2}, {"_ZN6x86_644InitEv"}}, 
   {{0xffffffff800272fc}, {"_ZN14PageMapIndexerC1Em"}}, 
   {{0xffffffff800272fc}, {"_ZN14PageMapIndexerC2Em"}}, 
   {{0xffffffff80027340}, {"_ZN16PageTableManager4ForkEPN3VMM12VirtualSpaceEb"}}, 
   {{0xffffffff80027720}, {"_ZN16PageTableManager9MapMemoryEPvS0_m"}}, 
   {{0xffffffff80027aa0}, {"_ZN16PageTableManager11UnmapMemoryEPv"}}, 
   {{0xffffffff80027bb0}, {"_ZN16PageTableManager18GetPhysicalAddressEPv"}}, 
   {{0xffffffff80027cb6}, {"_ZN16PageTableManagerC1EP9PageTable"}}, 
   {{0xffffffff80027cb6}, {"_ZN16PageTableManagerC2EP9PageTable"}}, 
   {{0xffffffff80027cca}, {"_ZN16PageTableManager13GetTopAddressEv"}}, 
   {{0xffffffff80027cd0}, {"_ZN16PageTableManagerD1Ev"}}, 
   {{0xffffffff80027cd0}, {"_ZN16PageTableManagerD2Ev"}}, 
   {{0xffffffff80027ce0}, {"_ZN16PageTableManagerD0Ev"}}, 
   {{0xffffffff80027cfe}, {"_ZN18PageDirectoryEntry7SetFlagE7PT_Flagb"}}, 
   {{0xffffffff80027d26}, {"_ZN18PageDirectoryEntry7GetFlagE7PT_Flag"}}, 
   {{0xffffffff80027d3c}, {"_ZN18PageDirectoryEntry10SetAddressEm"}}, 
   {{0xffffffff80027d64}, {"_ZN18PageDirectoryEntry10GetAddressEv"}}, 
   {{0xffffffff80027d79}, {"_ZN6x86_6415NewVirtualSpaceEv"}}, 
   {{0xffffffff80027dba}, {"_ZN6x86_6416LoadVirtualSpaceEPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80027dd0}, {"CPUPause"}}, 
   {{0xffffffff80027de0}, {"FlushGDT"}}, 
   {{0xffffffff80027de3}, {"reloadSegments"}}, 
   {{0xffffffff80027def}, {"reloadSegments.reloadCS"}}, 
   {{0xffffffff80027dfe}, {"FlushTSS"}}, 
   {{0xffffffff80027e06}, {"SetIOPL"}}, 
   {{0xffffffff80027e20}, {"EnableSCE"}}, 
   {{0xffffffff80027e60}, {"EnableSSE"}}, 
   {{0xffffffff80027e7b}, {"EnableAVX"}}, 
   {{0xffffffff80027e90}, {"SwitchStack"}}, 
   {{0xffffffff80027ed0}, {"EnterUserspace"}}, 
   {{0xffffffff80027ee0}, {"isr_stub_0"}}, 
   {{0xffffffff80027f21}, {"isr_stub_1"}}, 
   {{0xffffffff80027f62}, {"isr_stub_2"}}, 
   {{0xffffffff80027fa3}, {"isr_stub_3"}}, 
   {{0xffffffff80027fe4}, {"isr_stub_4"}}, 
   {{0xffffffff80028025}, {"isr_stub_5"}}, 
   {{0xffffffff80028066}, {"isr_stub_6"}}, 
   {{0xffffffff800280a7}, {"isr_stub_7"}}, 
   {{0xffffffff800280e8}, {"isr_stub_8"}}, 
   {{0xffffffff80028127}, {"isr_stub_9"}}, 
   {{0xffffffff80028168}, {"isr_stub_10"}}, 
   {{0xffffffff800281a7}, {"isr_stub_11"}}, 
   {{0xffffffff800281e6}, {"isr_stub_12"}}, 
   {{0xffffffff80028225}, {"isr_stub_13"}}, 
   {{0xffffffff80028264}, {"isr_stub_14"}}, 
   {{0xffffffff800282a3}, {"isr_stub_15"}}, 
   {{0xffffffff800282e4}, {"isr_stub_16"}}, 
   {{0xffffffff80028325}, {"isr_stub_17"}}, 
   {{0xffffffff80028364}, {"isr_stub_18"}}, 
   {{0xffffffff800283a5}, {"isr_stub_19"}}, 
   {{0xffffffff800283e6}, {"isr_stub_20"}}, 
   {{0xffffffff80028427}, {"isr_stub_21"}}, 
   {{0xffffffff80028468}, {"isr_stub_22"}}, 
   {{0xffffffff800284a9}, {"isr_stub_23"}}, 
   {{0xffffffff800284ea}, {"isr_stub_24"}}, 
   {{0xffffffff8002852b}, {"isr_stub_25"}}, 
   {{0xffffffff8002856c}, {"isr_stub_26"}}, 
   {{0xffffffff800285ad}, {"isr_stub_27"}}, 
   {{0xffffffff800285ee}, {"isr_stub_28"}}, 
   {{0xffffffff8002862f}, {"isr_stub_29"}}, 
   {{0xffffffff80028670}, {"isr_stub_30"}}, 
   {{0xffffffff800286af}, {"isr_stub_31"}}, 
   {{0xffffffff800286f0}, {"isr_stub_32"}}, 
   {{0xffffffff80028731}, {"isr_stub_33"}}, 
   {{0xffffffff80028772}, {"isr_stub_34"}}, 
   {{0xffffffff800287b3}, {"isr_stub_35"}}, 
   {{0xffffffff800287f4}, {"isr_stub_36"}}, 
   {{0xffffffff80028835}, {"isr_stub_37"}}, 
   {{0xffffffff80028876}, {"isr_stub_38"}}, 
   {{0xffffffff800288b7}, {"isr_stub_39"}}, 
   {{0xffffffff800288f8}, {"isr_stub_40"}}, 
   {{0xffffffff80028939}, {"isr_stub_41"}}, 
   {{0xffffffff8002897a}, {"isr_stub_42"}}, 
   {{0xffffffff800289bb}, {"isr_stub_43"}}, 
   {{0xffffffff800289fc}, {"isr_stub_44"}}, 
   {{0xffffffff80028a3d}, {"isr_stub_45"}}, 
   {{0xffffffff80028a7e}, {"isr_stub_46"}}, 
   {{0xffffffff80028abf}, {"isr_stub_47"}}, 
   {{0xffffffff80028b00}, {"isr_stub_48"}}, 
   {{0xffffffff80028b41}, {"isr_stub_49"}}, 
   {{0xffffffff80028b82}, {"isr_stub_50"}}, 
   {{0xffffffff80028bc3}, {"isr_stub_51"}}, 
   {{0xffffffff80028c04}, {"isr_stub_52"}}, 
   {{0xffffffff80028c45}, {"isr_stub_53"}}, 
   {{0xffffffff80028c86}, {"isr_stub_54"}}, 
   {{0xffffffff80028cc7}, {"isr_stub_55"}}, 
   {{0xffffffff80028d08}, {"isr_stub_56"}}, 
   {{0xffffffff80028d49}, {"isr_stub_57"}}, 
   {{0xffffffff80028d8a}, {"isr_stub_58"}}, 
   {{0xffffffff80028dcb}, {"isr_stub_59"}}, 
   {{0xffffffff80028e0c}, {"isr_stub_60"}}, 
   {{0xffffffff80028e4d}, {"isr_stub_61"}}, 
   {{0xffffffff80028e8e}, {"isr_stub_62"}}, 
   {{0xffffffff80028ecf}, {"isr_stub_63"}}, 
   {{0xffffffff80028f10}, {"isr_stub_64"}}, 
   {{0xffffffff80028f51}, {"isr_stub_65"}}, 
   {{0xffffffff80028f92}, {"isr_stub_66"}}, 
   {{0xffffffff80028fd3}, {"isr_stub_67"}}, 
   {{0xffffffff80029014}, {"isr_stub_68"}}, 
   {{0xffffffff80029055}, {"isr_stub_69"}}, 
   {{0xffffffff80029096}, {"isr_stub_70"}}, 
   {{0xffffffff800290d7}, {"isr_stub_71"}}, 
   {{0xffffffff80029118}, {"isr_stub_72"}}, 
   {{0xffffffff80029159}, {"isr_stub_73"}}, 
   {{0xffffffff8002919a}, {"isr_stub_74"}}, 
   {{0xffffffff800291db}, {"isr_stub_75"}}, 
   {{0xffffffff8002921c}, {"isr_stub_76"}}, 
   {{0xffffffff8002925d}, {"isr_stub_77"}}, 
   {{0xffffffff8002929e}, {"isr_stub_78"}}, 
   {{0xffffffff800292df}, {"isr_stub_79"}}, 
   {{0xffffffff80029320}, {"isr_stub_80"}}, 
   {{0xffffffff80029361}, {"isr_stub_81"}}, 
   {{0xffffffff800293a2}, {"isr_stub_82"}}, 
   {{0xffffffff800293e3}, {"isr_stub_83"}}, 
   {{0xffffffff80029424}, {"isr_stub_84"}}, 
   {{0xffffffff80029465}, {"isr_stub_85"}}, 
   {{0xffffffff800294a6}, {"isr_stub_86"}}, 
   {{0xffffffff800294e7}, {"isr_stub_87"}}, 
   {{0xffffffff80029528}, {"isr_stub_88"}}, 
   {{0xffffffff80029569}, {"isr_stub_89"}}, 
   {{0xffffffff800295aa}, {"isr_stub_90"}}, 
   {{0xffffffff800295eb}, {"isr_stub_91"}}, 
   {{0xffffffff8002962c}, {"isr_stub_92"}}, 
   {{0xffffffff8002966d}, {"isr_stub_93"}}, 
   {{0xffffffff800296ae}, {"isr_stub_94"}}, 
   {{0xffffffff800296ef}, {"isr_stub_95"}}, 
   {{0xffffffff80029730}, {"isr_stub_96"}}, 
   {{0xffffffff80029771}, {"isr_stub_97"}}, 
   {{0xffffffff800297b2}, {"isr_stub_98"}}, 
   {{0xffffffff800297f3}, {"isr_stub_99"}}, 
   {{0xffffffff80029834}, {"isr_stub_100"}}, 
   {{0xffffffff80029875}, {"isr_stub_101"}}, 
   {{0xffffffff800298b6}, {"isr_stub_102"}}, 
   {{0xffffffff800298f7}, {"isr_stub_103"}}, 
   {{0xffffffff80029938}, {"isr_stub_104"}}, 
   {{0xffffffff80029979}, {"isr_stub_105"}}, 
   {{0xffffffff800299ba}, {"isr_stub_106"}}, 
   {{0xffffffff800299fb}, {"isr_stub_107"}}, 
   {{0xffffffff80029a3c}, {"isr_stub_108"}}, 
   {{0xffffffff80029a7d}, {"isr_stub_109"}}, 
   {{0xffffffff80029abe}, {"isr_stub_110"}}, 
   {{0xffffffff80029aff}, {"isr_stub_111"}}, 
   {{0xffffffff80029b40}, {"isr_stub_112"}}, 
   {{0xffffffff80029b81}, {"isr_stub_113"}}, 
   {{0xffffffff80029bc2}, {"isr_stub_114"}}, 
   {{0xffffffff80029c03}, {"isr_stub_115"}}, 
   {{0xffffffff80029c44}, {"isr_stub_116"}}, 
   {{0xffffffff80029c85}, {"isr_stub_117"}}, 
   {{0xffffffff80029cc6}, {"isr_stub_118"}}, 
   {{0xffffffff80029d07}, {"isr_stub_119"}}, 
   {{0xffffffff80029d48}, {"isr_stub_120"}}, 
   {{0xffffffff80029d89}, {"isr_stub_121"}}, 
   {{0xffffffff80029dca}, {"isr_stub_122"}}, 
   {{0xffffffff80029e0b}, {"isr_stub_123"}}, 
   {{0xffffffff80029e4c}, {"isr_stub_124"}}, 
   {{0xffffffff80029e8d}, {"isr_stub_125"}}, 
   {{0xffffffff80029ece}, {"isr_stub_126"}}, 
   {{0xffffffff80029f0f}, {"isr_stub_127"}}, 
   {{0xffffffff80029f50}, {"isr_stub_128"}}, 
   {{0xffffffff80029f94}, {"isr_stub_129"}}, 
   {{0xffffffff80029fd8}, {"isr_stub_130"}}, 
   {{0xffffffff8002a01c}, {"isr_stub_131"}}, 
   {{0xffffffff8002a060}, {"isr_stub_132"}}, 
   {{0xffffffff8002a0a4}, {"isr_stub_133"}}, 
   {{0xffffffff8002a0e8}, {"isr_stub_134"}}, 
   {{0xffffffff8002a12c}, {"isr_stub_135"}}, 
   {{0xffffffff8002a170}, {"isr_stub_136"}}, 
   {{0xffffffff8002a1b4}, {"isr_stub_137"}}, 
   {{0xffffffff8002a1f8}, {"isr_stub_138"}}, 
   {{0xffffffff8002a23c}, {"isr_stub_139"}}, 
   {{0xffffffff8002a280}, {"isr_stub_140"}}, 
   {{0xffffffff8002a2c4}, {"isr_stub_141"}}, 
   {{0xffffffff8002a308}, {"isr_stub_142"}}, 
   {{0xffffffff8002a34c}, {"isr_stub_143"}}, 
   {{0xffffffff8002a390}, {"isr_stub_144"}}, 
   {{0xffffffff8002a3d4}, {"isr_stub_145"}}, 
   {{0xffffffff8002a418}, {"isr_stub_146"}}, 
   {{0xffffffff8002a45c}, {"isr_stub_147"}}, 
   {{0xffffffff8002a4a0}, {"isr_stub_148"}}, 
   {{0xffffffff8002a4e4}, {"isr_stub_149"}}, 
   {{0xffffffff8002a528}, {"isr_stub_150"}}, 
   {{0xffffffff8002a56c}, {"isr_stub_151"}}, 
   {{0xffffffff8002a5b0}, {"isr_stub_152"}}, 
   {{0xffffffff8002a5f4}, {"isr_stub_153"}}, 
   {{0xffffffff8002a638}, {"isr_stub_154"}}, 
   {{0xffffffff8002a67c}, {"isr_stub_155"}}, 
   {{0xffffffff8002a6c0}, {"isr_stub_156"}}, 
   {{0xffffffff8002a704}, {"isr_stub_157"}}, 
   {{0xffffffff8002a748}, {"isr_stub_158"}}, 
   {{0xffffffff8002a78c}, {"isr_stub_159"}}, 
   {{0xffffffff8002a7d0}, {"isr_stub_160"}}, 
   {{0xffffffff8002a814}, {"isr_stub_161"}}, 
   {{0xffffffff8002a858}, {"isr_stub_162"}}, 
   {{0xffffffff8002a89c}, {"isr_stub_163"}}, 
   {{0xffffffff8002a8e0}, {"isr_stub_164"}}, 
   {{0xffffffff8002a924}, {"isr_stub_165"}}, 
   {{0xffffffff8002a968}, {"isr_stub_166"}}, 
   {{0xffffffff8002a9ac}, {"isr_stub_167"}}, 
   {{0xffffffff8002a9f0}, {"isr_stub_168"}}, 
   {{0xffffffff8002aa34}, {"isr_stub_169"}}, 
   {{0xffffffff8002aa78}, {"isr_stub_170"}}, 
   {{0xffffffff8002aabc}, {"isr_stub_171"}}, 
   {{0xffffffff8002ab00}, {"isr_stub_172"}}, 
   {{0xffffffff8002ab44}, {"isr_stub_173"}}, 
   {{0xffffffff8002ab88}, {"isr_stub_174"}}, 
   {{0xffffffff8002abcc}, {"isr_stub_175"}}, 
   {{0xffffffff8002ac10}, {"isr_stub_176"}}, 
   {{0xffffffff8002ac54}, {"isr_stub_177"}}, 
   {{0xffffffff8002ac98}, {"isr_stub_178"}}, 
   {{0xffffffff8002acdc}, {"isr_stub_179"}}, 
   {{0xffffffff8002ad20}, {"isr_stub_180"}}, 
   {{0xffffffff8002ad64}, {"isr_stub_181"}}, 
   {{0xffffffff8002ada8}, {"isr_stub_182"}}, 
   {{0xffffffff8002adec}, {"isr_stub_183"}}, 
   {{0xffffffff8002ae30}, {"isr_stub_184"}}, 
   {{0xffffffff8002ae74}, {"isr_stub_185"}}, 
   {{0xffffffff8002aeb8}, {"isr_stub_186"}}, 
   {{0xffffffff8002aefc}, {"isr_stub_187"}}, 
   {{0xffffffff8002af40}, {"isr_stub_188"}}, 
   {{0xffffffff8002af84}, {"isr_stub_189"}}, 
   {{0xffffffff8002afc8}, {"isr_stub_190"}}, 
   {{0xffffffff8002b00c}, {"isr_stub_191"}}, 
   {{0xffffffff8002b050}, {"isr_stub_192"}}, 
   {{0xffffffff8002b094}, {"isr_stub_193"}}, 
   {{0xffffffff8002b0d8}, {"isr_stub_194"}}, 
   {{0xffffffff8002b11c}, {"isr_stub_195"}}, 
   {{0xffffffff8002b160}, {"isr_stub_196"}}, 
   {{0xffffffff8002b1a4}, {"isr_stub_197"}}, 
   {{0xffffffff8002b1e8}, {"isr_stub_198"}}, 
   {{0xffffffff8002b22c}, {"isr_stub_199"}}, 
   {{0xffffffff8002b270}, {"isr_stub_200"}}, 
   {{0xffffffff8002b2b4}, {"isr_stub_201"}}, 
   {{0xffffffff8002b2f8}, {"isr_stub_202"}}, 
   {{0xffffffff8002b33c}, {"isr_stub_203"}}, 
   {{0xffffffff8002b380}, {"isr_stub_204"}}, 
   {{0xffffffff8002b3c4}, {"isr_stub_205"}}, 
   {{0xffffffff8002b408}, {"isr_stub_206"}}, 
   {{0xffffffff8002b44c}, {"isr_stub_207"}}, 
   {{0xffffffff8002b490}, {"isr_stub_208"}}, 
   {{0xffffffff8002b4d4}, {"isr_stub_209"}}, 
   {{0xffffffff8002b518}, {"isr_stub_210"}}, 
   {{0xffffffff8002b55c}, {"isr_stub_211"}}, 
   {{0xffffffff8002b5a0}, {"isr_stub_212"}}, 
   {{0xffffffff8002b5e4}, {"isr_stub_213"}}, 
   {{0xffffffff8002b628}, {"isr_stub_214"}}, 
   {{0xffffffff8002b66c}, {"isr_stub_215"}}, 
   {{0xffffffff8002b6b0}, {"isr_stub_216"}}, 
   {{0xffffffff8002b6f4}, {"isr_stub_217"}}, 
   {{0xffffffff8002b738}, {"isr_stub_218"}}, 
   {{0xffffffff8002b77c}, {"isr_stub_219"}}, 
   {{0xffffffff8002b7c0}, {"isr_stub_220"}}, 
   {{0xffffffff8002b804}, {"isr_stub_221"}}, 
   {{0xffffffff8002b848}, {"isr_stub_222"}}, 
   {{0xffffffff8002b88c}, {"isr_stub_223"}}, 
   {{0xffffffff8002b8d0}, {"isr_stub_224"}}, 
   {{0xffffffff8002b914}, {"isr_stub_225"}}, 
   {{0xffffffff8002b958}, {"isr_stub_226"}}, 
   {{0xffffffff8002b99c}, {"isr_stub_227"}}, 
   {{0xffffffff8002b9e0}, {"isr_stub_228"}}, 
   {{0xffffffff8002ba24}, {"isr_stub_229"}}, 
   {{0xffffffff8002ba68}, {"isr_stub_230"}}, 
   {{0xffffffff8002baac}, {"isr_stub_231"}}, 
   {{0xffffffff8002baf0}, {"isr_stub_232"}}, 
   {{0xffffffff8002bb34}, {"isr_stub_233"}}, 
   {{0xffffffff8002bb78}, {"isr_stub_234"}}, 
   {{0xffffffff8002bbbc}, {"isr_stub_235"}}, 
   {{0xffffffff8002bc00}, {"isr_stub_236"}}, 
   {{0xffffffff8002bc44}, {"isr_stub_237"}}, 
   {{0xffffffff8002bc88}, {"isr_stub_238"}}, 
   {{0xffffffff8002bccc}, {"isr_stub_239"}}, 
   {{0xffffffff8002bd10}, {"isr_stub_240"}}, 
   {{0xffffffff8002bd54}, {"isr_stub_241"}}, 
   {{0xffffffff8002bd98}, {"isr_stub_242"}}, 
   {{0xffffffff8002bddc}, {"isr_stub_243"}}, 
   {{0xffffffff8002be20}, {"isr_stub_244"}}, 
   {{0xffffffff8002be64}, {"isr_stub_245"}}, 
   {{0xffffffff8002bea8}, {"isr_stub_246"}}, 
   {{0xffffffff8002beec}, {"isr_stub_247"}}, 
   {{0xffffffff8002bf30}, {"isr_stub_248"}}, 
   {{0xffffffff8002bf74}, {"isr_stub_249"}}, 
   {{0xffffffff8002bfb8}, {"isr_stub_250"}}, 
   {{0xffffffff8002bffc}, {"isr_stub_251"}}, 
   {{0xffffffff8002c040}, {"isr_stub_252"}}, 
   {{0xffffffff8002c084}, {"isr_stub_253"}}, 
   {{0xffffffff8002c0c8}, {"isr_stub_254"}}, 
   {{0xffffffff8002c10c}, {"isr_stub_255"}}, 
   {{0xffffffff8002c150}, {"isrStubTable"}}, 
   {{0xffffffff8002dad8}, {"_ZTV6Device"}}, 
   {{0xffffffff8002db00}, {"_ZTV10UARTDevice"}}, 
   {{0xffffffff8002de28}, {"_ZTV5Mutex"}}, 
   {{0xffffffff8002de50}, {"_ZTV8SpinLock"}}, 
   {{0xffffffff8002df60}, {"_ZL14memTypeStrings"}}, 
   {{0xffffffff80031540}, {"symbols"}}, 
   {{0xffffffff80033a70}, {"symbolCount"}}, 
   {{0xffffffff80033d60}, {"_ZL16CPUVendorStrings"}}, 
   {{0xffffffff80033e90}, {"_ZTVN6x86_646IOAPICE"}}, 
   {{0xffffffff80034300}, {"_ZTVN6x86_643PITE"}}, 
   {{0xffffffff80034630}, {"_ZTVN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80034678}, {"_ZTV16PageTableManager"}}, 
   {{0xffffffff80036000}, {"_ZL11TimeRequest"}}, 
   {{0xffffffff80036040}, {"_ZL10SMPRequest"}}, 
   {{0xffffffff80036080}, {"_ZL17KernelFileRequest"}}, 
   {{0xffffffff800360c0}, {"_ZL18FramebufferRequest"}}, 
   {{0xffffffff80036100}, {"_ZL15EFITableRequest"}}, 
   {{0xffffffff80036140}, {"_ZL13SMBIOSRequest"}}, 
   {{0xffffffff80036180}, {"_ZL11RSDPRequest"}}, 
   {{0xffffffff800361c0}, {"_ZL12KAddrRequest"}}, 
   {{0xffffffff80036200}, {"_ZL16MemoryMapRequest"}}, 
   {{0xffffffff80036240}, {"_ZL11HHDMRequest"}}, 
   {{0xffffffff80036280}, {"_ZL13ModuleRequest"}}, 
   {{0xffffffff800362c0}, {"_ZL12StackRequest"}}, 
   {{0xffffffff80036300}, {"_ZL17EntryPointRequest"}}, 
   {{0xffffffff80036338}, {"bootmemStatus"}}, 
   {{0xffffffff80037000}, {"gdt"}}, 
   {{0xffffffff80038000}, {"__stack_chk_guard"}}, 
   {{0xffffffff80038008}, {"info"}}, 
   {{0xffffffff80038010}, {"lastPosition"}}, 
   {{0xffffffff80038020}, {"bootmemMemory"}}, 
   {{0xffffffff80039020}, {"_ZL8HeapLock"}}, 
   {{0xffffffff80039030}, {"_ZL8totalMem"}}, 
   {{0xffffffff80039038}, {"_ZL7freeMem"}}, 
   {{0xffffffff80039040}, {"_ZL12isHeapActive"}}, 
   {{0xffffffff80039048}, {"_ZL10lastHeader"}}, 
   {{0xffffffff80039050}, {"_ZL7heapEnd"}}, 
   {{0xffffffff80039058}, {"_ZL9heapStart"}}, 
   {{0xffffffff80039060}, {"_ZL10HigherHalf"}}, 
   {{0xffffffff80039068}, {"_ZL15PageBitmapIndex"}}, 
   {{0xffffffff80039070}, {"_ZL10PageBitmap"}}, 
   {{0xffffffff80039080}, {"_ZL11Initialized"}}, 
   {{0xffffffff80039088}, {"_ZL10UsedMemory"}}, 
   {{0xffffffff80039090}, {"_ZL14ReservedMemory"}}, 
   {{0xffffffff80039098}, {"_ZL10FreeMemory"}}, 
   {{0xffffffff800390a0}, {"_ZZ6strtokPcS_E1p"}}, 
   {{0xffffffff800390a8}, {"_ZN4PROCL10CurrentPIDE"}}, 
   {{0xffffffff800390c0}, {"__dso_handle"}}, 
   {{0xffffffff800390c8}, {"__atexit_func_count"}}, 
   {{0xffffffff800390e0}, {"__atexit_funcs"}}, 
   {{0xffffffff80039ce0}, {"KernelPort"}}, 
   {{0xffffffff80039ce8}, {"_ZN6PRINTKL16TerminalPositionE"}}, 
   {{0xffffffff80039d00}, {"_ZN6PRINTKL14TerminalColumnE"}}, 
   {{0xffffffff80039e00}, {"_ZN6PRINTKL14PrintKSpinlockE"}}, 
   {{0xffffffff8003a000}, {"gdtPointer"}}, 
   {{0xffffffff8003b000}, {"tss"}}, 
   {{0xffffffff8003b068}, {"_ZN6x86_64L6cyclesE"}}, 
   {{0xffffffff8003b070}, {"idtr"}}, 
   {{0xffffffff8003b080}, {"idt"}}, 
};
