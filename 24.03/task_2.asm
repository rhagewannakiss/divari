%include "st_io.inc"

; 2. В массиве записаны результаты 20 игр футбольной команды (если игра
; окончилась выигрышем данной команды, то записано число 3,
; вничью— 2, если игра закончилась проигрышем — 1). Заполнить
; массив целыми значениями, лежащими в диапазоне от 1 до 3
; включительно. Определить номера проигранных игр.


section .data
    res_table      dw 3, 1, 2, 3, 3, 1, 1, 2, 1, 3, 1, 2, 3, 2, 3, 2, 2, 3, 1, 3
    res_table_len  equ 20

section .bss
    lost_games     resb 20

section .text
    global _start

_start:
    xor ebx, ebx      ; lost_count = 0
    xor esi, esi      ; i = 0

find_lost_games:
    cmp esi, res_table_len
    jge print_loop

    mov ax, [res_table + esi*2]

    cmp ax, 2
    jge not_lost

    mov [lost_games + ebx], esi
    inc ebx                           ; увеличиваем счётчик проигранных игр

not_lost:
    inc esi
    jmp find_lost_games

print_loop:
    xor ecx, ecx

print_loop_start:
    cmp ecx, ebx
    jge finish_program

    movzx ax, byte [lost_games + ecx]

    inc ax
    movzx eax, ax
    SIGNINT eax
    PRINT " "

    inc ecx
    jmp print_loop_start

finish_program:
    FINISH