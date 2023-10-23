// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSIM__DPI_H_
#define VERILATED_VSIM__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at ../vsrc/../vsrc/top.v:3:30
    extern void call_ebreak();
    // DPI import at ../vsrc/../vsrc/top.v:4:30
    extern void call_ecall();
    // DPI import at ../vsrc/../vsrc/regs_i.v:28:34
    extern void set_ptr_gpr(const svLogicVecVal* gpr);
    // DPI import at ../vsrc/../vsrc/top.v:2:30
    extern void set_ptr_pc(const svOpenArrayHandle inst);

#ifdef __cplusplus
}
#endif

#endif  // guard
