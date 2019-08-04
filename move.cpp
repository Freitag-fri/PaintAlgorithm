#include "mainwindow.h"
#include <windows.h>

void MainWindow::MotionOption()
{  bool hod = false;
   for(int i = 0; i < quantityCell; i++)
   {
       if(CellObj[i]->GetHealth() == 0)  //жив ли обект
           //arrPosition[CellObj[i]->GetWidthPos()][CellObj[i]->GetHeightPos()] = cageNull;
           CellObj[i]->HealtDown(2);
        if(!CellObj[i]->GetLife())  //жив ли обект
            continue;

        int n = CellObj[i]->RandMove();                     //получаем направление хода

        if (n == 0) hod = Up(i);
        else if (n == 1) hod = Down(i);
        else if (n == 2) hod = Left(i);
        else if (n == 3) hod = Right(i);
        else if (n == 4)
        {
            CellObj[i]->HealtDown(1);
            if (CellObj[i]->GetLife())
                ChangArr(i, cageObj);
            else
                ChangArr(i, cageNull);
            continue;
        }

        if (!hod) i--;
   }
}

bool MainWindow::Up(int i)
{
    int next = NextStatus(CellObj[i]->GetWidthPos(), CellObj[i]->GetHeightPos()-1);

    if(CellObj[i]->GetHeightPos() > 0 && next != cageLet && next != cageObj)
    {
        if(next == cageFood)
        {
            CellObj[i]->HealtUp();
            SetFood();
        }

        ChangArr(i, cageNull);
        CellObj[i]->SetHeight(CellObj[i]->GetHeight() - heightCell, heightCell);

        if (CellObj[i]->GetLife())
            ChangArr(i, cageObj);
        else
            ChangArr(i, cageNull);
        return true;
    }
    else return false;
}

bool MainWindow::Down(int i)
{
    int next = NextStatus(CellObj[i]->GetWidthPos(), CellObj[i]->GetHeightPos()+1);

    if(CellObj[i]->GetHeightPos() < maxPositionWidth-1  && next != cageLet && next != cageObj)
    {
        if(next == cageFood)
        {
            CellObj[i]->HealtUp();
            SetFood();
        }

        ChangArr(i, cageNull);
        CellObj[i]->SetHeight(CellObj[i]->GetHeight() + heightCell, heightCell);

        if (CellObj[i]->GetLife())
            ChangArr(i, cageObj);
        else
            ChangArr(i, cageNull);
        return true;
    }
    else return false;
}

bool MainWindow::Right(int i)
{
    int next = NextStatus(CellObj[i]->GetWidthPos()+1, CellObj[i]->GetHeightPos());

    if(CellObj[i]->GetWidthPos() < maxPositionWidth-1  && next != cageLet && next != cageObj)
    {
        if(next == cageFood)
        {
            CellObj[i]->HealtUp();
            SetFood();
        }

        ChangArr(i, cageNull);
        CellObj[i]->SetWidth(CellObj[i]->GetWidth() + widthCell, widthCell);
        if (CellObj[i]->GetLife())
            ChangArr(i, cageObj);
        else
            ChangArr(i, cageNull);

        return true;
    }
    else return false;
}

bool MainWindow::Left(int i)
{
    int next = NextStatus(CellObj[i]->GetWidthPos()-1, CellObj[i]->GetHeightPos());

    if(CellObj[i]->GetWidthPos() > 0  && next != cageLet && next != cageObj)
    {
        if(next == cageFood)
        {
            CellObj[i]->HealtUp();
            SetFood();
        }

        ChangArr(i, cageNull);
        CellObj[i]->SetWidth(CellObj[i]->GetWidth() - widthCell, widthCell);
        if (CellObj[i]->GetLife())
            ChangArr(i, cageObj);
        else
            ChangArr(i, cageNull);

        return true;
    }
    else return false;
}

void MainWindow::ChangArr(int index, int status)            //изменение значений массива положений
{
  arrPosition[CellObj[index]->GetWidthPos()][CellObj[index]->GetHeightPos()] = status;
}

int MainWindow::NextStatus(int GetWidthPosition, int GetHeightPosition)
{
  return arrPosition[GetWidthPosition][GetHeightPosition];
}
