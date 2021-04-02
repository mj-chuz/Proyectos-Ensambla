# Proyecto PI - Los Pingüinos

Nombre de equipo: Pingüinos


Logo del equipo: 

![logo](imgReadme/logo.png)

## Integrantes

- David Rojas - B96873
- Gabriel Revillat - B86524
- Maria Jesús Vargas - B98243

## Descripción Breve

El proyecto consiste de un programa que se encarga de recibir datos de un lugar en especifico con personas, se encarga de revisar la distancia, la temperatura y el uso de mascarilla de estos. Se procesan los datos y en caso de que suceda alguna anomalía surge una alerta.

## Descripción Detallada

#### Arquitectura

##### Imagen Arquitectura

![arquitectura](imgReadme/ArquitecturaDefinitiva.jpg)

##### Registros
El sistema cuenta con 6 registros de propósitos general de 32 bits cada uno

##### Memoria
El tamaño de memoria que se utilizará es de 1KB.

##### Entrada/Salida de datos
El sistema recibe los datos mediante archivos (formato a definir). Estos datos se procesan y los
resultados son enviados a la memoria.

Cuando se desea sacar los resultados, la información se guardará en un archivo de texto y los
resultados serán desplegados en consola.

##### Refrescamiento de Datos
Según lo planeado, los resultados serán actualizados una vez en un intervalo de 2 a 4 segundos.

#### Detalles de implementación

En términos de programación la solución será implementada utilizando lenguaje ensamblador
y c++.

La señal que representa una anomalía se mostraría en consola y en principio tendriamos alguna forma de desactivar esa alarma.

Los datos resultantes en el csv representan la informacion de las últimas personas a las que se le tomaron los datos 

## Manual de Usuario

### Requerimientos

Sistema operativo Linux, se recomienda que esté actualizado

Compilador de C++ 

Instalado Nasm

Arquitectura x86

### Ejecución el programa

Para compilar el programa simplemente se debe ejecutar el MakeFile, para esto se debe escribir make en la línea de comandos, luego de esto se debe colocar en la línea de comandos ./casm, para ejecutar el programa, el cual va a empezar a leer el archivo asignado, para obtener los respectivos datos y realizar su respectiva función.

Se necesita que el archivo de entrada se encuentre en la misma direccion que el programa, se tiene que tomar en cuenta que el nombre del archivo tiene que coincidir con el nombre predeterminado que se utiliza en el programa.

#### Caso de error

En caso de que haya un error con alguna persona, esta es la pantalla que se le muestra al usuario y el programa espera a que el usuario aprete "ENTER" para continuar con la ejecución
del programa.

![imgError](imgReadme/screenError.png)

### Funcionalidad

El programa consiste en la simulacion de una maquina, la cual se encarga de leer los datos de las personas que entran a un local en especifico, para analizar su temperatura, si se usa mascarilla y si se cumple la distancia reconmendada. Para esto, se recibe la radiacion de las personas, se compara una imagen de la cara de la persona con la imagen de una persona con mascarilla y sus coordenadas.

En la salida en consola se van a esperar las advertencias encontradas, en el caso que se encuentre una temperatura muy alta, no se este usando mascarillas o si la distancia que tengan las personas no sea la correcta.

En la salida del archivo csv se van a imprimir el número de la persona que entro al local, con sus repectivos datos, su temperatura, si está utilizando mascarilla y su menor distancia con respecto a las demás personas que se encuentran en el local en ese momento.

