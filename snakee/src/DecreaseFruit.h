#ifndef SPEEDFRUIT_H
#define SPEEDFRUIT_H

#include "Fruit.h"

class DecreaseFruit : public Fruit
{

    public:

        DecreaseFruit();
        DecreaseFruit(int n);
        virtual ~DecreaseFruit() override;

        virtual void print() override;
        virtual int getId() override;
        virtual void modifyIdentifier(int n) override;

};



#endif
