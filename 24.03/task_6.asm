%include "st_io.inc"

; 6. Найти минимальный и максимальный элементы матрицы и вывести их
; значения, номер строки и столбца, в которых они находится.

section .data
    a dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    rows equ 4
    cols equ 3

section .bss
    min resw 1
    max resw 1
    min_row resd 1
    min_col resd 1
    max_row resd 1
    max_col resd 1

section .text
    global _start

_start:
    mov ax, [a]
    mov [min], ax
    mov [max], ax

    mov dword [min_row], 0
    mov dword [min_col], 0
    mov dword [max_row], 0
    mov dword [max_col], 0

    xor edi, edi                 ; индекс строки (i)

row_loop:
    cmp edi, rows
    jge print_result

    xor esi, esi                 ; индекс столбца (j)

col_loop:
    cmp esi, cols
    jge next_row

    mov eax, edi
    imul eax, cols
    add eax, esi
    movzx ebx, word [a + eax*2]

    cmp bx, [min]
    jge check_max
    mov [min], bx
    mov [min_row], edi
    mov [min_col], esi

check_max:
    cmp bx, [max]
    jle next_element
    mov [max], bx
    mov [max_row], edi
    mov [max_col], esi

next_element:
    inc esi
    jmp col_loop

next_row:
    inc edi
    jmp row_loop

print_result:
    PRINT "Минимальный элемент: "

    movsx eax, word [min]
    SIGNINT eax

    PRINT " (Строка "
    mov eax, [min_row]
    inc eax
    UNSINT eax

    PRINT ", Столбец "
    mov eax, [min_col]
    inc eax
    UNSINT eax

    PRINT ")"
    PUTCHAR 10

    PRINT "Максимальный элемент: "
    movsx eax, word [max]
    SIGNINT eax

    PRINT " (Строка "
    mov eax, [max_row]
    inc eax
    UNSINT eax

    PRINT ", Столбец "
    mov eax, [max_col]
    inc eax
    UNSINT eax

    PRINT ")"
    PUTCHAR 10

    FINISH