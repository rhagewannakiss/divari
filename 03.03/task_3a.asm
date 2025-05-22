%include "st_io.inc"

; 3.	Реализовать присваивание b = a; (не более двух команд) при условии:
; // a
;  unsigned char a;
;  unsigned int b;

section .data
    a db 1
    b dd 7

;section .bss
;    a resb 1
;    b resw 1

section .TEXT
    global _start

_start:
    PRINT "№3, пункт а"
    PUTCHAR 10
    PUTCHAR 10

    PRINT "До присваивания: "
    PUTCHAR 10

    PRINT "a = "
    movzx eax, byte [a]
    UNSINT byte eax
    PUTCHAR 10

    PRINT "b = "
    movzx eax, byte [b]
    UNSINT byte eax
    PUTCHAR 10

    ; две команды
    movzx ax, byte [a]
    mov word [b], ax


    PRINT "После присваивания: "
    PUTCHAR 10

    PRINT "a = "
    movzx eax, byte [a]
    UNSINT byte eax
    PUTCHAR 10

    PRINT "b = "
    movzx eax, byte [b]
    UNSINT byte eax
    PUTCHAR 10

    FINISH