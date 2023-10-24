
gnu = riscv32-unknown-elf
CC = $(gnu)-gcc
CFLAGS = -Wall -march=rv32i -mabi=ilp32 -nostartfiles

LD = $(gnu)-ld
LD_SC = link.ld
LDFLAGS = -T $(LD_SC)

DP = $(gnu)-objdump
DPFLAGS = -S

CP = $(gnu)-objcopy
CPFLAGS = -O binary


all: $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.c,%.elf,$(wildcard *.c)) $(patsubst %.c,%.dump,$(wildcard *.c)) $(patsubst %.c,%.bin,$(wildcard *.c))  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.elf: %.o $(LD_SC)
	$(LD) $(LDFLAGS) $< -o $@

%.dump: %.elf
	$(DP) $(DPFLAGS) $< > $@

%.bin: %.elf
	$(CP) $(CPFLAGS) $< $@