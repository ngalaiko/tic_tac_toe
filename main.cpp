#include <iostream>
#include "easy.h"
#include "medium.h"
#include "hard.h"

using namespace std;

int main()
{
    int p;
    tic_tac_toe *game;
    std::cout << std::endl << "Игра \"Крестики-Нолики\"" << std::endl;
    do
    {
        std::cout << std::endl << "Меню:" << std::endl;
        std::cout << "1. Низкий уровень сложности." << std::endl;
        std::cout << "2. Средний уровень сложности." << std::endl;
        std::cout << "3. Высокий уровень сложности." << std::endl;
        std::cout << "4. Выход." << std::endl;
        std::cout << std::endl << "Введите команду:" << std::endl;
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
            std::cout << "Пока!" << std::endl;
            break;
        default:
            std::cout << "Нет такого пункта!" << std::endl;
            break;
        }
    }
    while (p != 4);
}

