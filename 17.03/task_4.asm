%include "st_io.inc"

; 4.	Напишите программу для умножения двух 32-битных целых без знака.
; В результате должно получиться 64-битное целое без знака.
; Результат записать в ячейку памяти размером 8 байт и выдать на печать как строку символов.

section .data
    result dq 0

section .bss
    res resb 20

section .text
    global _start

_start:
    PRINT "Введите первое число: "
    GETUN eax

    PRINT "Введите второе число: "
    GETUN ebx

    mul ebx        ; edx:eax = eax * ebx

    mov [result], eax
    mov [result+4], edx

    mov ecx, 19           ; ecx = индекс для записи в строку
    mov ebx, 10           ;делитель

loop_meow:
    xor edx, edx
    mov eax, dword [result+4]

    div ebx
    mov [result+4], eax

    mov eax, dword [result]
    div ebx
    mov [result], eax

    add dl, '0'           ; преобразуем остаток в ASCII
    mov byte [res+ecx], dl

    cmp dword [result], 0
    jne loop_mur

    cmp dword [result+4], 0
    je finish

loop_mur:
    loop loop_meow

finish:
    PRINT "Результат: "

    print_hex:

        PUTCHAR byte [res+ecx]
        inc ecx

        cmp ecx, 19
        jne print_hex

    PUTCHAR byte [res + ecx]
    PUTCHAR 10

    FINISH
