%include "st_io.inc"

; 3.	Оформить в виде процедур с=а+b, c=a-b.
; Расположить процедуру до и после основной программы.
; Параметры передать через регистры

section .data
    a dd 2
    b dd 7

section .bss
    c resd 1

section .text
    global _start

proc_add:
    add eax, ebx

    ret

_start:
    mov eax, [a]
    mov ebx, [b]

    call proc_add
    mov [c], eax

    PRINT "a + b: "
    SIGNINT dword [c]
    PUTCHAR 10

    mov eax, [a]
    mov ebx, [b]

    call proc_sub
    mov [c], eax

    PRINT "a - b: "
    SIGNINT dword [c]
    PUTCHAR 10

    FINISH

proc_sub:
    sub eax, ebx

    ret