%include "st_io.inc"

;3.	В одномерном массиве   найти: min, max, ∑ <0, и их кол-во, рассмотреть элементы массива, до первого 0.

section .data
    array db -2, 4, 0, -2, 6, -4, 6, 2, -3, 5, 6, 26, 0, 3, 2, 7, 5, 3

section .text
    global _start

_start:
    xor edx, edx

find_zero:
    cmp byte [array + edx], 0
    je zero_found
    inc edx
    cmp edx, 17
    jb find_zero

zero_found:
    test edx, edx
    jz exit_loop

    movsx eax, byte [array]

    mov ebx, eax                ; Минимум (ebx)
    mov edi, eax                ; Максимум (edi)

    xor esi, esi                ; Сумма отрицательных (esi)
    xor ebp, ebp                ; Количество отрицательных (ebp)

    test eax, eax
    jns prepare_loop
    add esi, eax
    inc ebp

prepare_loop:
    mov ecx, edx
    dec ecx
    jz exit_loop

    mov edx, 1

process_loop:
    movsx eax, byte [array + edx]

    cmp eax, ebx
    jge check_max
    mov ebx, eax

check_max:
    cmp eax, edi
    jle check_negative
    mov edi, eax

check_negative:
    test eax, eax
    jns next
    add esi, eax
    inc ebp

next:
    inc edx
    test eax, eax               ; ZF=0 (eax != 0)
    loopne process_loop         ; уменьшаем ecx на 1, переход если ecx != 0 и ZF=0

exit_loop:
    PRINT "Минимальное значение: "
    SIGNINT ebx
    PUTCHAR 10

    PRINT "Максимальное значение: "
    SIGNINT edi
    PUTCHAR 10

    PRINT "Сумма отрицательных чисел: "
    SIGNINT esi
    PUTCHAR 10

    PRINT "Количество отрицательных чисел: "
    UNSINT ebp
    PUTCHAR 10

    FINISH