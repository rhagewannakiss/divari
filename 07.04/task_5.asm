%include "st_io.inc"

; 5.	Найти мин эл-т массива, оформить в виде процедуры – параметры по адресу. Сформировать стековый фрейм.

section .data
    a      dd 7, -3, 12, 0, 45, -8, -7, 68, -30
    a_size equ ($ - a)
    a_len  equ (a_size / 4)

section .text
    global _start

_start:
    push a_len
    push a

    call find_min

    FINISH

find_min:
    push ebp
    mov ebp, esp
    sub esp, 16

    mov ecx, [ebp + 8]   ; a
    mov esi, [ebp + 12]  ; a_len

    mov eax, [ecx]
    mov [ebp - 4], eax   ;текущий минмум
    mov dword [ebp - 8], 1   ; i = 1

.loop:
    mov edx, [ebp - 8] ; i
    cmp edx, esi   ;сравниваем итекущий индекс и длину
    jge .exit

    mov eax, [ecx + edx*4]   ; a[index]
    cmp eax, [ebp - 4]
    jge .next

    mov [ebp - 4], eax

.next:
    inc dword [ebp - 8]     ;edx+1 == i++
    jmp .loop

.exit:
    mov eax, [ebp - 4]
    PRINT "минимальный элемент: "
    SIGNINT eax
    PUTCHAR 10

    mov esp, ebp
    pop ebp
    ret
