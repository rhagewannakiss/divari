; 3.	На факультете   512 студентов. Каждый из них имеет идентификационный номер от 0 до 511  717.   Необходимо хранить информацию,
; о том, присутствует студент на занятиях (бит – 0 отсутствует, бит 1 – присутствует).
; Для реализации задачи опишем массив из 16 двойных слов. Элемент с индексом 0 будет хранить статус студентов с номерами от 0 до 31,
; с индексом 1 от 32 до 63 и т.д. Будем считать, что биты пронумерованы справа налево.
; Чтобы по номеру объекта X узнать, в каком бите какого элемента массива хранится его статус, достаточно разделить X на 32.
; Частное – номер элемента в массиве, остаток – номер бита в этом элементе.
; Определить массив с любыми значениями.
;     - определить сколько студентов отсутствуют.
;     - определить присутствует ли студент с определенным
;        идентификационным номером
; Задачу решить, не используя команду div.


; вводить порядковый номер (с 1)

section .note.GNU-stack note

section .data
    t1            dq 0
    array         dd  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    ft2           db "%s", 0
    ft_printf1    db "Отсутствует:   %d", 10, 0
    ft_printf     db "Введите число:   ", 0
    ft_scanf      db "%d", 0
    ft_printf_yes db "yes", 10, 0
    ft_printf_no  db "no", 10, 0

section .text
    extern printf
    extern scanf
    extern exit
    global main


main:
    xor ebx, ebx
    xor rdx, rdx

count_loop:
    mov rax, [array + rdx*4]
    mov rcx, 32

bit_loop:
    shr rax, 1b
    adc rbx, 0
    loop bit_loop

    add rdx, 1

    cmp rdx, 16
    jne again

    mov rsi, 512
    sub rsi, rbx

    sub rsp, 8
    mov rdi, ft_printf1
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, ft2
    mov rsi, ft_printf
    xor rax, rax
    call printf
    add rsp, 8

    sub rsp, 8
    mov rdi, ft_scanf
    mov rsi, t1
    xor rax, rax
    call scanf
    add rsp, 8

    mov rax, [t1]
    dec rax
    mov cl, al
    and cl, 00011111b
    shr rax, 5

    mov rdx, [array + rax*4]
    shr rdx, cl
    and rdx, 1b
    cmp rdx, 0
    je not_pres

    sub rsp, 8
    mov rdi, ft_printf_yes
    xor rax, rax
    call printf
    add rsp, 8
    jmp finish

student_absent:
    sub rsp, 8
    mov rdi, ft_printf_no
    xor rax, rax
    call printf
    add rsp, 8

finish:
    xor rdi, rdi
    call exit
