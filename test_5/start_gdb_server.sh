#!/bin/bash

$SC_GDB_PATH/bin/riscv64-unknown-elf-gdb -ex 'target remote localhost:1234'
