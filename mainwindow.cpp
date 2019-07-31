#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(width, height);

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

    paint.drawRect(QRect(widthCell*2, heightCell*2, widthCell*2, heightCell*2));

    for (int i = widthCell*4/50; i > widthCell*2/50; i--)
    {
        for (int c = heightCell*4/50; c > heightCell*2/50; c--)
        {
           arrPosition[i-1][c-1] = 1;
        }
    }

    //    for(int i = width -widthWorker; i<=width; i++)
    //    {
    //        for(int c = height - heightWorker ; c<=height; c++)
    //        {
    //            paint.drawPoint(i, c);
    //        }
    //    }


    QPainter painter(this);
    // for (int i = 0; i<2; i++)
    painter.drawRect(QRect(nClass[0].GetWidth(), nClass[0].GetHeight(), widthCell, heightCell));
    painter.drawText(nClass[0].GetWidth()+widthCell/2, nClass[0].GetHeight()+heightCell/2, QString::number(nClass[0].GetLife()));


}

void MainWindow::on_upButton_clicked()
{
    if(nClass[0].GetHeight()/50 > 0 && arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50 - 1] != 1)
    {
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 0;
        nClass[0].SetHeight(nClass[0].GetHeight() - heightCell);
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 2;
    }
    MainWindow::update();
}

void MainWindow::on_rightButton_clicked()
{
    if(nClass[0].GetWidth()/50 < maxPositionWidth-1  && arrPosition[nClass[0].GetWidth()/50 +1][nClass[0].GetHeight()/50] != 1)
    {
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 0;
        nClass[0].SetWidth(nClass[0].GetWidth() + widthCell);
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 2;
    }
    MainWindow::update();
}

void MainWindow::on_downButton_clicked()
{
    if(nClass[0].GetHeight()/50 < maxPositionWidth-1  && arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50 + 1] != 1)
    {
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 0;
        nClass[0].SetHeight(nClass[0].GetHeight() + heightCell);
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 2;
    }
    MainWindow::update();
}

void MainWindow::on_leftButton_clicked()
{
    if(nClass[0].GetWidth()/50 > 0  && arrPosition[nClass[0].GetWidth()/50 -1][nClass[0].GetHeight()/50] != 1)
    {
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 0;
        nClass[0].SetWidth(nClass[0].GetWidth() - widthCell);
        arrPosition[nClass[0].GetWidth()/50][nClass[0].GetHeight()/50] = 2;
    }
    MainWindow::update();
}
