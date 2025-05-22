%include "st_io.inc"

; 3.	Необходимо разработать программное обеспечение для карманной электронной игрушки,
; умеющей отгадывать календарные даты (дни рождения). Человек загадывает календарную дату,
; умножает число (номер дня в месяце = X) на 12, прибавляет номер месяца (Y)
; и результат сообщает отгадчику. Отгадчик должен действовать по следующему алгоритму:
; определить остаток R от деления результата на 12, и тогда при R=0 имеем Y=12, в противном случае Y=R.
; Теперь, зная Y, уже легко найти X: из сообщённого результата вычитаем Y и то, что получилось, делим на 12.
;
; Написать программу, работающую в качестве отгадчика.
; Человек вводит результат своих подсчётов, программа выдаёт отгаданную дату XX:YY


section .bss
    date resw 1
    x resb 1
    y resb 1
    r resb 1

section .text
    global _start

_start:

    PRINT "Введите результат: "
    GETUN word [date]
    PUTCHAR 10

    mov ax, [date]    ; из [date] в ax
    xor dx, dx
    mov bx, 12
    div bx            ; ax частное, dx-остаток
    mov [r], dl       ; остаток в r


    cmp byte [r], 0
    je .set_y_to_12   ; y = 12 когда ост. = 0
    mov al, [r]       ; y = r, если ост. != 0
    mov [y], al
    jmp .calculate_x

.set_y_to_12:
    mov byte [y], 12

.calculate_x:
    mov ax, [date]
    mov bl, [y]       ; месяц y в bl
    sub ax, bx        ; ax = ax - y
    xor dx, dx
    mov bx, 12
    div bx            ; ax / bx → ax (частное), dx (остаток)
    mov [x], al       ; день в x

.print_result:
    PRINT "Дата: "

    mov al, [x]
    UNSINT eax
    PRINT ":"

    mov al, [y]
    UNSINT eax
    PUTCHAR 10

    FINISH