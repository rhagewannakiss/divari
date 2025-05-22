%include "st_io.inc"

section .bss
    m resb 1
    n resb 1
    k resd 1
    l resd 1

section .text
    global _start

_start:
    GETSIG eax
    mov byte [m], al

    GETSIG eax
    mov byte [n], al

    GETSIG eax
    mov dword [k], eax

    GETSIG eax
    mov byte [l], al


    mov al, byte [m]
    mov bl, byte [n]

    imul bl

    mov bx, 7
    imul bx

    sub eax, dword [k]

    mov bl, byte [l]
    sub al, bl
    sbb ah, 0

    UNSINT eax

    FINISH
