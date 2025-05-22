%include "st_io.inc"

; 7.	 Определить помещается ли произведение в размер, отведенный для сомножителей


section .bss
    a resd 1
    b resd 1
    result resd 1

section .text
    global _start

_start:
    PRINT "Введите первое число: "
    GETSIG [a]

    PRINT "Введите второе число: "
    GETSIG [b]

    mov eax, [a]
    mov ebx, [b]

    imul ebx             ; рез. будет в eax, возможное переполнение в edx

    jc .overflow         ; если cf = 1, то переполнение
    jo .overflow         ; если of= 1, то переполнение


    mov [result], eax
    PRINT "Произведение: "
    SIGNINT [result]
    PUTCHAR 10
    jmp .end

.overflow:
    PRINT "Произведение не помещается в регистр!"
    PUTCHAR 10

.end:
    FINISH
