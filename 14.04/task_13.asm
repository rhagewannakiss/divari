extern printf, exit, scanf

section .data
    fmt db "введите x, y, z", 10, 0
    scanf_fmt db "%hhd %hd %d", 0
    printf_fmt db "x = %d; y = %d; z = %d", 10, 0

section .bss
    x resb 1
    y resw 1
    z resd 1

section .text
    global main

main:
    push fmt
    call printf

    push z
    push y
    push x

    push scanf_fmt
    call scanf

    movsx eax, byte [x]
    movsx ebx, word [y]
    mov ecx, [z]

    push ecx
    push ebx
    push eax
    push printf_fmt

    call printf
    add esp, 16

    push 0
    call exit