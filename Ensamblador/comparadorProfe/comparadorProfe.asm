
section .text
global _start

_start: ;etiqueta

    mov si, [num]

    cmp si, 3
    jg mayor

    mov rsi, strMenor
    mov rdx, tamStrMenor
    mov rax, 1
    mov rdi, 1  ;salida estándar
    syscall     ;imprimir

    jmp salir

mayor:
    mov rsi, strMayor
    mov rdx, tamStrMayor
    mov rax, 1
    mov rdi, 1      ;salida estándar
    syscall         ;imprimir

salir:
    mov rax, 60
    mov rdi, 0
    syscall         ;salir