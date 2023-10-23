// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024unit.h"

extern "C" void set_ptr_pc(const svOpenArrayHandle inst);

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit(const IData/*31:0*/ &inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const VerilatedVarProps inst__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0);
    VerilatedDpiOpenVar inst__Vopenarray (&inst__Vopenprops, &inst);
    set_ptr_pc(&inst__Vopenarray);
}

extern "C" void call_ebreak();

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_call_ebreak_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_call_ebreak_TOP____024unit\n"); );
    // Body
    call_ebreak();
}

extern "C" void call_ecall();

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_call_ecall_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_call_ecall_TOP____024unit\n"); );
    // Body
    call_ecall();
}
