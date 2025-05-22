%include "st_io.inc"

; сформировать вектор b, элементы которого - суммы элементов соответствующей строки матрицы A

section .data
    a dw 1, 2, 3, 4, 5, 6, 7, 8, 9
    rows equ 3
    cols equ 3

section .bss
    b resw rows

section .text
    global _start

_start:
    xor edi, edi

row_loop:
    cmp edi, rows
    jge print_matrix

    xor eax, eax
    xor esi, esi

col_loop:
    cmp esi, cols
    jge store_b

    mov ebx, edi
    imul ebx, cols

    add ebx, esi
    shl ebx, 1

    mov cx, [a + ebx]
    movsx ecx, cx

    add eax, ecx
    inc esi
    jmp col_loop

store_b:
    mov bx, ax
    mov [b + edi*2], bx
    inc edi
    jmp row_loop

print_matrix:
    PRINT "Матрица A:"
    PUTCHAR 10
    xor edi, edi

print_matrix_row:
    cmp edi, rows
    jge print_vector
    xor esi, esi

print_matrix_col:
    cmp esi, cols
    jge newline_after_row

    mov ebx, edi
    imul ebx, cols
    add ebx, esi
    shl ebx, 1

    mov cx, [a + ebx]
    movsx eax, cx
    SIGNINT eax
    PRINT " "

    inc esi
    jmp print_matrix_col

newline_after_row:
    PUTCHAR 10
    inc edi
    jmp print_matrix_row

print_vector:
    PUTCHAR 10
    PRINT "Вектор b:"
    PUTCHAR 10
    xor edi, edi

print_vector_loop:
    cmp edi, rows
    jge finish_program

    mov ax, [b + edi*2]
    movsx eax, ax
    SIGNINT eax
    PRINT " "

    inc edi
    jmp print_vector_loop

finish_program:
    PUTCHAR 10
    FINISH
