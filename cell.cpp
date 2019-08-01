#include "cell.h"
#include "mainwindow.h"

Cell::Cell()
{
    widthPosition = 0;
    heightPosition = 0;
    width = 0;
    height = 0;
    life = 50;
}



int Cell::GetLife()
{
    return life;
}

int Cell::GetWidth()
{
    return width;
}

int Cell::GetHeight()
{
    return height;
}

int Cell::GetHeightPos()
{
    return heightPosition;
}

int Cell::GetWidthPos()
{
    return widthPosition;
}

void Cell::SetLife(int life)
{
   this->life = life;
}

void Cell::SetWidth(int width, int widthCell)
{
    widthPosition = width/widthCell;
    life--;
    this ->width = width;
}

void Cell::SetHeight(int height, int heightCell)
{
    heightPosition = height/heightCell;
    life--;
    this ->height = height;
}
