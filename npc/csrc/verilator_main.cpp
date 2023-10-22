#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsim.h"
#include "verilated_dpi.h"
#include <stdio.h>
#include <string>
#include "difftest_ref.h"

uint64_t cycles = 0;
uint32_t* cpu_gpr = NULL;
uint32_t* inst_ptr = NULL;

bool c_break = false;

extern "C" {
    void set_gpr_ptr(const svOpenArrayHandle r) {
        cpu_gpr = (uint32_t*)(((VerilatedDpiOpenVar*)r)->datap());
    }

    void set_inst_ptr(const svOpenArrayHandle r) {
        inst_ptr = (uint32_t*)(((VerilatedDpiOpenVar*)r)->datap());
    }

    void call_ebreak() {
        c_break = true;
    }

    void call_ecall() {
        c_break = true;
    }
}

void dump_gpr() {
    int i;
    for (i = 0; i < 32; i++) {
        printf("gpr[%d] = 0x%x\n", i, cpu_gpr[i]);
    }
}

void dump_inst() {
    // char s[40];
    // itoa(*inst_ptr, s, 2);
    printf("inst = %x\n", inst_ptr);
}

int main(int argc, char** argv, char** env) {

    VerilatedVcdC* m_tracep = new VerilatedVcdC;         // 波形
    Vsim* m_dut = new Vsim;
    int optype;

    m_dut->trace(m_tracep, 5);
    m_tracep->open("wave.vcd");

    difftest_init(1234);

    while (c_break == false) {
        m_dut->clk = !m_dut->clk;
        cycles++;
        printf("\t\tCurrent Cycle: %d\n", cycles);
        dump_inst();
        // printf("Optype: %d", optype);
        dump_gpr();

        // m_tracep->dump(m_contextp->time());
        // int a = rand();
        // int b = rand();
        // m_dut->multiplicand = a;
        // m_dut->multiplier = b;
        // m_dut->eval();
        // long c = m_dut->result
        // if(m_dut->result == a*b)
        //     std::cout << a <<"*"<< b <<"="<<m_dut << std::endl;
        // else {
        //     std::cout << a <<"*"<< b <<"!="<<m_dut << std::endl;
        //     break;
        // }
        // m_tracep->dump(test_num);
        // test_num++;
    }
    // m_tracep->close();
    delete m_dut;
    // delete m_tracep;
    return 0;
}
