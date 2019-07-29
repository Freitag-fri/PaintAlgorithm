#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int qq = 123;
    QString s = QString::number(qq);

    QPainter painter(this);
       //painter.drawPoint(100,200);
    painter.drawRect(QRect(100,100,100,100));
    painter.drawText(150,150,s);

}
