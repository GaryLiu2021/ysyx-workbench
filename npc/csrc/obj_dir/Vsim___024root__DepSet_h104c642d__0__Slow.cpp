// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024root.h"

void Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit(const IData/*31:0*/ &inst);
void Vsim___024root____Vdpiimwrap_sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__set_ptr_gpr_TOP(VlUnpacked<IData/*31:0*/, 32> gpr);
extern const VlWide<12>/*383:0*/ Vsim__ConstPool__CONST_h7c27e68b_0;

VL_ATTR_COLD void Vsim___024root___eval_initial__TOP(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_initial__TOP\n"); );
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"wave.vcd"});
    vlSymsp->_traceDumpOpen();
    Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0U] = 0x7a65726fU;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[1U] = 0x7261U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[2U] = 0x7370U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[3U] = 0x6770U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[4U] = 0x7470U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[5U] = 0x7430U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[6U] = 0x7431U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[7U] = 0x7432U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[8U] = 0x7330U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[9U] = 0x7331U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xaU] = 0x6130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xbU] = 0x6131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xcU] = 0x6132U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xdU] = 0x6133U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xeU] = 0x6134U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0xfU] = 0x6135U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x10U] = 0x6136U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x11U] = 0x6137U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x12U] = 0x7332U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x13U] = 0x7333U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x14U] = 0x7334U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x15U] = 0x7335U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x16U] = 0x7336U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x17U] = 0x7337U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x18U] = 0x7338U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x19U] = 0x7339U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1aU] = 0x733130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1bU] = 0x733131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1cU] = 0x7433U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1dU] = 0x7434U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1eU] = 0x7435U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__reg_name[0x1fU] = 0x7436U;
    Vsim___024root____Vdpiimwrap_sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__set_ptr_gpr_TOP(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0U] = 0x7a65726fU;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[1U] = 0x7261U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[2U] = 0x7370U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[3U] = 0x6770U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[4U] = 0x7470U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[5U] = 0x7430U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[6U] = 0x7431U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[7U] = 0x7432U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[8U] = 0x7330U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[9U] = 0x7331U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xaU] = 0x6130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xbU] = 0x6131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xcU] = 0x6132U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xdU] = 0x6133U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xeU] = 0x6134U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0xfU] = 0x6135U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x10U] = 0x6136U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x11U] = 0x6137U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x12U] = 0x7332U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x13U] = 0x7333U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x14U] = 0x7334U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x15U] = 0x7335U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x16U] = 0x7336U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x17U] = 0x7337U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x18U] = 0x7338U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x19U] = 0x7339U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1aU] = 0x733130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1bU] = 0x733131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1cU] = 0x7433U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1dU] = 0x7434U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1eU] = 0x7435U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_regs_csr__DOT__reg_name[0x1fU] = 0x7436U;
    VL_READMEM_N(false, 32, 8192, 0, VL_CVT_PACK_STR_NW(12, Vsim__ConstPool__CONST_h7c27e68b_0)
                 ,  &(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__ram)
                 , 0, ~0ULL);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__stl(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim___024root___eval_triggers__stl(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
