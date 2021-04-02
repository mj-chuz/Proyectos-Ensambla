section .data
    matriz: dw  12,     900,    38,     66,     21, 90,     2,      1,  933,    9,  1,  34
            dw  5,      45,     38,     4,      21, 90,     2,      1,  93,     9,  1,  341
            dw  28,     24,     138,    626,    21, 3,      6,      1,  33,     9,  1,  3
            dw  77,     876,    38,     866,    21, 77,     2,      1,  13,     9,  1,  4
            dw  109,    12,     348,    616,    21, 86,     24,     1,  23,     9,  1,  324
            dw  12,     65,     381,    61,     21, 910,    2,      1,  45,     9,  1,  134
            dw  32,     88,     308,    543,    21, 190,    12,     1,  6,      9,  1,  234
            dw  7,      4,      38,     166,    21, 590,    2,      1,  88,     9,  1,  344
            dw  100,    6,      328,    32,     21, 901,    82,     1,  11,     9,  1,  314
            dw  1,      6,      38,     676,    21, 9,      212,    1,  09,     9,  1,  12
            dw  9,      66,     8,      66,     21, 10,     42,     1,  23,     76, 1,  90
            dw  45,     346,    18,     66,     21, 90,     22,     1,  43,     9,  34, 74

    tamMatriz: equ 12
  
    vector: times 12 dw 0 
    tamVector: equ 12


section .text
global _start

_start:

    mov rsi, matriz
    mov rcx, tamMatriz
    mov rdi, vector

    call diagonal

    mov rax, 60
    mov rdi, 0
    syscall ; Salir.

diagonal:
    push rax
    push rcx
    push rbx
    push rdx

    mov rax, tamVector
    mov rbx, 0
    mov dx, 0 ; Valor actual de la matriz

    diagonalCiclo:
        dec rax
        mov dx, word [rsi + rbx*2]

        mov word [rdi + rax*2], dx ; Asi se guarda al reves en el registro

        add rbx, 13
    loop diagonalCiclo

    pop rdx
    pop rbx
    pop rcx
    pop rax
    ret