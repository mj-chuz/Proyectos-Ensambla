;Maria Jesus Vargas Medrano B98243


section .data
    frecuenciaBase: dd 261.63        ;Constantes que se utilizan para el programa
    numElevado: dd 1.05946309436
    amplitud: dd 4096.0
    duracion: dd 0.5
    frecuencia: dd 44100.0
    restaUno: dd 1.0
    calculoSeno: dd 0.0
    pi: dd 3.1415926535897

section .text
global obtenerNotas
global obtenerOnda
global obtenerDatosOnda

obtenerNotas:                       ;Obtiene la frecuencia de la nota al realizar la operacion de 
    vmovss xmm1, [numElevado]       ;frecuenciaBase*2^(i/12) (i siendo el numero designado a cada nota)
    vmovss xmm2, [numElevado]
    vmovss xmm3, [frecuenciaBase]
    cmp rdi, 0                      ;Se hace excepcion con 0 y 1, debido a las reglas de potencia
    je excepcion0
    cmp rdi, 1
    je excepcion1
    mov rcx, rdi
    dec rcx
    
    cicloMultiplicacion:
        vmulss xmm1, xmm1, xmm2     ;Este ciclo simula la potencia de 2^(i/12), dependiendo del numero de la nota
    loop cicloMultiplicacion

    vmulss xmm0, xmm3, xmm1
    ret


excepcion0:
    vmovss xmm0, [frecuenciaBase]
    ret

excepcion1:
    vmovss xmm1, [frecuenciaBase]
    vmulss xmm0, xmm1, xmm1
    ret
    

obtenerOnda:                    ;Este metodo se encarga de realizar el np.linspace que se hace en python
    vmovss xmm1, [duracion]
    vmovss xmm2, [frecuencia]
    vmulss xmm3, xmm1, xmm2
    vmovss xmm2, [restaUno]
    vsubss xmm4, xmm3, xmm2
    
    vdivss xmm4, xmm1, xmm4
    vaddss xmm0, xmm0, xmm4
    
    ret

obtenerDatosOnda:               ;Este metodo se encarga de realizar las multiplicaciones para obtener la onda
    vmovss xmm2, [pi]           ;que serian amplitud*sin(2*pi*frecuenciaNota*linspace)
    vaddss xmm2, xmm2, xmm2
    vmulss xmm3, xmm0, xmm1
    vmulss xmm1, xmm3, xmm2
    vmovss [calculoSeno], xmm1

    fld long [calculoSeno]
    fsin
    fstp long [calculoSeno]

    vmovss xmm1, [calculoSeno]
    vmovss xmm2, [amplitud]
    vmulss xmm0, xmm1, xmm2

    ret

