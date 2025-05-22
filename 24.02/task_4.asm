%include "st_io.inc"

;4.	Ввести символ, число со знаком и без знака, вывести строку, символ, число со знаком и без знака, используя макросы ввода-вывода.

SECTION .bss
    char resb 1
    uns_int resd 1
    sig_int resd 1

SECTION .TEXT
    GLOBAL _start

_start:
        PRINT "meow"
        PUTCHAR 10

        PRINT "enter char: "
        GETCHAR
        mov [char], al

        PRINT "enter unsigned: "
        GETUN [uns_int]

        PRINT "enter signed: "
        GETSIG [sig_int]

        PUTCHAR [char]
        PUTCHAR 10

        PRINT "unsigned: "
        UNSINT [uns_int]
        PUTCHAR 10

        PRINT "signed: "
        SIGNINT [sig_int]
        PUTCHAR 10

        FINISH
