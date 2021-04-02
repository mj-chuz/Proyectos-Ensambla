//Maria Jesus Vargas Medrano - B98243

#include <iostream>

extern "C" int multiplicacion(int,int);

int main()
{
	int num1 = 0;
	int num2 = 0;
	std::cin >> num1 >> num2;
	int resultado = 0;
	resultado = multiplicacion(num1, num2);
	std::cout << resultado << std::endl;
	return 0;
}