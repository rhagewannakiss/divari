%include "st_io.inc"

; 9.	Дана строка. Вывести первые три символа и последние три символа,
; если длина строки больше 5. Иначе вывести первый символ столько раз, какова длина строки.

section .data
    str1 db "g12444678", 0
    str1_len equ ($ - str1)

section .bss
    outbuf resb 6

section .text
    global _start

_start:
    mov ecx, str1_len

    cmp ecx, 5
    jle short_string

    mov esi, str1
    lea edi, [outbuf]

    mov ecx, 3
    rep movsb

    mov esi, str1
    add esi, str1_len
    sub esi, 4

    lea edi, [outbuf + 3]
    mov ecx, 3
    rep movsb

    lea esi, [outbuf]
    mov ecx, 6

.print_loop:
    mov al, [esi]

    PUTCHAR al

    inc esi
    loop .print_loop

    PUTCHAR 10

    jmp the_end

short_string:
    mov ecx, str1_len
    sub ecx, 1
    mov al, [str1]

.repeat:
    PUTCHAR al

    loop .repeat

    PUTCHAR 10

the_end:
    FINISH