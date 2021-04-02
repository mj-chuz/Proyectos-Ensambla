#define _XOPEN_SOURCE 600

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <unistd.h>

extern "C" float verificarMascarilla(float imagenA, float imagenB);
extern "C" float verificarTemperatura(float radiacion);
extern "C" float verificarDistancia(float coordX1, float coordY1, float coordX2, float coordY2);

struct Persona{ //Se utiliza para almacenar los datos de cada persona que esté en la imagen
	float imagenA;
	float imagenB;
	float radiacion;
	float coordX;
	float coordY;
};

int cantPersonas = 0;

/**
* Este método se encarga de calcular la temperatura de la persona que recibe cómo parámetro. Un valor mayor a 37.2° 
* indica que la persona tiene fiebre.
*/
float calcularTemperatura(struct Persona personaActual)
{
	float resultadoTemperatura = 0;
	resultadoTemperatura = verificarTemperatura(personaActual.radiacion);
	return resultadoTemperatura;
}

/**
* Este método calcula si la persona anda una mascarilla puesta. Si el valor de retorno está entre 0 y 1 quiere decir
* que la persona sí anda una mascarilla
*/
float calcularMascarilla(struct Persona personaActual)
{
	float resultadoMascarilla = 0;
	resultadoMascarilla = verificarMascarilla(personaActual.imagenA, personaActual.imagenB);
	return resultadoMascarilla;
}

/**
* Este método calcula la distancia de la persona que se pasa como índice con relación a las demás personas que se encuentran
* en la habitación. La distancia mínima aceptada es de 1.8 metros.
*/
float calcularDistancia(struct Persona* personas, int cantidadPersonas,int indice)
{
	if (cantidadPersonas > 1){
	float resultadoDistancia = 0;
	float menorDistancia = 10; //10 porque es la distancia máxima que pueden tener dos personas (espacio es 10x8)
	float coorX1 = personas[indice].coordX;
	float coorY1 = personas[indice].coordY;
		for(int j = 0; j<cantidadPersonas; j++)
		{
			if (j != indice){
				resultadoDistancia = verificarDistancia(coorX1, coorY1, personas[j].coordX, personas[j].coordY);
				if (menorDistancia>resultadoDistancia)
				{
					menorDistancia = resultadoDistancia;
				}
			}
		}
	return menorDistancia;
	}
	else{
		return -1;
	}
}

/**
 *  Este metodo comprueba si algún dato de la persona esta mal y en ese caso emite una señal a consola y espera la confirmación
 *  del usuario.
 */
void imprimirAdvertencias(float resultadoTemperatura, float resultadoMascarilla, float resultadoDistancia)
{
	char temp;
	bool error = false;
	if ( resultadoTemperatura > 37.2 )
	{
		std::cout << "Advertencia: La persona #" << cantPersonas << " tiene una temperatura mayor a 37.2.\n";
		error = true;
	}
	if ( resultadoMascarilla > 1 )
	{
		std::cout << "Advertencia: La persona #" << cantPersonas << " no esta usando mascarilla.\n";
		error = true;
	}
	if ( resultadoDistancia < 1.8 )
	{
		std::cout << "Advertencia: La persona #" << cantPersonas << " no esta manteniendo la distancia minima de 1.8 metros.\n";
		error = true;
	}
	if (error){
		std::cout << "Presione ENTER para continuar\n";
		getchar();
	}
}

/*
* Este metodo se encarga de el manejo de datos en el programa, tanto de leer los datos como de guardar los resultados
* en la memoria simulada.
*/
void manejarDatos(int cantidadPersonas, std::ifstream& file, FILE* salida) {
	struct Persona personasTotales[cantidadPersonas];
	float radiacion, coordX, coordY, imagenA, imagenB, resultadoTemperatura, resultadoMascarilla, resultadoDistancia = 0;
	
	for(int i = 0; i<cantidadPersonas; i++){
			cantPersonas++;
			fprintf(salida,"%i,",cantPersonas);
			file >> radiacion;
			personasTotales[i].radiacion = radiacion;
			resultadoTemperatura = calcularTemperatura(personasTotales[i]);
			fprintf(salida,"%f,",resultadoTemperatura);
			file >> coordX;
			personasTotales[i].coordX = coordX;
			file >> coordY;
			personasTotales[i].coordY = coordY;
			file >> imagenA;
			personasTotales[i].imagenA = imagenA;
			file >> imagenB;
			personasTotales[i].imagenB = imagenB;
			resultadoMascarilla = calcularMascarilla(personasTotales[i]);
			fprintf(salida,"%f,",resultadoMascarilla);
			resultadoDistancia = calcularDistancia(personasTotales,cantidadPersonas,i);
			fprintf(salida,"%f,",resultadoDistancia);
			fprintf(salida,"\n");

			imprimirAdvertencias(resultadoTemperatura, resultadoMascarilla, resultadoDistancia);

			if (file.eof()){
				break;
			}	
	}	
}

int main()
{
	int cantidadPersonas = 0; //La cantidad de personas va a ser aleatoria

	std::ifstream file;
	FILE* output;

	file.open("entradaDatos.txt", std::ios::in);
	
	if (!file.is_open()){
		std::cerr << "El archivo " << "entradaDatos.txt "  << "no se pudo abrir\n";
		exit(1);
	}else{
		bool fin = false;
		while ( !(fin) )
		{
			output = fopen("salida.csv","w+");
			if(!output){
				std::cerr << "No se pudo abrir o crear el archivo: salida.csv\n";
			}
			srand(time(NULL));
			cantidadPersonas = rand()%10;
			cantidadPersonas++;

			manejarDatos(cantidadPersonas, file, output);

			fin = file.eof();
			sleep(3);
			fclose(output);
		}
	}
	file.close();
	return 0;
}