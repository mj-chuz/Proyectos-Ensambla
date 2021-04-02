#ifndef FRUITMANAGER_H
#define FRUITMANAGER_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Fruit.h"
#include "Interfaz.h"


class FruitManager
{
private:
    int width=20;
    int height=20;
    int growthCount;
    int decreaseCount;
    int fruitX;
    int fruitY;
    int secFruitX;
    int secFruitY;
    std::vector<Fruit*> fruits;
    std::vector<Fruit*> randomFruit;

    Snake snake;
    Fruit* fruit;

public:
    FruitManager();
    ~FruitManager();
    void deleteFruits();
    Fruit* getRandomFruit(int position);
    std::vector<Fruit*> getActualFruit();
    void iniciate();
    void iniciateMultiplayer();
    int getFruitX();
    int getFruitY();

};

#endif // FRUITMANAGER_H
