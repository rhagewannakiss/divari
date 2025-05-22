section .data
    f db "%u",0
    fvv db "%u",0
    fviv db "%u ",0
    ent db "%c",0

section .bss
    n resb 1
    a resw 20
    min resw 1
    max resw 1

section .text
    global main
    extern exit
    extern scanf
    extern printf

section .note.GNU-stack note

main:
    sub rsp,8
    lea esi,[n]
    lea edi,[f]
    xor rax,rax
    push rbx
    push rcx
    call scanf
    pop rcx
    pop rbx
    add rsp,8

    sub rsp,8
    movzx rcx,byte[n]
    xor ebx,ebx

l1:
    push rcx
    sub rsp,8
    lea  esi, [a+ebx*2]
    mov edi, fvv
    xor rax,rax
    call scanf
    add rsp,8
    pop rcx
    inc ebx
    loop l1
;;;;;
    sub rsp,16     ; for min max
    push a
    movzx rax, byte[n]
    push rax
    call proc_min_max
    pop rax
    mov [max], ax
    pop rax
    mov [min],ax
    sub rsp,8
    mov edi,fviv
    movzx esi, word[min]
    xor rax,rax
    call printf
    mov edi,fvv
    movzx esi,word[max]
    xor rax,rax
    call printf
    mov edi,ent
    mov esi,0xa
    xor rax,rax
    call printf
    add rsp,8
    movzx rcx,byte[n]
    mov ebx,0
l2:
    push rcx
    sub rsp,8
    mov edi, fviv
    movzx eax, word[a + ebx*2]
    mov esi,eax
    xor rax,rax
    call printf
    add rsp,8
    pop rcx
    inc ebx
    loop l2
    mov rdi, ent
    mov esi,0xa
    xor rax, rax
    call printf
    xor rdi,rdi
    call exit

proc_min_max:
    push rbp
    sub rsp, 32      ; for min, i_min, max, i_max
    mov rbp,rsp
    mov ax, 65535   ; min
    mov rcx, [rbp + 48]
    xor rbx,rbx
    mov rdi,[rbp + 56]
    rasch_min:
    scasw
    jbe fin
    mov ebx,edi
    sub ebx,2
    mov esi,ebx
    lodsw
fin:
    loop rasch_min
    movzx rax,ax
    mov [rbp + 24], rax     ; min
    mov [rbp + 16], rbx     ; i_min
    mov ax, 0   ; max
    mov rcx, [rbp + 48]
    xor rbx,rbx
    mov rdi, [rbp + 56]

rasch_max:
    scasw
    jae fin1
    mov ebx,edi
    sub ebx,2
    mov esi,ebx
    lodsw

fin1:
    loop rasch_max
    movzx rax,ax
    mov [rbp + 8], rax    ; max
    mov [rbp],rbx
    ;;;;;;;
    mov rbx,[rbp +16]
    mov rax,[rbp + 8]
    mov word[ebx], ax
    mov rbx,[rbp]
    mov rax, [rbp + 24]
    mov word[ebx], ax
    ;;;;
    mov rax,[rbp + 8]
    mov [rbp + 64],rax
    mov rax,[rbp + 24]
    mov [rbp + 72],rax
    add rsp,32
    pop rbp
    ret 16