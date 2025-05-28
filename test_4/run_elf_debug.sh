#!/bin/bash

#$SC_QEMU_PATH/qemu-riscv64 -d int,plugin -plugin $SC_QEMU_PATH/contrib/plugins/libexeclog.so -cpu syntacore-scr9 -D $1.log $1
$SC_QEMU_PATH/qemu-riscv64 -cpu syntacore-scr9 -D $1.log  -g 1234 $1
