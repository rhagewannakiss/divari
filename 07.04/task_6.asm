%include "st_io.inc"
; 6.	Найти сумму положительных и отрицательных элементов матрицы.
; Передать массив по адресу, количество строк и столбцов по значению через стек.
; Возврат полученных значений передать через стек.
; Обязательно использовать локальные переменные.

section .data
    a       dd 1,2,3, 0,-6,-3, 2,5,6
    a_clmns dd 3
    a_rows  dd 3

section .text
    global _start

_start:
    push a_rows
    push a_clmns
    push a

    call find_sum_pos
    call find_sum_neg

    FINISH

find_sum_neg:
    push ebp
    mov ebp, esp
    sub esp, 16



    mov esp, ebp
    pop ebp
    ret