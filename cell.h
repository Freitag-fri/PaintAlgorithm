#ifndef CELL_H
#define CELL_H
#include <QMainWindow>


class Cell
{

public:
    Cell();

    void SetWidth(int width, int widthCell);

    void SetHeight(int height, int heightCell);
    void SetLife(int life);


    int GetWidthPos();
    int GetHeightPos();
    int GetWidth();
    int GetHeight();
    int GetLife();

private:
    int width;
    int height;
    int life;
    int widthPosition;
    int heightPosition;

};

#endif // CELL_H
