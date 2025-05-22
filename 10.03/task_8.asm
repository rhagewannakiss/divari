section .data
    a dd 5           ; Значение a
    b dd 3           ; Значение b
    c dd 10          ; Значение c
    d dd 0           ; Переменная для результата

section .text
    global _start

_start:
    ; Загружаем значения a и b в регистры
    mov ebx, dword [a]
    mov ecx, dword [b]

    ; Сравнение значений a и b
    cmp ebx, ecx
    jg L7            ; Переход, если a > b
    jl L8            ; Переход, если a < b

    ; Если a == b, результат = 0
    xor eax, eax
    jmp L9

L8:
    ; Если a < b → c / (b - a)
    mov edx, dword [c]  ; Загружаем значение c в edx
    mov eax, edx        ; Переносим в eax для деления
    mov edx, 0          ; Очищаем старшую часть делимого (для 64-битного деления)

    sub ecx, ebx        ; b - a
    idiv ecx            ; Делим c на (b - a)
    jmp L9              ; Переход к сохранению результата

L7:
    ; Если a > b → c / (a - b)
    mov edx, dword [c]  ; Загружаем значение c в edx
    mov eax, edx        ; Переносим в eax для деления
    mov edx, 0          ; Очищаем старшую часть делимого

    sub ebx, ecx        ; a - b
    idiv ebx            ; Делим c на (a - b)

L9:
    ; Сохранение результата в d
    mov dword [d], eax

    ; Завершаем программу
    mov eax, 1          ; syscall: sys_exit
    xor ebx, ebx        ; код возврата = 0
    int 0x80            ; вызов ядра Linux
