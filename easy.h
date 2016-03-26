#ifndef EASY_H
#define EASY_H
#include "tic_tac_toe.h"

class easy: public tic_tac_toe
{
private:
    virtual void move()
    {
        //массив с номерами пустых ячеек и их количество
        int a[9], n = 0;
        //ищем все свободные ячейки
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (field[i][j] == '-')
                {
                    a[n++] = (i) * 3 + (j + 1);
                }
            }
        }
        //выбираем случайную пустую ячейку
        srand(time(NULL));
        int num = a[rand() % n];
        //делаем ход игрока
        if (isCompFirst)
        {
            field[num / 3][num % 3 - 1] = 'X';
        }
        else
        {
            field[num / 3][num % 3 - 1] = 'O';
        }
    }

public:
    easy() {}
};

#endif // EASY_H
