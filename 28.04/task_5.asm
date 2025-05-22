%include "st_io.inc"

; 5.	Сделать переход на метку, если 2 правых бита регистра AL равны 2 правым битам регистра BL.

section .text
    global _start

_start:
    mov al, 0x03   ; AL = 00000011
    mov bl, 0xFF   ; BL = 11111111

    mov cl, al
    mov dl, bl

    xor cl, dl
    and cl, 0x03

    test cl, cl
    jz equal

    FINISH

equal:
    PRINT "OK"
    PUTCHAR 10
    FINISH