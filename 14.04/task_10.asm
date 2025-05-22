%include "st_io.inc"

;10.	Дана строка. Показать номера символов, совпадающих с последним символом строки.

section .data
    str1 db "g1244488678", 0
    str1_len equ ($ - str1)

section .text
    global _start

_start:
    mov ecx, str1_len
    sub ecx, 2

    mov al, [str1 + ecx]
    lea edi, [str1]
    add ecx, 1

loop:
    repne scasb

    je found
    jmp finish

found:
    mov ebx, edi
    sub ebx, str1

    UNSINT ebx
    PUTCHAR 10

    cmp ecx, 0
    jne loop

finish:
    FINISH