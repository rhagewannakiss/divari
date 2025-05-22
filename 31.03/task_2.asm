; 2.	Определить сколько среди них нулевых и записать ответ в регистр al.
%include "st_io.inc"

section .data
    shit    dw 99, 99, 99, 99, 99
    a       dw 1, 0, 0, 6, 3, 5, 0, 4, 6, 0, 0, 0, 9
    a_len   equ ($ - a)
    ; a_len = 13 * 2
    hlen    equ a_len / 2

section .text
    global _start

_start:
    mov ecx, hlen
    mov esi, a + a_len - 2  ; Указатель на последний элемент

push_loop:
    mov ax, [esi]
    push ax
    sub esi, 2
    loop push_loop

    mov ecx, hlen
    xor eax, eax                ; eax = 0 (счётчик нулей)

count_loop:
    pop dx
    cmp dx, 0
    jne skip
    inc al

skip:
    loop count_loop             ; Повторяем для всех элементов


    PRINT "Количество нулевых элементов: "
    movzx eax, al
    UNSINT eax
    PUTCHAR 10
    FINISH