#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <conio.h>
#include <curses.h>
#include <iostream>
#include "Fruit.h"
#include "GameManager.h"
using namespace std;

class Interface
{
private:
    int width=20;
    int height=20;

public:
    Interface();
    int showMenu();
    void printBoard(int x, int y, int fruitY, int fruitX, int secFruitY, int secFruitX, int nTail, int* tailX, int* tailY, int score, std::vector<Fruit*> fruitVec, int x2=-1, int y2=-1, int nTail2=-1, int* tailX2=0, int* tailY2=0, int score2=-1);
    void showCredits();
    void showInstructions();

};

#endif // INTERFACE_H
