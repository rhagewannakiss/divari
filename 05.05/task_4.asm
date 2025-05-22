; 4.	Для 64-х разрядной архитектуры ввести и вывести символьную строку, для которой выделено место в секции bss, используя системные прерывания

section .note.GNU-stack note

section .data
    enter_str db "Введите строку: ", 0
    enter_str_len equ $ - enter_str

section .bss
    str_buffer resb 256
    input_len resq 1

section .text
    global main

main:
    mov rax, 1
    mov rdi, 1
    mov rsi, enter_str
    mov rdx, enter_str_len
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, str_buffer
    mov rdx, 256
    syscall
    mov [input_len], rax

    mov rax, 1
    mov rdi, 1
    mov rsi, str_buffer
    mov rdx, [input_len]
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
