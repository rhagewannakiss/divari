;4.	Не используя команды умножения ввести без знаковое двоичное
;число, и записать его в регистр AX. Считать, что число задано без ошибок, содержит от 1 до 16 цифр и заканчивается пробелом.

%include "st_io.inc"

section .text
    global _start

_start:
    xor bx, bx

get_num_loop:
    GETCHAR
    cmp al, ' '
    je end_get_num

    sub al, '0'
    shl bx, 1
    or bl, al
    jmp get_num_loop

end_get_num:
    mov ax, bx
    UNSINT eax
    PUTCHAR 10
    FINISH