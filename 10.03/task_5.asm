%include "st_io.inc"

; 5. T время в секундах от начала суток, переменной k присвоить значение: T+1.
; (часы всегда <24) и выдать на печать в виде чч:мм:сек.

section .bss
    k resd 1
    hours resb 1
    minutes resb 1
    seconds resb 1

section .text
    global _start

_start:
    PRINT "Введите время в секундах от начала суток: "
    GETUN [k]

    mov eax, [k]


    cmp eax, 86400          ;если >= 86400, то это новый день
    jl .calc_time
    sub eax, 86400

.calc_time:

    mov ebx, 3600
    xor edx, edx
    div ebx
    mov [hours], al

    mov eax, edx
    mov ebx, 60
    xor edx, edx
    div ebx
    mov [minutes], al
    mov [seconds], dl

    inc byte [seconds]      ; теперь увеличили k на 1


    cmp byte [seconds], 60  ; еси секунд >= 60
    jl .check_minutes
    mov byte [seconds], 0
    inc byte [minutes]      ; увеличиваем минуты на 1

.check_minutes:
    cmp byte [minutes], 60  ; если минут >= 60
    jl .check_hours
    mov byte [minutes], 0
    inc byte [hours]        ; увеличиваем часы на 1

.check_hours:
    cmp byte [hours], 24    ; если часов >= 24
    jl .print_result
    mov byte [hours], 0     ; часы = 0

.print_result:
    PRINT "Результат: "
    movzx eax, byte [hours]
    UNSINT eax
    PUTCHAR ':'

    movzx eax, byte [minutes]
    UNSINT eax
    PUTCHAR ':'

    movzx eax, byte [seconds]
    UNSINT eax
    PUTCHAR 10

    FINISH
