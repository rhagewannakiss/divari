%include "st_io.inc"

;6.	Сделать переход на метку, если 3 правых бита равны   3 левым битам  регистра AX.

section .text
    global _start

_start:
    mov ax, 0b1110000000000111

    mov bx, ax
    and bx, 0x0007  ;3 мл. бита ax

    mov cx, ax
    shr cx, 13      ; старшие 3 бита в младшие
    and cx, 0x0007

    xor bx, cx
    jz equal

    FINISH

equal:
    PRINT "OK"
    PUTCHAR 10
    FINISH