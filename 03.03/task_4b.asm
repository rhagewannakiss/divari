%include "st_io.inc"

; 4.	Дан фрагмент программы на С
;             //b
;              unsigned int x;
; x++;
; написать программу на ассемблере, использовать только регистры размером 1 байт или ячейку размером один байт
;
; Проверить для значений
; //b - x=4 294 967 293



section .bss
    x resd 1

section .text
    global _start

_start:
    PRINT "№4, пункт b"
    PUTCHAR 10
    PUTCHAR 10

    PRINT "Пример:  "
    mov dword [x], 4294967293
    PRINT "x = "
    UNSINT [x]
    PUTCHAR 10

    mov eax, dword [x]
    add al, 1                    ;мл. байт
    adc ah, 0                    ; ст. байт + перенос
    adc dl, 0                    ;мл. байт 2 + перенос
    adc dh, 0                    ;ст. байт 2 + перенос
    mov dword [x], eax

    PRINT "x после инкремента = "
    UNSINT [x]
    PUTCHAR 10

    FINISH