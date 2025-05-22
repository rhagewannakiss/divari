; 6.	Ввести и вывести массив из 10 элементов для 64-х разрядной архитектуры, обязательно используя loop

section .data
    input db "Введите 10 чисел:", 10, 0
    output db "Массив:", 10, 0
    num db "%d", 0
    num_print db "%d ", 0
    newline db 10, 0

section .note.GNU-stack note

section .bss
    array   resd 10

section .text
    global main
    extern printf
    extern scanf
    extern exit

main:
    sub rsp, 8
    mov rdi, input
    xor rax, rax
    call printf
    add rsp, 8

    mov rcx, 10
    mov rbx, array

input_loop:
    push rcx
    push rbx

    sub rsp, 8
    mov rdi, num
    mov rsi, rbx
    xor rax, rax
    call scanf
    add rsp, 8

    pop rbx
    pop rcx

    add rbx, 4
    loop input_loop

    sub rsp, 8
    mov rdi, output
    xor rax, rax
    call printf
    add rsp, 8

    mov rcx, 10
    mov rbx, array


output_loop:
    push rcx
    push rbx

    sub rsp, 8
    mov rdi, num_print
    mov esi, [rbx]
    xor rax, rax
    call printf
    add rsp, 8

    pop rbx
    pop rcx

    add rbx, 4
    loop output_loop

    sub rsp, 8
    mov rdi, newline
    xor rax, rax
    call printf
    add rsp, 8

    xor rdi, rdi
    call exit