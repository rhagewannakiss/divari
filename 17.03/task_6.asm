%include "st_io.inc"

section .data
    x dd -5
    y dd -4

section .text
    global _start

_start:
    mov eax, [x]
    mov edx, [y]

    cmp eax, -3
    jge l2

    cmp eax, edx
    jle l3

    imul eax, edx
    jmp l4

l3:
    lea eax, [eax + edx]
    jmp l4

l2:
    cmp eax, 2
    jg l5

    xor eax, edx
    jmp l4

l5:
    sub eax, edx

l4:
    SIGNINT eax
    PUTCHAR 10
    FINISH
