; 1.	Используя логические команды и команды работы со стеком, поменять значение флага SF
; (7-й бит справа – нумерация битов от 0) на противоположный, проверить, используя команду js.
; Для решения задачи, сначала, используя арифметические команды,
; установите флаг SF в 0, поменяйте его значение, затем установите в 1.


section .note.GNU-stack note

section .data
    message_sf_set db "SF установлен", 0xA, 0
    message_sf_not_set db "SF не установлен", 0xA, 0

section .text
    extern printf
    extern exit

    global main


main:
    xor al, al
    or al, 10000000b
    js sf_true

    sub rsp, 8
    mov rdi, message_sf_not_set
    xor rax,rax
    call printf
    add rsp, 8

    pushfq
    pop rax
    xor rax, 0b10000000
    push rax
    popfq

    js sf_true

    sub rsp, 8
    mov rdi, message_sf_not_set
    xor rax,rax
    call printf
    add rsp, 8

    jmp finish

sf_true:
    sub rsp, 8
    mov rdi, message_sf_set
    xor rax,rax
    call printf
    add rsp, 8

finish:
    xor rdi, rdi
    call exit