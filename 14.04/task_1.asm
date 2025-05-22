%include "st_io.inc"

;1.	Скопировать строку “123456” в строку “asdfgh”.  Распечатать обе строки, используя системные прерывания.

section .data
    source      db "123456", 0
    destination db "abcdef", 0
    cnt         dd 6

section .text
    global _start

_start:
    PRINT "До копирования: "
    PUTCHAR 10

    mov eax, 4
    mov ebx, 1
    mov ecx, destination
    mov edx, [cnt]
    int 0x80

    PUTCHAR 10

    mov eax, 4
    mov ebx, 1
    mov ecx, source
    mov edx, [cnt]
    int 0x80

    PUTCHAR 10

    mov esi, source
    mov edi, destination
    mov ecx, [cnt]

    repe movsb

    PRINT "После копирования:"
    PUTCHAR 10

    mov eax, 4
    mov ebx, 1
    mov ecx, destination
    mov edx, [cnt]
    int 0x80

    PUTCHAR 10

    mov eax, 4
    mov ebx, 1
    mov ecx, source
    mov edx, [cnt]
    int 0x80

    PUTCHAR 10
    FINISH