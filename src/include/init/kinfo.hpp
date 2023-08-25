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
 * File: include/init/kinfo.hpp
 */

#pragma once
#include <cdefs.h>
#include <stddef.h>
#include <stdint.h>
#include <mm/memory.hpp>
#include <sys/file.hpp>
#include <mm/vmm.hpp>
#include <proc/process.hpp>
#include <proc/scheduler.hpp>
#include <module/modulemanager.hpp>
#include <module/buffer.hpp>
#include <module/section.hpp>
#include <dev/uart.hpp>

/*
 * struct: Framebuffer 
 * Contains the information the kernel stores for a framebuffer.
 *
 * attributes: packed
 */
struct Framebuffer {
	void *Address;
	uint32_t Width;
	uint32_t Height;
	uint16_t BPP;
	uint8_t RedShift;
	uint8_t GreenShift;
	uint8_t BlueShift;
}__attribute__((packed));

/*
 * struct: KInfo
 * Contains various data structures that need to be accessible to various
 * kernel components and subsystems.
 *
 * attributes: none
 */
struct KInfo {
	/* Kernel args */
	const char *KernelArgs;

	/* Memory information */
	MEM::MMapEntry *mMap; /* Pointer to the memory map */
	uint64_t mMapEntryCount; /* Number of memory map regions */

	uintptr_t higherHalfMapping; /* Start of higher half mapping */
	uintptr_t kernelStack; /* Start of kernel stack */

	uintptr_t kernelPhysicalBase; /* Start of the kernel in physical memory */
	uintptr_t kernelVirtualBase; /* Start of the kernel in virtual memory */

	VMM::VirtualSpace *kernelVirtualSpace; /* Kernel virtual memory space */
	PROC::Process *kernelProcess;
	PROC::Scheduler *kernelScheduler;

#ifdef CONFIG_KERNEL_MODULES
	/* Module information */
	FILE::BootFile *bootFiles; /* Pointer to the Limine modules */
	uint64_t fileCount; /* Number of modules provided */

	char UserModuleName[256];

	MODULE::Manager *KernelModuleManager;
	MODULE::BufferManager *KernelBufferManager;
	MODULE::SectionManager *KernelSectionManager;
#endif

#ifdef CONFIG_HW_UART
	/* Kernel serial device */
	UARTDevice *kernelPort; /* UART deivice used as serial port */
#endif

	void *RSDP;

	size_t framebufferCount;
	Framebuffer *framebuffers;
};

/*
 * function: InitInfo 
 * This function allocates memory for the KInfo struct and
 * clears it to zero. It has to be called before any call to
 * the GetInfo function.
 * 
 * arguments: void 
 * return: void 
 */
void InitInfo();

/*
 * function: GetInfo 
 * This function returns a pointer to the KInfo struct.
 * If the struct wasn't allocated prior with the InitInfo function,
 * it is undefined behavior.
 * 
 * arguments: void 
 * return: KInfo* 
 * The pointer to the KInfo struct.
 */
KInfo *GetInfo();
