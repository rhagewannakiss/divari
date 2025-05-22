; 1.	Подсчитать количество двоичных единиц в  регистре AX и записать их в переменную d.

%include "st_io.inc"


section .text
    global _start

_start:
    mov ax, 0b111
    xor cx, cx
    mov bx, 16

cnt_loop:
    shr ax, 1
    adc cx, 0
    dec bx
    jnz cnt_loop

    movzx ecx, cx
    UNSINT ecx
    PUTCHAR 10
    FINISH