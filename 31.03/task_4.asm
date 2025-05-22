;4.	Определить есть ли в стеке два одинаковых слова и записать в al 1, и 0 в противном случае.

%include "st_io.inc"

section .data
    a      dw 1, 2, 3, 4, 5, 7, 3, 9, 4, 2, 7, 0
    a_size dd 24
    a_len  dd 12

section .text
    global _start

_start:
    pushad

    PRINT "Массив: "
    mov ecx, [a_len]
    mov ebx, esp

print_before:
    movzx eax, word [a + (ecx-1)*2]
    push ax

    SIGNINT eax
    PUTCHAR ' '

    sub ecx, 1
    jne print_before

    PUTCHAR 10

    mov ebp, esp
    mov ecx, [a_size]

 find_repeating:
    mov ax, [ebp + ecx]
    mov edx, ecx
    jmp finding

finish_check:
    sub ecx, 2
    jne find_repeating

    jmp finish_zero

finding:
    sub edx, 2
    cmp word [ebp+edx], ax
    je finish_one

    cmp edx, 0
    je finish_check

    jmp finding

finish_one:
    mov ax, 1
    jmp finish

finish_zero:
    mov ax, 0

finish:
    PRINT "Значение AL: "

    movsx eax, ax
    SIGNINT eax
    PUTCHAR 10

    popad

    FINISH