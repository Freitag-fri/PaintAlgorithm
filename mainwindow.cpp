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
//    for(int i = width -widthWorker; i<=width; i++)
//    {
//        for(int c = height - heightWorker ; c<=height; c++)
//        {
//            paint.drawPoint(i, c);
//        }
//    }


    QPainter painter(this);
    for (int i = 0; i<2; i++)
        painter.drawRect(QRect(nClass[i].GetWidth(), nClass[i].GetHeight(), 50, 50));

}

//void MainWindow::paintEvent2()
//{
//    QPainter painter(this);
//    painter.drawRect(QRect(widthCell*2, heightCell*2, widthCell, heightCell));
//}

void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i<2;i++)
    {
        if (i == 0)
        {
            nClass[i].SetHeight(nClass[i].GetHeight()+100);
            nClass[i].SetWidth(nClass[i].GetWidth()+100);
        }
        else
        {
            nClass[i].SetHeight(nClass[i].GetHeight()+50);
            nClass[i].SetWidth(nClass[i].GetWidth()+50);
        }

    }

    MainWindow::update();

}
