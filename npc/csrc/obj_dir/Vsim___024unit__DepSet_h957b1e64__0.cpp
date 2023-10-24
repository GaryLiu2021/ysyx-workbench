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

extern "C" void call_return();

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_call_return_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_call_return_TOP____024unit\n"); );
    // Body
    call_return();
}

extern "C" void set_ptr_mem(const svOpenArrayHandle mem);

VL_INLINE_OPT void Vsim___024unit____Vdpiimwrap_set_ptr_mem__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 2> &mem) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim___024unit____Vdpiimwrap_set_ptr_mem__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const int mem__Vopenprops__ulims[2] = {-1, 0};
    static const VerilatedVarProps mem__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0, VerilatedVarProps::Unpacked(), 1, mem__Vopenprops__ulims);
    VerilatedDpiOpenVar mem__Vopenarray (&mem__Vopenprops, &mem);
    set_ptr_mem(&mem__Vopenarray);
}
