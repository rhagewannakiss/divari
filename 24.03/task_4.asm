%include "st_io.inc"

; 4. Найти произведение двух матриц


section .data
    first_matrix  dw 3,6,0, 0,6,2, 1,5,9
    second_matrix dw 2,4,5, 1,2,6, 3,5,7

section .bss
    result_matrix resw 9

section .text
    global _start

_start:
    xor edi, edi

row_loop:
    cmp edi, 3
    jge print_result

    xor esi, esi

col_loop:
    cmp esi, 3
    jge next_row

    xor eax, eax
    xor ebx, ebx

k_loop:
    cmp ebx, 3
    jge store_result


    mov edx, edi
    imul edx, 3
    add edx, ebx
    mov cx, [first_matrix + edx*2]
    movsx ecx, cx

    mov edx, ebx
    imul edx, 3
    add edx, esi
    mov dx, [second_matrix + edx*2]
    movsx edx, dx

    imul ecx, edx
    add eax, ecx

    inc ebx
    jmp k_loop

store_result:
    mov edx, edi
    imul edx, 3
    add edx, esi
    mov [result_matrix + edx*2], ax

    inc esi
    jmp col_loop

next_row:
    inc edi
    jmp row_loop

print_result:
    xor edi, edi

print_row1:
    cmp edi, 3
    jge .print_row2_pch
    movsx eax, word [result_matrix + edi*2]      ; Загрузка элемента
    SIGNINT eax                                   ; Вывод знакового числа
    PRINT " "
    inc edi
    jmp print_row1

.print_row2_pch:
    PUTCHAR 10
    jmp print_row2

print_row2:
    cmp edi, 6
    jge .print_row3_pch
    movsx eax, word [result_matrix + edi*2]
    SIGNINT eax
    PRINT " "
    inc edi
    jmp print_row2

.print_row3_pch:
    PUTCHAR 10
    jmp print_row3

print_row3:
    cmp edi, 9
    jge finish
    movsx eax, word [result_matrix + edi*2]
    SIGNINT eax
    PRINT " "
    inc edi
    jmp print_row3

finish:
    PUTCHAR 10
    FINISH