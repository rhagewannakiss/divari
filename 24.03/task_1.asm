; В заданном массиве поменять местами наибольший и наименьший элементы

%include "st_io.inc"

section .data
    a     dw 0, 1, 1, 2, 2, 2, 4, 3, 3, 9, 34, 2, -8, 2, 4, 89
    a_bytes_len equ $ - a

section .bss
    max_index resd 1
    min_index resd 1

section .text
    global _start

_start:
    mov ax, [a]         ; первый элемент
    mov bx, ax          ; текущее значение максимума
    mov dx, ax          ;  текущее значение минимума

    mov dword [max_index], 0
    mov dword [min_index], 0

    mov ecx, a_bytes_len
    shr ecx, 1

    mov esi, 1          ; индекс i = 1

find_min_max:
    cmp esi, ecx
    jge swap_elements   ; если i >= число элементов, переходим к обмену

    mov ax, [a + esi*2]

    cmp ax, bx
    jle check_min

    mov bx, ax
    mov [max_index], esi

check_min:
    cmp ax, dx
    jge next_iter

    mov dx, ax
    mov [min_index], esi

next_iter:
    inc esi
    jmp find_min_max

swap_elements:
    mov esi, [max_index]
    mov edi, [min_index]

    mov ax, [a + esi*2]
    mov cx, [a + edi*2]

    mov [a + esi*2], cx
    mov [a + edi*2], ax

    mov ecx, 0

print_loop:
    cmp ecx, a_bytes_len
    jge finish_program

    mov ax, [a + ecx]
    movsx eax, ax
    SIGNINT eax
    PRINT " "

    add ecx, 2          ; переходим к следующему элементу (2 байта)
    jmp print_loop

finish_program:
    FINISH












