%include "st_io.inc"

; 7. Напишите программу для вычисления формулы d = b - 1 + a - c.
; Все числа — 3-байтные целые без знака.
; Ввести переменную d (4 байта), так что d, d+1, d+2, d+3.
; Причем так как перевернем, то d+3 будет 0.
; Тогда в d запишется a, в d+1 - a+1, в d+2 - a+2, d+3 останется 0.

section .bss
    a resb 3
    b resb 3
    c resb 3
    d resb 3

section .text
    global _start

_start:

    PRINT "Введите b: "
    GETUN eax
    mov [b], al             ; мл. байт

    shr eax, 8              ; сдвиг eax на 8 бит вправо
    mov [b+1], al           ; след. байт в b+1
    shr eax, 8
    mov [b+2], al           ; ст. байт в b+2

    PRINT "Введите a: "
    GETUN eax
    mov [a], al
    shr eax, 8
    mov [a+1], al
    shr eax, 8
    mov [a+2], al

    PRINT "Введите c: "
    GETUN eax
    mov [c], al
    shr eax, 8
    mov [c+1], al
    shr eax, 8
    mov [c+2], al

    mov al, [b]             ; младший байт b в al
    sub al, 1
    mov [d], al
    mov al, [b+1]           ; следующий байт b в al
    sbb al, 0               ; с учетом флага переноса
    mov [d+1], al
    mov al, [b+2]           ; старший байт b в al
    sbb al, 0
    mov [d+2], al

    mov al, [d]             ; аналогично работаем с байтами d
    add al, [a]
    mov [d], al
    mov al, [d+1]
    adc al, [a+1]           ; прибавляем с учетом флага переноса
    mov [d+1], al
    mov al, [d+2]
    adc al, [a+2]
    mov [d+2], al

    mov al, [d]
    sub al, [c]             ; вычитаем младший байт c
    mov [d], al
    mov al, [d+1]
    sbb al, [c+1]           ; с учетом флага переноса
    mov [d+1], al
    mov al, [d+2]
    sbb al, [c+2]
    mov [d+2], al

    movzx eax, byte [d+2]   ; старший байт в eax
    shl eax, 16             ; влево на 16 бит
    mov ah, [d+1]           ; средний байт в ah
    mov al, [d]             ; младший байт в al

    PRINT "d = "
    SIGNINT eax
    PUTCHAR 10

    FINISH
