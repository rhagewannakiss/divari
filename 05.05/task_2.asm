; 2.	Заданы две даты в упакованном t1 в виде D:5, M:4,Y:7 – дата в формате дд –мм-гг, и t2 в виде Y1:7, M1:4, D1:5 гг – мм – дд.
; Написать программу, которая – выводит дату t2 на экран дд:мм:гг
;                                                           - присваивает переменной t2 ту же дату,
;                                                              что t1 и выводит на экран гг:мм:дд

section .note.GNU-stack note

section .data
    y1 db 99
    m1 db 12
    d1 db 31
    y2 db 99
    m2 db 12
    d2 db 31

section .data
    t1 dq 0
    day db 0
    month db 0
    year db 0
    ft_scanf db "%d", 0
    ft_printf1 db "t1:   %02d:%02d:2%03d", 0xA, 0
    ft_printf2 db "%d", 0xA, 0

section .text
    extern printf
    extern scanf
    extern exit
    global main

main:
    sub rsp, 8
    mov rdi, ft_scanf
    mov rsi, t1
    xor rax, rax
    call scanf
    add rsp, 8

    mov rax, [t1]
    mov bl, al
    and bl, 01111111b
    mov [year], bl

    shr ax, 7
    mov bl, al
    and bl, 00001111b
    mov [month], bl

    shr ax, 4
    mov bl, al
    and bl, 00011111b
    mov [day], bl

    sub rsp, 8
    mov rdi, ft_printf1
    xor rbx, rbx
    mov bl, [day]
    mov rsi, rbx
    mov bl, [month]
    mov rdx, rbx
    mov bl, [year]
    mov rcx, rbx
    xor rax,rax
    call printf
    add rsp, 8

    xor rax, rax
    mov ah, [year]
    shl ah, 1
meow:

    xor bx, bx
    mov bl, [month]
    shl bx, 5
    or ax, bx

    xor bx, bx
    mov bl, [day]
    or ax, bx

    sub rsp, 8
    mov rdi, ft_printf2
    mov rsi, rax
    xor rax,rax
    call printf
    add rsp, 8

finish:
    xor rdi, rdi
    call exit
