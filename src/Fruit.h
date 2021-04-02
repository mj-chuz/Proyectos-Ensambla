#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>

class Fruit
{
    protected:


        int identifier;
        int id;

    public:

        Fruit();
        virtual ~Fruit();
        virtual void print() = 0;
        virtual int getId() = 0;
        virtual void modifyIdentifier(int n) = 0;
        friend inline std::ostream& operator<<(std::ostream& output, const Fruit& fruit)
        {
            output << fruit.identifier;
            return output;
        }


};

#endif // FRUTAS_H
