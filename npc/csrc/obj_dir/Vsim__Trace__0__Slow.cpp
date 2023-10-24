// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsim__Syms.h"


VL_ATTR_COLD void Vsim___024root__trace_init_sub__TOP__0(Vsim___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->pushNamePrefix("sim ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->pushNamePrefix("u_single_cycle_cpu ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBus(c+33,"pc_out", false,-1, 31,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+71,"func3", false,-1, 2,0);
    tracep->declBit(c+72,"func7", false,-1);
    tracep->declBus(c+73,"reg_addr_rs1", false,-1, 4,0);
    tracep->declBus(c+74,"reg_addr_rs2", false,-1, 4,0);
    tracep->declBus(c+75,"reg_addr_rd", false,-1, 4,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBus(c+77,"reg_data_rs1", false,-1, 31,0);
    tracep->declBus(c+78,"reg_data_rs2", false,-1, 31,0);
    tracep->declBus(c+79,"alu_data_out", false,-1, 31,0);
    tracep->declBus(c+80,"alu_pc_out", false,-1, 31,0);
    tracep->declBus(c+34,"alu_pc_seq", false,-1, 31,0);
    tracep->declBus(c+81,"mem_data_in", false,-1, 31,0);
    tracep->declBus(c+79,"mem_data_addr", false,-1, 31,0);
    tracep->declBit(c+82,"mem_data_wr_en", false,-1);
    tracep->declBus(c+83,"mem_data_out", false,-1, 31,0);
    tracep->declBus(c+84,"mem_inst_out", false,-1, 31,0);
    tracep->declBus(c+85,"csr_rd_data", false,-1, 31,0);
    tracep->pushNamePrefix("u_dpi_verilator ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBus(c+84,"mem_inst_out", false,-1, 31,0);
    tracep->declBus(c+79,"mem_data_addr", false,-1, 31,0);
    tracep->declBus(c+81,"mem_data_in", false,-1, 31,0);
    tracep->declBus(c+83,"mem_data_out", false,-1, 31,0);
    tracep->declBus(c+33,"pc_out", false,-1, 31,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBus(c+86,"reg_addr_rd", false,-1, 31,0);
    tracep->declBus(c+87,"reg_addr_rs1", false,-1, 31,0);
    tracep->declBus(c+77,"reg_data_rs1", false,-1, 31,0);
    tracep->declBus(c+88,"reg_addr_rs2", false,-1, 31,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"reg_name", true,(i+0), 31,0);
    }
    tracep->declQuad(c+129,"counter", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_gpr ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBus(c+73,"reg_addr_rs1", false,-1, 4,0);
    tracep->declBus(c+74,"reg_addr_rs2", false,-1, 4,0);
    tracep->declBus(c+77,"reg_data_rs1", false,-1, 31,0);
    tracep->declBus(c+78,"reg_data_rs2", false,-1, 31,0);
    tracep->declBus(c+75,"reg_addr_rd", false,-1, 4,0);
    tracep->declBus(c+79,"alu_data_out", false,-1, 31,0);
    tracep->declBus(c+80,"alu_pc_out", false,-1, 31,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBus(c+34,"alu_pc_seq", false,-1, 31,0);
    tracep->declBus(c+83,"mem_data_out", false,-1, 31,0);
    tracep->declBus(c+85,"csr_data_out", false,-1, 31,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+35+i*1,"gpr", true,(i+0), 31,0);
    }
    tracep->declBit(c+89,"reg_wr_en", false,-1);
    tracep->declBus(c+131,"reg_data_rd", false,-1, 31,0);
    tracep->declBus(c+67,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_mem_ddr ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBit(c+82,"mem_wr_en", false,-1);
    tracep->declBus(c+71,"mem_rw_type", false,-1, 2,0);
    tracep->declBus(c+79,"mem_data_addr", false,-1, 31,0);
    tracep->declBus(c+81,"mem_data_in", false,-1, 31,0);
    tracep->declBus(c+83,"mem_data_out", false,-1, 31,0);
    tracep->declBus(c+33,"mem_inst_addr", false,-1, 31,0);
    tracep->declBus(c+84,"mem_inst_out", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+132+i*1,"mem", true,(i+-1), 31,0);
    }
    tracep->declBus(c+90,"rd_data", false,-1, 31,0);
    tracep->declBus(c+91,"wr_data_byte", false,-1, 31,0);
    tracep->declBus(c+92,"wr_data_half_word", false,-1, 31,0);
    tracep->declBus(c+93,"wr_data", false,-1, 31,0);
    tracep->declBus(c+94,"rd_data_byte", false,-1, 7,0);
    tracep->declBus(c+95,"rd_data_half_word", false,-1, 15,0);
    tracep->declBus(c+96,"rd_data_byte_ext", false,-1, 31,0);
    tracep->declBus(c+97,"rd_data_half_word_ext", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_reg_pc ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+79,"alu_data_out", false,-1, 31,0);
    tracep->declBus(c+80,"alu_pc_out", false,-1, 31,0);
    tracep->declBus(c+34,"alu_pc_seq", false,-1, 31,0);
    tracep->declBus(c+33,"pc_out", false,-1, 31,0);
    tracep->declBus(c+98,"pc_new", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_regs_csr ");
    tracep->declBit(c+127,"clk", false,-1);
    tracep->declBit(c+128,"rstn", false,-1);
    tracep->declBus(c+85,"csr_rd_data", false,-1, 31,0);
    tracep->declBus(c+77,"reg_data_rs1", false,-1, 31,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBit(c+99,"csr_wr_en", false,-1);
    tracep->declBit(c+134,"csr_rd_en", false,-1);
    tracep->declBus(c+100,"csr_wr_data", false,-1, 31,0);
    tracep->declBus(c+101,"zimm", false,-1, 31,0);
    tracep->declBus(c+102,"csr_addr", false,-1, 11,0);
    tracep->declBus(c+68,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_stage_decode ");
    tracep->declBus(c+84,"inst", false,-1, 31,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+71,"func3", false,-1, 2,0);
    tracep->declBit(c+72,"func7", false,-1);
    tracep->declBus(c+73,"reg_addr_rs1", false,-1, 4,0);
    tracep->declBus(c+74,"reg_addr_rs2", false,-1, 4,0);
    tracep->declBus(c+75,"reg_addr_rd", false,-1, 4,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBit(c+103,"inst_is_I_type", false,-1);
    tracep->declBit(c+104,"inst_is_U_type", false,-1);
    tracep->declBit(c+105,"inst_is_J_type", false,-1);
    tracep->declBit(c+106,"inst_is_B_type", false,-1);
    tracep->declBit(c+107,"inst_is_S_type", false,-1);
    tracep->declBit(c+108,"inst_is_R_type", false,-1);
    tracep->declBit(c+109,"inst_type_error", false,-1);
    tracep->declBit(c+110,"inst_is_csr_op", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_stage_execute ");
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+76,"imme", false,-1, 31,0);
    tracep->declBus(c+77,"reg_data_rs1", false,-1, 31,0);
    tracep->declBus(c+78,"reg_data_rs2", false,-1, 31,0);
    tracep->declBus(c+33,"reg_data_pc", false,-1, 31,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+79,"alu_data_out", false,-1, 31,0);
    tracep->declBus(c+80,"alu_pc_out", false,-1, 31,0);
    tracep->declBus(c+34,"alu_pc_seq", false,-1, 31,0);
    tracep->declBit(c+111,"adder_enable", false,-1);
    tracep->declBus(c+77,"adder_data_in1", false,-1, 31,0);
    tracep->declBus(c+112,"adder_data_in2", false,-1, 31,0);
    tracep->declBus(c+113,"adder_data_in2_sig", false,-1, 31,0);
    tracep->declBus(c+114,"adder_out", false,-1, 31,0);
    tracep->declBus(c+115,"adder_data_out", false,-1, 31,0);
    tracep->declBit(c+116,"adder_carry_in", false,-1);
    tracep->declBit(c+117,"adder_carry_out", false,-1);
    tracep->declBit(c+118,"lt_data_out", false,-1);
    tracep->declBit(c+119,"ltu_data_out", false,-1);
    tracep->declBit(c+120,"neq_data_out", false,-1);
    tracep->declBit(c+121,"logic_enable", false,-1);
    tracep->declBus(c+122,"logic_data_out", false,-1, 31,0);
    tracep->declBit(c+123,"shift_enable", false,-1);
    tracep->declBus(c+124,"shift_data_out", false,-1, 31,0);
    tracep->declBus(c+125,"shift_opnum", false,-1, 4,0);
    tracep->declBit(c+126,"signal_rs1", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_stage_loadstore ");
    tracep->declBus(c+79,"alu_data_out", false,-1, 31,0);
    tracep->declBus(c+70,"op_type", false,-1, 5,0);
    tracep->declBus(c+78,"reg_data_rs2", false,-1, 31,0);
    tracep->declBus(c+81,"mem_data_in", false,-1, 31,0);
    tracep->declBus(c+79,"mem_data_addr", false,-1, 31,0);
    tracep->declBit(c+82,"mem_data_wr_en", false,-1);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vsim___024root__trace_init_top(Vsim___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_init_top\n"); );
    // Body
    Vsim___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsim___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsim___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsim___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsim___024root__trace_register(Vsim___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vsim___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vsim___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vsim___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsim___024root__trace_full_sub_0(Vsim___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsim___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_full_top_0\n"); );
    // Init
    Vsim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsim___024root*>(voidSelf);
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsim___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsim___024root__trace_full_sub_0(Vsim___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[31]),32);
    bufp->fullIData(oldp+33,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out),32);
    bufp->fullIData(oldp+34,(((IData)(4U) + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)),32);
    bufp->fullIData(oldp+35,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[0]),32);
    bufp->fullIData(oldp+36,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[1]),32);
    bufp->fullIData(oldp+37,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[2]),32);
    bufp->fullIData(oldp+38,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[3]),32);
    bufp->fullIData(oldp+39,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[4]),32);
    bufp->fullIData(oldp+40,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[5]),32);
    bufp->fullIData(oldp+41,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[6]),32);
    bufp->fullIData(oldp+42,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[7]),32);
    bufp->fullIData(oldp+43,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[8]),32);
    bufp->fullIData(oldp+44,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[9]),32);
    bufp->fullIData(oldp+45,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[10]),32);
    bufp->fullIData(oldp+46,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[11]),32);
    bufp->fullIData(oldp+47,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[12]),32);
    bufp->fullIData(oldp+48,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[13]),32);
    bufp->fullIData(oldp+49,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[14]),32);
    bufp->fullIData(oldp+50,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[15]),32);
    bufp->fullIData(oldp+51,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[16]),32);
    bufp->fullIData(oldp+52,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[17]),32);
    bufp->fullIData(oldp+53,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[18]),32);
    bufp->fullIData(oldp+54,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[19]),32);
    bufp->fullIData(oldp+55,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[20]),32);
    bufp->fullIData(oldp+56,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[21]),32);
    bufp->fullIData(oldp+57,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[22]),32);
    bufp->fullIData(oldp+58,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[23]),32);
    bufp->fullIData(oldp+59,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[24]),32);
    bufp->fullIData(oldp+60,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[25]),32);
    bufp->fullIData(oldp+61,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[26]),32);
    bufp->fullIData(oldp+62,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[27]),32);
    bufp->fullIData(oldp+63,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[28]),32);
    bufp->fullIData(oldp+64,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[29]),32);
    bufp->fullIData(oldp+65,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[30]),32);
    bufp->fullIData(oldp+66,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr[31]),32);
    bufp->fullIData(oldp+67,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__i),32);
    bufp->fullIData(oldp+68,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i),32);
    bufp->fullCData(oldp+69,((0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)),7);
    bufp->fullCData(oldp+70,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type),6);
    bufp->fullCData(oldp+71,((7U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+72,((1U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+73,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+74,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+75,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 7U))),5);
    bufp->fullIData(oldp+76,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme),32);
    bufp->fullIData(oldp+77,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1),32);
    bufp->fullIData(oldp+78,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2),32);
    bufp->fullIData(oldp+79,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out),32);
    bufp->fullIData(oldp+80,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out),32);
    bufp->fullIData(oldp+81,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in),32);
    bufp->fullBit(oldp+82,(((0xfU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                            | ((0x10U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                               | (0x11U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))))));
    bufp->fullIData(oldp+83,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_out),32);
    bufp->fullIData(oldp+84,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out),32);
    bufp->fullIData(oldp+85,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data),32);
    bufp->fullIData(oldp+86,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 7U))),32);
    bufp->fullIData(oldp+87,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 0xfU))),32);
    bufp->fullIData(oldp+88,((0x1fU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
                                       >> 0x14U))),32);
    bufp->fullBit(oldp+89,(((0x63U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                            & ((0x23U != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                               & ((0xfU != (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)) 
                                  & (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT____VdfgTmp_h1d7be2bd__0))))));
    bufp->fullIData(oldp+90,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data),32);
    bufp->fullIData(oldp+91,(((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                               ? ((1U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                                   ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                       << 0x18U) | 
                                      (0xffffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
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
                                      | ((0xff00U & 
                                          (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                           << 8U)) 
                                         | (0xffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data)))
                                   : ((0xffffff00U 
                                       & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                      | (0xffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in))))),32);
    bufp->fullIData(oldp+92,(((2U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)
                               ? ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in 
                                   << 0x10U) | (0xffffU 
                                                & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data))
                               : ((0xffff0000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data) 
                                  | (0xffffU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_in)))),32);
    bufp->fullIData(oldp+93,(((0U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
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
                               : ((1U == (3U & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out 
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
    bufp->fullCData(oldp+94,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte),8);
    bufp->fullSData(oldp+95,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word),16);
    bufp->fullIData(oldp+96,(((0x4000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                               ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)
                               : (((- (IData)((1U & 
                                               ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte) 
                                                >> 7U)))) 
                                   << 8U) | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte)))),32);
    bufp->fullIData(oldp+97,(((0x4000U & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out)
                               ? (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)
                               : (((- (IData)((1U & 
                                               ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word) 
                                                >> 0xfU)))) 
                                   << 0x10U) | (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word)))),32);
    bufp->fullIData(oldp+98,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new),32);
    bufp->fullBit(oldp+99,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en));
    bufp->fullIData(oldp+100,(((0x29U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1
                                : ((0x2aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                    ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                                       | vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1)
                                    : ((0x2bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                        ? ((~ vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1) 
                                           & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                        : ((0x2cU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                            ? (0x1fU 
                                               & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)
                                            : ((0x2dU 
                                                == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                                ? (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data 
                                                   | (0x1fU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme))
                                                : (
                                                   (0x2eU 
                                                    == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                                    ? 
                                                   ((~ 
                                                     (0x1fU 
                                                      & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)) 
                                                    & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data)
                                                    : 0U))))))),32);
    bufp->fullIData(oldp+101,((0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)),32);
    bufp->fullSData(oldp+102,((0xfffU & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme 
                                         >> 5U))),12);
    bufp->fullBit(oldp+103,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type));
    bufp->fullBit(oldp+104,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type));
    bufp->fullBit(oldp+105,((0x6fU == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
    bufp->fullBit(oldp+106,((0x63U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
    bufp->fullBit(oldp+107,((0x23U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
    bufp->fullBit(oldp+108,((0x33U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
    bufp->fullBit(oldp+109,((1U & (~ ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type) 
                                      | ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type) 
                                         | ((0x6fU 
                                             == (0x7fU 
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
    bufp->fullBit(oldp+110,((0x73U == (0x7fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))));
    bufp->fullBit(oldp+111,(((0x12U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                             | ((0x1bU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x13U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
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
    bufp->fullIData(oldp+112,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2),32);
    bufp->fullIData(oldp+113,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig),32);
    bufp->fullIData(oldp+114,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out),32);
    bufp->fullIData(oldp+115,((((0x1eU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
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
                                               == (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                                   >> 0x1fU)))))
                                : (((0x1fU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                    | ((0x14U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                       | ((8U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                          | (9U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))
                                    ? (1U & (~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)))
                                    : (((4U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                        | (5U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                                        ? (0U != vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)
                                        : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)))),32);
    bufp->fullBit(oldp+116,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in));
    bufp->fullBit(oldp+117,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out));
    bufp->fullBit(oldp+118,((1U & (((~ (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                        >> 0x1fU)) 
                                    & (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                       >> 0x1fU)) | 
                                   ((~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)) 
                                    & ((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                                        >> 0x1fU) == 
                                       (vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2 
                                        >> 0x1fU)))))));
    bufp->fullBit(oldp+119,((1U & (~ (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out)))));
    bufp->fullBit(oldp+120,((0U != vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out)));
    bufp->fullBit(oldp+121,(((0x15U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                             | ((0x20U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x23U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x16U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x17U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | (0x24U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))));
    bufp->fullIData(oldp+122,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out),32);
    bufp->fullBit(oldp+123,(((0x1dU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                             | ((0x18U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                | ((0x21U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                   | ((0x19U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                      | ((0x22U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                         | (0x1aU == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))))))));
    bufp->fullIData(oldp+124,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out),32);
    bufp->fullCData(oldp+125,((0x1fU & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme)),5);
    bufp->fullBit(oldp+126,((vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1 
                             >> 0x1fU)));
    bufp->fullBit(oldp+127,(vlSelf->clk));
    bufp->fullBit(oldp+128,(vlSelf->rstn));
    bufp->fullQData(oldp+129,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__counter),64);
    bufp->fullIData(oldp+131,(((0U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__imme
                                : ((1U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type))
                                    ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out
                                    : (((2U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)) 
                                        | (3U == (IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__op_type)))
                                        ? ((IData)(4U) 
                                           + vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out)
                                        : ((IData)(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en)
                                            ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data
                                            : ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out))
                                                ? vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_data_out
                                                : vlSelf->sim__DOT__u_single_cycle_cpu__DOT__alu_data_out)))))),32);
    bufp->fullIData(oldp+132,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__mem[0]),32);
    bufp->fullIData(oldp+133,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__mem[1]),32);
    bufp->fullBit(oldp+134,(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_rd_en));
}
