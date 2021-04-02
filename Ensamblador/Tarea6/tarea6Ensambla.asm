;Maria Jesus Vargas - B98243
;Gabriel Revillat - B86524
;David Rojas - B96873

global ackermannMain

ackermannMain:

    call ackermann
    ret

ackermann:
    cmp rdi, 0
    je primerCaso
    cmp rsi, 0
    je segundoCaso
    dec rsi
    push rdi
    push rsi
    call ackermann
    pop rsi
    pop rdi
    dec rdi
    push rax
    push rdi
    call ackermann
    pop rdi
    pop rsi
    ret


primerCaso:
    mov rax, rsi
    inc rax
    ret


segundoCaso:
    dec rdi
    push qword 1
    push rdi
    call ackermann
    pop rdi
    pop rsi

    ret

