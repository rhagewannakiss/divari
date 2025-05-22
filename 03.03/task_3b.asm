%include "st_io.inc"

; 3.	Реализовать присваивание b = a; (не более двух команд) при условии:
; // b
; char a;
; short b

section .data
    a db -1
    b dw 0

;section .bss
;    a resb 1
;    b resw 1

section .TEXT
    global _start

_start:
    PRINT "№3, пункт b"
    PUTCHAR 10
    PUTCHAR 10

    PRINT "До присваивания: "
    PUTCHAR 10

    PRINT "a = "
    movsx eax, byte [a]
    SIGNINT byte eax
    PUTCHAR 10

    PRINT "b = "
    movsx eax, byte [b]
    SIGNINT byte eax
    PUTCHAR 10

    ; две команды
    movsx ax, byte [a]
    mov word [b], ax


    PRINT "После присваивания: "
    PUTCHAR 10

    PRINT "a = "
    movsx eax, byte [a]
    SIGNINT byte eax
    PUTCHAR 10

    PRINT "b = "
    movsx eax, byte [b]
    SIGNINT byte eax
    PUTCHAR 10

    FINISH