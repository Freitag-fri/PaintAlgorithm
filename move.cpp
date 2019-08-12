#include "mainwindow.h"
#include <windows.h>

void MainWindow::MotionOption()
{  bool hod = false;
    for(int i = 0; i < quantityCell; i++)
    {
        if(CellObj[i]->GetDeadCell())       //новое поколение
        {
            Breed();
            break;
        }

        if(!CellObj[i]->GetLife())  //жив ли обект
            continue;

        int n = CellObj[i]->RandMove();                     //получаем направление

        if (!n) continue;                                   //если осмотр соседних ячеек нинадо, то пропускаем
        else if (n == N_) CellObj[i]->NextObj(N(i));
        else if (n == NE_)  CellObj[i]->NextObj(NE(i));
        else if (n == E_)   CellObj[i]->NextObj(E(i));
        else if (n == SE_)  CellObj[i]->NextObj(SE(i));
        else if (n == S_)   CellObj[i]->NextObj(S(i));
        else if (n == SW_)  CellObj[i]->NextObj(SW(i));
        else if (n == W_)   CellObj[i]->NextObj(W(i));
        else if (n == NW_)  CellObj[i]->NextObj(NW(i));
        //        else if (n == 4)
        //        {
        //            CellObj[i]->HealtDown(1);
        //            if (CellObj[i]->GetLife())
        //                ChangArr(i, cageObj);
        //            else
        //                ChangArr(i, cageNull);
        //            continue;
        //        }

        //        if (!hod) i--;
    }
}

int MainWindow::N(int i)        // ^  вверх
{
    return NextStatus(CellObj[i]->GetWidthPos(), CellObj[i]->GetHeightPos()-1);

    //    if(CellObj[i]->GetHeightPos() > 0 && next != cageLet && next != cageObj)
    //    {
    //        if(next == cageFood)
    //        {
    //            CellObj[i]->HealtUp();
    //            SetFood();
    //        }

    //        ChangArr(i, cageNull);
    //        CellObj[i]->SetHeight(CellObj[i]->GetHeight() - heightCell, heightCell);

    //        if (CellObj[i]->GetLife())
    //            ChangArr(i, cageObj);
    //        else
    //            ChangArr(i, cageNull);
    //        return true;
    //    }
    //    else return false;
}

int MainWindow::NE(int i)       // >^
{
    return NextStatus(CellObj[i]->GetWidthPos()+1, CellObj[i]->GetHeightPos()-1);
}

int MainWindow::E(int i)        // > left
{
    return NextStatus(CellObj[i]->GetWidthPos()+1, CellObj[i]->GetHeightPos());

    //    if(CellObj[i]->GetWidthPos() < maxPositionWidth-1  && next != cageLet && next != cageObj)
    //    {
    //        if(next == cageFood)
    //        {
    //            CellObj[i]->HealtUp();
    //            SetFood();
    //        }

    //        ChangArr(i, cageNull);
    //        CellObj[i]->SetWidth(CellObj[i]->GetWidth() + widthCell, widthCell);
    //        if (CellObj[i]->GetLife())
    //            ChangArr(i, cageObj);
    //        else
    //            ChangArr(i, cageNull);

    //        return true;
    //    }
    //    else return false;
}

int MainWindow::SE(int i)       // >↓
{
    return NextStatus(CellObj[i]->GetWidthPos()+1, CellObj[i]->GetHeightPos()+1);
}

int MainWindow::S(int i)        // ↓    down
{
    return NextStatus(CellObj[i]->GetWidthPos(), CellObj[i]->GetHeightPos()+1);

    //    if(CellObj[i]->GetHeightPos() < maxPositionWidth-1  && next != cageLet && next != cageObj)
    //    {
    //        if(next == cageFood)
    //        {
    //            CellObj[i]->HealtUp();
    //            SetFood();
    //        }

    //        ChangArr(i, cageNull);
    //        CellObj[i]->SetHeight(CellObj[i]->GetHeight() + heightCell, heightCell);

    //        if (CellObj[i]->GetLife())
    //            ChangArr(i, cageObj);
    //        else
    //            ChangArr(i, cageNull);
    //        return true;
    //    }
    //    else return false;
}

int MainWindow::SW(int i)       // <↓
{
    return NextStatus(CellObj[i]->GetWidthPos()-1, CellObj[i]->GetHeightPos()+1);
}

int MainWindow::W(int i)        // <    right
{
    return NextStatus(CellObj[i]->GetWidthPos()-1, CellObj[i]->GetHeightPos());

    //    if(CellObj[i]->GetWidthPos() > 0  && next != cageLet && next != cageObj)
    //    {
    //        if(next == cageFood)
    //        {
    //            CellObj[i]->HealtUp();
    //            SetFood();
    //        }

    //        ChangArr(i, cageNull);
    //        CellObj[i]->SetWidth(CellObj[i]->GetWidth() - widthCell, widthCell);
    //        if (CellObj[i]->GetLife())
    //            ChangArr(i, cageObj);
    //        else
    //            ChangArr(i, cageNull);

    //        return true;
    //    }
    //    else return false;
}

int MainWindow::NW(int i)       //<^
{
    return NextStatus(CellObj[i]->GetWidthPos()-1, CellObj[i]->GetHeightPos()-1);
}

void MainWindow::ChangArr(int index, int status)            //изменение значений массива положений
{
    arrPosition[CellObj[index]->GetWidthPos()][CellObj[index]->GetHeightPos()] = status;
}

int MainWindow::NextStatus(int GetWidthPosition, int GetHeightPosition)
{
    return arrPosition[GetWidthPosition][GetHeightPosition];
}
