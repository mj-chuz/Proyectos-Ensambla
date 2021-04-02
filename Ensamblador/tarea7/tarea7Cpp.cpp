#include <iostream>

extern "C" void sumaPacked(int* lista1, int* lista2, int* resultado);

int main()
{
	int tamano = 2;
	int contador = 0;
	int *lista1 = new int[tamano];
    int *lista2 = new int[tamano];
	for (int i = 0; i<tamano; i++){
		lista1[i]=i+4;
		lista2[i]=i+9;
	}
	//lista1 = [4, 5]
	//lista2 = [9, 10]
	int* resultado = new int[tamano];
	sumaPacked(lista1, lista2, resultado);
	std::cout <<"[ ";
	while (contador < tamano){
		std::cout << resultado[contador] << " ";
		contador++;
	}
	//resultado = [13, 15]
	delete (lista1);
	delete (lista2);
	delete (resultado);
	std::cout <<"]\n";
	return 0;
}
