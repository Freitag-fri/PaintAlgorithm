#include "cell.h"
#include "mainwindow.h"

Cell::Cell(int widthPosition, int heightPosition, int sizeCell)
{
    this -> widthPosition = widthPosition;
    this -> heightPosition = heightPosition;
    width = widthPosition * sizeCell;
    height = heightPosition * sizeCell;
    health = 40 ;
    life = true;
}

Cell::Cell()
{

}

int Cell::deadCell = 0;     //иницилизация статической переменной

int Cell::RandMove()
{
    return rand() %5;
}

int Cell::GetHealth()
{
    return health;
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

bool Cell::GetDeadCell()
{
    if (deadCell == 20)
        return true;
    else
        return false;
}

void Cell::HealtUp(/*int Healt*/)
{
   health += 11;
}


void Cell::HealtDown(int health)
{
    this->health -= health;
    if(this ->health == 0)
    {
        life = false;
        deadCell++;
    }
}

bool Cell::GetLife()
{
    return life;
}

void Cell::SetWidth(int width, int widthCell)
{
    widthPosition = width/widthCell;  
    this ->width = width;
    HealtDown(1);

//    if (health <=0)
//        life = false;
}

void Cell::SetHeight(int height, int heightCell)
{
    heightPosition = height/heightCell;
    this ->height = height;
    HealtDown(1);

//    if (health <=0)
//        life = false;
}



