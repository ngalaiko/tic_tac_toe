#include "tic_tac_toe.h"

tic_tac_toe::tic_tac_toe()
{
    //обнуляем поле
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            field[i][j] = '-';
            field_full[i][j] = (i) * 3 + (j + 1) + '0';
        }
    }
    //случайное значение (0 или 1)
    srand(time(NULL));
    isCompFirst = rand() % 2;

    this->SetColor(White, Black);
}

int tic_tac_toe::getWinCell(char mark)
{
    //выиграшная ячейка
    int result = 0;
    //проверяем строки
    for (int i = 0; i < 3; i++)
    {
        //количество символов mark в строке
        int nrow = 0;
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] == mark)
            {
                nrow++;
            }
            if (field[i][j] == '-')
            {
                result = (i) * 3 + (j + 1);
            }
        }
        //если в строке не хватает одного символа, возвращаем номер его ячейки
        if (nrow == 2)
        {
            std::cout << "строка!" << std::endl;
            return result;
        }
    }
    //проверяем столбцы
    for (int j = 0; j < 3; j++)
    {
        //количество символов mark в строке
        int ncol = 0;
        for (int i = 0; i < 3; i++)
        {
            if (field[i][j] == mark)
            {
                ncol++;
            }
            if (field[i][j] == '-')
            {
                result = (i) * 3 + (j + 1);
            }
        }
        //если в столбце не хватает одного символа, возвращаем номер его ячейки
        if (ncol == 2)
        {
            std::cout << "столбец!" << std::endl;
            return result;
        }
    }
    //проверяем главную диагональ
    int ngl = 0;
    for (int i = 0; i < 3; i++)
    {
        if (field[i][i] == mark)
        {
            ngl++;
        }
        if (field[i][i] == '-')
        {
            result = (i) * 3 + (i + 1);
        }
    }
    if (ngl == 2)
    {
        std::cout << "главная!" << std::endl;
        return result;
    }
    //проверяем побочную диагональ
    int npob = 0;
    for (int i = 0; i < 3; i++)
    {
        if (field[i][2 - i] == mark)
        {
            npob++;
        }
        if (field[i][2 - i] == '-')
        {
            result = (i) * 3 + (3 - i);
        }
    }
    if (npob == 2)
    {
        std::cout << "побочная!" << std::endl;
        return result;
    }
    return 0;
}

void tic_tac_toe::play()
{
    std::cout << std::endl << "Игра началась!" << std::endl;
    this->draw(field);
    if (isCompFirst)
    {
        std::cout << "Вы играете О, ход компьютера..." << std::endl;
        do
        {
            std::cout << std::endl  << "Компьютер делает ход:" << std::endl;
            this->move();
            this->draw(field);
            if (this->checkIfEnd() != '+')
                break;
            std::cout << std::endl;
            this->draw(field_full);
            std::cout << std::endl  << "Сделайте ваш ход:" << std::endl;
            this->getMove();
            this->draw(field);
        }
        while (this->checkIfEnd() == '+');
    }
    else
    {
        std::cout << "Вы играете X, ваш ход... " << std::endl;
        do
        {
            std::cout << std::endl;
            this->draw(field_full);
            std::cout << std::endl  << "Сделайте ваш ход:" << std::endl;
            this->getMove();
            this->draw(field);
            if (this->checkIfEnd() != '+')
                break;
            std::cout << std::endl << "Компьютер делает ход:" << std::endl;
            this->move();
            this->draw(field);
        }
        while (this->checkIfEnd() == '+');
    }
    if (this->checkIfEnd() == 'X')
    {
        std::cout << "X победил!" << std::endl;
    }
    else if (this->checkIfEnd() == 'O')
    {
        std::cout << "O победил!" << std::endl;
    }
    else
    {
        std::cout << "Ничья!" << std::endl;
    }
}

void tic_tac_toe::getMove()
{
    int num;
    do
    {
        std::cout << "Введите номер ячейки для хода: ";
        std::cin >> num;
    }
    while (field[num / 3][num % 3 - 1] != '-');
    //делаем ход игрока
    if (isCompFirst)
    {
        field[num / 3][num % 3 - 1] = 'O';
    }
    else
    {
        field[num / 3][num % 3 - 1] = 'X';
    }
}

void tic_tac_toe::draw(char field[][3])
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << '|';
        for (int j = 0; j < 3; j++)
        {
            std::cout << field[i][j] << '|';
        }
        std::cout << std::endl;
    }
}

char tic_tac_toe::checkIfEnd()
{
    //если победитель на диагоналях
    if ((field[2][0] == field[1][1] && field[1][1] == field[0][2] && field[1][1] != '-') || (field[0][0] == field[1][1] && field[1][1] == field[2][2]) && field[1][1] != '-')
    {
        return field[1][1];
    }
    int not_empty = 0;
    for (int i = 0; i < 3; i++)
    {
        //считаем непустые ячейки
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] != '-')
            {
                not_empty++;
            }
        }
        //если по горизонтали победитель - возвращаем его
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != '-')
        {
            return field[i][0];
        }
        //если по вертикале победитель - возвращаем его
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != '-')
        {
            return field[0][i];
        }
    }
    //если все занято, возвращаем ничью
    if (not_empty == 9)
    {
        return '-';
    }
    //возвращаем что игра не окончена
    return '+';
}

void tic_tac_toe::SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
