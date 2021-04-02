%macro calcularMSE 4
    vmovdqu xmm0, [%1]
    vmovdqu xmm1, [%2]
    vmovdqu xmm2, [%3]
    vsubss xmm2, xmm0, xmm1 ; xmm2 <- Resta de la intensidad de pixeles de cada imagen.
    vmulss xmm2, xmm2       ; xmm2 <- Resultado de la resta elevado a la 2.
    vdivss xmm0, xmm2, [%4] ; xmm0 <- Error cuadratico medio: Division del resultado entre 10000.
%endmacro

%macro calculoDistancia 4
    vmovdqu xmm0, [%1]
    vmovdqu xmm1, [%2]
    vmovdqu xmm2, [%3]
    vmovdqu xmm3, [%4]
    vsubss xmm0, xmm2, xmm0 ; x2 - x1
    vmulss xmm0,xmm0,xmm0 ; (x2 - x1)²
    vsubss xmm1, xmm3, xmm1 ; y2 - y1
    vmulss xmm1,xmm1,xmm1 ; (y2 - y1)²
    ; xmm0 -> (x2 - x1)² y xmm1 -> (y2 - y1)²
    vaddss xmm0, xmm0, xmm1 ; xmm0 -> (x2 - x1)² + (y2 - y1)²
    vsqrtss xmm0, xmm0 
%endmacro

%macro calcularTemperatura 3
    vmovdqu xmm1, [%1] 
    vmovdqu xmm0, [%2]
    vdivss xmm2, xmm0, xmm1 ;se divide la radiacion entre la constTempResta 5.72e-08
    vsqrtss xmm3, xmm2 ;se saca la raiz cuadrada
    vsqrtss xmm4, xmm3 ; se vuelve a sacar la raiz para que sea igual a ^1/4
    ;En xmm4 se tiene lo que equivale a Kelvin en la formula
    vmovdqu xmm1, [%3]
    vsubss xmm0, xmm4, xmm1  ;restar Kelvin por 273.15
    ;En xmm0 queda la temperatura final de la persona
%endmacro

section .data
    constDivisor: dd 10000.0
    consTempResta: dd 273.15 
    constTempDivisor: dd 0.0000000572
    r1: dd 0
    r2: dd 0
    r3: dd 0
    r4: dd 0

section .text
global verificarMascarilla
global verificarTemperatura
global verificarDistancia

; Parametros:   xmm0 -> imagenA
;               xmm1 -> imagenB
verificarMascarilla:

    vmovdqu [r1], xmm0
    vmovdqu [r2], xmm1

    calcularMSE r1, r2, r3, constDivisor

    ret

; Parametro:   xmm0 -> radiacion
verificarTemperatura:

    vmovdqu [r1], xmm0

    calcularTemperatura constTempDivisor, r1, constTempResta
    
    ret
    
verificarDistancia: 
    ;Recibe como parámetros: xmm0 -> coordenada "x" 1
    ;                        xmm1 -> coordenada "y" 1
    ;                        xmm2 -> coordenada "x" 2
    ;                        xmm3 -> coordenada "y" 2
    vmovdqu [r1], xmm0
    vmovdqu [r2], xmm1
    vmovdqu [r3], xmm2
    vmovdqu [r4], xmm3
    calculoDistancia r1,r2,r3,r4
    ret