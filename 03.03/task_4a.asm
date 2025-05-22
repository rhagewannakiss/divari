%include "st_io.inc"

; 4.	Дан фрагмент программы на С
; //a
;  int x;
; x++;

; написать программу на ассемблере, использовать только регистры размером 1 байт или ячейку размером один байт
;
; Проверить для значений
; //a -  x=-2147483645
;        x=2147483640


section .bss
    x resd 1

section .text
    global _start

_start:
    PRINT "№4, пункт а"
    PUTCHAR 10
    PUTCHAR 10


    PRINT "Первый пример:  "
    mov dword [x], -2147483645
    PRINT "x = "
    SIGNINT dword [x]
    PUTCHAR 10

    mov eax, dword [x]
    add al, 1                   ; младший байт
    adc ah, 0                    ; старший байт + перенос
    adc dl, 0                    ; младший 2 + перенос
    adc dh, 0                    ; старший 2 + перенос
    mov dword [x], eax

    PRINT "x после инкремента = "
    SIGNINT dword [x]
    PUTCHAR 10
    PUTCHAR 10

    PRINT "Второй пример:  "
    mov dword [x], 2147483640
    PRINT "x = "
    SIGNINT dword [x]
    PUTCHAR 10

    mov eax, dword [x]
    add al, 1                   ;мл. байт
    adc ah, 0                   ;ст. + перенос
    adc dl, 0                   ;мл. 2 + перенос
    adc dh, 0                   ; ст. 2 + перенос
    mov dword [x], eax

    PRINT "x после инкремента = "
    SIGNINT dword [x]
    PUTCHAR 10
    PUTCHAR 10

    FINISH
