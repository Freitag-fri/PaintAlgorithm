#include "cell.h"
#include "mainwindow.h"
void AddFood();
void AddVenom();

Cell::Cell(int widthPosition, int heightPosition/*, int sizeCell*/)
{
    for (int i = 0; i < sizeArrAct; i++)
    {
        arrAct[i] = rand()% sizeArrAct;     //заполнение массива случайными действиями
    }

    this -> widthPosition = widthPosition;
    this -> heightPosition = heightPosition;
    //width = widthPosition * sizeCell;
    //height = heightPosition * sizeCell;
    SetObj();
    //act = actStand;
}

Cell::Cell()
{

}

int Cell::deadCell = 0;     //иницилизация статической переменной

void Cell::SetObj()
{
    currentPos = rand()% sizeArrAct;
    health = 60;
    life = true;
    moveIsOver = false;
}

int Cell::RandMove()
{
    int tempCurrentPos = 0;
    //    if(arrAct[currentPos] == 0)         //стоять на месте
    //    {
    //        act = actStand;
    //    }
    /*else*/ if (arrAct[currentPos] < 8)    //движение
    {
        act = actMove;
        tempCurrentPos = arrAct[currentPos];
    }
    else if (arrAct[currentPos] < 16)    //посмотреть
    {
        act = actLook;
        tempCurrentPos = arrAct[currentPos] - 8;
    }
    else if (arrAct[currentPos] < 24)    //взять
    {
        act = actgGrab;
        tempCurrentPos = arrAct[currentPos] - 16;
    }
    else if(arrAct[currentPos] == 24)         //стоять на месте
    {
        act = actStand;
    }
    else
    {   act =actPass;
    }

    return tempCurrentPos;
}

void Cell::NextObj(int obj, int width, int height)
{
    numberPasses ++;
    if (act == actStand)
    {
        moveIsOver = true;
        currentPos = AddCurrentPos(1, currentPos);       //увеличение позиции массива на 1
        HealtDown(1);
    }
    else if (act == actMove)
    {
        currentPos = AddCurrentPos(obj, currentPos);
        moveIsOver = true;
        Move(obj, width, height);
        HealtDown(1);
    }
    else if (act == actLook)
    {
        currentPos = AddCurrentPos(obj, currentPos);
    }
    else if (act == actgGrab)
    {
        currentPos = AddCurrentPos(obj, currentPos);
        moveIsOver = true;
        Grab (obj, width, height);
        HealtDown(1);
    }
    else if (act == actPass)
    {
        currentPos = AddCurrentPos(arrAct[currentPos], currentPos);
    }
}

void Cell::Move(int nextObj, int width, int height)
{
    if(nextObj == cageNull || nextObj == cageFood)
    {
        if ( nextObj == cageFood)
        {
            HealtUp(15);
            AddFood();
        }
        MainWindow::arrPosition[widthPosition][heightPosition]=cageNull;
        widthPosition +=width;
        heightPosition +=height;
        MainWindow::arrPosition[widthPosition][heightPosition]=cageObj;
    }
    else if(nextObj == cageVenom)
    {
        MainWindow::arrPosition[widthPosition][heightPosition]=cageNull;
        widthPosition +=width;
        heightPosition +=height;
        HealtDown(health-1);
        AddVenom();
        MainWindow::venomKill++;
    }
}

void Cell::Grab (int nextObj, int width, int heigh)
{
    if (nextObj == cageFood)
    {
        HealtUp(15);
        AddFood();
        MainWindow::arrPosition[widthPosition+width][heightPosition+heigh]=cageNull;
    }
    if(nextObj == cageVenom)
    {
        MainWindow::venomEat++;
        HealtUp(15);
        AddVenom();
        MainWindow::arrPosition[widthPosition+width][heightPosition+heigh]=cageNull;
    }
}

void AddFood()
{
    MainWindow::SetFood();
}

void AddVenom()
{
    MainWindow::SetVenom();
}

int Cell::GetHealth()
{
    return health;
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
    if (deadCell == 72)
        return true;
    else
        return false;
}

void Cell::HealtUp(int health)
{
    this -> health += health;
    if (this ->health >200)
        this ->health = 200;
}

void Cell::HealtDown(int health)
{
    this->health -= health;
    if(this->health <= 0)
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

void Cell::SetWidthPos(int widthPosition)
{
    this->widthPosition = widthPosition;
}
void Cell::SetHeightPos(int heightPosition)
{
    this->heightPosition = heightPosition;
}

int Cell::AddCurrentPos(int addVal, int val)
{
    int temp = val+addVal;
    if (temp > sizeArrAct-1)
    {
        temp -= sizeArrAct;
    }
    return temp;
}

void Cell::Mutation()
{
    if(rand() %100 <40)
    {
        for(int i = 0, element; i < 5; i++)
        {
            element = rand()%sizeArrAct;
            arrAct[element] = AddCurrentPos(rand()%6, arrAct[element]);
        }
    }
}
