#ifndef CELL_H
#define CELL_H
#include <QMainWindow>


class Cell
{

public:
    Cell(int widthPosition, int heightPosition, int sizeCell);

    void SetWidth(int width, int widthCell);

    void SetHeight(int height, int heightCell);

    void HealtUp(/*int health*/);
    void HealtDown(int health);


    int GetWidthPos();
    int GetHeightPos();
    int GetWidth();
    int GetHeight();
    int GetHealth();
    bool GetLife();

    int RandMove();

private:
    int width;
    int height;
    int health;
    int widthPosition;
    int heightPosition;

    bool life;

};

#endif // CELL_H
