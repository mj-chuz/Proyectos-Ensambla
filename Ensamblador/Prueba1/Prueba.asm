section .data

    a: dw -1, 0, 5, 01, 0x02, 0x0AA
    b: db 01, 02, 03, "hola"
    c: dw 6
    


section .text
global _start

_start:
    mov word bx, [a]
    mov word cx, [c] ;o pudo haber sido mov cx, 6
    mov rdx, 1

    ciclo:
        cmp bx, 4
        jge suma
        jmp else
        suma:
            ;add ax, [a+rdx*2]
            add ax, bx
        else:
            mov word bx, [a+rdx*2]
            inc rdx
    loop ciclo


    mov rcx, rax
    mov rax, 60
    mov rdi, 0
    syscall
