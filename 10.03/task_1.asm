%include "st_io.inc"

section .text
    global _start

_start:
    mov eax, 5
    jmp l
m:
    PUTCHAR 56
    mov eax, 1
    mov ebx, 0
    int 0x80
l:
    jmp m
