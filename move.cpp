#include "mainwindow.h"
#include <windows.h>
#include "ui_mainwindow.h"

void MainWindow::MotionOption()
{  //bool hod = false;
    int Width = 0;
    int Height = 0;
    int index = 0;
    int nextObj = 0;

    for(int obj = 0; obj < quantityCell; obj++)
    {

        if(CellObj[obj]->GetDeadCell())       //новое поколение
        {
            Breed();
            break;
        }

        if(!CellObj[obj]->GetLife())  //жив ли обект
            continue;

        index = CellObj[obj]->RandMove();                     //получаем направление

        nextObj = Route(obj, index, &Width, &Height);           //получаем следующий обект

        CellObj[obj]->NextObj(nextObj, Width, Height);

        if ( CellObj[obj]->numberPasses >=50 && !CellObj[obj]->GetMoveIsOver())       //закончен ход
        {
            CellObj[obj]->numberPasses = 0;
            CellObj[obj]->HealtDown(1);
            CellObj[obj]->SetMoveIsOver(false);

            //            MainWindow::update();
            //            QApplication::processEvents();
            //            Sleep(20);
        }
        else if (!CellObj[obj]->GetMoveIsOver())
            obj--;
        else
        {
            CellObj[obj]->SetMoveIsOver(false);

            //            MainWindow::update();
            //            QApplication::processEvents();
            //            Sleep(20);
        }
    }
}

int MainWindow::Route(int obj,int index, int *Width, int *Height)
{
    *Width = routeWidth[index];
    *Height = routeHeight[index];
    return NextStatus(CellObj[obj]->GetWidthPos() + *Width, CellObj[obj]->GetHeightPos()+ *Height);
}

void MainWindow::ChangArr(int index, int status)            //изменение значений массива положений
{
    arrPosition[CellObj[index]->GetWidthPos()][CellObj[index]->GetHeightPos()] = status;
}

int MainWindow::NextStatus(int GetWidthPosition, int GetHeightPosition)
{
    return arrPosition[GetWidthPosition][GetHeightPosition];
}
