#include "Interfaz.h"
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "FruitManager.h"

Snake snake;
Interfaz::Interfaz()
{
}
int Interfaz::menu(){
    FruitManager control;
    int option=0;
    bool hideMenu = true;
    while(hideMenu){ //
        hideMenu = false;
        std::cout<<"SNAKE GAME"<<endl;
        std::cout<<endl<<"Press 1 to play"<<endl;
        std::cout<<endl<<"Press 2 to play multiplayer"<<endl;
        std::cout<<endl<<"Press 3 to exit game"<<endl;
        std::cin>>option;

        switch(option){
            case 1:
                control.iniciate();
                break;
            case 2:
                control.iniciateMultiplayer();
                break;
            case 3:
                std::cout<<"Are you sure you want to exit? "<<endl;
                std::cout<<"Press 1: yes "<<endl;
                std::cout<<"Press 2: no  "<<endl;
                std::cin>>option;
                if(option==1){
                    return 0;
                }
                else{
                   hideMenu = true;
                }
                break;
            default:
                hideMenu = true;
                break;
            }
    }
    return 0;
}

void Interfaz::draw(int x, int y, int fruitY, int fruitX, int secFruitY, int secFruitX, int nTail, int* tailX, int* tailY, int score, std::vector<Fruit*> fruitVec, int x2, int y2, int nTail2, int* tailX2, int* tailY2, int score2)
{

    system("cls"); //system("clear");
    for (int i = 0; i < this->width+2; i++)
        std::cout << "#";
    std::cout << endl;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (j == 0)
                std::cout << "#";
            if (i == y && j == x)
                std::cout << "O";
            if  (y2!=-1 && i== y2 && j== x2)
                {
                    std::cout << "X";
                }


            else if (i == fruitY && j == fruitX)
                std::cout << *fruitVec[0];
            else if (i == secFruitY && j == secFruitX)
                std::cout << *fruitVec[1];
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }

                if (nTail2!=-1)
                {
                    for (int k = 0; k < nTail2; k++)
                     {

                        if (tailX2[k] == j && tailY2[k] == i)
                        {
                            std::cout << "x";
                            print = true;
                        }
                     }
                }

                if (!print)
                    std::cout << " ";
            }


            if (j == this->width - 1)
                std::cout << "#";
        }
        std::cout << endl;
    }

    for (int i = 0; i < this->width+2; i++)
        std::cout << "#";
    std::cout << endl;
    std::cout << "Score:" << score << endl;
    if (score2!=-1){
        std::cout << "ScoreX:" << score2 << endl;
    }
}




