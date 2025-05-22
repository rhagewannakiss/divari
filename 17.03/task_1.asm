%include "st_io.inc"

;1.	Выдать на печать max число, факториал которого помещается в db, dw, dd и его факториал.

section .text
    global _start

_start:
    mov al, 1
    mov bl, 1

db_factorial:
    mul bl
    jc print_db   ;переход если CF=1

    inc bl

    jmp db_factorial

print_db:
    PRINT "Максимальное число, факториал которого помещается в db: "
    dec bx

    movzx eax, bx
    UNSINT eax
    PUTCHAR 10

    mov bx, 1
    mov ax, 1

dw_factorial:
    mul bx
    jc print_dw

    inc bx

    jmp dw_factorial

print_dw:
    PRINT "Максимальное число, факториал которого помещается в dw: "
    dec bx

    movzx eax, bx
    UNSINT eax
    PUTCHAR 10

    mov ebx, 1
    mov eax, 1

dd_factorial:
    mul ebx
    jc print_dd

    inc ebx

    jmp dd_factorial

print_dd:
    PRINT "Максимальное число, факториал которого помещается в dd: "
    dec ebx

    mov eax, ebx
    UNSINT eax
    PUTCHAR 10

    FINISH