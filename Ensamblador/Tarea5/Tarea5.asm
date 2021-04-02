;Tarea 1
;Maria Jesus Vargas Medrano B98243 Porcentaje hecho: 50%
;David Rojas Obando B96873 Porcentaje hecho 50%

section .data
    num: dw 25
    hileraNum: dw 50, 31, 00010, 200, -1, 0700 ;Numeros que usamos para probar.
    ;El -1 se va a imprimir sin signo y no como -1
    salidaNum: db " ", 10

section .text
global _start

_start:

    mov ax, [num] ; mueve a ax el numero
    mov bx, 10
    mov rdi, salidaNum
 
    mov r8, 0 ;se va a utilizar como contador, porque ya se utilizan los demás registros
    
    convertirNumero:
        xor dx, dx 
        div bx
        push dx ;hace push de el digito que se obtuvo en la division
        inc rcx
        cmp ax, 0
        jne convertirNumero ;Si puede seguir dividiendo vuelve a hacerlo.
 
    mov rbx, 1

    extraerNumero:
        pop dx ;Se saca un dígito de la pila
        add dl, 0x30 ;Se le suma 0x30 para obtener el valor en ASCII
        mov [rdi+rbx], dl ;Se añade a un String que contiene la respuesta.
        inc rbx  
    loop extraerNumero

    ;Imprime los digitos convertidos en la salida estándar.
    mov rsi, rdi
    mov rdx, rbx
    mov rax, 1
    mov rdi, 1
    syscall

    ;Para imprimir los 5 numeros con las diferentes caracteristicas
    mov ax, [hileraNum + r8*2] ;Se mueve el siguiente numero a ax.
    
    
    ;Reiniciar el valor de los registros
    mov bx, 10
    mov rdi, salidaNum
    mov rcx, 0
    inc r8
    cmp r8, 7 
    jge exit ;Si ya hizo todos los numeros salta a la etiqueta salir
   
    jmp convertirNumero

    exit: ;se encarga de terminar la ejecución del programa.
        mov rax, 60
        mov rdi, 0
        syscall
