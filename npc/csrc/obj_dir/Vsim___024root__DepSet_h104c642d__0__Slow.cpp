// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024root.h"

void Vsim___024root____Vdpiimwrap_sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__set_ptr_gpr__Vdpioc2_TOP(const VlUnpacked<IData/*31:0*/, 32> &gpr);
void Vsim___024unit____Vdpiimwrap_set_ptr_mem__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 8192> &mem);
void Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit(const IData/*31:0*/ &pc_out);
void Vsim___024unit____Vdpiimwrap_set_ptr_inst__Vdpioc2_TOP____024unit(const IData/*31:0*/ &mem_inst_out);

VL_ATTR_COLD void Vsim___024root___eval_initial__TOP(Vsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_initial__TOP\n"); );
    // Body
    Vsim___024root____Vdpiimwrap_sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__set_ptr_gpr__Vdpioc2_TOP(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_gpr__DOT__gpr);
    Vsim___024unit____Vdpiimwrap_set_ptr_mem__Vdpioc2_TOP____024unit(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_mem_ddr__DOT__mem);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0U] = 0x6c7569ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[1U] = 0x6175697063ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[2U] = 0x6a616cULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[3U] = 0x6a616c72ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[4U] = 0x626571ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[5U] = 0x626e65ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[6U] = 0x626c74ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[7U] = 0x626765ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[8U] = 0x626c7475ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[9U] = 0x62676575ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xaU] = 0x6c62ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xbU] = 0x6c68ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xcU] = 0x6c77ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xdU] = 0x6c6275ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xeU] = 0x6c6875ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0xfU] = 0x7362ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x10U] = 0x7368ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x11U] = 0x7377ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x12U] = 0x61646469ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x13U] = 0x736c7469ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x14U] = 0x736c746975ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x15U] = 0x786f7269ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x16U] = 0x6f7269ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x17U] = 0x616e6469ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x18U] = 0x736c6c69ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x19U] = 0x73726c69ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1aU] = 0x73726169ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1bU] = 0x616464ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1cU] = 0x737562ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1dU] = 0x736c6cULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1eU] = 0x736c74ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x1fU] = 0x736c7475ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x20U] = 0x786f72ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x21U] = 0x73726cULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x22U] = 0x737261ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x23U] = 0x6f72ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x24U] = 0x616e64ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x25U] = 0x66656e6365ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x26U] = 0x66656e636569ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x27U] = 0x6563616c6cULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x28U] = 0x65627265616bULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x29U] = 0x6373727277ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2aU] = 0x6373727273ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2bU] = 0x6373727263ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2cU] = 0x637372727769ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2dU] = 0x637372727369ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2eU] = 0x637372726369ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__inst_str[0x2fU] = 0x6572726f72ULL;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0U] = 0x7a65726fU;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[1U] = 0x7261U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[2U] = 0x7370U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[3U] = 0x6770U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[4U] = 0x7470U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[5U] = 0x7430U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[6U] = 0x7431U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[7U] = 0x7432U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[8U] = 0x7330U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[9U] = 0x7331U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xaU] = 0x6130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xbU] = 0x6131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xcU] = 0x6132U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xdU] = 0x6133U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xeU] = 0x6134U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0xfU] = 0x6135U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x10U] = 0x6136U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x11U] = 0x6137U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x12U] = 0x7332U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x13U] = 0x7333U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x14U] = 0x7334U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x15U] = 0x7335U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x16U] = 0x7336U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x17U] = 0x7337U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x18U] = 0x7338U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x19U] = 0x7339U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1aU] = 0x733130U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1bU] = 0x733131U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1cU] = 0x7433U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1dU] = 0x7434U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1eU] = 0x7435U;
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__reg_name[0x1fU] = 0x7436U;
    Vsim___024unit____Vdpiimwrap_set_ptr_pc__Vdpioc2_TOP____024unit(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__pc_out);
    Vsim___024unit____Vdpiimwrap_set_ptr_inst__Vdpioc2_TOP____024unit(vlSelf->sim__DOT__u_single_cycle_cpu__DOT__mem_inst_out);
    vlSelf->sim__DOT__u_single_cycle_cpu__DOT__u_dpi_verilator__DOT__counter = 0ULL;
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
