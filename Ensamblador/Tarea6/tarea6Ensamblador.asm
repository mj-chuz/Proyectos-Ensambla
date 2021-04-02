;Maria Jesus Vargas - B98243
;Gabriel Revillat - B86524
;David Rojas - B96873

global ackermann

ackermann:
    cmp rsi, 0
    je primerCaso
    cmp rdi, 0
    je segundoCaso
    dec rdi
    push rdi
    push rsi
    call ackermann
    pop rsi
    pop rdi
    dec rsi
    push rax
    push rsi
    call ackermann
    pop rsi
    pop rdi
    ret


primerCaso:
    mov rax, rdi
    inc rax
    ret


segundoCaso:
    dec rsi
    ;mov rbx, 1
    ;push rbx
    push rdi
    push rsi
    call ackermann
    pop rsi
    pop rdi

