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

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
    // Move MIE to MPIE
	cpu.csr.mstatus = (cpu.csr.mstatus & ~MPIE_MASKBIT) | (((cpu.csr.mstatus & MIE_MASKBIT) >> MIE_OFFSET) << MPIE_OFFSET);

    // Clear MIE bit
    cpu.csr.mstatus &= ~MIE_MASKBIT;

    cpu.csr.mcause = NO;
    cpu.csr.mepc = epc;
	return cpu.csr.mtvec;
}

#define IRQ_TIMER 0x80000007  // for riscv32

word_t isa_query_intr() {
    if ((cpu.csr.mstatus & MIE_MASKBIT) && cpu.INTR) {
        cpu.INTR = false;
        return IRQ_TIMER;
    }
    return INTR_EMPTY;
}

void restore_intr() {
    // Move MPIE to MIE
    cpu.csr.mstatus = (cpu.csr.mstatus & ~MIE_MASKBIT) | (((cpu.csr.mstatus & MPIE_MASKBIT) >> MPIE_OFFSET) << MIE_OFFSET);

    // Set MPIE
    cpu.csr.mstatus |= MPIE_MASKBIT;
}
