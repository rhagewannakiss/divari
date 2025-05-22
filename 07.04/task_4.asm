%include "st_io.inc"

; 4.	Оформить в виде процедур с=а+b, и c=a-b.
; Расположить процедуры до и после основной программы.
; Параметры передать через стек. Сформировать стековый фрейм.

section .data
    a dd 10
    b dd 5
    c dd 0

section .text
    global _start

proc_add:
    push ebp
    mov ebp, esp
    sub esp, 16

    mov eax, [ebp + 8]    ; b
    mov ebx, [ebp + 12]   ;a
    add ebx, eax          ; a + b
    mov [ebp + 16], ebx   ; c

    PRINT "a + b = "
    mov eax, [ebp + 16]
    SIGNINT eax
    PUTCHAR 10

    mov esp, ebp
    pop ebp
    ret


_start:
    push dword [a]
    push dword [b]

    call proc_add

    push dword [a]
    push dword [b]

    call proc_sub

    FINISH

proc_sub:
    push ebp
    mov ebp, esp
    sub esp, 16

    mov eax, [ebp + 8]    ;b
    mov ebx, [ebp + 12]   ;a

    sub ebx, eax          ; a - b
    mov [ebp + 16], ebx   ; c

    PRINT "a - b = "
    mov eax, [ebp + 16]
    SIGNINT eax
    PUTCHAR 10

    mov esp, ebp
    pop ebp
    ret