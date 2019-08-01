#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(width, height);
arrPosition[5][6] = 3;
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

    paint.setPen(Qt::red);

    paint.drawRect(QRect(widthCell*2, heightCell*2, widthCell*2, heightCell*2));

    for (int i = widthCell*4/50; i > widthCell*2/50; i--)
    {
        for (int c = heightCell*4/50; c > heightCell*2/50; c--)
        {
           arrPosition[i-1][c-1] = 1;
        }
    }

    paint.setPen(Qt::green);
    if (arrPosition[5][6] == 3)
    paint.drawRect(QRect(widthCell*5, heightCell*6, widthCell, heightCell));


    QPainter painter(this);
    // for (int i = 0; i<2; i++)
    painter.drawRect(QRect(nClass[0].GetWidth(), nClass[0].GetHeight(), widthCell, heightCell));
    painter.drawText(nClass[0].GetWidth()+widthCell/2, nClass[0].GetHeight()+heightCell/2, QString::number(nClass[0].GetLife()));


}

void MainWindow::on_upButton_clicked()
{
    Up();
}

void MainWindow::on_rightButton_clicked()
{
    Right();
}

void MainWindow::on_downButton_clicked()
{
    Down();
}

void MainWindow::on_leftButton_clicked()
{
    Left();
}
