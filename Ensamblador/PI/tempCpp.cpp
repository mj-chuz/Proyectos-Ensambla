#include <iostream>

extern "C" float calcularTemp(float radiacion);

int main()
{
	float radiacion = 0;
	std::cin >> radiacion; //Esto realmente se recibe por medio del archivo de entrada
	float resultado = 0;
	resultado = calcularTemp(radiacion);
	if (resultado > 37.2)
	{
		std::cout << "Fiebre detectada con una temperatura de " << resultado << std::endl;
	}else{
		std::cout << "Su resultado es " << resultado << std::endl;
	}
	
	return 0;
}