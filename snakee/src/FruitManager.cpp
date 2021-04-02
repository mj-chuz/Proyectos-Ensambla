#include "FruitManager.h"
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Interfaz.h"
#include "Fruit.h"
#include "GrowthFruit.h"
#include "DecreaseFruit.h"



FruitManager::FruitManager()
{
    fruitX = rand() % width;
    fruitY = rand() % height;
    secFruitX = rand() % width;
    secFruitY = rand() % height;
    growthCount = 5;
    decreaseCount = 1;
    randomFruit.push_back(new GrowthFruit(growthCount));
    randomFruit.push_back(new DecreaseFruit(decreaseCount));
}

FruitManager::~FruitManager()
{
    this->deleteFruits();
}

void FruitManager::iniciate()
{
    Interfaz in;
    while(!snake.getCondition()){
        in.draw(snake.getCoordX(), snake.getCoordY(), fruitY, fruitX, secFruitY, secFruitX, snake.getTailSize(), snake.getTailX(), snake.getTailY(), snake.getScore(), this->getActualFruit());

        snake.input();

        snake.logic(fruitX, fruitY, secFruitX, secFruitY, this->getActualFruit());
        if(snake.getFruitFound())
        {
            if(snake.getType() == 1){
                this->randomFruit[0] = this->getRandomFruit(0);
            }else{
                this->randomFruit[1] = this->getRandomFruit(1);
            }
            fruitX=rand() % width;
            fruitY=rand() % height;
            secFruitX = rand() % width;
            secFruitY = rand() % height;
        }

    }
}

void FruitManager::iniciateMultiplayer()
{
    Snake multiplayerSnake;
    multiplayerSnake.setCoordX(width-1);
    multiplayerSnake.setCoordY(height-1);
    multiplayerSnake.setMultiplayerSnake(true);
    Interfaz in;
    while(!snake.getCondition() && !multiplayerSnake.getCondition()){

        in.draw(snake.getCoordX(), snake.getCoordY(), fruitY, fruitX, secFruitY, secFruitX, snake.getTailSize(), snake.getTailX(), snake.getTailY(), snake.getScore(), this->getActualFruit(), multiplayerSnake.getCoordX(), multiplayerSnake.getCoordY(), multiplayerSnake.getTailSize(), multiplayerSnake.getTailX(), multiplayerSnake.getTailY(), multiplayerSnake.getScore());
        snake.input();

        snake.logic(fruitX, fruitY, secFruitX, secFruitY, this->getActualFruit());

        multiplayerSnake.input();

        multiplayerSnake.logic(fruitX, fruitY, secFruitX, secFruitY, this->getActualFruit());

        if(snake.getFruitFound() || multiplayerSnake.getFruitFound())
        {
            if(snake.getType() == 1 || multiplayerSnake.getType() == 1){

                this->randomFruit[0] = this->getRandomFruit(0);
            }else{
                this->randomFruit[1] = this->getRandomFruit(1);
            }
            fruitX=rand() % width;
            fruitY=rand() % height;
            secFruitX = rand() % width;
            secFruitY = rand() % height;
        }

    }
}


Fruit* FruitManager::getRandomFruit(int position)
{
    int sum = (rand() % 15) + 1;
    randomFruit[0]->modifyIdentifier(sum);
    randomFruit[1]->modifyIdentifier(sum);
    Fruit* changedFruit = randomFruit[position];
    return changedFruit;

}

std::vector<Fruit*> FruitManager::getActualFruit()
{
    return randomFruit;
}

void FruitManager::deleteFruits()
{
    for(Fruit* fruit : this->randomFruit)
        delete fruit;
    this->randomFruit.clear();
}



