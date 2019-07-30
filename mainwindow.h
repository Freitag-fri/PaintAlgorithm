#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <cell.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *);


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


    const static int width = 700;        //ширина окна
    const static int height = 650;       //высота окна

    const static int widthWorker = 600;        //ширина окна
    const static int heightWorker = 600;       //высота окна

    const static int widthCell = 50;    //ширина ячейки
    const static int heightCell = 50;   //высота ячейки
    int a[widthWorker/widthCell][heightWorker/heightCell] = {};

    Cell testClass;
    Cell testClass2;
    Cell nClass[2] = {testClass, testClass2};
    int ncl = 0;
};

#endif // MAINWINDOW_H
