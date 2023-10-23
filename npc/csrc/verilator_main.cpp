#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsim.h"
#include "verilated_dpi.h"
#include <svdpi.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <dlfcn.h>

uint64_t cycles = 0;
uint32_t* ptr_gpr[32] = { NULL };
uint32_t* ptr_pc = NULL;

bool c_break = false;

extern "C" {

    void set_ptr_gpr(const svOpenArrayHandle r) {
        printf("array dimension is %d\n", svDimensions(r));
        assert(0);
        // ptr_gpr = (uint32_t*)(((VerilatedDpiOpenVar*)r)->datap());
    }

    // void set_ptr_gpr(const svOpenArrayHandle r, int i) {
    //     printf("Fuck!\n");
    //     ptr_gpr[i] = (uint32_t*)(((VerilatedDpiOpenVar*)r)->datap());
    // }

    void set_ptr_pc(const svOpenArrayHandle r) {
        printf("Fuck!!!\n");
        ptr_pc = (uint32_t*)(((VerilatedDpiOpenVar*)r)->datap());
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
        printf("gpr[%d] = 0x%8x\n", i, *ptr_gpr[i]);
    }
}

void dump_inst() {
    // char s[40];
    // itoa(*ptr_pc, s, 2);
    printf("inst = %x\n", *ptr_pc);
}

int main(int argc, char** argv, char** env) {

    void* library_handle = dlopen("/home/sgap/ysyx-workbench/nemu/tools/spike-diff/build/riscv32-spike-so", RTLD_NOW);
    if (!library_handle) {
        // 处理库加载失败的情况
        fprintf(stderr, "Failed to open library: %s\n", dlerror());
        return 1;
    }

    void (*difftest_init)(int) = (void (*)(int))dlsym(library_handle, "difftest_init");
    if (!difftest_init) {
        // 处理获取函数指针失败的情况
        fprintf(stderr, "Failed to find function: %s\n", dlerror());
        dlclose(library_handle); // 关闭共享库句柄
        return 1;
    }

    Verilated::traceEverOn(true);
    // VerilatedVcdC* m_tracep = new VerilatedVcdC;         // 波形
    Vsim* m_dut = new Vsim;
    int optype;

    // m_dut->trace(m_tracep, 5);
    // m_tracep->open("wave.vcd");

    difftest_init(1234);
    m_dut->clk = 0;

    while (c_break == false) {

        m_dut->clk = !m_dut->clk; // 0 -> 1
        m_dut->eval();
        dump_inst();
        dump_gpr();
        m_dut->clk = !m_dut->clk;
        m_dut->eval();
        // printf("\t\tCurrent Cycle: %d\n", cycles);
        cycles++;

        // printf("Optype: %d", optype);

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
    dlclose(library_handle);
    // delete m_tracep;
    return 0;
}
