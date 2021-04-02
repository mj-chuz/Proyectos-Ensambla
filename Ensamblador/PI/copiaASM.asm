section .data
    constante: dd 273.15 ;constante utilizada para la formula
    constTemp: dd 0.0000000572 ;constante utilizada para la formula

section .text
global calcularTemp

calcularTemp:
    vmovss xmm1, [constTemp] 

    vdivss xmm2, xmm0, xmm1 ;se divide la radiacion entre la constante 5.72e-08
    
    vsqrtss xmm3, xmm2 ;se saca la raiz cuadrada
    
    vsqrtss xmm4, xmm3 ; se vuelve a sacar la raiz para que sea igual a ^1/4
    
    ;En xmm4 se tiene lo que equivale a Kelvin en la formula

    vmovss xmm1, [constante]
    
    vsubss xmm0, xmm4, xmm1  ;restar Kelvin por 273.15

    ;En xmm0 queda la temperatura final de la persona
    
    ret