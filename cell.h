#ifndef CELL_H
#define CELL_H
#include <QMainWindow>


class Cell
{

public:
    Cell(int widthPosition, int heightPosition, int sizeCell);
    Cell();


    void SetWidth(int width, int widthCell);

    void SetHeight(int height, int heightCell);

    void HealtUp(/*int health*/);
    void HealtDown(int health);



    int GetWidthPos();
    int GetHeightPos();
    int GetWidth();
    int GetHeight();
    int GetHealth();
    bool GetDeadCell();
    bool GetLife();

    int RandMove();

    static int deadCell;

    Cell& operator =(Cell& obj) // Оператор присваивания
        {
            this->life = obj.life;
            this->health = obj.health;
            return *this;
        }

private:
    int width;
    int height;
    int health;
    int widthPosition;
    int heightPosition;

          //количесво умерших обектов

    bool life;                  //жив или нет обект

};

#endif // CELL_H
