section .bss
    nwln resb 1
    char resb 1
    string resb 4
section .text
    global _start
_start:
    mov eax, 3
    mov ebx, 0
    mov ecx, char
    mov edx, 1
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, nwln
    mov edx, 1
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, string
    mov edx, 4
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, nwln
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, string
    mov edx, 4
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, char
    mov edx, 1
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80