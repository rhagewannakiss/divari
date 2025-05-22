%include "st_io.inc"

; 8.	Умножить слово на байт
; x старш	x младш
;                                       *
; y

section .bss
    x resw 1
    k resb 1
    y resd 1

section .text
    global _start

_start:
    PRINT "Введите x: "
    GETSIG word [x]

    PRINT "Введите k: "
    GETSIG byte [k]

    mov ax, word [x]
    mov bl, byte [k]
    mul bl

    mov dword [y], eax

    PRINT "y = "
    SIGNINT dword [y]
    PUTCHAR 10


    FINISH
