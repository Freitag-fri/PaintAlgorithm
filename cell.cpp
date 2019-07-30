#include "cell.h"

Cell::Cell()
{
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

void Cell::SetLife(int life)
{
   this->life = life;
}

void Cell::SetWidth(int width)
{
    this ->width = width;
}

void Cell::SetHeight(int height)
{
    this ->height = height;
}
