#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

//перечисляем цвета
enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

class tic_tac_toe
{
protected:
    //поле
    char field[3][3];
    //поле с номерами ячеек
    char field_full[3][3];
    //ходит ли компьютер первым
    bool isCompFirst;
    //сделать ход
    virtual void move() {}
    //проверить, закончна ли игра и вернуть символ того, что выиграл (x или о)
    char checkIfEnd();
    //дать сходить игроку
    void getMove();
    //нарисовать поле
    void draw(char field[][3]);
    //функция, возвращающая номер победной ячейки
    int getWinCell(char mark);
    //функция смены цвета
    void SetColor(ConsoleColor text, ConsoleColor background);

public:
    //констуктор
    tic_tac_toe();
    //начать игру
    void play();
};

#endif // TIC_TAC_TOE_H
