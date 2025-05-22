section .text
    global _start

_start:
    mov eax, l
    jmp eax
m:
    mov eax, 1
    mov ebx, 0
    int 0x80

l:
    jmp m


