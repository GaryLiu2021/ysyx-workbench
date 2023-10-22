// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim___024root.h"

VL_ATTR_COLD void Vsim___024root___eval_static(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsim___024root___eval_final(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vsim___024root___eval_triggers__stl(Vsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__stl(Vsim___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vsim___024root___eval_stl(Vsim___024root* vlSelf);

VL_ATTR_COLD void Vsim___024root___eval_settle(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vsim___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vsim___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("../vsrc/../vsrc/sim.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vsim___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__stl(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vsim___024root___nba_comb__TOP__0(Vsim___024root* vlSelf);

VL_ATTR_COLD void Vsim___024root___eval_stl(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsim___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__act(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge rstn)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__nba(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge rstn)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim___024root___ctor_var_reset(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rstn = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type = VL_RAND_RESET_I(6);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2 = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__reg_name[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_rd_en = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out = VL_RAND_RESET_I(1);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data = VL_RAND_RESET_I(32);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte = VL_RAND_RESET_I(8);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rstn__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
