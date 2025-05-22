%include "st_io.inc"

;2.	Сложить побайтно два числа (Числа – слова, использовать только регистры размером в байт).  Распечатать
;A dw 254
;B dw 250
;A=A+B

section .data
    A dw 254
    B dw 250

section .bss
    rslt resw 1

section .text
    global _start

_start:

    mov al, byte [A]
    add al, byte [B]
    mov byte [rslt], al

    mov al, byte [A+1]
    adc al, byte [B+1]    ; с учетом единицы переноса
    mov byte [rslt + 1], al

    PRINT "A = "
    movzx eax, word [A]
    UNSINT eax
    PUTCHAR 10

    PRINT "B = "
    movzx eax, word [B]
    UNSINT eax
    PUTCHAR 10

    PRINT "A + B = "
    SIGNINT word [rslt]
    PUTCHAR 10

    FINISH
