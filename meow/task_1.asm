section .data
    fmt_scanf db "%hhd", 0
    fmt_printf db "%hhd", 32, 0
    fmt_newline db "%hhd", 10, 0
    no_msg db "NO", 10, 0

section .bss
    array resb 10

section .text
    extern printf
    extern scanf
    extern exit
    global main

main:
    mov rcx, 10
    mov rbx, array

input_loop:
    push rcx
    push rbx

    xor rax, rax
    mov rdi, fmt_scanf
    mov rsi, rbx
    sub rsp, 8
    call scanf
    add rsp, 8

    pop rbx
    pop rcx

    inc rbx
    loop input_loop

    mov rcx, 10
    mov rbx, array
    xor rax, rax

push_to_stack_loop:
    mov al, [rbx]
    push ax
    inc rbx
    loop push_to_stack_loop

    mov rbp, rsp
    add rbp, 18

    mov rcx, 10

find_first_negative_loop:
    mov dx, [rbp]
    cmp dl, 0
    jge check_next_element

    mov rax, rbp
    jmp first_negative_found

check_next_element:
    sub rbp, 2
    loop find_first_negative_loop

first_negative_found:
    xor rbx, rbx
    jmp continue_search

find_second_negative_loop:
    mov dx, [rbp]
    cmp dl, 0
    jge continue_search

    mov rbx, rbp
    jmp second_negative_found

continue_search:
    sub rbp, 2
    dec rcx
    cmp rcx, 0
    jg find_second_negative_loop

second_negative_found:
    cmp rbx, 0
    je NO

    mov cl, [rax]
    xchg cl, [rbx]
    mov [rax], cl

    mov rcx, 10
restore_array_from_stack:
    pop ax
    mov [array + rcx - 1], al
    loop restore_array_from_stack

    mov rcx, 9
    mov rbx, array

loop_print:
    push rcx
    push rbx

    xor rax, rax
    mov rdi, fmt_printf
    mov rsi, 0ffh
    and rsi, [rbx]
    call printf

    pop rbx
    pop rcx

    inc rbx
    loop loop_print

    xor rax, rax
    mov rdi, fmt_newline
    mov rsi, 0ffh
    and rsi, [rbx]
    call printf

    jmp finish

NO:
    xor rax, rax
    mov rdi, no_msg
    call printf

finish:
    xor rdi, rdi
    call exit