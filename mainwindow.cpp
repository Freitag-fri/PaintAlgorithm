#include "mainwindow.h"
#include "ui_mainwindow.h"
int MainWindow::arrPosition[maxPositionWidth][maxPositionHeight];       //поределение статического массива позиций поля
int MainWindow::venomKill = 0;
int MainWindow::venomEat = 0;

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
            else if (arrPosition[i][c] == cageLet) paint.setPen(Qt::blue);
            else if (arrPosition[i][c] == cageFood) paint.setPen(Qt::green);
            else if (arrPosition[i][c] == cageVenom) paint.setPen(Qt::red);
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
        ui->textEdit_3->setText((QString::number(series)));
        series++;
        MotionOption();
        MainWindow::update();
        QApplication::processEvents();
       // Sleep(2);
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

    for (int i = 0; i < 40; i++)
        SetFood();

    for (int i = 0; i < 35; i++)
        SetVenom();
}

void MainWindow::SetLet()
{
    for (int i = maxPositionWidth-4; i < maxPositionWidth; i++)
    {

            arrPosition[i][10] = cageLet;
            arrPosition[10][i] = cageLet;
    }

    for (int i = 10; i < 19; i++)
    {
        for (int c = 10; c < 11; c++)
        {
            arrPosition[i][c] = cageLet;
            arrPosition[c][i] = cageLet;
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

void MainWindow::SetVenom()
{
    int widthRand;
    int heightRand;

    do
    {
        widthRand = rand() %maxPositionWidth;
        heightRand = rand() %maxPositionHeight;
    }
    while(arrPosition[widthRand][heightRand] != cageNull);

    arrPosition[widthRand][heightRand] = cageVenom;
}

void MainWindow::Breed()        //новое поколение
{
    generation++;
    ui->textEdit->append((QString::number(series)));
    ui->textEdit_2->setText((QString::number(generation)));
    ui->textEdit_Kill->append((QString::number(venomKill)));
    ui->textEdit_Eat->append((QString::number(venomEat)));
    venomEat = 0;
    venomKill =0;
    series =0;                      //обнуление количества ходов
    Cell testOBg[quantityCell/10];
    for (int i = 0, n = 0; i < quantityCell/10; n++)
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
        *CellObj[i] = testOBg[i/10];
        SetCoordinates(i);
        CellObj[i]->Mutation();
    }
    Cell::deadCell = 0;
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
