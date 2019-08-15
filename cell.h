#ifndef CELL_H
#define CELL_H
#include <QMainWindow>


class Cell
{

public:
    Cell(int widthPosition, int heightPosition/*, int sizeCell*/);
    Cell();
    void SetObj();

    //void SetWidth(int width, int widthCell);

    //void SetHeight(int height, int heightCell);

    void HealtUp(int health);
    void HealtDown(int health);
    void Move(int nextObj, int width, int height);  //перемещение
    void Grab (int nextObj, int width, int heigh);  //схватить


    int GetWidthPos();
    int GetHeightPos();
    //int GetWidth();
    //int GetHeight();
    int GetHealth();
    bool GetDeadCell();
    bool GetLife();
    bool GetMoveIsOver();
    void SetMoveIsOver(bool n);
    void SetWidthPos(int pos);
    void SetHeightPos(int pos);

    int RandMove();

    void NextObj(int obj, int , int);

    void Mutation();

    static int deadCell;

    Cell& operator =(Cell& obj) // Оператор присваивания
    {
        for(int i = 0; i < sizeArrAct; i++)
            this->arrAct[i] = obj.arrAct[i];
        SetObj();
        return *this;
    }

    int numberPasses = 0;

private:
    enum act {actStand, actMove, actLook, actgGrab, actPass};    //возможные действия
    int act;                    //кокое действие обект совершает
    //int width;
    //int height;
    int health;
    int widthPosition;
    int heightPosition;
    int currentPos;             //слудующий элемент в массиве
    int AddCurrentPos(int addVal, int val);





    bool life;                  //жив или нет обект
    bool moveIsOver;            // закончен ход


    static const int sizeArrAct = 25;
    int arrAct[sizeArrAct];
};

#endif // CELL_H
