%include "st_io.inc"

;7.	Найти в строке S1 первое вхождение символа * и заменить его на +.

section .data
    str1     db "63*1*+", 0
    str1_len dd 6

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    lea ecx, [str1]
    mov edx, [str1_len]
    int 0x80

    PUTCHAR 10

    lea edi, [str1]
    mov ecx, [str1_len]
    mov al, '*'
    repne scasb

    jne finish
    mov byte [edi-1], '+'

finish:
    mov eax, 4
    mov ebx, 1
    lea ecx, [str1]
    mov edx, [str1_len]
    int 0x80

    PUTCHAR 10

    FINISH