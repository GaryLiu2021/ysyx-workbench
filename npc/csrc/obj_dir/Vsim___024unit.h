// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim.h for the primary calling header

#ifndef VERILATED_VSIM___024UNIT_H_
#define VERILATED_VSIM___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsim__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vsim__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim___024unit(Vsim__Syms* symsp, const char* v__name);
    ~Vsim___024unit();
    VL_UNCOPYABLE(Vsim___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
