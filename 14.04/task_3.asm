%include "st_io.inc"

;Скопировать элементы массива A[10]  в  B[10] – dw со знаком.

section .data
    A dw 1, -2, -3, -4, 5, -6, -7, -8, 9, -10
    B dw 0,  0,  0,  0, 0,  0,  0,  0, 0,  0

section .text
    global _start

_start:
    lea esi, [A]
    lea edi, [B]
    mov ecx, 10
    repe movsw

    lea ebx, [B]
    mov ecx, 10

print:
    movsx eax, word [ebx]

    SIGNINT eax
    PUTCHAR ' '

    add ebx, 2
    sub ecx, 1
    cmp ecx, 0
    jne print

    PUTCHAR 10

    FINISH