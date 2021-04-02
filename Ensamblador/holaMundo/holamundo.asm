section .data
    cadena: db "hola hola!", 10
    tamCadena: equ $ - cadena

section .text
global _start
_start:

    mov rsi, cadena ;direccion del inicio de la hilera que quiero imprimir
    mov rdx, tamCadena ;cuantos bytes quiero imprimir a partir de la direccion de rsi
    mov rax, 1, ;indica que tiene que imprimir algo
    mov rdi, 1 ; salida estándar, indica donde se imprime
    syscall ; imprimir

    mov rax, 60 ;dele control al sistema operativo
    mov rdi, 0  ;equivalente a return 0, devuelva el control al sistema operativo con codigo de error 0
    syscall ; salir