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
    moveIsOver = false;
    //act = actStand;
}

Cell::Cell()
{

}

int Cell::deadCell = 0;     //иницилизация статической переменной

int Cell::RandMove()
{
    int tempCurrentPos = 0;
    if(arrAct[currentPos] == 0)         //стоять на месте
    {
        act = actStand;
    }
    else if (arrAct[currentPos] <= 8)    //движение
    {
        act = actMove;
        tempCurrentPos = arrAct[currentPos] - 1;
    }
    else if (arrAct[currentPos] <= 16)    //посмотреть
    {
        act = actLook;
        tempCurrentPos = arrAct[currentPos] - 9;
    }
    else if (arrAct[currentPos] <= 24)    //взять
    {
        act = actgGrab;
        tempCurrentPos = arrAct[currentPos] - 17;
    }
    else
    {   act =actPass;
        AddCurrentPos(arrAct[currentPos]);
    }
    return tempCurrentPos;
}

void Cell::NextObj(int obj, int width, int height)
{
    if (act == actStand)
    {
        moveIsOver = true;
        AddCurrentPos(1);
        HealtDown(1);

    }
    else if (act == actMove)    //!!
    {
        AddCurrentPos(obj);
        moveIsOver = true;
        Move(obj, width, height);
        HealtDown(1);
    }
    else if (act == actLook)
    {
        AddCurrentPos(obj);
    }
    else if (act == actgGrab)
    {
        AddCurrentPos(obj);
        moveIsOver = true;
        HealtDown(1);
    }
    else if (act == actPass){}
}

void Cell::Move(int nextObj, int width, int height)
{
    if(nextObj == cageNull || nextObj == cageFood)
    {
        MainWindow::arrPosition[widthPosition][heightPosition]=cageNull;
        widthPosition +=width;
        heightPosition +=height;
        MainWindow::arrPosition[widthPosition][heightPosition]=cageObj;
    }
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
        MainWindow::arrPosition[widthPosition][heightPosition]=cageNull;
        deadCell++;
    }
}

bool Cell::GetLife()
{
    return life;
}

bool Cell::GetMoveIsOver()
{
    return moveIsOver;
}

void Cell::SetMoveIsOver(bool n)
{
   moveIsOver = n;
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

void Cell::AddCurrentPos(int val)
{
    currentPos += val;
    if (currentPos > sizeArrAct-1)
    {
      currentPos -= sizeArrAct;
    }
}

