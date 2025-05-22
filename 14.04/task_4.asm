%include "st_io.inc"

;4.	Скопировать 3, 4 и 5 элементы массива A[10]  в  2,3 и 4 B[10] – dd , без  знака.

section .data
    A dd 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    B dd 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

section .text
    global _start

_start:
    PRINT "До копирования:"
    PUTCHAR 10

    lea ebx, [A]
    mov ecx, 10

printA:
    SIGNINT dword [ebx]
    PUTCHAR ' '

    add ebx, 4
    sub ecx, 1
    cmp ecx, 0
    jne printA

    PUTCHAR 10

    lea ebx, [B]
    mov ecx, 10

printB:
    SIGNINT dword [ebx]
    PUTCHAR ' '

    add ebx, 4
    sub ecx, 1
    cmp ecx, 0
    jne printB

    PUTCHAR 10
    PUTCHAR 10


    lea esi, [A+8]
    lea edi, [B+4]
    mov ecx, 3
    repe movsd

    lea ebx, [A]
    mov ecx, 10

    PRINT "После копирования:"
    PUTCHAR 10

printAafter:
    SIGNINT dword [ebx]
    PUTCHAR ' '

    add ebx, 4
    sub ecx, 1
    cmp ecx, 0
    jne printAafter

    PUTCHAR 10

    lea ebx, [B]
    mov ecx, 10

printBafter:
    SIGNINT dword [ebx]
    PUTCHAR ' '

    add ebx, 4
    sub ecx, 1
    cmp ecx, 0
    jne printBafter

    PUTCHAR 10
    FINISH