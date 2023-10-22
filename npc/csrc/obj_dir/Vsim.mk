# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vsim.mk

default: Vsim

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vsim
# Module prefix (from --prefix)
VM_MODPREFIX = Vsim
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/fesvr -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/riscv -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/disasm -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/customext -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/fdt -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/softfloat -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/spike_main -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/spike_dasm -I/home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo/build -I/home/sgap/ysyx-workbench/nemu/include -L/home/sgap/ysyx-workbench/nemu/tools/spike-diff/build -lriscv32-spike-so \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	verilator_main \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	. \


### Default rules...
# Include list of all generated classes
include Vsim_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

verilator_main.o: verilator_main.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
Vsim: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
