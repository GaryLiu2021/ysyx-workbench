// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__act(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim___024root___eval_triggers__act(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->sim__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sim__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->sim__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__sim__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->sim__DOT__rstn)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__sim__DOT__rstn__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__sim__DOT__clk__0 
        = vlSelf->sim__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__sim__DOT__rstn__0 
        = vlSelf->sim__DOT__rstn;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vsim___024unit____Vdpiimwrap_call_ebreak_TOP____024unit();
void Vsim___024unit____Vdpiimwrap_call_ecall_TOP____024unit();

VL_INLINE_OPT void Vsim___024root___nba_sequent__TOP__0(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*12:0*/ __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0;
    __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 = 0;
    IData/*31:0*/ __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0;
    __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 = 0;
    // Body
    if (VL_UNLIKELY(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en)) {
        VL_WRITEF("writing data %0# into CSR[%0#]\n",
                  32,((0x29U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                       ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1
                       : ((0x2aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                           ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                              | vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1)
                           : ((0x2bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                               ? ((~ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1) 
                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                               : ((0x2cU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                   ? (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)
                                   : ((0x2dU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                       ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                                          | (0x1fU 
                                             & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme))
                                       : ((0x2eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                           ? ((~ (0x1fU 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)) 
                                              & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                           : 0U)))))),
                  12,(0xfffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                                >> 5U)));
    }
    if ((0x100073U == vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) {
        Vsim___024unit____Vdpiimwrap_call_ebreak_TOP____024unit();
    }
    if ((0x73U == vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) {
        Vsim___024unit____Vdpiimwrap_call_ecall_TOP____024unit();
    }
    if (VL_UNLIKELY(((0x63U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                     & ((0x23U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                        & ((0xfU != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                           & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0)))))) {
        VL_WRITEF("writing data %0d into %0s\n",32,
                  ((0U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme
                    : ((1U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                        ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                        : (((2U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                            | (3U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                            ? ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                            : ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en)
                                ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data
                                : ((3U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))
                                    ? ((0U == (3U & 
                                               (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                >> 0xcU)))
                                        ? ((0x4000U 
                                            & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                            ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)
                                            : (((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte) 
                                                               >> 7U)))) 
                                                << 8U) 
                                               | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)))
                                        : ((1U == (3U 
                                                   & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                      >> 0xcU)))
                                            ? ((0x4000U 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)
                                                : (
                                                   ((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word) 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)))
                                            : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                    : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out))))),
                  32,vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__reg_name
                  [(0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                             >> 7U))]);
    }
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 = 0U;
    if (((0xfU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
         | ((0x10U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
            | (0x11U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))))) {
        __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 
            = ((0U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                             >> 0xcU))) ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                            ? ((1U 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                                ? (
                                                   (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                    << 0x18U) 
                                                   | (0xffffffU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                                : (
                                                   (0xff000000U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                                   | ((0xff0000U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                          << 0x10U)) 
                                                      | (0xffffU 
                                                         & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))))
                                            : ((1U 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                                ? (
                                                   (0xffff0000U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                                   | ((0xff00U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data)))
                                                : (
                                                   (0xffffff00U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                                   | (0xffU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in))))
                : ((1U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                 >> 0xcU))) ? ((2U 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                                ? (
                                                   (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                                : (
                                                   (0xffff0000U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                                   | (0xffffU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in)))
                    : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in));
        __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 = 1U;
        __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0 
            = (0x1fffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out 
                          >> 2U));
    }
    if (__Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram[__Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0] 
            = __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram__v0;
    }
}
