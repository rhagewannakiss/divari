%include "st_io.inc"

; 6.	Найти 10-е  число Фибоначчи

section .bss
    n resd 1
    fib resd 1

section .text
    global _start

_start:
    mov dword [n], 10

    mov eax, 0        ; F(0) = 0
    mov ebx, 1        ; F(1) = 1
    mov ecx, [n]


    cmp ecx, 1
    je .result

.loop:
    add eax, ebx        ; F(n) = F(n-1) + F(n-2)

    xchg eax, ebx       ; F(n-2) = F(n-1), F(n-1) = F(n), результат в ebx

    dec ecx
    cmp ecx, 2
    jge .loop

.result:
    mov [fib], ebx

    PRINT "10-е число Фибоначчи: "
    UNSINT [fib]

    PUTCHAR 10

    FINISH
