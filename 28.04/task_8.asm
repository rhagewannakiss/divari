; 8.	В регистре  AX заменить 5 левых битов на 5 правых

%include "st_io.inc"

section .text
    global _start

_start:
    mov ax, 0xF0F0    ; AX = 1111000011110000

    mov bx, ax
    and bx, 0x001F    ; Маска 0000000000011111
    and ax, 0x07FF    ; Маска 0000011111111111

    shl bx, 11
    or ax, bx

    PRINT "AX (dec): "
    movzx eax, ax
    UNSINT eax
    PUTCHAR 0x0A

    PRINT "AX (bin): "
    mov dx, ax
    mov ecx, 16

print_bin_loop:
    shl dx, 1
    jc print_one
    PUTCHAR '0'
    jmp next_bit

print_one:
    PUTCHAR '1'

next_bit:
    dec ecx
    jnz print_bin_loop

    PUTCHAR 10
    FINISH