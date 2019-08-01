#include "mainwindow.h"


void MainWindow::Up()
{
    int next = NextStatus(nClass[0].GetWidthPos(), nClass[0].GetHeightPos()-1);

    if(nClass[0].GetHeightPos() > 0 && next != 1)
    {
        if(next == 3) nClass[0].SetLife(nClass[0].GetLife()+11);

        ChangArr(0, 0);
        nClass[0].SetHeight(nClass[0].GetHeight() - heightCell, heightCell);
        ChangArr(0, 2);
    }
    MainWindow::update();
}

void MainWindow::Down()
{
    int next = NextStatus(nClass[0].GetWidthPos(), nClass[0].GetHeightPos()+1);

    if(nClass[0].GetHeightPos() < maxPositionWidth-1  && next != 1)
    {
        if(next == 3) nClass[0].SetLife(nClass[0].GetLife()+11);

        ChangArr(0, 0);
        nClass[0].SetHeight(nClass[0].GetHeight() + heightCell, heightCell);
        ChangArr(0, 2);
    }
    MainWindow::update();
}

void MainWindow::Right()
{
    int next = NextStatus(nClass[0].GetWidthPos()+1, nClass[0].GetHeightPos());

    if(nClass[0].GetHeightPos() < maxPositionWidth-1  && next != 1)
    {
        if(next == 3) nClass[0].SetLife(nClass[0].GetLife()+11);

        ChangArr(0, 0);
        nClass[0].SetWidth(nClass[0].GetWidth() + widthCell, widthCell);
        ChangArr(0, 2);
    }
    MainWindow::update();
}

void MainWindow::Left()
{
    int next = NextStatus(nClass[0].GetWidthPos()-1, nClass[0].GetHeightPos()+1);

    if(nClass[0].GetHeightPos() > 0  && next != 1)
    {
        if(next == 3) nClass[0].SetLife(nClass[0].GetLife()+11);

        ChangArr(0, 0);
        nClass[0].SetWidth(nClass[0].GetWidth() - widthCell, widthCell);
        ChangArr(0, 2);
    }
    MainWindow::update();
}

void MainWindow::ChangArr(int index, int status)            //изменение значений массива положений
{
  arrPosition[nClass[index].GetWidthPos()][nClass[index].GetHeightPos()] = status;
}

int MainWindow::NextStatus(int GetWidthPosition, int GetHeightPosition)
{
  return arrPosition[GetWidthPosition][GetHeightPosition];
}
