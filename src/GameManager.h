#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <curses.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Fruit.h"
#include "Interface.h"


class GameManager
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
    GameManager();
    ~GameManager();
    void deleteFruits();
    Fruit* getRandomFruit(int position);
    std::vector<Fruit*> getActualFruit();
    void iniciate();
    void iniciateMultiplayer();
    int getFruitX();
    int getFruitY();
    void restartGame();

};

#endif // GAMEMANAGER_H
