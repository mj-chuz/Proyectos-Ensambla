#include "GrowthFruit.h"
#include <iostream>
GrowthFruit::GrowthFruit()
{
    this->identifier = (rand() % 100) + 50;
    this->id=1;
}

GrowthFruit::~GrowthFruit()
{

}

GrowthFruit::GrowthFruit(int n)
{
    this->identifier = n;
    this->id=1;
}

void GrowthFruit::print()
{
    std::cout << this->identifier;
}

int GrowthFruit::getId()
{
    return this->id;
}

void GrowthFruit::modifyIdentifier(int n)
{
    this->identifier += n;
}

