%include "st_io.inc"

section .bss
    p1 resw 1
    p2 resw 1
    p3 resb 1
    p4 resb 1

section .text
    global _start

_start:
    GETUN eax
    mov word [p1], ax

    GETUN eax
    mov word [p2], ax

    GETUN eax
    mov byte [p3], al

    GETUN eax
    mov byte [p4], al

    mov ax, word [p1]
    add ax, word [p2]

    mov bl, byte [p3]
    adc al, bl

    adc ah, 0
    mov bl, byte [p4]

    sub al, bl
    sbb ah, 0

    movzx eax, ax
    UNSINT eax

    FINISH