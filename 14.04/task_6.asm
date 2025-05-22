%include "st_io.inc"

;6.	Определить равны ли символы 3, 4, 5 и 6 символы первой строки 2, 3, 4 и 5 символу второй строки

section .data
    A db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    B db 0, 3, 4, 5, 6, 0, 0, 0, 0, 0

section .text
    global _start

_start:
    PRINT "A: "

    lea ebx, [A]
    mov ecx, 10

printA:
    movzx eax, byte [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 1
    sub ecx, 1
    cmp ecx, 0
    jne printA

    PUTCHAR 10

    PRINT "B: "

    lea ebx, [B]
    mov ecx, 10

printB:
    movzx eax, byte [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 1
    sub ecx, 1
    cmp ecx, 0
    jne printB

    PUTCHAR 10
    PUTCHAR 10

    lea esi, [A+2]
    lea edi, [B+1]
    mov ecx, 4
    repe cmpsb

    je equal
    jmp nonequal

equal:
    PRINT "Символы равны."
    PUTCHAR 10
    jmp finish

nonequal:
    PRINT "Символы не равны."
    PUTCHAR 10
    jmp finish


finish:
    FINISH