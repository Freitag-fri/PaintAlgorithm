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
    void Move(int nextObj, int width, int height);


    int GetWidthPos();
    int GetHeightPos();
    int GetWidth();
    int GetHeight();
    int GetHealth();
    bool GetDeadCell();
    bool GetLife();
    bool GetMoveIsOver();
    void SetMoveIsOver(bool n);

    int RandMove();

    void NextObj(int obj, int , int);



    static int deadCell;

    Cell& operator =(Cell& obj) // Оператор присваивания
        {
            this->life = obj.life;
            this->health = obj.health;
            return *this;
        }

private:
    enum act {actStand, actMove, actLook, actgGrab, actPass};    //возможные действия
    int act;                    //кокое действие обект совершает
    int width;
    int height;
    int health;
    int widthPosition;
    int heightPosition;
    int currentPos;             //слудующий элемент в массиве
    void AddCurrentPos(int val);




    bool life;                  //жив или нет обект
    bool moveIsOver;            // закончен ход


    static const int sizeArrAct = 25;
    int arrAct[sizeArrAct];
};

#endif // CELL_H
