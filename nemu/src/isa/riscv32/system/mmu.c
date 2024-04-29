/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>

#define VA_OFFSET(addr) (addr & 0x00000FFF)
#define VA_VPN_2(addr)  ((addr >> 12) & 0x000003FF)
#define VA_VPN_1(addr)  ((addr >> 22) & 0x000003FF)

#define PTE_V(item)   (item & 0x1)
#define PTE_R(item)   ((item >> 1) & 0x1)
#define PTE_W(item)   ((item >> 2) & 0x1)
#define PTE_X(item)   ((item >> 3) & 0x1)
#define PTE_PPN(item) ((item >> 12) & 0xFFFFF) 

typedef word_t PTE;
typedef PTE* PTE_Ptr;
typedef word_t rtlreg_t;
#define PTE_BYTES (4)

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
	// check(vaddr);
	// Fetch level-1 PT base
	rtlreg_t satp = cpu.csr.satp;
	// check(satp);
	PTE_Ptr page_dir_base = (PTE_Ptr)(uintptr_t)(satp << 12);
	// checkp(page_dir_base);

	// Extract l1 VPN, l2 VPN, page offset
	uint32_t offset = VA_OFFSET(vaddr);
	uint32_t vpn_1 = VA_VPN_1(vaddr);
	uint32_t vpn_2 = VA_VPN_2(vaddr);

	PTE_Ptr page_dir_target = page_dir_base + vpn_1;
	PTE page_dir_entry = paddr_read((uintptr_t)page_dir_target, PTE_BYTES);
	// checkp(page_dir_target);
	// check(page_dir_entry);

	// Should be valid
	assert(PTE_V(page_dir_entry));

	PTE_Ptr page_table_base = (PTE_Ptr)(uintptr_t)(PTE_PPN(page_dir_entry) << 12);
	PTE_Ptr page_table_target = page_table_base + vpn_2;
	PTE page_table_entry = paddr_read((uintptr_t)page_table_target, PTE_BYTES);
	// checkp(page_table_base);
	// checkp(page_table_target);
	// check(page_table_entry);

	// Should be valid
	assert(PTE_V(page_table_entry));

	// Access type sanity check
	switch (type) {
	case MEM_TYPE_IFETCH: assert(PTE_X(page_table_entry)); break;
	case MEM_TYPE_READ:   assert(PTE_R(page_table_entry)); break;
	case MEM_TYPE_WRITE:  assert(PTE_W(page_table_entry)); break;
	default: panic("Error type memory access!"); break;
	}

	// Calculate physical address
	paddr_t ppn = PTE_PPN(page_table_entry) << 12;
	paddr_t paddr = ppn | offset;

	// For now, we use identical map
	assert(paddr == vaddr);
	
	return paddr;
}
