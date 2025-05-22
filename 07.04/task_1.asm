%include "st_io.inc"

; 1.	c=a+b, осуществить  косвенный переход с возвратом, используя jmp для разных значений a и b

section .data
    a dd 5
    b dd 3

section .bss
    c resd 1

section .text
    global _start

_start:
    mov eax, [a]
    mov ebx, [b]

    PRINT "Для значений a = 5, b = 3: "
    PUTCHAR 10
    PRINT "c = "

    push .return1
    jmp add_proc

.return1:
    mov dword [a], 10
    mov dword [b], 20

    mov eax, [a]
    mov ebx, [b]

    PRINT "Для значений a = 10, b = 20: "
    PUTCHAR 10
    PRINT "c = "

    push .return2
    jmp add_proc

.return2:
    FINISH

add_proc:
    add eax, ebx
    mov [c], eax

    UNSINT eax
    PUTCHAR 10

    pop ebx
    jmp ebx