section .data
    constDivisor: dd 10000.0
    consTempResta: dd 273.15 
    constTempDivisor: dd 0.0000000572 

section .text
global verificarMascarilla
global verificarTemperatura

; Parametros:   xmm0 -> imagenA
;               xmm1 -> imagenB
verificarMascarilla:
    ; xmm2 <- Resta de la cantidad de pixeles de cada imagen.
    vsubss xmm2, xmm0, xmm1
    ; xmm2 <- Resultado de la resta elevado a la 2.
    vmulss xmm2, xmm2
    ; xmm3 <- Constante 10000
    vmovss xmm3, [constDivisor]

    ; xmm0 <- Error cuadratico medio: Division del resultado entre 10000 (la cantidad total de pixeles)
    vdivss xmm0, xmm2, xmm3

    ; El error cuadratico medio es el valor a retornar (queda en xmm0)

    ret

verificarTemperatura:
    vmovss xmm1, [constTempDivisor] 

    vdivss xmm2, xmm0, xmm1 ;se divide la radiacion entre la constante 5.72e-08
    
    vsqrtss xmm3, xmm2 ;se saca la raiz cuadrada
    
    vsqrtss xmm4, xmm3 ; se vuelve a sacar la raiz para que sea igual a ^1/4
    
    ;En xmm4 se tiene lo que equivale a Kelvin en la formula

    vmovss xmm1, [consTempResta]
    
    vsubss xmm0, xmm4, xmm1  ;restar Kelvin por 273.15

    ;En xmm0 queda la temperatura final de la persona
    
    ret