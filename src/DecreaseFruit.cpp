#include "DecreaseFruit.h"
#include <iostream>

DecreaseFruit::DecreaseFruit()
{
    this->identifier = (rand() % 49) + 1;
    this->id=2;
}

DecreaseFruit::~DecreaseFruit()
{

}

DecreaseFruit::DecreaseFruit(int n)
{
    this->identifier = n;
    this->id = 2;
}

void DecreaseFruit::print()
{
    std::cout << this->identifier;
}

int DecreaseFruit::getId()
{
    return this->id;
}

void DecreaseFruit::modifyIdentifier(int n)
{
    this->identifier += n;
}
