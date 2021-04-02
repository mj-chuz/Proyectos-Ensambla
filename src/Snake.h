#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <curses.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Fruit.h"
#include "GrowthFruit.h"
#include "DecreaseFruit.h"


using namespace std;

class Snake
{
private:
    int width=20;
    int height=20;
    int coordinateX;
    int coordinateY;
    int tailX[100], tailY[100];
    int tailSize;
    int score=0;
    enum directions { STOP = 0, LEFT, RIGHT, UP, DOWN, PAUSE};
    directions direction;
    bool gameOver;
    bool fruitFound;
    int typeFound;
    bool pausedGame;
    bool isMultiplayerGame;
    bool multiplayerSnake;


public:

    Snake();
    void input();
    void logic(int fruitX, int fruitY, int secFruitcX, int secFruitY, std::vector<Fruit*> fruitVec, int coordMultiX=-1, int coordMultiY=-1, int* multiTailX=0, int* multiTailY=0, int multiTailSize=-1 );
    int getCoordX();
    int getCoordY();
    int getTailSize();
    int getType();
    int* getTailX();
    int* getTailY();
    bool getFruitFound();
    bool getCondition();
    int getScore();
    void setCondition(bool newCond);
    void chooseSize(Fruit* actualFruit);
    bool getMultiplayerSnake();
    void setMultiplayerSnake(bool multiplayer);
    void setIsMultiplayerGame(bool isMultiplayer);
    void setCoordX(int newX);
    void setCoordY(int newY);

};

#endif // SNAKE_H
