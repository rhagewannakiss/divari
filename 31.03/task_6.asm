%include "st_io.inc"

;6.	Записать в регистры общего назначения, какие-нибудь данные. Затем, используя команду PUSHAD записать в стек значения регистров,
; поменять значения регистра EBX, затем извлечь их из стека и проверить изменилось ли значение EBX.

section .text
    global _start

;mov ebx, 95
;это нужно было сделать в стеке, и после popad это значение должно было быть в ebx

;pushad    -      заносит в СТЕК содержимое регистров EAX, ECX, EDX, EBX, ESP, EBP, EDI, ESI



_start:
    mov eax, 10
    mov ebx, 52
    mov ecx, 77
    mov edx, 65

    PRINT "Изначальное значение ebx: "
    UNSINT ebx
    PUTCHAR 10

    pushad

    PRINT "После PUSHAD: "
    UNSINT ebx
    PUTCHAR 10

    mov dword [esp + 16], 92

    popad

    PRINT "После POPAD: "
    UNSINT ebx
    PUTCHAR 10

    FINISH

