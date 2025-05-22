%include "st_io.inc"

; 4.	Содержит ли введенное число цифру 5?
; Байт, число без знака ( или – слово без знака, количество цифр числа неизвестно).

section .bss
    number resw 1
    flag resb 1         ; 0 - нет цфиры 5, 1 - есть

section .text
    global _start

_start:
    PRINT "Введите число: "
    GETUN word [number]
    PUTCHAR 10

    mov ax, [number]
    mov byte [flag], 0

check_loop:
    cmp ax, 0            ; если число = 0 -> выходим из цикла
    je check_done
    mov bx, 10
    xor dx, dx
    div bx               ; ax = ax / 10, dx = остаток, т.е. последняя цифра числа
    cmp dx, 5
    je found_five        ; если найденное число = 5 -> flag = 1
    jmp check_loop       ; если же нет, то возвращаемся в начало цикла и проверяем следующую цифру числа

found_five:
    mov byte [flag], 1
    jmp check_done

check_done:
    cmp byte [flag], 1
    je print_yes
    PRINT "Нет цифры 5"
    jmp end_program

print_yes:
    PRINT "Есть цифра 5"

end_program:
    PUTCHAR 10
    FINISH