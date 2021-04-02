#include <iostream>
#include "Cola.h"


int main()
{
    Cola colaNueva;
    colaNueva.Iniciar();

    colaNueva.Agregar(1);
    colaNueva.Agregar(2);
    colaNueva.Agregar(3);
    colaNueva.Agregar(4);
    colaNueva.Agregar(5);
    colaNueva.Agregar(6);
    colaNueva.Agregar(7);
    colaNueva.Agregar(8);
    colaNueva.Agregar(9);
    colaNueva.Agregar(10);


    //colaNueva.Vaciar();
    int num = colaNueva.Sacar();
    std::cout<<num;
    if(colaNueva.Vacia()){
        std::cout<<"ta vacia ";
    }else{ 
        std::cout<<"no ta vacia ";
    }
    //colaNueva.print();*/
    return 0;

}
