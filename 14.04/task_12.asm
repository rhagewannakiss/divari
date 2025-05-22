%include "st_io.inc"

;12.	Даны две строки. Определите, содержится ли меньшая по длине строка в большей.

section .data
    str1 db "meowmeowmeowmeowmeow", 0
    str1_len equ $-str1 - 1
    str2 db "meeeow", 0
    str2_len equ $-str2 - 1

section .text
    global _start

_start:
    mov edx, str1_len
    sub edx, str2_len
    inc edx

    mov edi, str1
    mov esi, str2

search_loop:
    mov ecx, str2_len
    repe cmpsb
    je found

    mov esi, str2
    mov edi, str1

    add edi, eax
    inc eax

    cmp eax, edx
    je not_found

    jmp search_loop

found:
    PRINT "Длина меньшей строки содержится в большей."
    PUTCHAR 10

    jmp exit

not_found:
    PRINT "Длина меньшей строки НЕ содержится в большей."
    PUTCHAR 10

    jmp exit

exit:
    FINISH