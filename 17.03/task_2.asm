%include "st_io.inc"

; Найти сумму отрицательных элементов одномерного массива из 20 элементов,
; пропустив первые k элементов. Значение k вводится пользователем.

section .data
    array db 5, -34, 25, 3, -6, -7, -22, 5,0 ,3, 6, 234, 5, -3, -6, -73, 7, 98, -3,-1
    array_size equ $ - array

section .bss
    min resb 1
    max resb 1
    sum resd 1
    count resd 1
    k resd 1

section .text
    global _start

_start:
    PRINT "Введите значение k: "
    GETUN [k]

    mov eax, [k]        ;k не выходит за границы массива
    cmp eax, array_size
    jge end_invalid_k

    mov al, [array + eax]
    mov [min], al
    mov [max], al
    xor eax, eax
    mov [sum], eax
    mov [count], eax

    mov ecx, array_size
    sub ecx, [k]
    mov edx, [k]

process_array:
    cmp ecx, 0
    je end_processing

    mov al, [array + edx]

    cmp al, [min]
    jge check_max

    mov [min], al

check_max:
    cmp al, [max]
    jle check_negative

    mov [max], al

check_negative:
    cmp al, 0
    jge next_element

    movsx eax, al
    add dword [sum], eax
    inc dword [count]

next_element:
    inc edx
    dec ecx
    jmp process_array

end_processing:
    PRINT "Сумма отрицательных элементов: "
    mov eax, dword [sum]
    SIGNINT eax
    PUTCHAR 10

    PRINT "Количество отрицательных элементов: "
    mov eax, dword [count]
    UNSINT eax
    PUTCHAR 10

    FINISH

end_invalid_k:
    PRINT "Ошибка: значение k выходит за границы массива!"
    PUTCHAR 10
    FINISH
