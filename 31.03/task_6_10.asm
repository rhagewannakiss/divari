%include "st_io.inc"

; 6.	Найти сумму положительных и отрицательных элементов матрицы.
; Передать массив по адресу, количество строк и столбцов по значению через стек.
; Возврат полученных значений передать через стек. Обязательно использовать локальные переменные.

section .data
    matrix dd 1, -2, 3,   -7, 5, -6,    1, 2, 5
    rows dd 3
    cols dd 3
    sum_pos dd 0
    sum_neg dd 0

section .text
    global _start

_start:
    sub esp, 20                 ;

    push dword [cols]
    push dword [rows]
    push matrix
    push sum_pos
    push sum_neg

    call sum_matrix

    add esp, 20                 ;

    SIGNINT [sum_pos]
    PUTCHAR 10
    SIGNINT [sum_neg]
    PUTCHAR 10
    FINISH

sum_matrix:
    push ebp
    mov ebp, esp
    sub esp, 16

    ;локальные переменные
    mov dword [ebp - 4], 0   ;сумма отриц.
    mov dword [ebp - 8], 0  ; сумма полож.

    ;аргументы
    mov ecx, [ebp+16]       ; адрес матрицы
    mov edx, [ebp+20]       ;  строки
    mov esi, [ebp+24]       ;  столбцы

    xor edi, edi            ;i

.row_loop:
    cmp edi, edx
    jge .end_row_loop

    xor ebx, ebx             ;j

.column_loop:
    cmp ebx, esi
    jge .end_column_loop

    mov eax, edi            ; i
    imul eax, esi           ; i * cols
    add eax, ebx            ; i * cols + j
    mov eax, [ecx + eax*4]

    cmp eax, 0
    jl .negative

.positive:
    add [ebp - 4], eax
    jmp .next_element

.negative:
    add [ebp-8], eax

.next_element:
    inc ebx
    jmp .column_loop

.end_column_loop:
    inc edi
    jmp .row_loop

.end_row_loop:
    mov eax, [ebp+12]       ;
    mov ebx, [ebp-4]
    mov [eax], ebx

    mov eax, [ebp+8]
    mov ebx, [ebp-8]
    mov [eax], ebx

    mov esp, ebp
    pop ebp
    ret