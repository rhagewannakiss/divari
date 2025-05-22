%include "st_io.inc"

;2.	 В строке S1(10 символов) заменить 3,4,5 и 6 символы на 5,6,7 и 8 символы строки S2 (10 символов).

section .data
    str1 db "1234567890", 0
    str2 db "0000111100", 0

section .text
    global _start

_start:
    PRINT "До копирования: "
    PUTCHAR 10

    PRINT "str1: "

    mov eax, 4
    mov ebx, 1
    mov ecx, str1
    mov edx, 10
    int 0x80

    PUTCHAR 10

    PRINT "str2: "

    mov eax, 4
    mov ebx, 1
    mov ecx, str2
    mov edx, 10
    int 0x80

    PUTCHAR 10

    lea esi, [str2+4]
    lea edi, [str1+2]
    movsd

    PRINT "После копирования: "
    PUTCHAR 10

    PRINT "str1: "

    mov eax, 4
    mov ebx, 1
    mov ecx, str1
    mov edx, 10
    int 0x80

    PUTCHAR 10

    PRINT "str2: "

    mov eax, 4
    mov ebx, 1
    mov ecx, str2
    mov edx, 10
    int 0x80

    PUTCHAR 10
    FINISH