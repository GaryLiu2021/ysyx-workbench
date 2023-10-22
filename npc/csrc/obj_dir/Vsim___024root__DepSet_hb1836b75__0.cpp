// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim___024root.h"

VL_ATTR_COLD void Vsim___024root___eval_initial__TOP(Vsim___024root* vlSelf);
VlCoroutine Vsim___024root___eval_initial__TOP__0(Vsim___024root* vlSelf);
VlCoroutine Vsim___024root___eval_initial__TOP__1(Vsim___024root* vlSelf);

void Vsim___024root___eval_initial(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_initial\n"); );
    // Body
    Vsim___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vsim___024root___eval_initial__TOP__0(vlSelf);
    Vsim___024root___eval_initial__TOP__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__sim__DOT__clk__0 
        = vlSelf->sim__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__sim__DOT__rstn__0 
        = vlSelf->sim__DOT__rstn;
}

VL_INLINE_OPT VlCoroutine Vsim___024root___eval_initial__TOP__0(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_initial__TOP__0\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "../vsrc/../vsrc/sim.v", 
                                       14);
    vlSelf->sim__DOT__rstn = 1U;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "../vsrc/../vsrc/sim.v", 
                                       15);
    VL_WRITEF("Time Out!!!\n");
    VL_FINISH_MT("../vsrc/../vsrc/sim.v", 17, "");
}

VL_INLINE_OPT VlCoroutine Vsim___024root___eval_initial__TOP__1(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_initial__TOP__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h34b1970b__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge sim.clk)", 
                                                           "../vsrc/../vsrc/regs_i.v", 
                                                           62);
        if (VL_UNLIKELY(((0x27U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                         & (0x5dU == vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs
                            [0x11U])))) {
            if ((0U == vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs
                 [0xaU])) {
                VL_WRITEF("Pass!!!\n");
            } else {
                VL_WRITEF("Fail!!!\n");
            }
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "../vsrc/../vsrc/regs_i.v", 
                                               68);
            VL_FINISH_MT("../vsrc/../vsrc/regs_i.v", 68, "");
        }
    }
}

void Vsim___024root___eval_act(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsim___024root___nba_sequent__TOP__1(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0;
    __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0;
    __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v1;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v1 = 0;
    SData/*11:0*/ __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0;
    __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0;
    __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 = 0;
    // Body
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 = 0U;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 = 0U;
    __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v1 = 0U;
    if ((1U & (~ (IData)(vlSelf->sim__DOT__rstn)))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__i = 0x20U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i = 0U;
        while (VL_GTS_III(32, 0x1000U, vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i)) {
            vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs[(0xfffU 
                                                                              & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i)] = 0U;
            vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i 
                = ((IData)(1U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i);
        }
    }
    if (vlSelf->sim__DOT__rstn) {
        if (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en) {
            __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 
                = ((0x29U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
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
                                       | (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme))
                                    : ((0x2eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                        ? ((~ (0x1fU 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)) 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                        : 0U))))));
            __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 = 1U;
            __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0 
                = (0xfffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                             >> 5U));
        }
        if (((0x63U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
             & ((0x23U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                & ((0xfU != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                   & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0))))) {
            __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 
                = ((0U == (0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                    >> 7U))) ? 0U : 
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
                                     ? ((0U == (3U 
                                                & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
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
                                         : ((1U == 
                                             (3U & 
                                              (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                               >> 0xcU)))
                                             ? ((0x4000U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)
                                                 : 
                                                (((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word) 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)))
                                             : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                     : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out))))));
            __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 = 1U;
            __Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0 
                = (0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 7U));
        }
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out 
            = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new;
    } else {
        __Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v1 = 1U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out = 0U;
    }
    if (__Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs[__Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0] 
            = __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs__v0;
    }
    if (__Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[__Vdlyvdim0__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0] 
            = __Vdlyvval__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v0;
    }
    if (__Vdlyvset__sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs__v1) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[1U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[2U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[3U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[4U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[5U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[6U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[7U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[8U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[9U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xaU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xbU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xcU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xdU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xeU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0xfU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x10U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x11U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x12U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x13U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x14U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x15U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x16U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x17U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x18U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x19U] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1aU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1bU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1cU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1dU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1eU] = 0U;
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[0x1fU] = 0U;
    }
}

VL_INLINE_OPT void Vsim___024root___nba_comb__TOP__0(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
        = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram
        [(0x1fffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out 
                     >> 2U))];
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
        = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs
        [(0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                   >> 0xfU))];
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2 
        = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs
        [(0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                   >> 0x14U))];
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type 
        = ((0x67U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
           | ((3U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
              | ((0x13U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                 | (0xfU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)))));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type 
        = ((0x37U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
           | (0x17U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type 
        = ((0x40U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
            ? ((0x20U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                ? ((0x10U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                    ? ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                        ? 0x2fU : ((4U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                    ? 0x2fU : ((2U 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                ? (
                                                   (1U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 
                                                    ((0x100000U 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                      ? 0x28U
                                                      : 0x27U)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 0x29U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                           >> 0xcU)))
                                                       ? 0x2aU
                                                       : 
                                                      ((3U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                            >> 0xcU)))
                                                        ? 0x2bU
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                             >> 0xcU)))
                                                         ? 0x2cU
                                                         : 
                                                        ((6U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                              >> 0xcU)))
                                                          ? 0x2dU
                                                          : 
                                                         ((7U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                               >> 0xcU)))
                                                           ? 0x2eU
                                                           : 0x2fU)))))))
                                                    : 0x2fU)
                                                : 0x2fU)))
                    : ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                        ? ((4U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                            ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                    ? 2U : 0x2fU) : 0x2fU)
                            : 0x2fU) : ((4U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                         ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                             ? ((1U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 3U
                                                 : 0x2fU)
                                             : 0x2fU)
                                         : ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                             ? ((1U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                      >> 0xcU)))
                                                  ? 4U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                       >> 0xcU)))
                                                   ? 5U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 6U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 7U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 8U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                           >> 0xcU)))
                                                       ? 9U
                                                       : 0x2fU))))))
                                                 : 0x2fU)
                                             : 0x2fU))))
                : 0x2fU) : ((0x20U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                             ? ((0x10U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                 ? ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                     ? 0x2fU : ((4U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 
                                                ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 0U
                                                   : 0x2fU)
                                                  : 0x2fU)
                                                 : 
                                                ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 
                                                   ((0x40000000U 
                                                     & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                     ? 0x1cU
                                                     : 0x1bU)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 0x1dU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 0x1eU
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                           >> 0xcU)))
                                                       ? 0x1fU
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                            >> 0xcU)))
                                                        ? 0x20U
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                             >> 0xcU)))
                                                         ? 0x23U
                                                         : 
                                                        ((7U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                              >> 0xcU)))
                                                          ? 0x24U
                                                          : 
                                                         ((0x40000000U 
                                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                           ? 0x22U
                                                           : 0x21U))))))))
                                                   : 0x2fU)
                                                  : 0x2fU)))
                                 : ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                     ? 0x2fU : ((4U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 0x2fU
                                                 : 
                                                ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 0x11U
                                                      : 0x2fU)))
                                                   : 0x2fU)
                                                  : 0x2fU))))
                             : ((0x10U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                 ? ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                     ? 0x2fU : ((4U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 
                                                ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 1U
                                                   : 0x2fU)
                                                  : 0x2fU)
                                                 : 
                                                ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 0x12U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 0x13U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 0x14U
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                           >> 0xcU)))
                                                       ? 0x15U
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                            >> 0xcU)))
                                                        ? 0x16U
                                                        : 
                                                       ((7U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                             >> 0xcU)))
                                                         ? 0x17U
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                              >> 0xcU)))
                                                          ? 0x18U
                                                          : 
                                                         ((0x40000000U 
                                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                           ? 0x1aU
                                                           : 0x19U))))))))
                                                   : 0x2fU)
                                                  : 0x2fU)))
                                 : ((8U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                     ? ((4U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                         ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                             ? ((1U 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                 ? 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                      >> 0xcU)))
                                                  ? 0x25U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                       >> 0xcU)))
                                                   ? 0x26U
                                                   : 0x2fU))
                                                 : 0x2fU)
                                             : 0x2fU)
                                         : 0x2fU) : 
                                    ((4U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                      ? 0x2fU : ((2U 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 0xaU
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                         >> 0xcU)))
                                                     ? 0xbU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                          >> 0xcU)))
                                                      ? 0xcU
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                           >> 0xcU)))
                                                       ? 0xdU
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                            >> 0xcU)))
                                                        ? 0xeU
                                                        : 0x2fU)))))
                                                   : 0x2fU)
                                                  : 0x2fU))))));
    if (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (((- (IData)((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 0x1fU))) << 0xcU) | 
               (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                >> 0x14U));
    } else if (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (0xfffff000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out);
    } else if ((0x6fU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (((- (IData)((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 0x1fU))) << 0x14U) | 
               ((0xff000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out) 
                | ((0x800U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                              >> 9U)) | (0x7feU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                   >> 0x14U)))));
    } else if ((0x63U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (((- (IData)((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 0x1fU))) << 0xcU) | 
               ((0x800U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                           << 4U)) | ((0x7e0U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                  >> 7U)))));
    } else if ((0x23U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (((- (IData)((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 0x1fU))) << 0xcU) | 
               ((0xfe0U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                           >> 0x14U)) | (0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                  >> 7U))));
    } else if ((0x73U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
            = (((- (IData)((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                            >> 0x1fU))) << 0x11U) | 
               (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                >> 0xfU));
    } else if ((1U & (~ ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type) 
                         | ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type) 
                            | ((0x6fU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                               | ((0x63U == (0x7fU 
                                             & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                  | ((0x23U == (0x7fU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                     | ((0x33U == (0x7fU 
                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                        | (0x73U == 
                                           (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))))))))))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme = 0U;
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
        = ((0xfU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
            ? (0xffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2)
            : ((0x10U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                ? (0xffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2)
                : ((0x11U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2
                    : 0U)));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0 
        = ((0x27U != (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
           & (0x28U != (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in 
        = ((0x1cU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
           | ((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
              | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                 | ((0x63U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                    | ((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                       | (0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
        = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs
        [(0xfffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                    >> 5U))];
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out 
        = ((3U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
            ? (0xfffffffeU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                              + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1))
            : (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
               + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out));
    if ((0x15U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               ^ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme);
    } else if ((0x20U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               ^ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2);
    } else if ((0x16U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               | vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme);
    } else if ((0x23U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               | vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2);
    } else if ((0x17U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme);
    } else if ((0x24U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2);
    }
    if ((0x1dU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               << (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2));
    } else if ((0x18U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               << (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme));
    } else if ((0x21U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               >> (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2));
    } else if ((0x19U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
               >> (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme));
    } else if ((0x22U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (IData)(((((QData)((IData)((- (IData)(
                                                    (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                                     >> 0x1fU))))) 
                         << 0x20U) | (QData)((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1))) 
                       >> (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2)));
    } else if ((0x1aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out 
            = (IData)(((((QData)((IData)((- (IData)(
                                                    (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                                     >> 0x1fU))))) 
                         << 0x20U) | (QData)((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1))) 
                       >> (0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)));
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
        = (((0x17U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
            | ((0x6fU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
               | ((0x67U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                  | ((3U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                     | ((0x23U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                        | ((0x12U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                           | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                              | (0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))))
            ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme
            : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en 
        = ((0x73U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
           & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig 
        = ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in)
            ? (~ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2)
            : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out 
        = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1)) 
                                  + ((QData)((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig)) 
                                     + (QData)((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in)))) 
                                 >> 0x20U))));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out 
        = (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
           + (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig 
              + (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in)));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out 
        = (((0x12U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
            | ((0x1bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
               | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                  | ((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                     | ((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                        | ((0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                           | ((1U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                              | ((2U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                 | ((3U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                    | ((0x63U == (0x7fU 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                       | ((0x23U == 
                                           (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                          | ((3U == 
                                              (0x7fU 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                             | (0x1cU 
                                                == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))))))))))))))
            ? (((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                   | ((6U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                      | (7U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))
                ? (1U & (((~ (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                              >> 0x1fU)) & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                            >> 0x1fU)) 
                         | ((~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)) 
                            & ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                >> 0x1fU) == (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                              >> 0x1fU)))))
                : (((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                    | ((0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                       | ((8U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                          | (9U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))
                    ? (1U & (~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)))
                    : (((4U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                        | (5U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                        ? (0U != vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)
                        : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)))
            : (((0x15U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                | ((0x20U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                   | ((0x23U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                      | ((0x16U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                         | ((0x17U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                            | (0x24U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))
                ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out
                : (((0x1dU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                    | ((0x18U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                       | ((0x21U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                          | ((0x19U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                             | ((0x22U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | (0x1aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))
                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out
                    : 0U)));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new 
        = ((0x20U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
            ? ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
            : ((0x10U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                ? ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                : ((8U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                    ? ((4U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                        ? ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                        : ((2U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                            ? ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                            : ((1U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                                    : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out)
                                : ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                                    : ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)))))
                    : ((4U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                        ? ((2U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                            ? ((1U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                                    : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out)
                                : ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                                    : ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)))
                            : ((1U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                                    : ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out))
                                : ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                    ? ((IData)(4U) 
                                       + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                                    : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out)))
                        : ((2U & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                            ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                            : ((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out))))));
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data 
        = vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram
        [(0x1fffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out 
                     >> 2U))];
    if ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte 
            = (0xffU & ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                         ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data 
                            >> 0x18U) : (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data 
                                         >> 0x10U)));
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word 
            = (0xffffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data 
                          >> 0x10U));
    } else {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte 
            = (0xffU & ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                         ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data 
                            >> 8U) : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data));
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word 
            = (0xffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data);
    }
}

void Vsim___024root___nba_sequent__TOP__0(Vsim___024root* vlSelf);

void Vsim___024root___eval_nba(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vsim___024root___eval_triggers__act(Vsim___024root* vlSelf);
void Vsim___024root___timing_commit(Vsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__act(Vsim___024root* vlSelf);
#endif  // VL_DEBUG
void Vsim___024root___timing_resume(Vsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__nba(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim___024root___eval(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vsim___024root___eval_triggers__act(vlSelf);
            Vsim___024root___timing_commit(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vsim___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("../vsrc/../vsrc/sim.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vsim___024root___timing_resume(vlSelf);
                Vsim___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vsim___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("../vsrc/../vsrc/sim.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vsim___024root___eval_nba(vlSelf);
        }
    }
}

void Vsim___024root___timing_commit(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h34b1970b__0.commit("@(posedge sim.clk)");
    }
}

void Vsim___024root___timing_resume(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h34b1970b__0.resume("@(posedge sim.clk)");
    }
}

#ifdef VL_DEBUG
void Vsim___024root___eval_debug_assertions(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
