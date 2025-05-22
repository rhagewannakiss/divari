; Транспонирование матрицы (3х3 двойные слова без знака)

%include "st_io.inc"

section .data
    a dd 2, 3, 5,
      dd 7, 4, 3,
      dd 7, 1, 5

section .bss
    s_trans resd 9

section .text
    global _start

_start:
    xor ecx, ecx           ;ecx = номер строки (i)

outer_loop:
    cmp ecx, 3
    jge done_transpose
    xor edx, edx            ; edx = 6номер столбца (j)

inner_loop:
    cmp edx, 3
    jge next_outer

    mov eax, ecx
    imul eax, 3           ; eax = i * 3
    add eax, edx          ; eax = i*3 + j
    shl eax, 2
    mov ebx, [a + eax]    ; ebx = a[i*3+j]

    mov eax, edx
    imul eax, 3           ; eax = j * 3
    add eax, ecx          ; eax = j*3 + i
    shl eax, 2

    mov [s_trans + eax], ebx
    inc edx

    jmp inner_loop

next_outer:
    inc ecx

    jmp outer_loop

done_transpose:
    xor ecx, ecx

print_outer:
    cmp ecx, 3
    jge finish

    mov edx, 0

print_inner:
    cmp edx, 3
    jge new_line

    mov eax, ecx
    imul eax, 3
    add eax, edx
    shl eax, 2

    mov ebx, [s_trans + eax]

    mov eax, ebx
    UNSINT eax
    PRINT " "

    inc edx

    jmp print_inner

new_line:
    PUTCHAR 10
    inc ecx
    jmp print_outer

finish:
    PUTCHAR 10
    FINISH
