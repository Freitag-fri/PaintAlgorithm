#ifndef CELL_H
#define CELL_H
#include <QMainWindow>


class Cell
{

public:
    Cell();

    void SetWidth(int width);
    void SetHeight(int height);
    void SetLife(int life);

    int GetWidth();
    int GetHeight();
    int GetLife();

private:
    int width;
    int height;
    int life;
};

#endif // CELL_H
