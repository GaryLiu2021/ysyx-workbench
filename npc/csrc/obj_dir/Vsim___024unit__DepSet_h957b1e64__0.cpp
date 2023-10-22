// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024unit.h"

extern "C" void set_gpr_ptr(const svOpenArrayHandle a);

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 32> &a) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const int a__Vopenprops__ulims[2] = {31, 0};
    static const VerilatedVarProps a__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0, VerilatedVarProps::Unpacked(), 1, a__Vopenprops__ulims);
    VerilatedDpiOpenVar a__Vopenarray (&a__Vopenprops, &a);
    set_gpr_ptr(&a__Vopenarray);
}

extern "C" void set_inst_ptr(const svOpenArrayHandle inst);

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_set_inst_ptr__Vdpioc2_TOP____024unit(const IData/*31:0*/ &inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_set_inst_ptr__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const VerilatedVarProps inst__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0);
    VerilatedDpiOpenVar inst__Vopenarray (&inst__Vopenprops, &inst);
    set_inst_ptr(&inst__Vopenarray);
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
