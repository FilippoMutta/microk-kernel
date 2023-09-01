#include <sys/symbol.hpp>
const uint64_t symbolCount = 592;
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
   {{0xffffffff8002157e}, {"_ZN10UARTDevice4InitE11SerialPorts"}}, 
   {{0xffffffff80021670}, {"_ZN10UARTDevice15isTransmitEmptyEv"}}, 
   {{0xffffffff80021688}, {"_ZN10UARTDevice7PutCharEc"}}, 
   {{0xffffffff800216ba}, {"_ZN10UARTDevice6PutStrEPKc"}}, 
   {{0xffffffff80021702}, {"_ZN10UARTDevice14serialReceivedEv"}}, 
   {{0xffffffff8002171a}, {"_ZN10UARTDevice7GetCharEv"}}, 
   {{0xffffffff80021752}, {"_ZN10UARTDevice5IoctlEmz"}}, 
   {{0xffffffff80021858}, {"_ZN10UARTDeviceD1Ev"}}, 
   {{0xffffffff80021858}, {"_ZN10UARTDeviceD2Ev"}}, 
   {{0xffffffff80021868}, {"_ZN10UARTDeviceD0Ev"}}, 
   {{0xffffffff80021886}, {"_Z9ParseArgsv"}}, 
   {{0xffffffff8002193e}, {"_Z8InitInfov"}}, 
   {{0xffffffff80021967}, {"_Z7GetInfov"}}, 
   {{0xffffffff8002196f}, {"_Z15EarlyKernelInitv"}}, 
   {{0xffffffff80021989}, {"_Z11PrintBannerv"}}, 
   {{0xffffffff80021a32}, {"_Z11KernelStartv"}}, 
   {{0xffffffff80021b97}, {"_ZN7BOOTMEM17DeactivateBootmemEv"}}, 
   {{0xffffffff80021b9f}, {"_ZN7BOOTMEM15BootmemIsActiveEv"}}, 
   {{0xffffffff80021ba7}, {"_ZN7BOOTMEM6MallocEm"}}, 
   {{0xffffffff80021bf3}, {"_ZN7BOOTMEM4FreeEPv"}}, 
   {{0xffffffff80021bf4}, {"_ZN7BOOTMEM7GetFreeEv"}}, 
   {{0xffffffff80021c00}, {"_ZN7BOOTMEM8GetTotalEv"}}, 
   {{0xffffffff80021c06}, {"_Z41__static_initialization_and_destruction_0v"}}, 
   {{0xffffffff80021c24}, {"_ZN13HeapSegHeader14CombineForwardEv"}}, 
   {{0xffffffff80021c6c}, {"_ZN13HeapSegHeader15CombineBackwardEv"}}, 
   {{0xffffffff80021c88}, {"_ZN13HeapSegHeader5SplitEm"}}, 
   {{0xffffffff80021d00}, {"_ZN4HEAP12IsHeapActiveEv"}}, 
   {{0xffffffff80021d08}, {"_ZN4HEAP7GetFreeEv"}}, 
   {{0xffffffff80021d10}, {"_ZN4HEAP8GetTotalEv"}}, 
   {{0xffffffff80021d18}, {"_ZN4HEAP14InitializeHeapEPvm"}}, 
   {{0xffffffff80021dd9}, {"_ZN4HEAP4FreeEPv"}}, 
   {{0xffffffff80021e38}, {"_ZN4HEAP10ExpandHeapEm"}}, 
   {{0xffffffff80021f28}, {"_ZN4HEAP6MallocEm"}}, 
   {{0xffffffff80021ffa}, {"_GLOBAL__sub_I__ZN13HeapSegHeader14CombineForwardEv"}}, 
   {{0xffffffff80022006}, {"_ZN8SpinLock6UnlockEv"}}, 
   {{0xffffffff8002200c}, {"_ZN8SpinLock8IsLockedEv"}}, 
   {{0xffffffff80022012}, {"_ZN8SpinLock4LockEv"}}, 
   {{0xffffffff80022044}, {"memcmp"}}, 
   {{0xffffffff8002206f}, {"memcpy"}}, 
   {{0xffffffff8002208c}, {"_Z6Mallocm"}}, 
   {{0xffffffff800220c9}, {"_Z4FreePv"}}, 
   {{0xffffffff800220d4}, {"_Znwm"}}, 
   {{0xffffffff80022111}, {"_Znam"}}, 
   {{0xffffffff8002214e}, {"_ZdlPv"}}, 
   {{0xffffffff80022159}, {"_ZdlPvm"}}, 
   {{0xffffffff80022164}, {"_ZdaPv"}}, 
   {{0xffffffff8002216f}, {"_ZdaPvm"}}, 
   {{0xffffffff8002217a}, {"_ZN3MEM10DisplayRamEv"}}, 
   {{0xffffffff800221e5}, {"_ZN3MEM4InitEv"}}, 
   {{0xffffffff800221f0}, {"memset"}}, 
   {{0xffffffff80022208}, {"_ZL10InitBitmapmPv"}}, 
   {{0xffffffff80022234}, {"_ZL13UnreservePagePv"}}, 
   {{0xffffffff8002229d}, {"_ZL14UnreservePagesPvm"}}, 
   {{0xffffffff800222da}, {"_ZL11ReservePagePv"}}, 
   {{0xffffffff80022333}, {"_ZL12ReservePagesPvm"}}, 
   {{0xffffffff80022370}, {"_ZN3PMM22InitPageFrameAllocatorEv"}}, 
   {{0xffffffff800224cd}, {"_ZN3PMM8FreePageEPv"}}, 
   {{0xffffffff8002253d}, {"_ZN3PMM8LockPageEPv"}}, 
   {{0xffffffff800225a2}, {"_ZN3PMM11RequestPageEv"}}, 
   {{0xffffffff8002261e}, {"_ZN3PMM9FreePagesEPvm"}}, 
   {{0xffffffff8002265b}, {"_ZN3PMM9LockPagesEPvm"}}, 
   {{0xffffffff80022698}, {"_ZN3PMM12RequestPagesEm"}}, 
   {{0xffffffff80022746}, {"_ZN3PMM10GetFreeMemEv"}}, 
   {{0xffffffff8002274e}, {"_ZN3PMM10GetUsedMemEv"}}, 
   {{0xffffffff80022756}, {"_ZN3PMM14GetReservedMemEv"}}, 
   {{0xffffffff8002275e}, {"_Z6strlenPKc"}}, 
   {{0xffffffff80022770}, {"_Z6strcpyPcPKc"}}, 
   {{0xffffffff800227a5}, {"_Z6strcmpPKcS0_"}}, 
   {{0xffffffff800227e8}, {"_Z8is_delimcPc"}}, 
   {{0xffffffff80022801}, {"_Z6strtokPcS_"}}, 
   {{0xffffffff8002289a}, {"_Z4itoaPcix"}}, 
   {{0xffffffff80022933}, {"_Z4atoiPc"}}, 
   {{0xffffffff8002295e}, {"_ZN3VMM15NewVirtualSpaceEv"}}, 
   {{0xffffffff80022969}, {"_ZN3VMM21NewModuleVirtualSpaceEv"}}, 
   {{0xffffffff80022acf}, {"_ZN3VMM21NewKernelVirtualSpaceEv"}}, 
   {{0xffffffff80022c07}, {"_ZN3VMM16LoadVirtualSpaceEPNS_12VirtualSpaceE"}}, 
   {{0xffffffff80022c12}, {"_ZN3VMM7InitVMMEv"}}, 
   {{0xffffffff80022c4b}, {"_ZN3VMM9MapMemoryEPNS_12VirtualSpaceEPvS2_"}}, 
   {{0xffffffff80022c5c}, {"_ZN3VMM9MapMemoryEPNS_12VirtualSpaceEPvS2_m"}}, 
   {{0xffffffff80022c68}, {"_ZN6MODULE13BufferManagerC1Ev"}}, 
   {{0xffffffff80022c68}, {"_ZN6MODULE13BufferManagerC2Ev"}}, 
   {{0xffffffff80022c9e}, {"_ZN6MODULE13BufferManager8FindNodeEjPPNS_10BufferNodeEPb"}}, 
   {{0xffffffff80022cd8}, {"_ZN6MODULE13BufferManager7AddNodeEPNS_6BufferE"}}, 
   {{0xffffffff80022d42}, {"_ZN6MODULE13BufferManager10RemoveNodeEj"}}, 
   {{0xffffffff80022dba}, {"_ZN6MODULE13BufferManager12CreateBufferEjjNS_10BufferTypeEm"}}, 
   {{0xffffffff80022e6a}, {"_ZN6MODULE13BufferManager9GetBufferEj"}}, 
   {{0xffffffff80022eb4}, {"_ZN6MODULE13BufferManager9MapBufferEjjjPN3VMM12VirtualSpaceEm"}}, 
   {{0xffffffff80022fda}, {"_ZN6MODULE13BufferManager12DeleteBufferEPNS_6BufferE"}}, 
   {{0xffffffff8002303c}, {"_ZN6MODULE13BufferManager10LockBufferEPNS_6BufferE"}}, 
   {{0xffffffff8002307a}, {"_ZN6MODULE13BufferManager12UnlockBufferEPNS_6BufferE"}}, 
   {{0xffffffff800230a2}, {"_ZN6MODULE14ComposeMessageEPNS_7MessageEjjm"}}, 
   {{0xffffffff80023128}, {"_ZN6MODULE6ModuleC1EjjPN4PROC11ProcessBaseE"}}, 
   {{0xffffffff80023128}, {"_ZN6MODULE6ModuleC2EjjPN4PROC11ProcessBaseE"}}, 
   {{0xffffffff80023132}, {"_ZN6MODULE7ManagerC1Ev"}}, 
   {{0xffffffff80023132}, {"_ZN6MODULE7ManagerC2Ev"}}, 
   {{0xffffffff80023160}, {"_ZN6MODULE7Manager8FindNodeEjjPPNS_10ModuleNodeEPb"}}, 
   {{0xffffffff800231b0}, {"_ZN6MODULE7Manager7AddNodeEjj"}}, 
   {{0xffffffff80023214}, {"_ZN6MODULE7Manager10RemoveNodeEjj"}}, 
   {{0xffffffff8002328c}, {"_ZN6MODULE7Manager14RegisterModuleEPN4PROC11ProcessBaseEjj"}}, 
   {{0xffffffff8002330c}, {"_ZN6MODULE7Manager9GetModuleEjj"}}, 
   {{0xffffffff80023352}, {"_ZN6MODULE7Manager9GetModuleEm"}}, 
   {{0xffffffff80023380}, {"_ZN6MODULE7Manager16UnregisterModuleEjj"}}, 
   {{0xffffffff8002338c}, {"_ZN6MODULE14SectionManagerC1Ev"}}, 
   {{0xffffffff8002338c}, {"_ZN6MODULE14SectionManagerC2Ev"}}, 
   {{0xffffffff800233ca}, {"_ZN6MODULE14SectionManager8FindNodeEPKcjjPPNS_11SectionNodeEPb"}}, 
   {{0xffffffff80023490}, {"_ZN6MODULE14SectionManager7AddNodeEPKcjj"}}, 
   {{0xffffffff8002350e}, {"_ZN6MODULE14SectionManager10RemoveNodeEPKcjj"}}, 
   {{0xffffffff80023572}, {"_ZN6MODULE14SectionManager21RegisterSectionDriverEPKcjj"}}, 
   {{0xffffffff800235e0}, {"_ZN6MODULE14SectionManager16GetSectionDriverEPKcPjS3_"}}, 
   {{0xffffffff80023658}, {"_ZN6MODULE14SectionManager23UnregisterSectionDriverEPKcjj"}}, 
   {{0xffffffff80023663}, {"_ZN4PROCL14GetHighestFreeEv"}}, 
   {{0xffffffff8002366e}, {"_ZN4PROCL10RequestTIDEPNS_11ProcessBaseE"}}, 
   {{0xffffffff80023692}, {"_ZN4PROCL26CreateExecutableUnitHeaderEPNS_11ProcessBaseENS_18ExecutableUnitTypeEbht"}}, 
   {{0xffffffff80023813}, {"_ZN4PROC13CreateProcessEPNS_11ProcessBaseENS_18ExecutableUnitTypeEPN3VMM12VirtualSpaceEht"}}, 
   {{0xffffffff800238b3}, {"_ZN4PROC13DeleteProcessEPNS_11ProcessBaseE"}}, 
   {{0xffffffff800238f4}, {"_ZN4PROC12CreateThreadEPNS_11ProcessBaseEmmht"}}, 
   {{0xffffffff80023ac9}, {"_ZN4PROC10FindThreadEPNS_11ProcessBaseEm"}}, 
   {{0xffffffff80023ae8}, {"_ZN4PROC12DeleteThreadEPNS_10ThreadBaseE"}}, 
   {{0xffffffff80023b29}, {"_ZN4PROC22SetExecutableUnitStateEPNS_20ExecutableUnitHeaderENS_19ExecutableUnitStateE"}}, 
   {{0xffffffff80023b3d}, {"_ZN4PROC19InitializeSchedulerEm"}}, 
   {{0xffffffff80023bc7}, {"_ZN4PROC21DeinitializeSchedulerEPNS_9SchedulerE"}}, 
   {{0xffffffff80023c75}, {"_ZN4PROC16AddThreadToQueueEPNS_9SchedulerEmPNS_10ThreadBaseE"}}, 
   {{0xffffffff80023d46}, {"_ZN4PROC21RemoveThreadFromQueueEPNS_9SchedulerEmmm"}}, 
   {{0xffffffff80023e53}, {"_ZN4PROC18GetThreadFromQueueEPNS_9SchedulerEmmm"}}, 
   {{0xffffffff80023f0e}, {"_ZN4PROC9GetThreadEPNS_9SchedulerEmm"}}, 
   {{0xffffffff80023fbd}, {"_ZN4PROC20RecalculateSchedulerEPNS_9SchedulerE"}}, 
   {{0xffffffff800240a2}, {"_ZN6Bitmap3GetEm"}}, 
   {{0xffffffff800240de}, {"_ZN6BitmapixEm"}}, 
   {{0xffffffff800240ea}, {"_ZN6Bitmap3SetEmb"}}, 
   {{0xffffffff8002413c}, {"_Z18LoadProgramHeadersPhmP10Elf64_EhdrPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80024363}, {"_Z11LoadProcessP10Elf64_EhdrPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff800243ec}, {"_Z7LoadELFPhm"}}, 
   {{0xffffffff8002443c}, {"_ZN4FILE4OpenEPcPm"}}, 
   {{0xffffffff800245d3}, {"__cxa_guard_acquire"}}, 
   {{0xffffffff800245dd}, {"__cxa_guard_release"}}, 
   {{0xffffffff800245e1}, {"__cxa_guard_abort"}}, 
   {{0xffffffff800245e2}, {"__cxa_pure_virtual"}}, 
   {{0xffffffff800245f9}, {"__cxa_atexit"}}, 
   {{0xffffffff8002463c}, {"__cxa_finalize"}}, 
   {{0xffffffff800246d1}, {"_Z16RequestInterruptj"}}, 
   {{0xffffffff800246d4}, {"_Z18LoadExecutableFilePhm"}}, 
   {{0xffffffff8002471b}, {"_Z12TryLockMutexPb"}}, 
   {{0xffffffff8002472d}, {"_Z17SpinlockLockMutexPb"}}, 
   {{0xffffffff8002473e}, {"_Z11UnlockMutexPb"}}, 
   {{0xffffffff80024742}, {"_Z5PanicPKcS0_S0_j"}}, 
   {{0xffffffff80024777}, {"_Z4OopsPKcS0_S0_j"}}, 
   {{0xffffffff800247ac}, {"_Z41__static_initialization_and_destruction_0v"}}, 
   {{0xffffffff800247ca}, {"_ZN6PRINTK11FlushBufferEv"}}, 
   {{0xffffffff80024809}, {"_ZN6PRINTK7PutCharEc"}}, 
   {{0xffffffff80024871}, {"_ZN6PRINTK6PutStrEPc"}}, 
   {{0xffffffff8002489a}, {"_ZN6PRINTK7VPrintKEPcP13__va_list_tag"}}, 
   {{0xffffffff80024a1a}, {"_ZN6PRINTK6PrintKEPcz"}}, 
   {{0xffffffff80024a77}, {"_ZN6PRINTK9EarlyInitEv"}}, 
   {{0xffffffff80024ae1}, {"_GLOBAL__sub_I_KernelPort"}}, 
   {{0xffffffff80024aec}, {"_Z11LoadShebangPhm"}}, 
   {{0xffffffff80024af4}, {"_Z12LookupSymbolPKc"}}, 
   {{0xffffffff80024b47}, {"_Z12LookupSymbolm"}}, 
   {{0xffffffff80024ba3}, {"_ZL10GetProcessv"}}, 
   {{0xffffffff80024be1}, {"_ZL15GetVirtualSpacePN4PROC11UserProcessE"}}, 
   {{0xffffffff80024c1a}, {"_Z11AddOverridem"}}, 
   {{0xffffffff80024c1b}, {"_Z13CheckOverridem"}}, 
   {{0xffffffff80024c21}, {"_Z11RunOverridem"}}, 
   {{0xffffffff80024c27}, {"_Z24HandleSyscallDebugPrintKPKc"}}, 
   {{0xffffffff80024c46}, {"_Z26HandleSyscallMemoryGetinfom"}}, 
   {{0xffffffff80024ca5}, {"_Z26HandleSyscallMemoryVmallocmmm"}}, 
   {{0xffffffff80024db7}, {"_Z25HandleSyscallMemoryPallocPmm"}}, 
   {{0xffffffff80024e29}, {"_Z25HandleSyscallMemoryVmfreemm"}}, 
   {{0xffffffff80024f1e}, {"_Z23HandleSyscallMemoryMmapmmmm"}}, 
   {{0xffffffff80024fe9}, {"_Z24HandleSyscallMemoryUnmapmm"}}, 
   {{0xffffffff800250ab}, {"_Z24HandleSyscallMemoryInOutmbmPmh"}}, 
   {{0xffffffff80025246}, {"_Z21HandleSyscallProcExecmm"}}, 
   {{0xffffffff80025393}, {"_Z21HandleSyscallProcForkm"}}, 
   {{0xffffffff80025399}, {"_Z23HandleSyscallProcReturnmm"}}, 
   {{0xffffffff800253fc}, {"_Z21HandleSyscallProcExitmm"}}, 
   {{0xffffffff80025430}, {"_Z21HandleSyscallProcWaitm"}}, 
   {{0xffffffff80025436}, {"_Z21HandleSyscallProcKillm"}}, 
   {{0xffffffff8002543c}, {"_Z27HandleSyscallModuleRegistermm"}}, 
   {{0xffffffff800254a7}, {"_Z29HandleSyscallModuleUnregisterv"}}, 
   {{0xffffffff80025516}, {"_Z31HandleSyscallModuleBufferCreatemmPj"}}, 
   {{0xffffffff800255ad}, {"_Z28HandleSyscallModuleBufferMapmj"}}, 
   {{0xffffffff80025641}, {"_Z30HandleSyscallModuleBufferUnmapmj"}}, 
   {{0xffffffff80025647}, {"_Z31HandleSyscallModuleBufferDeletej"}}, 
   {{0xffffffff8002564d}, {"_Z33HandleSyscallModuleMessageHandlerm"}}, 
   {{0xffffffff8002567b}, {"_Z30HandleSyscallModuleMessageSendjjPvm"}}, 
   {{0xffffffff800258b3}, {"_Z34HandleSyscallModuleSectionRegisterPKc"}}, 
   {{0xffffffff80025996}, {"_Z29HandleSyscallModuleSectionGetPKcPjS1_"}}, 
   {{0xffffffff80025a52}, {"_Z36HandleSyscallModuleSectionUnregisterPKc"}}, 
   {{0xffffffff80025b13}, {"_Z21HandleSyscallFileOpenPcPmS0_"}}, 
   {{0xffffffff80025ba5}, {"_Z21HandleSyscallFileReadPcmm"}}, 
   {{0xffffffff80025c51}, {"_Z22HandleSyscallFileWritem"}}, 
   {{0xffffffff80025c57}, {"_Z22HandleSyscallFileClosem"}}, 
   {{0xffffffff80025c5d}, {"_Z25HandleSyscallKernOverridem"}}, 
   {{0xffffffff80025c63}, {"HandleSyscall"}}, 
   {{0xffffffff80025fc4}, {"_ZL10EnableSMIDv"}}, 
   {{0xffffffff80026082}, {"_ZN6x86_646x86CPU4InitEv"}}, 
   {{0xffffffff800260c6}, {"_ZN6x86_646x86CPU9GetVendorEPc"}}, 
   {{0xffffffff80026120}, {"_ZN6x86_647TSSInitEm"}}, 
   {{0xffffffff800261ba}, {"_ZN6x86_647LoadGDTEm"}}, 
   {{0xffffffff800261fd}, {"_Z15InitializeStackPvm"}}, 
   {{0xffffffff8002620c}, {"_ZN6x86_6411GetAPICBaseEv"}}, 
   {{0xffffffff8002622d}, {"_ZN6x86_6411SetAPICBaseEm"}}, 
   {{0xffffffff80026247}, {"_ZN6x86_6417WriteAPICRegisterEtj"}}, 
   {{0xffffffff80026264}, {"_ZN6x86_6416ReadAPICRegisterEt"}}, 
   {{0xffffffff80026280}, {"_ZN6x86_6412SetAPICTimerEm"}}, 
   {{0xffffffff80026288}, {"_ZN6x86_648WaitAPICEv"}}, 
   {{0xffffffff8002629e}, {"_ZN6x86_6410EnableAPICEv"}}, 
   {{0xffffffff8002634b}, {"_ZN6x86_6411SendAPICEOIEv"}}, 
   {{0xffffffff80026360}, {"_Z20CalibrateTSCWithHPETmPm"}}, 
   {{0xffffffff80026430}, {"_ZN6x86_646IOAPICC1Em"}}, 
   {{0xffffffff80026430}, {"_ZN6x86_646IOAPICC2Em"}}, 
   {{0xffffffff80026444}, {"_ZN6x86_646IOAPIC10ReadIOAPICEj"}}, 
   {{0xffffffff80026452}, {"_ZN6x86_646IOAPIC11WriteIOAPICEjj"}}, 
   {{0xffffffff80026460}, {"_ZN6x86_646IOAPIC5IoctlEmz"}}, 
   {{0xffffffff8002653a}, {"_ZN6x86_646IOAPICD1Ev"}}, 
   {{0xffffffff8002653a}, {"_ZN6x86_646IOAPICD2Ev"}}, 
   {{0xffffffff8002654a}, {"_ZN6x86_646IOAPICD0Ev"}}, 
   {{0xffffffff80026568}, {"_ZN6x86_6410HandleMADTEP10MADTHeader"}}, 
   {{0xffffffff800266ba}, {"_ZN6x86_6410HandleSRATEP9SDTHeader"}}, 
   {{0xffffffff800266fe}, {"_ZN6x86_6410HandleHPETEP10HPETHeader"}}, 
   {{0xffffffff8002680d}, {"_ZN6x86_6411InitDevicesEv"}}, 
   {{0xffffffff8002691e}, {"_ZN6x86_643PIT5IoctlEmz"}}, 
   {{0xffffffff80026974}, {"_ZN6x86_643PITC1Ev"}}, 
   {{0xffffffff80026974}, {"_ZN6x86_643PITC2Ev"}}, 
   {{0xffffffff80026984}, {"_ZN6x86_643PITD1Ev"}}, 
   {{0xffffffff80026984}, {"_ZN6x86_643PITD2Ev"}}, 
   {{0xffffffff80026994}, {"_ZN6x86_643PITD0Ev"}}, 
   {{0xffffffff800269b2}, {"_ZL16IDTSetDescriptorhPvh"}}, 
   {{0xffffffff800269fa}, {"_ZL10GetProcessv"}}, 
   {{0xffffffff80026a38}, {"_ZL15GetVirtualSpacePN4PROC11UserProcessE"}}, 
   {{0xffffffff80026a71}, {"_ZN6x86_647IDTInitEv"}}, 
   {{0xffffffff80026aef}, {"InterruptHandler"}}, 
   {{0xffffffff80026d83}, {"_ZN6x86_644OutBEth"}}, 
   {{0xffffffff80026d89}, {"_ZN6x86_644OutWEtt"}}, 
   {{0xffffffff80026d90}, {"_ZN6x86_644OutDEtj"}}, 
   {{0xffffffff80026d96}, {"_ZN6x86_643InBEt"}}, 
   {{0xffffffff80026d9a}, {"_ZN6x86_643InWEt"}}, 
   {{0xffffffff80026d9f}, {"_ZN6x86_643InDEt"}}, 
   {{0xffffffff80026da3}, {"_ZN6x86_646IoWaitEv"}}, 
   {{0xffffffff80026db8}, {"_ZN6x86_649EarlyInitEv"}}, 
   {{0xffffffff80026e0d}, {"_ZN6x86_644InitEv"}}, 
   {{0xffffffff80026e86}, {"_ZN14PageMapIndexerC1Em"}}, 
   {{0xffffffff80026e86}, {"_ZN14PageMapIndexerC2Em"}}, 
   {{0xffffffff80026ed0}, {"_ZN16PageTableManager4ForkEPN3VMM12VirtualSpaceEb"}}, 
   {{0xffffffff800272b0}, {"_ZN16PageTableManager9MapMemoryEPvS0_m"}}, 
   {{0xffffffff80027630}, {"_ZN16PageTableManager11UnmapMemoryEPv"}}, 
   {{0xffffffff80027740}, {"_ZN16PageTableManager18GetPhysicalAddressEPv"}}, 
   {{0xffffffff80027846}, {"_ZN16PageTableManagerC1EP9PageTable"}}, 
   {{0xffffffff80027846}, {"_ZN16PageTableManagerC2EP9PageTable"}}, 
   {{0xffffffff8002785a}, {"_ZN16PageTableManager13GetTopAddressEv"}}, 
   {{0xffffffff80027860}, {"_ZN16PageTableManagerD1Ev"}}, 
   {{0xffffffff80027860}, {"_ZN16PageTableManagerD2Ev"}}, 
   {{0xffffffff80027870}, {"_ZN16PageTableManagerD0Ev"}}, 
   {{0xffffffff8002788e}, {"_ZN18PageDirectoryEntry7SetFlagE7PT_Flagb"}}, 
   {{0xffffffff800278b6}, {"_ZN18PageDirectoryEntry7GetFlagE7PT_Flag"}}, 
   {{0xffffffff800278cc}, {"_ZN18PageDirectoryEntry10SetAddressEm"}}, 
   {{0xffffffff800278f4}, {"_ZN18PageDirectoryEntry10GetAddressEv"}}, 
   {{0xffffffff80027909}, {"_ZN6x86_6415NewVirtualSpaceEv"}}, 
   {{0xffffffff8002794a}, {"_ZN6x86_6416LoadVirtualSpaceEPN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80027960}, {"CPUPause"}}, 
   {{0xffffffff80027970}, {"FlushGDT"}}, 
   {{0xffffffff80027973}, {"reloadSegments"}}, 
   {{0xffffffff8002797f}, {"reloadSegments.reloadCS"}}, 
   {{0xffffffff8002798e}, {"FlushTSS"}}, 
   {{0xffffffff800279a0}, {"EnableSCE"}}, 
   {{0xffffffff800279e0}, {"EnableSSE"}}, 
   {{0xffffffff800279fb}, {"EnableAVX"}}, 
   {{0xffffffff80027a10}, {"SwitchStack"}}, 
   {{0xffffffff80027a50}, {"EnterUserspace"}}, 
   {{0xffffffff80027a60}, {"isr_stub_0"}}, 
   {{0xffffffff80027aa1}, {"isr_stub_1"}}, 
   {{0xffffffff80027ae2}, {"isr_stub_2"}}, 
   {{0xffffffff80027b23}, {"isr_stub_3"}}, 
   {{0xffffffff80027b64}, {"isr_stub_4"}}, 
   {{0xffffffff80027ba5}, {"isr_stub_5"}}, 
   {{0xffffffff80027be6}, {"isr_stub_6"}}, 
   {{0xffffffff80027c27}, {"isr_stub_7"}}, 
   {{0xffffffff80027c68}, {"isr_stub_8"}}, 
   {{0xffffffff80027ca7}, {"isr_stub_9"}}, 
   {{0xffffffff80027ce8}, {"isr_stub_10"}}, 
   {{0xffffffff80027d27}, {"isr_stub_11"}}, 
   {{0xffffffff80027d66}, {"isr_stub_12"}}, 
   {{0xffffffff80027da5}, {"isr_stub_13"}}, 
   {{0xffffffff80027de4}, {"isr_stub_14"}}, 
   {{0xffffffff80027e23}, {"isr_stub_15"}}, 
   {{0xffffffff80027e64}, {"isr_stub_16"}}, 
   {{0xffffffff80027ea5}, {"isr_stub_17"}}, 
   {{0xffffffff80027ee4}, {"isr_stub_18"}}, 
   {{0xffffffff80027f25}, {"isr_stub_19"}}, 
   {{0xffffffff80027f66}, {"isr_stub_20"}}, 
   {{0xffffffff80027fa7}, {"isr_stub_21"}}, 
   {{0xffffffff80027fe8}, {"isr_stub_22"}}, 
   {{0xffffffff80028029}, {"isr_stub_23"}}, 
   {{0xffffffff8002806a}, {"isr_stub_24"}}, 
   {{0xffffffff800280ab}, {"isr_stub_25"}}, 
   {{0xffffffff800280ec}, {"isr_stub_26"}}, 
   {{0xffffffff8002812d}, {"isr_stub_27"}}, 
   {{0xffffffff8002816e}, {"isr_stub_28"}}, 
   {{0xffffffff800281af}, {"isr_stub_29"}}, 
   {{0xffffffff800281f0}, {"isr_stub_30"}}, 
   {{0xffffffff8002822f}, {"isr_stub_31"}}, 
   {{0xffffffff80028270}, {"isr_stub_32"}}, 
   {{0xffffffff800282b1}, {"isr_stub_33"}}, 
   {{0xffffffff800282f2}, {"isr_stub_34"}}, 
   {{0xffffffff80028333}, {"isr_stub_35"}}, 
   {{0xffffffff80028374}, {"isr_stub_36"}}, 
   {{0xffffffff800283b5}, {"isr_stub_37"}}, 
   {{0xffffffff800283f6}, {"isr_stub_38"}}, 
   {{0xffffffff80028437}, {"isr_stub_39"}}, 
   {{0xffffffff80028478}, {"isr_stub_40"}}, 
   {{0xffffffff800284b9}, {"isr_stub_41"}}, 
   {{0xffffffff800284fa}, {"isr_stub_42"}}, 
   {{0xffffffff8002853b}, {"isr_stub_43"}}, 
   {{0xffffffff8002857c}, {"isr_stub_44"}}, 
   {{0xffffffff800285bd}, {"isr_stub_45"}}, 
   {{0xffffffff800285fe}, {"isr_stub_46"}}, 
   {{0xffffffff8002863f}, {"isr_stub_47"}}, 
   {{0xffffffff80028680}, {"isr_stub_48"}}, 
   {{0xffffffff800286c1}, {"isr_stub_49"}}, 
   {{0xffffffff80028702}, {"isr_stub_50"}}, 
   {{0xffffffff80028743}, {"isr_stub_51"}}, 
   {{0xffffffff80028784}, {"isr_stub_52"}}, 
   {{0xffffffff800287c5}, {"isr_stub_53"}}, 
   {{0xffffffff80028806}, {"isr_stub_54"}}, 
   {{0xffffffff80028847}, {"isr_stub_55"}}, 
   {{0xffffffff80028888}, {"isr_stub_56"}}, 
   {{0xffffffff800288c9}, {"isr_stub_57"}}, 
   {{0xffffffff8002890a}, {"isr_stub_58"}}, 
   {{0xffffffff8002894b}, {"isr_stub_59"}}, 
   {{0xffffffff8002898c}, {"isr_stub_60"}}, 
   {{0xffffffff800289cd}, {"isr_stub_61"}}, 
   {{0xffffffff80028a0e}, {"isr_stub_62"}}, 
   {{0xffffffff80028a4f}, {"isr_stub_63"}}, 
   {{0xffffffff80028a90}, {"isr_stub_64"}}, 
   {{0xffffffff80028ad1}, {"isr_stub_65"}}, 
   {{0xffffffff80028b12}, {"isr_stub_66"}}, 
   {{0xffffffff80028b53}, {"isr_stub_67"}}, 
   {{0xffffffff80028b94}, {"isr_stub_68"}}, 
   {{0xffffffff80028bd5}, {"isr_stub_69"}}, 
   {{0xffffffff80028c16}, {"isr_stub_70"}}, 
   {{0xffffffff80028c57}, {"isr_stub_71"}}, 
   {{0xffffffff80028c98}, {"isr_stub_72"}}, 
   {{0xffffffff80028cd9}, {"isr_stub_73"}}, 
   {{0xffffffff80028d1a}, {"isr_stub_74"}}, 
   {{0xffffffff80028d5b}, {"isr_stub_75"}}, 
   {{0xffffffff80028d9c}, {"isr_stub_76"}}, 
   {{0xffffffff80028ddd}, {"isr_stub_77"}}, 
   {{0xffffffff80028e1e}, {"isr_stub_78"}}, 
   {{0xffffffff80028e5f}, {"isr_stub_79"}}, 
   {{0xffffffff80028ea0}, {"isr_stub_80"}}, 
   {{0xffffffff80028ee1}, {"isr_stub_81"}}, 
   {{0xffffffff80028f22}, {"isr_stub_82"}}, 
   {{0xffffffff80028f63}, {"isr_stub_83"}}, 
   {{0xffffffff80028fa4}, {"isr_stub_84"}}, 
   {{0xffffffff80028fe5}, {"isr_stub_85"}}, 
   {{0xffffffff80029026}, {"isr_stub_86"}}, 
   {{0xffffffff80029067}, {"isr_stub_87"}}, 
   {{0xffffffff800290a8}, {"isr_stub_88"}}, 
   {{0xffffffff800290e9}, {"isr_stub_89"}}, 
   {{0xffffffff8002912a}, {"isr_stub_90"}}, 
   {{0xffffffff8002916b}, {"isr_stub_91"}}, 
   {{0xffffffff800291ac}, {"isr_stub_92"}}, 
   {{0xffffffff800291ed}, {"isr_stub_93"}}, 
   {{0xffffffff8002922e}, {"isr_stub_94"}}, 
   {{0xffffffff8002926f}, {"isr_stub_95"}}, 
   {{0xffffffff800292b0}, {"isr_stub_96"}}, 
   {{0xffffffff800292f1}, {"isr_stub_97"}}, 
   {{0xffffffff80029332}, {"isr_stub_98"}}, 
   {{0xffffffff80029373}, {"isr_stub_99"}}, 
   {{0xffffffff800293b4}, {"isr_stub_100"}}, 
   {{0xffffffff800293f5}, {"isr_stub_101"}}, 
   {{0xffffffff80029436}, {"isr_stub_102"}}, 
   {{0xffffffff80029477}, {"isr_stub_103"}}, 
   {{0xffffffff800294b8}, {"isr_stub_104"}}, 
   {{0xffffffff800294f9}, {"isr_stub_105"}}, 
   {{0xffffffff8002953a}, {"isr_stub_106"}}, 
   {{0xffffffff8002957b}, {"isr_stub_107"}}, 
   {{0xffffffff800295bc}, {"isr_stub_108"}}, 
   {{0xffffffff800295fd}, {"isr_stub_109"}}, 
   {{0xffffffff8002963e}, {"isr_stub_110"}}, 
   {{0xffffffff8002967f}, {"isr_stub_111"}}, 
   {{0xffffffff800296c0}, {"isr_stub_112"}}, 
   {{0xffffffff80029701}, {"isr_stub_113"}}, 
   {{0xffffffff80029742}, {"isr_stub_114"}}, 
   {{0xffffffff80029783}, {"isr_stub_115"}}, 
   {{0xffffffff800297c4}, {"isr_stub_116"}}, 
   {{0xffffffff80029805}, {"isr_stub_117"}}, 
   {{0xffffffff80029846}, {"isr_stub_118"}}, 
   {{0xffffffff80029887}, {"isr_stub_119"}}, 
   {{0xffffffff800298c8}, {"isr_stub_120"}}, 
   {{0xffffffff80029909}, {"isr_stub_121"}}, 
   {{0xffffffff8002994a}, {"isr_stub_122"}}, 
   {{0xffffffff8002998b}, {"isr_stub_123"}}, 
   {{0xffffffff800299cc}, {"isr_stub_124"}}, 
   {{0xffffffff80029a0d}, {"isr_stub_125"}}, 
   {{0xffffffff80029a4e}, {"isr_stub_126"}}, 
   {{0xffffffff80029a8f}, {"isr_stub_127"}}, 
   {{0xffffffff80029ad0}, {"isr_stub_128"}}, 
   {{0xffffffff80029b14}, {"isr_stub_129"}}, 
   {{0xffffffff80029b58}, {"isr_stub_130"}}, 
   {{0xffffffff80029b9c}, {"isr_stub_131"}}, 
   {{0xffffffff80029be0}, {"isr_stub_132"}}, 
   {{0xffffffff80029c24}, {"isr_stub_133"}}, 
   {{0xffffffff80029c68}, {"isr_stub_134"}}, 
   {{0xffffffff80029cac}, {"isr_stub_135"}}, 
   {{0xffffffff80029cf0}, {"isr_stub_136"}}, 
   {{0xffffffff80029d34}, {"isr_stub_137"}}, 
   {{0xffffffff80029d78}, {"isr_stub_138"}}, 
   {{0xffffffff80029dbc}, {"isr_stub_139"}}, 
   {{0xffffffff80029e00}, {"isr_stub_140"}}, 
   {{0xffffffff80029e44}, {"isr_stub_141"}}, 
   {{0xffffffff80029e88}, {"isr_stub_142"}}, 
   {{0xffffffff80029ecc}, {"isr_stub_143"}}, 
   {{0xffffffff80029f10}, {"isr_stub_144"}}, 
   {{0xffffffff80029f54}, {"isr_stub_145"}}, 
   {{0xffffffff80029f98}, {"isr_stub_146"}}, 
   {{0xffffffff80029fdc}, {"isr_stub_147"}}, 
   {{0xffffffff8002a020}, {"isr_stub_148"}}, 
   {{0xffffffff8002a064}, {"isr_stub_149"}}, 
   {{0xffffffff8002a0a8}, {"isr_stub_150"}}, 
   {{0xffffffff8002a0ec}, {"isr_stub_151"}}, 
   {{0xffffffff8002a130}, {"isr_stub_152"}}, 
   {{0xffffffff8002a174}, {"isr_stub_153"}}, 
   {{0xffffffff8002a1b8}, {"isr_stub_154"}}, 
   {{0xffffffff8002a1fc}, {"isr_stub_155"}}, 
   {{0xffffffff8002a240}, {"isr_stub_156"}}, 
   {{0xffffffff8002a284}, {"isr_stub_157"}}, 
   {{0xffffffff8002a2c8}, {"isr_stub_158"}}, 
   {{0xffffffff8002a30c}, {"isr_stub_159"}}, 
   {{0xffffffff8002a350}, {"isr_stub_160"}}, 
   {{0xffffffff8002a394}, {"isr_stub_161"}}, 
   {{0xffffffff8002a3d8}, {"isr_stub_162"}}, 
   {{0xffffffff8002a41c}, {"isr_stub_163"}}, 
   {{0xffffffff8002a460}, {"isr_stub_164"}}, 
   {{0xffffffff8002a4a4}, {"isr_stub_165"}}, 
   {{0xffffffff8002a4e8}, {"isr_stub_166"}}, 
   {{0xffffffff8002a52c}, {"isr_stub_167"}}, 
   {{0xffffffff8002a570}, {"isr_stub_168"}}, 
   {{0xffffffff8002a5b4}, {"isr_stub_169"}}, 
   {{0xffffffff8002a5f8}, {"isr_stub_170"}}, 
   {{0xffffffff8002a63c}, {"isr_stub_171"}}, 
   {{0xffffffff8002a680}, {"isr_stub_172"}}, 
   {{0xffffffff8002a6c4}, {"isr_stub_173"}}, 
   {{0xffffffff8002a708}, {"isr_stub_174"}}, 
   {{0xffffffff8002a74c}, {"isr_stub_175"}}, 
   {{0xffffffff8002a790}, {"isr_stub_176"}}, 
   {{0xffffffff8002a7d4}, {"isr_stub_177"}}, 
   {{0xffffffff8002a818}, {"isr_stub_178"}}, 
   {{0xffffffff8002a85c}, {"isr_stub_179"}}, 
   {{0xffffffff8002a8a0}, {"isr_stub_180"}}, 
   {{0xffffffff8002a8e4}, {"isr_stub_181"}}, 
   {{0xffffffff8002a928}, {"isr_stub_182"}}, 
   {{0xffffffff8002a96c}, {"isr_stub_183"}}, 
   {{0xffffffff8002a9b0}, {"isr_stub_184"}}, 
   {{0xffffffff8002a9f4}, {"isr_stub_185"}}, 
   {{0xffffffff8002aa38}, {"isr_stub_186"}}, 
   {{0xffffffff8002aa7c}, {"isr_stub_187"}}, 
   {{0xffffffff8002aac0}, {"isr_stub_188"}}, 
   {{0xffffffff8002ab04}, {"isr_stub_189"}}, 
   {{0xffffffff8002ab48}, {"isr_stub_190"}}, 
   {{0xffffffff8002ab8c}, {"isr_stub_191"}}, 
   {{0xffffffff8002abd0}, {"isr_stub_192"}}, 
   {{0xffffffff8002ac14}, {"isr_stub_193"}}, 
   {{0xffffffff8002ac58}, {"isr_stub_194"}}, 
   {{0xffffffff8002ac9c}, {"isr_stub_195"}}, 
   {{0xffffffff8002ace0}, {"isr_stub_196"}}, 
   {{0xffffffff8002ad24}, {"isr_stub_197"}}, 
   {{0xffffffff8002ad68}, {"isr_stub_198"}}, 
   {{0xffffffff8002adac}, {"isr_stub_199"}}, 
   {{0xffffffff8002adf0}, {"isr_stub_200"}}, 
   {{0xffffffff8002ae34}, {"isr_stub_201"}}, 
   {{0xffffffff8002ae78}, {"isr_stub_202"}}, 
   {{0xffffffff8002aebc}, {"isr_stub_203"}}, 
   {{0xffffffff8002af00}, {"isr_stub_204"}}, 
   {{0xffffffff8002af44}, {"isr_stub_205"}}, 
   {{0xffffffff8002af88}, {"isr_stub_206"}}, 
   {{0xffffffff8002afcc}, {"isr_stub_207"}}, 
   {{0xffffffff8002b010}, {"isr_stub_208"}}, 
   {{0xffffffff8002b054}, {"isr_stub_209"}}, 
   {{0xffffffff8002b098}, {"isr_stub_210"}}, 
   {{0xffffffff8002b0dc}, {"isr_stub_211"}}, 
   {{0xffffffff8002b120}, {"isr_stub_212"}}, 
   {{0xffffffff8002b164}, {"isr_stub_213"}}, 
   {{0xffffffff8002b1a8}, {"isr_stub_214"}}, 
   {{0xffffffff8002b1ec}, {"isr_stub_215"}}, 
   {{0xffffffff8002b230}, {"isr_stub_216"}}, 
   {{0xffffffff8002b274}, {"isr_stub_217"}}, 
   {{0xffffffff8002b2b8}, {"isr_stub_218"}}, 
   {{0xffffffff8002b2fc}, {"isr_stub_219"}}, 
   {{0xffffffff8002b340}, {"isr_stub_220"}}, 
   {{0xffffffff8002b384}, {"isr_stub_221"}}, 
   {{0xffffffff8002b3c8}, {"isr_stub_222"}}, 
   {{0xffffffff8002b40c}, {"isr_stub_223"}}, 
   {{0xffffffff8002b450}, {"isr_stub_224"}}, 
   {{0xffffffff8002b494}, {"isr_stub_225"}}, 
   {{0xffffffff8002b4d8}, {"isr_stub_226"}}, 
   {{0xffffffff8002b51c}, {"isr_stub_227"}}, 
   {{0xffffffff8002b560}, {"isr_stub_228"}}, 
   {{0xffffffff8002b5a4}, {"isr_stub_229"}}, 
   {{0xffffffff8002b5e8}, {"isr_stub_230"}}, 
   {{0xffffffff8002b62c}, {"isr_stub_231"}}, 
   {{0xffffffff8002b670}, {"isr_stub_232"}}, 
   {{0xffffffff8002b6b4}, {"isr_stub_233"}}, 
   {{0xffffffff8002b6f8}, {"isr_stub_234"}}, 
   {{0xffffffff8002b73c}, {"isr_stub_235"}}, 
   {{0xffffffff8002b780}, {"isr_stub_236"}}, 
   {{0xffffffff8002b7c4}, {"isr_stub_237"}}, 
   {{0xffffffff8002b808}, {"isr_stub_238"}}, 
   {{0xffffffff8002b84c}, {"isr_stub_239"}}, 
   {{0xffffffff8002b890}, {"isr_stub_240"}}, 
   {{0xffffffff8002b8d4}, {"isr_stub_241"}}, 
   {{0xffffffff8002b918}, {"isr_stub_242"}}, 
   {{0xffffffff8002b95c}, {"isr_stub_243"}}, 
   {{0xffffffff8002b9a0}, {"isr_stub_244"}}, 
   {{0xffffffff8002b9e4}, {"isr_stub_245"}}, 
   {{0xffffffff8002ba28}, {"isr_stub_246"}}, 
   {{0xffffffff8002ba6c}, {"isr_stub_247"}}, 
   {{0xffffffff8002bab0}, {"isr_stub_248"}}, 
   {{0xffffffff8002baf4}, {"isr_stub_249"}}, 
   {{0xffffffff8002bb38}, {"isr_stub_250"}}, 
   {{0xffffffff8002bb7c}, {"isr_stub_251"}}, 
   {{0xffffffff8002bbc0}, {"isr_stub_252"}}, 
   {{0xffffffff8002bc04}, {"isr_stub_253"}}, 
   {{0xffffffff8002bc48}, {"isr_stub_254"}}, 
   {{0xffffffff8002bc8c}, {"isr_stub_255"}}, 
   {{0xffffffff8002bcd0}, {"isrStubTable"}}, 
   {{0xffffffff8002d658}, {"_ZTV6Device"}}, 
   {{0xffffffff8002d680}, {"_ZTV10UARTDevice"}}, 
   {{0xffffffff8002d9a8}, {"_ZTV5Mutex"}}, 
   {{0xffffffff8002d9d0}, {"_ZTV8SpinLock"}}, 
   {{0xffffffff8002daa0}, {"_ZL14memTypeStrings"}}, 
   {{0xffffffff80030ec0}, {"symbols"}}, 
   {{0xffffffff800333c0}, {"symbolCount"}}, 
   {{0xffffffff80033538}, {"_ZTVN6x86_646IOAPICE"}}, 
   {{0xffffffff800339a8}, {"_ZTVN6x86_643PITE"}}, 
   {{0xffffffff80033ca0}, {"_ZTVN3VMM12VirtualSpaceE"}}, 
   {{0xffffffff80033ce8}, {"_ZTV16PageTableManager"}}, 
   {{0xffffffff80035000}, {"_ZL11TimeRequest"}}, 
   {{0xffffffff80035040}, {"_ZL10SMPRequest"}}, 
   {{0xffffffff80035080}, {"_ZL17KernelFileRequest"}}, 
   {{0xffffffff800350c0}, {"_ZL18FramebufferRequest"}}, 
   {{0xffffffff80035100}, {"_ZL15EFITableRequest"}}, 
   {{0xffffffff80035140}, {"_ZL13SMBIOSRequest"}}, 
   {{0xffffffff80035180}, {"_ZL11RSDPRequest"}}, 
   {{0xffffffff800351c0}, {"_ZL12KAddrRequest"}}, 
   {{0xffffffff80035200}, {"_ZL16MemoryMapRequest"}}, 
   {{0xffffffff80035240}, {"_ZL11HHDMRequest"}}, 
   {{0xffffffff80035280}, {"_ZL13ModuleRequest"}}, 
   {{0xffffffff800352c0}, {"_ZL12StackRequest"}}, 
   {{0xffffffff80035300}, {"_ZL17EntryPointRequest"}}, 
   {{0xffffffff80035338}, {"bootmemStatus"}}, 
   {{0xffffffff80036000}, {"gdt"}}, 
   {{0xffffffff80037000}, {"__stack_chk_guard"}}, 
   {{0xffffffff80037008}, {"info"}}, 
   {{0xffffffff80037010}, {"lastPosition"}}, 
   {{0xffffffff80037020}, {"bootmemMemory"}}, 
   {{0xffffffff80038020}, {"_ZL8HeapLock"}}, 
   {{0xffffffff80038030}, {"_ZL8totalMem"}}, 
   {{0xffffffff80038038}, {"_ZL7freeMem"}}, 
   {{0xffffffff80038040}, {"_ZL12isHeapActive"}}, 
   {{0xffffffff80038048}, {"_ZL10lastHeader"}}, 
   {{0xffffffff80038050}, {"_ZL7heapEnd"}}, 
   {{0xffffffff80038058}, {"_ZL9heapStart"}}, 
   {{0xffffffff80038060}, {"_ZL10HigherHalf"}}, 
   {{0xffffffff80038068}, {"_ZL15PageBitmapIndex"}}, 
   {{0xffffffff80038070}, {"_ZL10PageBitmap"}}, 
   {{0xffffffff80038080}, {"_ZL11Initialized"}}, 
   {{0xffffffff80038088}, {"_ZL10UsedMemory"}}, 
   {{0xffffffff80038090}, {"_ZL14ReservedMemory"}}, 
   {{0xffffffff80038098}, {"_ZL10FreeMemory"}}, 
   {{0xffffffff800380a0}, {"_ZZ6strtokPcS_E1p"}}, 
   {{0xffffffff800380a8}, {"_ZN4PROCL10CurrentPIDE"}}, 
   {{0xffffffff800380c0}, {"__dso_handle"}}, 
   {{0xffffffff800380c8}, {"__atexit_func_count"}}, 
   {{0xffffffff800380e0}, {"__atexit_funcs"}}, 
   {{0xffffffff80038ce0}, {"KernelPort"}}, 
   {{0xffffffff80038ce8}, {"_ZN6PRINTKL16TerminalPositionE"}}, 
   {{0xffffffff80038d00}, {"_ZN6PRINTKL14TerminalColumnE"}}, 
   {{0xffffffff80038e00}, {"_ZN6PRINTKL14PrintKSpinlockE"}}, 
   {{0xffffffff80039000}, {"gdtPointer"}}, 
   {{0xffffffff8003a000}, {"tss"}}, 
   {{0xffffffff8003a068}, {"_ZN6x86_64L6cyclesE"}}, 
   {{0xffffffff8003a070}, {"idtr"}}, 
   {{0xffffffff8003a080}, {"idt"}}, 
};
