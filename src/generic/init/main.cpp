/*  __  __  _                _  __        ___   ___
 * |  \/  |(_) __  _ _  ___ | |/ /       / _ \ / __|
 * | |\/| || |/ _|| '_|/ _ \|   <       | (_) |\__ \
 * |_|  |_||_|\__||_|  \___/|_|\_\       \___/ |___/
 *
 * MicroKernel, a simple futiristic Unix-shattering kernel
 * Copyright (C) 2022-2023 Mutta Filippo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General does return to userspacePublic License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * File: generic/init/main.cpp
 */

#include <cdefs.h>
#include <stdint.h>
#include <stddef.h>
#include <mm/pmm.hpp>
#include <mm/heap.hpp>
#include <init/main.hpp>
#include <init/kargs.hpp>
#include <sys/panic.hpp>
#include <mm/memory.hpp>
#include <mm/bootmem.hpp>
#include <init/kinfo.hpp>
#include <sys/atomic.hpp>
#include <sys/printk.hpp>
#include <sys/loader.hpp>
#include <proc/scheduler.hpp>
#include <module/modulemanager.hpp>
#include <module/buffer.hpp>
#include <module/section.hpp>

#if defined(ARCH_x64)
#include <arch/x64/main.hpp>
#elif defined(ARCH_aarch64)
#include <arch/aarch64/main.hpp>
#endif


int EarlyKernelInit() {
	/* Allocating memory for the info struct */
	InitInfo();
	KInfo *info = GetInfo();

	/* Initializing early architecture-specific devices */
#if defined(ARCH_x64)
	x86_64::EarlyInit();
#elif defined(ARCH_aarch64)
	AArch64::EarlyInit();
#endif

	/* Loading early serial printk */
	PRINTK::EarlyInit();

	return 0;
}


void PrintBanner() {
	/* Getting some useful system info */
	KInfo *info = GetInfo();

	/* Printing banner */
	PRINTK::PrintK(" __  __  _                _  __\r\n"
		       "|  \\/  |(_) __  _ _  ___ | |/ /\r\n"
		       "| |\\/| || |/ _|| '_|/ _ \\|   < \r\n"
		       "|_|  |_||_|\\__||_|  \\___/|_|\\_\\\r\n"
		       "The operating system for the future...at your fingertips.\r\n"
		       "%s %s Started.\r\n"
		       "System stats:\r\n"
		       "  Memory:\r\n"
		       "   Physical: %dkb free out of %dkb (%dkb used).\r\n"
		       "   Virtual: Kernel at virtual address 0x%x.\r\n"
		       "   Bootmem: %d bytes free out of %d bytes (%d bytes used).\r\n",
		       CONFIG_KERNEL_CNAME,
		       CONFIG_KERNEL_CVER,
			PMM::GetFreeMem() / 1024,
			(PMM::GetFreeMem() + PMM::GetUsedMem()) / 1024,
			PMM::GetUsedMem() / 1024,
			info->kernelVirtualBase,
			BOOTMEM::GetFree(),
			BOOTMEM::GetTotal(),
			BOOTMEM::GetTotal() - BOOTMEM::GetFree());
}

__attribute__((noreturn)) void KernelStart() {
	KInfo *info = GetInfo();

	PRINTK::PrintK("MicroKosm is booted. Cmdline: %s\r\n", info->KernelArgs);
	ParseArgs();

	/* Enabling the page frame allocator */
	PMM::InitPageFrameAllocator();

	/* Starting the memory subsystem */
	MEM::DisplayRam();
	MEM::Init();

	/* Initializing the heap */
	HEAP::InitializeHeap(CONFIG_HEAP_BASE, CONFIG_HEAP_SIZE / 0x1000);

	/* With the heap initialized, disable new bootmem allocations */
	BOOTMEM::DeactivateBootmem();

	/* Starting architecture-specific instructions */
#if defined(ARCH_x64)
	x86_64::Init();
#elif defined(ARCH_aarch64)
	AArch64::Init();
#endif

	/* Printing banner to show off */
	PrintBanner();

#ifdef CONFIG_KERNEL_MODULES
	/* Initializing the scheduler framework */
	info->kernelScheduler = new PROC::Scheduler();

	/* Initialize the kernel's module manager */
	info->KernelModuleManager = new MODULE::Manager();
	info->KernelBufferManager = new MODULE::BufferManager();
	info->KernelSectionManager = new MODULE::SectionManager();

	PRINTK::PrintK("Module managment initialized.\r\n");
	
	/* Load all the files we are told to load */
	size_t moduleSize;
	void *addr;

	/* Get the memory location of the user module */
	addr = FILE::Open(info->UserModuleName, &moduleSize);
	
	/* Check if it is present */
	if (addr != NULL) {
		PRINTK::PrintK("Loading user module from 0x%x\r\n", addr);

		/* Create the process and set it to a ready state */
		size_t pid = LoadExecutableFile(addr, moduleSize);
		info->kernelScheduler->SetProcessState(pid, PROC::P_READY);

		/* Recalculate the scheduler and wait for the context switch */
		PRINTK::PrintK("Switching to user module.\r\n");
		info->kernelScheduler->RecalculateScheduler();

		x86_64::EnableAPIC();
		x86_64::WaitAPIC();

		info->kernelScheduler->SwitchToTask(info->kernelScheduler->GetRunningProcess(),info->kernelScheduler->GetRunningProcess()->GetMainThread());
	} else PANIC("Could not find User Module");
#endif

	/* We are done */
	while (true) CPUPause();
}
