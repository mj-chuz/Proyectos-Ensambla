//Maria Jesus Vargas - B98243
//Gabriel Revillat - B86524
//David Rojas - B96873

#include <iostream>

extern "C" int ackermannMain(int, int);

int main()
{
    int num1 = 0;
    int num2 = 0;
    std::cin >> num1 >> num2;
    int resultado = 0;
    resultado = ackermannMain(num1, num2);
    std::cout << resultado << std::endl;
    return 0;
}