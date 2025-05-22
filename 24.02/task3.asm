section .data
    nwln db 10
    st db 'MIPT'
section .text
    global _start
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, st
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, nwln
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, st+1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, nwln
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, st+2
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, nwln
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov ecx, st+3
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80