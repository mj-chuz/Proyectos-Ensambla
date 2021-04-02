section .data
    frecuenciaBase: dd 261.63

section .text
global sumaPacked

sumaPacked:
    vmovdqu xmm0, [rdi] ;Se pasa la direccion del arreglo a xmm0
    vmovdqu xmm1, [rsi] ;Se pasa la direccion del segundo arreglo a xmm1
    vaddps xmm0, xmm0, xmm1 ;Se realiza la suma entre los arreglos (packed)
    vmovdqu [rdx], xmm0 ;El resultado queda en la direccion del arreglo resultado
    ret
    