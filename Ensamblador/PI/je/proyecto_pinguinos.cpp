#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

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

void calcularTemperatura(struct Persona personaActual)
{
	float resultadoTemperatura = 0;
	resultadoTemperatura = verificarTemperatura(personaActual.radiacion);
	//aqui se podría ver si la temperatura no es buena
	std::cout << resultadoTemperatura <<std::endl;
}

void calcularMascarilla(struct Persona personaActual)
{
	float resultadoMascarilla = 0;
	resultadoMascarilla = verificarMascarilla(personaActual.imagenA, personaActual.imagenB);
	//aqui se podría ver si se usa o no mascarilla
	std::cout << resultadoMascarilla << std::endl;
}


void calcularDistancia(struct Persona* personas, int cantidadPersonas)
{
	float resultadoDistancia = 0;
	float menorDistancia = 2;
	for(int i = 0; i<cantidadPersonas; i++)
	{
		for(int j = i+1; j<cantidadPersonas; j++)
		{
			resultadoDistancia = verificarDistancia(personas[i].coordX, personas[i].coordY, personas[j].coordX, personas[j].coordY);
			if (menorDistancia>resultadoDistancia)
			{
				menorDistancia = resultadoDistancia;
				std::cout <<"D: "<< menorDistancia << std::endl;
				//aqui se podría ver si la distancia no es buena
			}
		}
	}
}

void leerDatos(int cantidadPersonas, std::ifstream& file) //Se va a encargar de tomar los datos de cada persona del archivo de entrada
{
	
	struct Persona personasTotales[cantidadPersonas];
	float radiacion, coordX, coordY, imagenA, imagenB, resultadoTemperatura, resultadoMascarilla, resultadoDistancia = 0;
	
	for(int i = 0; i<cantidadPersonas; i++){ //esto podria ser un while para llevar un bool, verificando si hay alarma o no
			file >> radiacion;
			personasTotales[i].radiacion = radiacion;
			calcularTemperatura(personasTotales[i]);
			file >> coordX;
			personasTotales[i].coordX = coordX;
			file >> coordY;
			personasTotales[i].coordY = coordY;
			file >> imagenA;
			personasTotales[i].imagenA = imagenA;
			file >> imagenB;
			personasTotales[i].imagenB = imagenB;
			calcularMascarilla(personasTotales[i]);		
	}
	if(cantidadPersonas>1)
	{
		calcularDistancia(personasTotales, cantidadPersonas);
	}
	
	
	//return &personasTotales;
}

int main()
{
	int cantidadPersonas = 0; //La cantidad de personas va a ser aleatoria
	//while(no haya alarma)
	srand(time(NULL));
	cantidadPersonas = rand()%10;
	cantidadPersonas++;
	std::ifstream file;
	file.open("entradaDatos.txt", std::ios::in);
	if (!file.is_open()){
		std::cerr << "El archivo " << "entradaDatos.txt "  << "no se pudo abrir";
		exit(1);
	}else{
		leerDatos(cantidadPersonas, file);
	}
	//std::vector<Persona> vect(cantidadPersonas, Persona);
	//struct Persona personasTotales[cantidadPersonas];
	//struct Persona* datosPersonas;

	
	file.close();
	/*float resultadoTemperatura = 0;
	float resultadoDistancia = 0;
	float resultadoMascarilla = 0;
	struct Persona PersonaActual;
	for (int i = 0; i<cantidadPersonas; i++){
		PersonaActual = datosPersonas[i];
		resultadoTemperatura = verificarTemperatura(PersonaActual.radiacion);
	//resultadoDistancia = verificarDistancia(PersonaActual.coordX1, PersonaActual.coordY1, float SiguientePersona.coordX2, float SiguientePersona.coordY2);
		resultadoMascarilla = verificarMascarilla(PersonaActual.imagenA, PersonaActual.imagenB);
	}*/
	return 0;
}