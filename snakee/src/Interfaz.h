#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "Fruit.h"
#include "FruitManager.h"
using namespace std;

class Interfaz
{
private:
    int width=20;
    int height=20;

public:
    Interfaz();
    int menu();
    void draw(int x, int y, int fruitY, int fruitX, int secFruitY, int secFruitX, int nTail, int* tailX, int* tailY, int score, std::vector<Fruit*> fruitVec, int x2=-1, int y2=-1, int nTail2=-1, int* tailX2=0, int* tailY2=0, int score2=-1);

};

#endif // INTERFAZ_H
