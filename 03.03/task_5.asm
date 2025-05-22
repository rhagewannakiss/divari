%include "st_io.inc"

;  5.	Вычислить значение Y
;                               Y=
;        x=2 (байт)       a=7 (байт)

section .data
    x db 2
    a db 7
    Y db 0

section .bss
    x2 resb 1
    x3 resb 1
    x4 resb 1

section .text
    global _start

_start:
    mov al, [x]
    mul byte [x]
    mov [x2], al

    PRINT "(x^2) = "
    movsx ecx, byte [x2]
    SIGNINT ecx
    xor ecx, ecx
    PUTCHAR 10

    mul byte [x]
    mov [x3], al

    PRINT "x^3 = "
    movsx ecx, byte [x3]
    SIGNINT ecx
    xor ecx, ecx
    PUTCHAR 10

    mov al, [x2]
    mov bl, 10
    mul bl
    mov [x4], al
    add byte [x4], 5

    PRINT "10x^2 + 5 = "
    movsx ecx, byte [x4]
    SIGNINT ecx
    xor ecx, ecx
    PUTCHAR 10

    mov al, [x3]
    neg al                   ; al = -x^3


    sub al, [x4]

    PRINT "-x^3 - (10x^2 + 5) = "
    movsx cx, al
    movsx ecx, cx
    SIGNINT ecx
    xor ecx, ecx
    PUTCHAR 10

    cbw                 ;al -> ax

    idiv byte [a]
    mov [Y], al
    movsx bx, ah    ;al - частное, ah - остаток
    movsx ebx, bx
    PRINT "Остаток: "
    SIGNINT ebx
    PUTCHAR 10

    PRINT "Y = "
    movsx eax, byte [Y]
    SIGNINT eax
    PUTCHAR 10

    FINISH
