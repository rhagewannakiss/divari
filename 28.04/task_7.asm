%include "st_io.inc"

; 7.	Записать в регистр CL байт, составленный из 4 левых битов регистра AL и 4 правых битов регистра BL.


section .text
    global _start

_start:
    mov al, 0xA5      ; AL = 10100101 (4 левых бита: 1010)
    mov bl, 0x3C      ; BL = 00111100 (4 правых бита: 1100)

    ; Формируем CL
    mov cl, al
    shr cl, 4         ; 00001010
    and cl, 0x0F

    mov dl, bl
    and dl, 0x0F      ; Маска 00001111: 00001100

    shl cl, 4         ; 10100000
    or cl, dl         ; 10101100

    ; CL в десятичной системе
    PRINT "CL (dec): "
    movzx eax, cl
    UNSINT eax
    PUTCHAR 10

    ;CL в двоичной системе
    PRINT "CL (bin): "
    mov dl, cl
    mov ecx, 8

print_bin_loop:
    shl dl, 1
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