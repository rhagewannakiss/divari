; 3.	Удалить из стека нулевые   слова, «сжав» его, дополнительный массив не использовать.
%include "st_io.inc"

section .data
    a dw 7, 0, 9, 0
    a_len dd 4

section .text
    global _start

_start:
    mov ecx, [a_len]
    mov esi, a
    lea esi, [esi + ecx*2 - 2]


loop1:
    mov ax, [esi]
    push ax
    sub esi, 2
    loop loop1

    xor ebx, ebx
    mov ecx, [a_len]

process:
    pop ax
    cmp ax, 0
    je .skip

    push ax
    inc ebx

.skip:
    add ebx, 1
    jnz process

    mov ebp, esp

    xor ecx, ecx

reverse_stack:
    cmp esp, ebp
    je .reverse_done

    pop ax
    push ecx
    mov ecx, eax
    xor eax, eax
    push eax
    mov eax, ecx
    inc ecx
    jmp reverse_stack
.reverse_done:
    mov ecx, ebx                ; Количество ненулевых элементов

; Вывести результат
    PRINT "result: "

output:
    test ecx, ecx
    jz .end
    pop ax
    movsx eax, ax
    SIGNINT eax
    PUTCHAR ' '
    dec ecx
    jmp output

.end:
    PUTCHAR 10
    FINISH