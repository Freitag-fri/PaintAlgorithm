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
    void on_upButton_clicked();

    void on_rightButton_clicked();

    void on_downButton_clicked();

    void on_leftButton_clicked();

    void Up();
    void Down();
    void Left();
    void Right();
    void ChangArr(int index, int status);
    int NextStatus(int GetWidthPosition, int GetHeightPosition);


private:
    Ui::MainWindow *ui;


    const static int width = 800;        //ширина окна
    const static int height = 650;       //высота окна

    const static int widthWorker = 600;        //ширина окна
    const static int heightWorker = 600;       //высота окна

    const static int widthCell = 50;    //ширина ячейки
    const static int heightCell = 50;   //высота ячейки

    const static int maxPositionWidth = widthWorker/widthCell;
    const static int maxPositionHeight = heightWorker/heightCell;
    int arrPosition[maxPositionWidth][maxPositionHeight] = {};

    Cell testClass;
    Cell testClass2;
    Cell nClass[2] = {testClass, testClass2};
    int ncl = 0;
};

#endif // MAINWINDOW_H
