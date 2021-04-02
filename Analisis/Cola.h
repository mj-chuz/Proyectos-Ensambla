#ifndef COLA_H
#define COLA_H

#include <iostream>

#define m 10

class Cola{

    private:

        int cola[m];
        int inicio = -1;
        int final = -1;
        int contador = 0;
        
    public:
        //Cola();

        //~Cola();

        void Iniciar();

        void Destruir();

        bool Vacia();

        void Vaciar();

        void Agregar(int elemento);

        int Sacar();

        int NumElem();

        int Frente();

};

#endif