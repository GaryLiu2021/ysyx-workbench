// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsim__Syms.h"


void Vsim___024root__trace_chg_sub_0(Vsim___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsim___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_chg_top_0\n"); );
    // Init
    Vsim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsim___024root*>(voidSelf);
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsim___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vsim___024root__trace_chg_sub_0(Vsim___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[31]),32);
        bufp->chgIData(oldp+32,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0]),32);
        bufp->chgIData(oldp+33,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[1]),32);
        bufp->chgIData(oldp+34,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[2]),32);
        bufp->chgIData(oldp+35,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[3]),32);
        bufp->chgIData(oldp+36,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[4]),32);
        bufp->chgIData(oldp+37,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[5]),32);
        bufp->chgIData(oldp+38,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[6]),32);
        bufp->chgIData(oldp+39,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[7]),32);
        bufp->chgIData(oldp+40,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[8]),32);
        bufp->chgIData(oldp+41,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[9]),32);
        bufp->chgIData(oldp+42,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[10]),32);
        bufp->chgIData(oldp+43,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[11]),32);
        bufp->chgIData(oldp+44,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[12]),32);
        bufp->chgIData(oldp+45,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[13]),32);
        bufp->chgIData(oldp+46,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[14]),32);
        bufp->chgIData(oldp+47,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[15]),32);
        bufp->chgIData(oldp+48,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[16]),32);
        bufp->chgIData(oldp+49,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[17]),32);
        bufp->chgIData(oldp+50,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[18]),32);
        bufp->chgIData(oldp+51,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[19]),32);
        bufp->chgIData(oldp+52,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[20]),32);
        bufp->chgIData(oldp+53,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[21]),32);
        bufp->chgIData(oldp+54,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[22]),32);
        bufp->chgIData(oldp+55,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[23]),32);
        bufp->chgIData(oldp+56,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[24]),32);
        bufp->chgIData(oldp+57,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[25]),32);
        bufp->chgIData(oldp+58,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[26]),32);
        bufp->chgIData(oldp+59,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[27]),32);
        bufp->chgIData(oldp+60,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[28]),32);
        bufp->chgIData(oldp+61,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[29]),32);
        bufp->chgIData(oldp+62,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[30]),32);
        bufp->chgIData(oldp+63,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+64,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out),32);
        bufp->chgIData(oldp+65,(((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)),32);
        bufp->chgIData(oldp+66,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[0]),32);
        bufp->chgIData(oldp+67,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[1]),32);
        bufp->chgIData(oldp+68,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[2]),32);
        bufp->chgIData(oldp+69,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[3]),32);
        bufp->chgIData(oldp+70,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[4]),32);
        bufp->chgIData(oldp+71,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[5]),32);
        bufp->chgIData(oldp+72,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[6]),32);
        bufp->chgIData(oldp+73,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[7]),32);
        bufp->chgIData(oldp+74,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[8]),32);
        bufp->chgIData(oldp+75,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[9]),32);
        bufp->chgIData(oldp+76,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[10]),32);
        bufp->chgIData(oldp+77,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[11]),32);
        bufp->chgIData(oldp+78,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[12]),32);
        bufp->chgIData(oldp+79,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[13]),32);
        bufp->chgIData(oldp+80,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[14]),32);
        bufp->chgIData(oldp+81,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[15]),32);
        bufp->chgIData(oldp+82,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[16]),32);
        bufp->chgIData(oldp+83,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[17]),32);
        bufp->chgIData(oldp+84,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[18]),32);
        bufp->chgIData(oldp+85,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[19]),32);
        bufp->chgIData(oldp+86,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[20]),32);
        bufp->chgIData(oldp+87,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[21]),32);
        bufp->chgIData(oldp+88,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[22]),32);
        bufp->chgIData(oldp+89,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[23]),32);
        bufp->chgIData(oldp+90,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[24]),32);
        bufp->chgIData(oldp+91,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[25]),32);
        bufp->chgIData(oldp+92,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[26]),32);
        bufp->chgIData(oldp+93,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[27]),32);
        bufp->chgIData(oldp+94,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[28]),32);
        bufp->chgIData(oldp+95,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[29]),32);
        bufp->chgIData(oldp+96,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[30]),32);
        bufp->chgIData(oldp+97,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[31]),32);
        bufp->chgIData(oldp+98,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__i),32);
        bufp->chgIData(oldp+99,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+100,((0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)),7);
        bufp->chgCData(oldp+101,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type),6);
        bufp->chgCData(oldp+102,((7U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                        >> 0xcU))),3);
        bufp->chgBit(oldp+103,((1U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                      >> 0x1eU))));
        bufp->chgCData(oldp+104,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+105,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+106,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                           >> 7U))),5);
        bufp->chgIData(oldp+107,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme),32);
        bufp->chgIData(oldp+108,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1),32);
        bufp->chgIData(oldp+109,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2),32);
        bufp->chgIData(oldp+110,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out),32);
        bufp->chgIData(oldp+111,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out),32);
        bufp->chgIData(oldp+112,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in),32);
        bufp->chgBit(oldp+113,(((0xfU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x10U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | (0x11U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))))));
        bufp->chgIData(oldp+114,(((0U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                >> 0xcU)))
                                   ? ((0x4000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                       ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)
                                       : (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte) 
                                                          >> 7U)))) 
                                           << 8U) | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)))
                                   : ((1U == (3U & 
                                              (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                               >> 0xcU)))
                                       ? ((0x4000U 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                           ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)
                                           : (((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word) 
                                                              >> 0xfU)))) 
                                               << 0x10U) 
                                              | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)))
                                       : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))),32);
        bufp->chgIData(oldp+115,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out),32);
        bufp->chgIData(oldp+116,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data),32);
        bufp->chgBit(oldp+117,(((0x63U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                & ((0x23U != (0x7fU 
                                              & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                   & ((0xfU != (0x7fU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                      & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT____VdfgTmp_h1d7be2bd__0))))));
        bufp->chgIData(oldp+118,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data),32);
        bufp->chgIData(oldp+119,(((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                   ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                       ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                           << 0x18U) 
                                          | (0xffffffU 
                                             & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                       : ((0xff000000U 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                          | ((0xff0000U 
                                              & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                 << 0x10U)) 
                                             | (0xffffU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))))
                                   : ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                       ? ((0xffff0000U 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                          | ((0xff00U 
                                              & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                 << 8U)) 
                                             | (0xffU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data)))
                                       : ((0xffffff00U 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                          | (0xffU 
                                             & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in))))),32);
        bufp->chgIData(oldp+120,(((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                   ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                       << 0x10U) | 
                                      (0xffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                   : ((0xffff0000U 
                                       & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                      | (0xffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in)))),32);
        bufp->chgIData(oldp+121,(((0U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                >> 0xcU)))
                                   ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                       ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                           ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                               << 0x18U) 
                                              | (0xffffffU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                           : ((0xff000000U 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                              | ((0xff0000U 
                                                  & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))))
                                       : ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                           ? ((0xffff0000U 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                              | ((0xff00U 
                                                  & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data)))
                                           : ((0xffffff00U 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                              | (0xffU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in))))
                                   : ((1U == (3U & 
                                              (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                               >> 0xcU)))
                                       ? ((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                           ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                               << 0x10U) 
                                              | (0xffffU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                                           : ((0xffff0000U 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                              | (0xffffU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in)))
                                       : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in))),32);
        bufp->chgCData(oldp+122,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte),8);
        bufp->chgSData(oldp+123,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word),16);
        bufp->chgIData(oldp+124,(((0x4000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                   ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)
                                   : (((- (IData)((1U 
                                                   & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte) 
                                                      >> 7U)))) 
                                       << 8U) | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)))),32);
        bufp->chgIData(oldp+125,(((0x4000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                   ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)
                                   : (((- (IData)((1U 
                                                   & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word) 
                                                      >> 0xfU)))) 
                                       << 0x10U) | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)))),32);
        bufp->chgIData(oldp+126,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new),32);
        bufp->chgBit(oldp+127,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en));
        bufp->chgIData(oldp+128,(((0x29U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                   ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1
                                   : ((0x2aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                       ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                                          | vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1)
                                       : ((0x2bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                           ? ((~ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1) 
                                              & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                           : ((0x2cU 
                                               == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                               ? (0x1fU 
                                                  & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)
                                               : ((0x2dU 
                                                   == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                                   ? 
                                                  (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                                                   | (0x1fU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme))
                                                   : 
                                                  ((0x2eU 
                                                    == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                                    ? 
                                                   ((~ 
                                                     (0x1fU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)) 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                                    : 0U))))))),32);
        bufp->chgIData(oldp+129,((0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)),32);
        bufp->chgSData(oldp+130,((0xfffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                                            >> 5U))),12);
        bufp->chgBit(oldp+131,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type));
        bufp->chgBit(oldp+132,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type));
        bufp->chgBit(oldp+133,((0x6fU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
        bufp->chgBit(oldp+134,((0x63U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
        bufp->chgBit(oldp+135,((0x23U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
        bufp->chgBit(oldp+136,((0x33U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
        bufp->chgBit(oldp+137,((1U & (~ ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type) 
                                         | ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type) 
                                            | ((0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                               | ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                  | ((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                     | ((0x33U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                        | (0x73U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))))))))))));
        bufp->chgBit(oldp+138,((0x73U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
        bufp->chgBit(oldp+139,(((0x12U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x1bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | ((0x1fU 
                                             == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                            | ((0x14U 
                                                == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                               | ((1U 
                                                   == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                                  | ((2U 
                                                      == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                                     | ((3U 
                                                         == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                                        | ((0x63U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                           | ((0x23U 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                              | ((3U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                                                 | (0x1cU 
                                                                    == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))))))))))))))));
        bufp->chgIData(oldp+140,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2),32);
        bufp->chgIData(oldp+141,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig),32);
        bufp->chgIData(oldp+142,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out),32);
        bufp->chgIData(oldp+143,((((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((6U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | (7U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))
                                   ? (1U & (((~ (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                                 >> 0x1fU)) 
                                             & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                                >> 0x1fU)) 
                                            | ((~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)) 
                                               & ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                                   >> 0x1fU) 
                                                  == 
                                                  (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                                   >> 0x1fU)))))
                                   : (((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                       | ((0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                          | ((8U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                             | (9U 
                                                == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))
                                       ? (1U & (~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)))
                                       : (((4U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                           | (5U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                                           ? (0U != vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)
                                           : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)))),32);
        bufp->chgBit(oldp+144,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in));
        bufp->chgBit(oldp+145,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out));
        bufp->chgBit(oldp+146,((1U & (((~ (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                           >> 0x1fU)) 
                                       & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                          >> 0x1fU)) 
                                      | ((~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)) 
                                         & ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                             >> 0x1fU) 
                                            == (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                                >> 0x1fU)))))));
        bufp->chgBit(oldp+147,((1U & (~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)))));
        bufp->chgBit(oldp+148,((0U != vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)));
        bufp->chgBit(oldp+149,(((0x15U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x20U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x23U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x16U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | ((0x17U 
                                             == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                            | (0x24U 
                                               == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))));
        bufp->chgIData(oldp+150,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out),32);
        bufp->chgBit(oldp+151,(((0x1dU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x18U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x21U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x19U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | ((0x22U 
                                             == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                            | (0x1aU 
                                               == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))));
        bufp->chgIData(oldp+152,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out),32);
        bufp->chgCData(oldp+153,((0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)),5);
        bufp->chgBit(oldp+154,((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                >> 0x1fU)));
    }
    bufp->chgBit(oldp+155,(vlSelf->clk));
    bufp->chgBit(oldp+156,(vlSelf->sim__DOT__rstn));
    bufp->chgIData(oldp+157,(((0U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                               ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme
                               : ((1U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                   ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                                   : (((2U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                       | (3U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                                       ? ((IData)(4U) 
                                          + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                                       : ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en)
                                           ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data
                                           : ((3U == 
                                               (0x7fU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))
                                               ? ((0U 
                                                   == 
                                                   (3U 
                                                    & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                       >> 0xcU)))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                                                    ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte) 
                                                                    >> 7U)))) 
                                                     << 8U) 
                                                    | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (3U 
                                                     & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                                        >> 0xcU)))
                                                    ? 
                                                   ((0x4000U 
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
                                               : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)))))),32);
}

void Vsim___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_cleanup\n"); );
    // Init
    Vsim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsim___024root*>(voidSelf);
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
