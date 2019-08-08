#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(0));                     //сбрасывает рандомные числа
    this->setFixedSize(width, height);  //пиксирование размеров окна
    FirstInstallElement();              //установка элементов

    ui->setupUi(this);

    int test;
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

    for (int i = 0; i < quantityCell; i++)
    {
        //         if (!CellObj[i]->GetHealth()) continue;
        //         paint.drawRect(QRect(CellObj[i]->GetWidth(), CellObj[i]->GetHeight(), widthCell, heightCell));
        if (CellObj[i]->GetLife())
            paint.drawText(CellObj[i]->GetWidth()+widthCell/2, CellObj[i]->GetHeight()+heightCell/2, QString::number(CellObj[i]->GetHealth()));
    }



}

void MainWindow::on_upButton_clicked()
{
    // Up(0);
    int n = 0;
    while(true)
    {
        MotionOption();
        MainWindow::update();
        QApplication::processEvents();
        Sleep(100);
        n ++;
    }
    MainWindow::update();
}

void MainWindow::on_rightButton_clicked()
{
    //Right(0);
    MainWindow::update();
    Breed();

}

void MainWindow::on_downButton_clicked()
{
    Down(0);
    MainWindow::update();
}

void MainWindow::on_leftButton_clicked()
{
    Left(0);
    MainWindow::update();
}

void MainWindow::FirstInstallElement()
{
    SetLet();
    for (int i = 0; i < quantityCell; i++)
        SetObj(i);
    SetLet();
    for (int i = 0; i < 3; i++)
        SetFood();
}

void MainWindow::SetLet()
{
    for (int i = 2; i < 4; i++)
    {
        for (int c = 2; c < 4; c++)
        {
            arrPosition[i][c] = cageLet;
        }
    }
}

void MainWindow::SetObj(int pos)
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %12;
        heightRand = rand() %12;
    }
    while(arrPosition[widthRand][heightRand] != cageNull);

    arrPosition[widthRand][heightRand] = cageObj;
    Cell *test = new Cell(widthRand, heightRand, widthCell);
    CellObj[pos] = test;
}

void MainWindow::SetFood()
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %12;
        heightRand = rand() %12;
    }
    while(arrPosition[widthRand][heightRand] != cageNull);

    arrPosition[widthRand][heightRand] = cageFood;
}

void MainWindow::Breed()        //новое поколение
{
    Cell testOBg[5];
    for (int i = 0, n = 0; i < 5; n++)
    {
        if (CellObj[n]->GetLife())
        {
            arrPosition[CellObj[n]->GetWidthPos()][CellObj[n]->GetHeightPos()] = cageNull;
            testOBg[i] = *CellObj[n];
            i++;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        *CellObj[i] = testOBg[i/5];
        SetObj(i);
    }
    CellObj[0]->deadCell = 0;
    MainWindow::update();
}
