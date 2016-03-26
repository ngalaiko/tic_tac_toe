#include <iostream>
#include "easy.h"
#include "medium.h"
#include "hard.h"

using namespace std;

int main()
{
    system( "color F0" );
    //переменная для считывания команды
    int p;
    //указатель на базовый класс игр
    tic_tac_toe *game;
    std::cout << std::endl << "The \"Tic-Tac-Toe\" game" << std::endl;
    do
    {
        std::cout << std::endl << "Menu:" << std::endl;
        std::cout << "1. Easy." << std::endl;
        std::cout << "2. Medium." << std::endl;
        std::cout << "3. Hard." << std::endl;
        std::cout << "4. Exit." << std::endl;
        std::cout << std::endl << "Please, input option:" << std::endl;
        std::cin >> p;
        switch(p)
        {
        case 1:
            game = new easy();
            game->play();
            break;
        case 2:
            game = new medium();
            game->play();
            break;
        case 3:
            game = new hard();
            game->play();
            break;
        case 4:
            std::cout << "Bye!" << std::endl;
            break;
        default:
            std::cout << "No such option!" << std::endl;
            break;
        }
    }
    while (p != 4);
}

