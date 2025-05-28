PROJECTS=hello_test
PROJECTS_SOURCES=$(PROJECTS).c
PROJECTS_ELF=$(PROJECTS).elf
PROJECTS_LOG=$(PROJECTS).log
CROSS_COMPILE=$(SC_GCC_PATH)/bin/riscv64-unknown-elf-
QEMU_RISCV=$(SC_QEMU_PATH)/qemu-riscv64
OBJDUMP_FLAGS=-w -x -C -p -S

.PHONY: all clean run debug

all: $(PROJECTS_ELF)

run:
	$(QEMU_RISCV) -cpu syntacore-scr9 $(PROJECTS_ELF)

run_trace:
	$(QEMU_RISCV) -cpu syntacore-scr9 -d int,plugin -plugin $(SC_QEMU_PATH)/contrib/plugins/libexeclog.so -D $(PROJECTS_LOG) $(PROJECTS_ELF)

debug:
	$(QEMU_RISCV) -cpu syntacore-scr9 -g 1234 $(PROJECTS_ELF)

$(PROJECTS_ELF): $(PROJECTS_SOURCES)
	$(CROSS_COMPILE)gcc $(CFLAGS) -o $@ $< -I .
	$(CROSS_COMPILE)objdump $(OBJDUMP_FLAGS) $@ > $@_fulldebug.dump

clean:
	rm -f *.o $(PROJECTS_ELF) *.dump *.log

