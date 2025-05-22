; 2.	Не используя команды деления, выдать на печать значение AX в виде без знакового двоичного числа без незначащих нулей.
%include "st_io.inc"

section .text
    global _start

_start:
    mov ax, 13          ;тестовые данные
    mov cx, 16
    xor bx, bx

print_loop:
    shl ax, 1
    jc print_1

print_0:
    cmp bx, 0
    je next_bit
    PUTCHAR '0'
    jmp next_bit

print_1:
    PUTCHAR '1'
    mov bx, 1

next_bit:
    dec cx
    jnz print_loop

    cmp bx, 0
    je print_number_zero
    jmp finish

print_number_zero:
    PUTCHAR '0'

finish:
    PUTCHAR 10
    FINISH