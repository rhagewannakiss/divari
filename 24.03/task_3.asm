%include "st_io.inc"

; 3. Дан массив a, состоящий из слов со знаком. Отсортировать его по
; возрастанию.

section .data
    a         dw -5, 6, -3, 25, -125, 24, 23, 10, 19, 127, 89, 1903, -235
    elem_size equ 2                                ; размер элемента в байтах
    n         equ ($ - a) / elem_size              ; число элементов

section .text
    global _start

_start:
    xor edi, edi          ; i = 0 (внешний цикл)

outer_loop:
    cmp edi, n
    jge print_loop        ; если i >= n, сортировка окончена

    xor ebx, ebx          ; j = 0 (внутренний цикл)

inner_loop:
    mov ax, [a + ebx*2]
    mov dx, [a + ebx*2 + 2]

    cmp ax, dx
    jle no_swap

    mov [a + ebx*2], dx
    mov [a + ebx*2 + 2], ax

no_swap:
    inc ebx

    mov ecx, n
    sub ecx, edi
    dec ecx               ; ecx = n - edi - 1
    cmp ebx, ecx
    jl inner_loop

    inc edi
    jmp outer_loop

print_loop:
    xor ecx, ecx          ; индекс для печати = 0

print_loop1:
    cmp ecx, n
    jge finish_program

    mov ax, [a + ecx*2]
    movsx eax, ax
    SIGNINT eax            ; вывод числа
    PRINT " "            ; пробел-разделитель

    inc ecx
    jmp print_loop1

finish_program:
    FINISH 0
