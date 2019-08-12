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

    void NextObj(int obj);

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
    int currentPos;             //слудующий элемент в массиве


    bool life;                  //жив или нет обект


    static const int sizeArrAct = 50;
    int arrAct[sizeArrAct];
};

#endif // CELL_H
