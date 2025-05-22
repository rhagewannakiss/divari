%include "st_io.inc"

; 1.	Напишите программу на ассемблере, которая соответствует приведенному коду на С.
; static int  x, y=25, t=19;
; static int *xp;
; xp =&t;
;      x = *xp;
;          *xp = y;
; printf(“%d   %d\n”, x, *xp);

section .data
    y dd 25
    t dd 19

section .bss
    x resd 1
    xp resd 1

section .text
    global _start

_start:
    mov dword [xp], t

    mov eax, [t]
    mov [x], eax

    mov eax, [y]
    mov [t], eax

    SIGNINT dword [t]
    PRINT '   '
    SIGNINT dword [x]
    PUTCHAR 10

    FINISH
