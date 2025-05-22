%include "st_io.inc"


;6.	Вычислить значение z
;
;z=10*a/(a+b)+10*b/(c+d)
;
;a, b, c – байт со знаком
;d        -  слово со знаком


section .bss
    a resb 1
    b resb 1
    c resb 1
    d resw 1

    sum_ab resw 1
    sum_cd resw 1


section .text
    global _start

_start:
    PRINT "Введите a: "
    GETSIG byte [a]

    PRINT "Введите b: "
    GETSIG byte [b]

    PRINT "Введите c: "
    GETSIG byte [c]

    PRINT "Введите d: "
    GETSIG byte [d]

    PUTCHAR 10

    movsx ax, byte [a]
    movsx bx, byte [b]
    add ax, bx
    mov [sum_ab], ax               ; ebx = a + b

    PRINT "a + b = "
    SIGNINT [sum_ab]
    PUTCHAR 10

    movsx eax, byte [a]         ; eax = a
    mov ecx, 10                 ; ecx = 10
    imul ecx                    ; eax = 10 * a

    PRINT "10 * a = "
    SIGNINT eax
    PUTCHAR 10

    cdq                         ; расширяем
    idiv ebx                    ; eax = eax / ebx = 10 * a / (a + b)

    PRINT "10 * a / (a + b) = "
    SIGNINT eax
    PUTCHAR 10

    mov esi, eax                ;записали в edx = 10 * a / (a + b)

    movsx eax, byte [c]
    movsx ebx, word [d]
    add eax, ebx
    mov ebx, eax                ; ebx = c + d

    PRINT "c + d = "
    SIGNINT ebx
    PUTCHAR 10

    movsx eax, byte [b]         ; eax = b
    mov ecx, 10                 ;ecx = 10
    imul ecx                    ; eax = eax *ecx = 10 * b

    PRINT "10 * b = "
    SIGNINT eax
    PUTCHAR 10

    cdq                         ; расширяем
    idiv ebx                    ;eax = eax / ebx = 10 * b / (c + d)

    PRINT "10 * b / (c + d) = "
    SIGNINT eax
    PUTCHAR 10
    PUTCHAR 10


    add eax, esi                ;eax = 10 * a/ (a + b) + 10 * b / (c + d)

    PRINT "Z = "
    SIGNINT eax
    PUTCHAR 10

    FINISH