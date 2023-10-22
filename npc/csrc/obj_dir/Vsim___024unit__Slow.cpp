// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vsim__Syms.h"
#include "Vsim__Syms.h"
#include "Vsim___024unit.h"

void Vsim___024unit___ctor_var_reset(Vsim___024unit* vlSelf);

Vsim___024unit::Vsim___024unit(Vsim__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsim___024unit___ctor_var_reset(this);
}

void Vsim___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsim___024unit::~Vsim___024unit() {
}
