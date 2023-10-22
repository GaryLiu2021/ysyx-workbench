// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim.h for the primary calling header

#ifndef VERILATED_VSIM___024ROOT_H_
#define VERILATED_VSIM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vsim___024unit;


class Vsim__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsim___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rstn,0,0);
    CData/*5:0*/ sim__DOT__u_single_cycle_cpu__DOT__op_type;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_I_type;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_decode__DOT__inst_is_U_type;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT____VdfgTmp_h1d7be2bd__0;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_wr_en;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csr_rd_en;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_in;
    CData/*0:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_carry_out;
    CData/*7:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_byte;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rstn__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data_half_word;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__pc_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__imme;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__reg_data_rs2;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__alu_data_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__alu_pc_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__mem_data_in;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__csr_rd_data;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_reg_pc__DOT__pc_new;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__i;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__i;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in1;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_data_in2_sig;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__adder_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__logic_data_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_stage_execute__DOT__shift_data_out;
    IData/*31:0*/ sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__rd_data;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__regs;
    VlUnpacked<IData/*31:0*/, 32> sim__DOT__u_single_cycle_cpu__DOT__u_regs__DOT__reg_name;
    VlUnpacked<IData/*31:0*/, 4096> sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__csrs;
    VlUnpacked<IData/*31:0*/, 32> sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name;
    VlUnpacked<IData/*31:0*/, 8192> sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h3d404911__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsim__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim___024root(Vsim__Syms* symsp, const char* v__name);
    ~Vsim___024root();
    VL_UNCOPYABLE(Vsim___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
