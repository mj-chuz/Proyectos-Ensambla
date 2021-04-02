#include "GameManager.h"
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Interface.h"
#include "Fruit.h"
#include "GrowthFruit.h"
#include "DecreaseFruit.h"



GameManager::GameManager()
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

GameManager::~GameManager()
{
    this->deleteFruits();
}

void GameManager::iniciate()
{
    Interface in;
    while(!snake.getCondition()){
        in.printBoard(snake.getCoordX(), snake.getCoordY(), fruitY, fruitX, secFruitY, secFruitX, snake.getTailSize(), snake.getTailX(), snake.getTailY(), snake.getScore(), this->getActualFruit());

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
    std::cout << "GAME OVER :(" << std::endl;
    this->restartGame();
}

void GameManager::iniciateMultiplayer()
{
    Snake multiplayerSnake;
    snake.setIsMultiplayerGame(true);
    multiplayerSnake.setIsMultiplayerGame(true);
    multiplayerSnake.setCoordX(width-1);
    multiplayerSnake.setCoordY(height-1);
    multiplayerSnake.setMultiplayerSnake(true);
    Interface in;
    while(!snake.getCondition() && !multiplayerSnake.getCondition()){

        in.printBoard(snake.getCoordX(), snake.getCoordY(), fruitY, fruitX, secFruitY, secFruitX, snake.getTailSize(), snake.getTailX(), snake.getTailY(), snake.getScore(), this->getActualFruit(), multiplayerSnake.getCoordX(), multiplayerSnake.getCoordY(), multiplayerSnake.getTailSize(), multiplayerSnake.getTailX(), multiplayerSnake.getTailY(), multiplayerSnake.getScore());
        snake.input();

        snake.logic(fruitX, fruitY, secFruitX, secFruitY, this->getActualFruit(), multiplayerSnake.getCoordX(), multiplayerSnake.getCoordY(), multiplayerSnake.getTailX(), multiplayerSnake.getTailY(), multiplayerSnake.getTailSize());

        multiplayerSnake.input();

        multiplayerSnake.logic(fruitX, fruitY, secFruitX, secFruitY, this->getActualFruit(), snake.getCoordX(), snake.getCoordY(), snake.getTailX(), snake.getTailY(), snake.getTailSize());

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
    std::cout << "GAME OVER!" << std::endl;
    if(snake.getScore() > multiplayerSnake.getScore()){
        std::cout << "WINNER: O's player" << std::endl;
        this->restartGame();
    }else if(snake.getScore() < multiplayerSnake.getScore()){
        std::cout << "WINNER: X's player" << std::endl;
        this->restartGame();
    }else{
        std::cout << "DRAW" << std::endl;
        this->restartGame();
    }

}

void GameManager::restartGame()
{
    Interface in;
    int answer = 0;
    std::cout << "Want to play again? " << std::endl;
    std::cout << "Press 1 if answer is yes" << std::endl;
    std::cout << "Press 2 if answer is no" << std::endl;

    std::cin >> answer;

    switch (answer) {

        case 1:
            in.showMenu();
            break;
        case 2:
            std::cout << "Thank you for playing! :)" << std::endl;
            exit(0);
    }
}



Fruit* GameManager::getRandomFruit(int position)
{
    int sum = (rand() % 15) + 1;
    randomFruit[0]->modifyIdentifier(sum);
    randomFruit[1]->modifyIdentifier(sum);
    Fruit* changedFruit = randomFruit[position];
    return changedFruit;

}

std::vector<Fruit*> GameManager::getActualFruit()
{
    return randomFruit;
}

void GameManager::deleteFruits()
{
    for(Fruit* fruit : this->randomFruit)
        delete fruit;
    this->randomFruit.clear();
}



