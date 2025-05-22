%include "st_io.inc"

; 11.	Дан текст. Найти слова, состоящие из цифр, и сумму чисел, которые образуют эти слова. (слова разделены символом “пробел”)

section .data
    text        db "342 meow meow 232 meow 948",0
    text_len    equ $-text

    num         dd 0
    sum         dd 0
    prev_char   db ' '
    in_num      db 0

section .text
    global _start

_start:
    mov     esi, text

.loop:
    lodsb
    test    al, al
    jz      .done

    cmp     al, ' '
    je      .finish_number

    cmp     al, '0'
    jb      .not_digit

    cmp     al, '9'
    ja      .not_digit

    cmp     byte [in_num], 1
    je      .continue_num

    cmp     byte [prev_char], ' '
    jne     .store_prev

    mov     dword [num], 0
    mov     byte [in_num], 1

.continue_num:
    mov     ebx, [num]
    imul    ebx, 10
    sub     al, '0'
    add     ebx, eax
    mov     [num], ebx
    jmp     .store_prev

.not_digit:
    mov     byte [in_num], 0

.store_prev:
    mov     [prev_char], al
    jmp     .loop

.finish_number:
    cmp     byte [in_num], 1
    jne     .skip_add

    cmp     byte [prev_char], ' '
    je      .skip_add

    mov     ebx, [num]
    add     [sum], ebx

.skip_add:
    mov     dword [num], 0
    mov     byte [in_num], 0
    mov     [prev_char], al
    jmp     .loop

.done:
    cmp     byte [in_num], 1
    jne     .print_sum

    cmp     byte [prev_char], ' '
    je      .print_sum

    mov     ebx, [num]
    add     [sum], ebx

.print_sum:
    PRINT "Сумма: "

    mov eax, dword [sum]
    UNSINT eax

    PUTCHAR 10

    FINISH
