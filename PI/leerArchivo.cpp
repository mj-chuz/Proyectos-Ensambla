#include <iostream>
#include <fstream>


extern "C" int verificarMascarilla(float imagenA, float imagenB);
extern "C" int verificarTemperatura(float radiacion);
extern "C" int verificarDistancia(float coordX1, float coordY1, float coordX2, float coordY2);

struct Persona{ //Se utiliza para almacenar los datos de cada persona que esté en la imagen
	float imagenA;
	float imagenB;
	float radiacion;
	float coordX;
	float coordY;
};


void leerDatos(int cantidadPersonas) //Se va a encargar de tomar los datos de cada persona del archivo de entrada
{
	std::ifstream file;
	struct Persona personasTotales[cantidadPersonas];
	file.open("entradaDatos.txt", std::ios::in);
	float radiacion, coordX, coordY, imagenA, imagenB = 0;
	if (!file.is_open()){
		std::cerr << "El archivo " << "entradaDatos.txt "  << "no se pudo abrir";
		exit(1);
	}else{
		for(int i = 0; i<cantidadPersonas; i++){
			file >> radiacion;
			personasTotales[i].radiacion = radiacion;
			file >> coordX;
			personasTotales[i].coordX = coordX;
			file >> coordY;
			personasTotales[i].coordY = coordY;
			file >> imagenA;
			personasTotales[i].imagenA = imagenA;
			file >> imagenB;
			personasTotales[i].imagenB = imagenB;
		}
	}
	file.close();
}

int main()
{
	int cantidadPersonas = 7; //La cantidad de personas va a ser aleatoria
	leerDatos(cantidadPersonas);
	//resultadoTemperatura = verificarTemperatura(float PersonaActual.radiacion);
	//resultadoDistancia = verificarDistancia(float PersonaActual.coordX1, float PersonaActual.coordY1, float SiguientePersona.coordX2, float SiguientePersona.coordY2);
	// resultadoascarilla = verificarMascarilla(float PersonaActual.imagenA, float PersonaActual.imagenB);
	return 0;
}