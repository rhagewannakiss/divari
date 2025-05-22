%include "st_io.inc"

section .bss
    a resd 1
    b resd 1
    c resd 1

section .text
    global _start

_start:
    PRINT "Введите а, b, c: "
    PUTCHAR 10

    GETSIG [a]
    mov eax, dword [a]

    GETSIG [b]
    mov ebx, dword [b]

    GETSIG [c]
    mov ecx, dword [c]

    ;  c = 10*a + b + 14

    lea ecx, [eax + eax*4]       ; ecx = a*5
    lea ecx, [ecx*2 + ebx + 14]  ; ecx = 10*a

    SIGNINT ecx
    PUTCHAR 10

    ; c = 24*a - 15 + b

    lea ecx, [eax*8]                ; ecx = 8a
    lea ecx, [ecx + ecx*2 - 15]     ; ecx = 24a
    lea ecx, [ecx + ebx]


    SIGNINT ecx
    PUTCHAR 10

    FINISH