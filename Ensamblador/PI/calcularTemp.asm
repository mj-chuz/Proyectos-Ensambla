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
    constTempResta: dd 273.15 ;constTempResta utilizada para la formula
    constTempDivisor: dd 0.0000000572 ;constTempResta utilizada para la formula
    r1: dd 0
    r2: dd 0
    r3: dd 0

section .text
global calcularTemp

calcularTemp:

    vmovdqu [r1], xmm0

    calcularTemperatura constTempDivisor, r1, constTempResta
    
    ret
