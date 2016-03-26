#ifndef MEDIUM_H
#define MEDIUM_H
#include "tic_tac_toe.h"

class medium : public tic_tac_toe
{
private:
    virtual void move()
    {
        //массив с номерами пустых ячеек и их количество
        int a[9], n = 0;
        //ищем все свободные ячейки, в которых возможна победа
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
            //если есть выиграшная ячейка, ставим туда
            if (this->getWinCell('X'))
            {
                num = this->getWinCell('X');
            }
            field[num / 3][num % 3 - 1] = 'X';
        }
        else
        {
            //если есть выиграшная ячейка, ставим туда
            if (this->getWinCell('O'))
            {
                num = this->getWinCell('O');
            }
            field[num / 3][num % 3 - 1] = 'O';
        }
    }

public:
    medium() {}
};

#endif // MEDIUM_H
