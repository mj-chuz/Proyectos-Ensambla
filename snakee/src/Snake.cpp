#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Interfaz.h"
#include "Fruit.h"
#include "GrowthFruit.h"
#include "DecreaseFruit.h"

using namespace std;

Snake::Snake()

{
    gameOver = false;
    direction = STOP;
    coordinateX = width / 2;
    coordinateY = height / 2;
    fruitFound=false;
    tailSize = 0;
    typeFound = 0;
    score = 0;
}

int Snake::getCoordX()
{
    return coordinateX;
}

int Snake::getCoordY()
{
    return coordinateY;
}

void Snake::setCoordX(int newX)
{
    coordinateX=newX;
}

void Snake::setCoordY(int newY)
{
    coordinateY=newY;
}


int Snake::getTailSize()
{
    return tailSize;
}

int* Snake::getTailX()
{
    return tailX;
}

int* Snake::getTailY()
{
    return tailY;
}

bool Snake::getFruitFound()
{
    return fruitFound;
}

int Snake::getType()
{
    return typeFound;
}

int Snake::getScore()
{
    return score;
}

void Snake::setCondition(bool newCondition)
{
    gameOver=newCondition;
}

bool Snake::getMultiplayerSnake()
{
    return multiplayerSnake;
}

void Snake::setMultiplayerSnake(bool multiplayer)
{
    multiplayerSnake=multiplayer;
}

void Snake::input()
{
    if (!multiplayerSnake)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }else{
        if (_kbhit())
        {
                switch (_getch())
                {
                case 75:
                    direction = LEFT;
                    break;
                case 77:
                    direction = RIGHT;
                    break;
                case 72:
                    direction = UP;
                    break;
                case 80:
                    direction = DOWN;
                    break;
                case 'x':
                    gameOver = true;
                    break;
                }
        }
    }
}


void Snake::logic(int fruitX, int fruitY, int secFruitX, int secFruitY, std::vector<Fruit*> fruitVec)
{
    fruitFound=false;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = coordinateX;
    tailY[0] = coordinateY;
    for (int i = 1; i < tailSize; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (direction)
    {
    case LEFT:
        coordinateX--;
        break;
    case RIGHT:
        coordinateX++;
        break;
    case UP:
        coordinateY--;
        break;
    case DOWN:
        coordinateY++;
        break;
    default:
        break;
    }
    if (coordinateX >= width) coordinateX = 0; else if (coordinateX < 0) coordinateX = width - 1;
    if (coordinateY >= height) coordinateY = 0; else if (coordinateY < 0) coordinateY = height - 1;

    for (int i = 0; i < tailSize; i++)
        if (tailX[i] == coordinateX && tailY[i] == coordinateY)
            gameOver = true;

    if (coordinateX == fruitX && coordinateY == fruitY)
    {
        this->chooseSize(fruitVec[0]);
        fruitX = rand() % width;
        fruitY = rand() % height;
        fruitFound = true;
        typeFound = 1;
        if (score<0)
        {
            gameOver=true;
        }

    }

    if (coordinateX == secFruitX && coordinateY == secFruitY)
    {
        this->chooseSize(fruitVec[1]);
        secFruitX = rand() % width;
        secFruitY = rand() % height;
        fruitFound = true;
        typeFound = 2;
        if (score<0)
        {
            gameOver=true;
        }
    }

}


void Snake::chooseSize(Fruit* actualFruit)
{
    if (actualFruit->getId()==1)
    {
            tailSize++;
           score=score+10;
    }
    if (actualFruit->getId()==2)
    {
        tailSize--;
        score=score-10;
    }
}


bool Snake::getCondition()
{
    return gameOver;
}
