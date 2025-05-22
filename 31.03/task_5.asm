; 5.	Рассматривая двойные слова из стека как адреса некоторых байтов из секции данных, обнулить эти байты.

%include "st_io.inc"

section .data
    a dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    a_len equ ($ - a)/2

section .text
    global _start

_start:
    push dword 3    ; Смещение 3
    push dword 8    ; Смещение 8

    pop edx         ; edx = 5
    mov byte [a + edx*2], 0

    pop edx         ; edx = 3
    mov byte [a + edx*2], 0


    xor ecx, ecx
    mov esi, a

print_loop:
    cmp ecx, a_len
    je finish

    movsx eax, word [esi + ecx*2]
    SIGNINT eax
    PRINT " "

    inc ecx
    jmp print_loop

finish:
    PUTCHAR 10
    FINISH