#!/bin/bash

set -e

nasm -f elf32 "$1.asm" -o "$1.o" -g
ld -m elf_i386 "$1.o" -o "$1"
./"$1"
rm -f "$1.o"