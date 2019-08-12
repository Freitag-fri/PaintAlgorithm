#include "cell.h"
#include "mainwindow.h"

Cell::Cell(int widthPosition, int heightPosition, int sizeCell)
{
    for (int i = 0; i < sizeArrAct; i++)
    {
      arrAct[i] = rand()% sizeArrAct;     //заполнение массива случайными действиями
    }

    currentPos = 0;
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
    if(currentPos == 0)         //стоять на месте
    {
        HealtDown(1);
        currentPos++;
        return 0;
    }
    else if (currentPos <= 8)    //движение
    {}
    else if (currentPos <= 16)    //посмотреть
    {}
    else if (currentPos <= 24)    //взять
    {}

    //return rand() %5;
}

void Cell::NextObj(int obj)
{

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



