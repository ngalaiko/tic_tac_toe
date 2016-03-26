#ifndef HARD_H
#define HARD_H
#include "tic_tac_toe.h"

class hard : public tic_tac_toe
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
        //делаем ход компьютера
        if (isCompFirst)
        {
            //если можем выиграть, выигрываем, если нет, пробуем помешать выиграть противнику
            int win = this->getWinCell('X');
            int prevent = this->getWinCell('O');
            if (win)
            {
                num = win;
            }
            else if (prevent)
            {
                num = prevent;
            }
            field[num / 3][num % 3 - 1] = 'X';
        }
        else
        {
            //если можем выиграть, выигрываем, если нет, пробуем помешать выиграть противнику
            int win = this->getWinCell('O');
            int prevent = this->getWinCell('X');
            if (win)
            {
                num = win;
            }
            else if (prevent)
            {
                num = prevent;
            }
            field[num / 3][num % 3 - 1] = 'O';
        }
    }
public:
    hard() {}
};

#endif // HARD_H
