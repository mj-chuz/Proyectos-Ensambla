#include <iostream>
#include "Cola.h"

#define m 10


/*Cola::Cola()
    {
    }*/

/*Cola::~Cola()
    {
    }*/

void Cola::Iniciar()
    {
        this->cola[m];
    }

void Cola::Destruir()
    {
        this->Vaciar();
        this -> cola[0];
    }

bool Cola::Vacia()
    {
        if (this->inicio == -1 && this->final == -1){
            return true;
        }else{
            return false;
        }
    }

void Cola::Vaciar()
    {
        while (!this->Vacia())
        {
            this->Sacar();
        }
        this->inicio = -1;
        this->final = -1;
    }

void Cola::Agregar(int elemento)
    {
        if (this->contador == m){
            std::cout << "Colita llena juejue\n";
        }else{
            if(this->inicio == -1)
                this->inicio == 0;  
            if (this->contador==0)
                this->cola[-1] = elemento;
            else{
                this->final = (this->final+1)%m;
                this->cola[this->final] = elemento;
            }   
            this->contador++;     
        }
    }

int Cola::Sacar()
    {
        int element = 0;
        if(this->Vacia()){
            std::cout << "La cola está vacía\n";
        }else{
            if(this->final == this->inicio)
            {
                this->inicio = this->final = -1;
            }else{
                element=this->cola[this->inicio];
                this->inicio = (this->inicio + 1)%m;
                this->contador--;
            }
        }
        return element;
    }

int Cola::NumElem()
    {
        return contador;
            
    }

int Cola::Frente()
    {
        if(this->Vacia()){
            std::cout<<"La cola se encuentra vacía";
        }else{
            return this->cola[this->inicio];
        }
        return 0;
    }


};
/*
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
    //int num = colaNueva.Sacar();
    //std::cout<<num;
    if(colaNueva.Vacia()){
        std::cout<<"ta vacia ";
    }else{ 
        std::cout<<"no ta vacia ";
    }
    colaNueva.print();
    return 0;

}

*/

