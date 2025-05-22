section .data
    enter_w db "Введите w: ", 0
    enter_x db "Введите x: ", 0
    enter_y db "Введите y: ", 0
    enter_z db "Введите z: ", 0

    w_fmt db "%hhd", 10, 0
    x_fmt db "%hd", 10, 0
    y_fmt db "%d", 10, 0
    z_fmt db "%ld", 10, 0

    w_fmt2 db "%hhd", 0
    x_fmt2 db "%hd", 0
    y_fmt2 db "%d", 0
    z_fmt2 db "%ld", 0

    newline db 10, 0

    enter_wxyz db "Введите w x y z: ", 0
    xyz_fmt db "%hhd %hd %d %ld", 10, 0
    xyz_fmt2 db "%hhd %hd %d %ld", 0

section .note.GNU-stack note

section .bss
    w resb 1
    x resw 1
    y resd 1
    z resq 1

section .text
    extern printf
    extern scanf
    extern exit
    global main

main:
    sub rsp, 8
    mov rdi, enter_w
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, w_fmt2
    mov rsi, w

    xor rax, rax
    push rbx
    push rcx
    call scanf
    pop rcx
    pop rbx

    add rsp, 8


    sub rsp, 8
    mov rdi, enter_x
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, x_fmt2
    mov rsi, x

    xor rax, rax
    push rbx
    push rcx
    call scanf
    pop rcx
    pop rbx

    add rsp, 8

    sub rsp, 8
    mov rdi, enter_y
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, y_fmt2
    mov rsi, y

    xor rax, rax
    push rbx
    push rcx
    call scanf
    pop rcx
    pop rbx

    add rsp, 8

    sub rsp, 8
    mov rdi, enter_z
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, z_fmt2
    mov rsi, z

    xor rax, rax
    push rbx
    push rcx
    call scanf
    pop rcx
    pop rbx

    add rsp, 8

    sub rsp, 8
    mov rdi, newline
    xor rax, rax
    call printf
    add rsp, 8


    sub rsp, 8
    mov rdi, w_fmt
    mov esi, [w]
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, x_fmt
    mov esi, [x]
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, y_fmt
    mov esi, [y]
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, z_fmt
    mov rsi, [z]
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, newline
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, enter_wxyz
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, xyz_fmt2
    mov rsi, w
    mov rdx, x
    mov rcx, y
    mov r8, z
    xor rax, rax
    call scanf
    add rsp, 8

    sub rsp, 8
    mov rdi, newline
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, xyz_fmt
    mov rsi, [w]
    mov rdx, [x]
    mov rcx, [y]
    mov r8, qword [z]
    xor rax, rax
    call printf
    add rsp, 8

    xor rdi, rdi
    call exit