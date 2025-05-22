%include "st_io.inc"

; 2.	Оформить в виде процедур с=а+b, и c=a-b.
; Расположить процедуру до и после основной программы.
; Использовать глобальные переменные.

section .data
    a dd 12
    b dd 5

section .bss
    c resd 1

section .text
    global _start

proc_add:
    mov eax, [a]
    add eax, [b]
    mov [c], eax

    ret

_start:
    call proc_add
    PRINT "a + b: "
    SIGNINT dword [c]
    PUTCHAR 10


    call proc_sub
    PRINT "a - b: "
    SIGNINT dword [c]
    PUTCHAR 10


    FINISH

proc_sub:
    mov eax, [a]
    sub eax, [b]
    mov [c], eax

    ret

