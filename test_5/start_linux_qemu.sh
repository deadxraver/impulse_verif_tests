#!/bin/bash

#with trace: ATTENTION !!! VERY HUGE LOGS
#$SC_QEMU_PATH/qemu-system-riscv64 -d int,plugin -plugin $SC_QEMU_PATH/contrib/plugins/libexeclog.so -smp 1 -machine scr9_l2  -nographic -kernel $SC_DT_PATH/riscv-sw/OpenSBI/fw_jump.bin -device loader,addr=0x400000,file=$SC_DT_PATH/riscv-sw/U-Boot/u-boot.bin -device loader,addr=0x800000,file=$SC_DT_PATH/riscv-sw/Linux_v6.6/linux64_fs/Image -D linux_start.log
#without trace
$SC_QEMU_PATH/qemu-system-riscv64 -smp 1 -machine scr9_l2  -nographic -kernel $SC_DT_PATH/riscv-sw/OpenSBI/fw_jump.bin -device loader,addr=0x400000,file=$SC_DT_PATH/riscv-sw/U-Boot/u-boot.bin -device loader,addr=0x800000,file=$SC_DT_PATH/riscv-sw/Linux_v6.6/linux64_fs/Image
