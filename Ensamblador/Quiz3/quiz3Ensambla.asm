;Maria Jesus Vargas Medrano - B98243

section .text

global multiplicacion

multiplicacion:
    mov ax, di
    mov cx, 0
    call calcularPotencia
    cmp bx, si
    jne suma
    shl ax, cl
    ret

calcularPotencia: ;Calcula la potencia de 2 del segundo numero
    mov bx, 1
    inc cx
    shl bx, cl
    cmp bx, si
    jl calcularPotencia
    ret

suma: ;Si el numero no es potencia de 2, se realiza la suma
    dec cl
    shl ax, cl
    mov bx, 1
    shl bx, cl
    sub si, bx
    mov cx, si   
    ciclo:
        add ax, di
    loop ciclo
    ret
    
