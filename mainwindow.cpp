#include "mainwindow.h"
#include "ui_mainwindow.h"
int MainWindow::arrPosition[maxPositionWidth][maxPositionHeight];       //поределение статического массива позиций поля

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(0));                     //сбрасывает рандомные числа
    this->setFixedSize(width, height);  //пиксирование размеров окна
    FirstInstallElement();              //установка элементов

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.setPen(Qt::blue);
    paint.drawRect(QRect(0, 0, widthWorker, heightWorker));        //рабочее поле

    for (int i = 0; i < maxPositionWidth; i++)                  //закрашиваем поле
    {
        for (int c = 0; c < maxPositionHeight; c++)
        {
            if (arrPosition[i][c] == cageNull) continue;
            else if (arrPosition[i][c] == cageObj) paint.setPen(Qt::black);
            else if (arrPosition[i][c] == cageLet) paint.setPen(Qt::red);
            else if (arrPosition[i][c] == cageFood) paint.setPen(Qt::green);
            paint.drawRect(QRect(i*widthCell, c*heightCell, widthCell, heightCell));
        }
    }
    paint.setPen(Qt::black);
//    for (int i = 0; i < quantityCell; i++)
//    {
//        //         if (!CellObj[i]->GetHealth()) continue;
//        //         paint.drawRect(QRect(CellObj[i]->GetWidth(), CellObj[i]->GetHeight(), widthCell, heightCell));
//        if (CellObj[i]->GetLife())
//            paint.drawText(CellObj[i]->GetWidthPos()*widthCell+widthCell/2, CellObj[i]->GetHeightPos()*heightCell+heightCell/2, QString::number(CellObj[i]->GetHealth()));
//    }



}

void MainWindow::on_upButton_clicked()
{

    // Up(0);
    while(true)
    {
        series++;
        MotionOption();
        MainWindow::update();
        QApplication::processEvents();
        Sleep(2);
    }
}

void MainWindow::on_rightButton_clicked()
{
    //Right(0);
    MainWindow::update();
    Breed();

}

void MainWindow::on_downButton_clicked()
{
   // Down(0);
    MainWindow::update();
}

void MainWindow::on_leftButton_clicked()
{
   // Left(0);
    MainWindow::update();
}

void MainWindow::FirstInstallElement()
{
    for(int i = 0; i < maxPositionWidth; i++)
    {
        for(int c = 0; c < maxPositionHeight; c++)
        {
            arrPosition[i][c] = cageNull;
        }
    }

    SetLet();
    for (int i = 0; i < quantityCell; i++)
        SetObj(i);

    for (int i = 0; i < 300; i++)
        SetFood();
}

void MainWindow::SetLet()
{
    for (int i = 28; i < 34; i++)
    {
        for (int c = 28; c < 34; c++)
        {
            arrPosition[i][c] = cageLet;
        }
    }

    for(int i = 0; i <maxPositionWidth; i++)
    {
        for(int c = 0; c < maxPositionHeight; c+=maxPositionHeight-1)
        {
          arrPosition[i][c] = cageLet;
          arrPosition[c][i] = cageLet;
        }
    }
}

void MainWindow::SetObj(int pos)
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %maxPositionWidth;
        heightRand = rand() %maxPositionHeight;
    }
    while(arrPosition[widthRand][heightRand] != cageNull);

    arrPosition[widthRand][heightRand] = cageObj;
    Cell *test = new Cell(widthRand, heightRand/*, widthCell*/);
    CellObj[pos] = test;
}

void MainWindow::SetFood()
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %maxPositionWidth;
        heightRand = rand() %maxPositionHeight;
    }
    while(arrPosition[widthRand][heightRand] != cageNull);

    arrPosition[widthRand][heightRand] = cageFood;
}

void MainWindow::Breed()        //новое поколение
{
    generation++;
    ui->textEdit->append((QString::number(series)));
    ui->textEdit_2->setText((QString::number(generation)));
    series =0;                      //обнуление количества ходов
    Cell testOBg[quantityCell/5];
    for (int i = 0, n = 0; i < quantityCell/5; n++)
    {
        if (CellObj[n]->GetLife())
        {
            arrPosition[CellObj[n]->GetWidthPos()][CellObj[n]->GetHeightPos()] = cageNull;
            testOBg[i] = *CellObj[n];
            i++;
        }
    }

    for (int i = 0; i < quantityCell; i++)
    {
        *CellObj[i] = testOBg[i/5];
        SetCoordinates(i);
        CellObj[i]->Mutation();
    }
    CellObj[0]->deadCell = 0;
   // MainWindow::update();
}

void MainWindow::SetCoordinates(int i)
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %maxPositionWidth;
        heightRand = rand() %maxPositionHeight;
    }
    while(arrPosition[widthRand][heightRand] != cageNull && arrPosition[widthRand][heightRand] != cageFood);
    CellObj[i]->SetWidthPos(widthRand);
    CellObj[i]->SetHeightPos(heightRand);

    if(arrPosition[widthRand][heightRand] == cageFood)
    {
      CellObj[i]->HealtUp(10);
      SetFood();
    }

    arrPosition[widthRand][heightRand] = cageObj;
}
