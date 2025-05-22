%include "st_io.inc"

;11 - №5
;Нужно было поменять порядок рассмотрения элементов строки
;Зачтено с дисконтом

;5.	Скопировать 4 последних элемента массива A[10] в последние 4 элемента B[10] – dw, без знака.

section .data
    A dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    B dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

section .text
    global _start

_start:
    PRINT "Before copy:"
    PUTCHAR 10

    lea ebx, [A]
    mov ecx, 10

printAbefore:
    movzx eax, word [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 2
    sub ecx, 1

    cmp ecx, 0
    jne printAbefore

    PUTCHAR 10

    lea ebx, [B]
    mov ecx, 10

printBbefore:
    movzx eax, word [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 2
    sub ecx, 1

    cmp ecx, 0
    jne printBbefore

    PUTCHAR 10
    PUTCHAR 10


    lea esi, [A+12]
    lea edi, [B+12]

    mov ecx, 4
    repe movsw

    lea ebx, [A]
    mov ecx, 10

    PRINT "After copy:"
    PUTCHAR 10

printAafter:
    movzx eax, word [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 2
    sub ecx, 1

    cmp ecx, 0
    jne printAafter

    PUTCHAR 10

    lea ebx, [B]
    mov ecx, 10

printBafter:
    movzx eax, word [ebx]

    SIGNINT dword eax
    PUTCHAR ' '

    add ebx, 2
    sub ecx, 1

    cmp ecx, 0
    jne printBafter

    PUTCHAR 10
    FINISH