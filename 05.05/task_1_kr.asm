;Переписать полученные данные в обратно в массив, в исходном порядке, распечатать значения полученного массива,
;Дан массив из 10 элементов, размер 1 байт со знаком. Ввести элементы массива, используя функцию scanf, записать числа из массива в стек,
;Если двух отрицательных элементов в массиве нет, вывести на печать, используя функцию printf, сообщение “NO”.  Перевести строку.
;найти первые два отрицательных и поменять их местами, не вынимая из стека.
;
;используя функцию printf, в одной строке через пробел. Перевести строку.
;Архитектура 64-х разрядная
;Обратите внимание, что вынимать элементы из стека, можно только для печати.
;
;1 -6 7 -10 9 8 -3 2 5 4
;Пример:
;4 5 2 -10 8 9 -3 7 -6 1

section .note.GNU-stack note

section .data
    fmt_in db "%d", 0
    fmt_out db "%d ", 0
    fmt_no db "NO", 10, 0

section .bss
    a resb 10

section .text
    global main
    extern printf
    extern scanf
    extern exit

main:
    ; выделяем место на стеке под сохранение rbp
    push rbp
    sub rsp, 8

    ; Ввод 10 элементов массива (signed byte)
    mov rcx, 10
    mov rsi, a
read_loop:
    lea rdi, [fmt_in]
    xor rax, rax
    call scanf
    inc rsi
    loop read_loop

    ; Копируем элементы в стек, одновременно ищем два отрицательных
    ; Используем rbx как индекс массива, rcx как счетчик
    xor rbx, rbx
    mov rcx, 10
    mov rsi, -1        ; индекс первого отрицательного
    mov rdi, -1        ; индекс второго отрицательного
    mov rdx, 0         ; текущий индекс в стеке

store_loop:
    movsx ax, byte [a + rbx]
    push ax

    ; если элемент отрицательный — сохраняем индексы
    cmp ax, 0
    jge .not_negative

    cmp rsi, -1
    jne .check_second
    mov rsi, rdx
    jmp .next
.check_second:
    cmp rdi, -1
    jne .next
    mov rdi, rdx

.next:
.not_negative:
    inc rbx
    inc rdx
    loop store_loop

    ; проверка: если не нашли два отрицательных — печатаем "NO"
    cmp rsi, -1
    je .print_no
    cmp rdi, -1
    je .print_no

    ; меняем местами два отрицательных элемента в стеке
    ; стек начинается с вершины, значит адрес: [rbp - offset]
    ; каждый элемент занимает 2 байта (push ax)

    ; вычисляем адреса нужных элементов в стеке
    ; стек рос вниз, поэтому: адрес = rsp + 2 * индекс
    mov rbx, rsp
    mov rcx, rsi
    mov rdx, rdi
    imul rcx, 2
    imul rdx, 2

    mov ax, word [rbx + rcx]
    mov bx, word [rbx + rdx]
    mov word [rbx + rcx], bx
    mov word [rbx + rdx], ax

    ; Запись обратно из стека в массив в обратном порядке (так как стек — LIFO)
    mov rcx, 10
    lea rdi, [a + 9]    ; последняя ячейка
write_back:
    pop ax
    mov [rdi], al
    dec rdi
    loop write_back

    ; Печать массива
    mov rcx, 10
    xor rbx, rbx
print_loop:
    movsx rsi, byte [a + rbx]
    lea rdi, [fmt_out]
    xor rax, rax
    call printf
    inc rbx
    loop print_loop
    jmp .exit

.print_no:
    lea rdi, [fmt_no]
    xor rax, rax
    call printf

.exit:
    add rsp, 8
    pop rbp
    xor rax, rax
    call exit
