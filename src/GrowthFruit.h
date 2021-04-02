#ifndef GROWTHFRUIT_H
#define GROWTHFRUIT_H

#include "Fruit.h"


class GrowthFruit : public Fruit
{
    public:

        GrowthFruit();
        GrowthFruit(int n);
        virtual ~GrowthFruit() override;

        virtual void print() override;
        virtual int getId() override;
        virtual void modifyIdentifier(int n) override;

};




#endif
