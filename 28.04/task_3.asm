;3.	Перевернуть содержимое регистра AX. (поменять местами al и ah)
%include "st_io.inc"

section .text
    global _start

_start:
    ; Исходное значение AX
    mov ax, 0b1111000010101010  ; AX = 1111000010101010 (61610 в dec)

    ; Вывод исходного AX в двоичной системе
    PRINT "Исходный AX (bin): "
    movzx edx, ax
    mov ecx, 16
print_original:
    shl edx, 1
    jc original_one
    PUTCHAR '0'
    jmp original_next
original_one:
    PUTCHAR '1'
original_next:
    dec ecx
    jnz print_original
    PUTCHAR 0x0A

    ; Переворот битов AX
    mov ecx, 16
    xor edx, edx        ; EDX для хранения перевернутых битов

reverse_loop:
    shl ax, 1           ; Старший бит AX -> CF
    rcr edx, 1          ; CF -> старший бит EDX
    loop reverse_loop

    ; Сохраняем результат (16 младших бит EDX -> AX)
    mov ax, dx

    ; Вывод перевернутого AX в двоичной системе
    PRINT "Перевернутый AX (bin): "
    movzx edx, ax
    mov ecx, 16
print_result:
    shl edx, 1
    jc result_one
    PUTCHAR '0'
    jmp result_next
result_one:
    PUTCHAR '1'
result_next:
    dec ecx
    jnz print_result

    PUTCHAR 0x0A
    FINISH