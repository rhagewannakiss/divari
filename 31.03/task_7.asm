%include "st_io.inc"

;7.	Дана строка – арифметическое выражение. Определить правильность расстановки скобок. Выдать на печать YES или NO.

section .data
    a db '(', '(', '(', ')', ')', ')', '(', ')'
    a_len dd 8

    ;неправильно если стек пустой при считывании ')' или если в стэке остаются элеменыты по завершению считывания других
    ;записывать скобки в стэк, ни в коем случае не считать их количество, а удалять скобки

section .text
    global _start

_start:
    xor edx, edx            ;колво элементов в стэке
    xor ecx, ecx            ;длина выражения

loop_start:
    cmp ecx, [a_len]
    jge end_loop

    mov al, [a + ecx]
    cmp al, '('
    je .push_open

    cmp al, ')'
    jne .next_char

    test edx, edx
    jz error

    pop eax
    dec edx
    jmp .next_char

.push_open:
    push eax
    inc edx

.next_char:
    inc ecx
    jmp loop_start

end_loop:
    test edx, edx
    jz correct
    jmp error

correct:
    PRINT "YES"
    PUTCHAR 10
    FINISH

error:
    PRINT "NO"
    PUTCHAR 10
    FINISH