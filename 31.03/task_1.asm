; 1.	В стек записать 10 слов (двойных слов).
; Поменять местами два «верхних» слова,
; используя только команды работы со стеком,
; не меняя значения регистров и глобальных переменных.

%include "st_io.inc"

section .data
    a dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

section .text
    global _start

_start:
    push word [a]
    push word [a + 2]
    push word [a + 4]
    push word [a + 6]
    push word [a + 8]
    push word [a + 10]
    push word [a + 12]
    push word [a + 14]
    push word [a + 16]
    push word [a + 18]

    pop word [a + 18]
    pop word [a + 16]

    push word [a + 18]
    push word [a + 16]


    pop word [a + 18]
    movsx eax, word [a + 18]
    SIGNINT eax
    PRINT " "

    pop word [a + 16]
    movsx eax, word [a + 16]
    SIGNINT eax
    PRINT " "

    pop word [a + 14]
    movsx eax, word [a + 14]
    SIGNINT  eax
    PRINT " "

    pop word [a + 12]
    movsx eax, word [a + 12]
    SIGNINT eax
    PRINT " "

    pop word [a + 10]
    movsx eax, word [a + 10]
    SIGNINT eax
    PRINT " "

    pop word [a + 8]
    movsx eax, word [a + 8]
    SIGNINT eax
    PRINT " "

    pop word [a + 6]
    movsx eax, word [a + 6]
    SIGNINT eax
    PRINT " "

    pop word [a + 4]
    movsx eax, word [a + 4]
    SIGNINT eax
    PRINT " "

    pop word [a + 2]
    movsx eax, word [a + 2]
    SIGNINT eax
    PRINT " "

    pop word [a]
    movsx eax, word [a]
    SIGNINT eax
    PRINT " "

    PUTCHAR 10
    FINISH