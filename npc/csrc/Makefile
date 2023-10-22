# Init directory
wave_dir=./wave/
src_dir=../vsrc

# Verilog srcs
VERILOG_VSRCS = ${src_dir}/*.v
VERILOG_TOP = --top-module sim

# Verilator flags
VERILATOR_FLAGS = --timing -Wno-fatal -Wall --trace -cc -exe -build

# Verilator include
VERILATOR_INC = -I${src_dir}

# Verilator wrapper file
VERILATOR_CSRCS = verilator_main.cpp

# C compiler flags
REPO_PATH = /home/sgap/ysyx-workbench/nemu/tools/spike-diff/repo
inc_dependencies = fesvr riscv disasm customext fdt softfloat spike_main spike_dasm build
INC_PATH = $(REPO_PATH) $(addprefix -I$(REPO_PATH)/, $(inc_dependencies))

lib_dir = /home/sgap/ysyx-workbench/nemu/tools/spike-diff/build
lib_name = riscv32-spike-so

CFLAGS = -CFLAGS "${INC_PATH} -l${lib_dir}/${lib_name}"

sim:
	verilator ${VERILATOR_FLAGS} ${VERILATOR_INC} ${VERILOG_VSRCS} ${VERILOG_TOP} ${VERILATOR_CSRCS} ${CFLAGS}
	@echo "\n\n\tSimulation Begin!\n\n"
	./obj_dir/V${top_module}
	@echo "\n\n\tSimulation Finished!\n\n"
	mv -i -v *.vcd ${wave_dir}