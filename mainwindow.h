#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <cell.h>
#include <time.h>
#include <windows.h>

enum obje {cageNull = 1, cageLet, cageObj, cageFood};   //обекты

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend void AddFood();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *);

private slots:
    void on_upButton_clicked();
    void on_rightButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();

    int Route( int obj, int index, int *Width, int *Height);

    void ChangArr(int index, int status);
    int NextStatus(int GetWidthPosition, int GetHeightPosition);

    void MotionOption();            //вариант движения

    void FirstInstallElement();     //задание координат элементов
    void SetLet();
    void SetObj(int pos);
    static void SetFood();
    void Breed();                   //новое поколение
    void SetCoordinates(int i);

private:
    Ui::MainWindow *ui;

    const int width = 800;        //ширина окна
    const int height = 650;       //высота окна

    const static int widthWorker = 600;        //ширина окна
    const static int heightWorker = 600;       //высота окна

    const static int widthCell = 25;    //ширина ячейки
    const static int heightCell = 25;   //высота ячейки

    const static int maxPositionWidth = widthWorker/widthCell;          //количесво ячеек
    const static int maxPositionHeight = heightWorker/heightCell;

    const static int quantityCell = 25;         //количесво обектов
    Cell *CellObj[quantityCell];

    const int routeWidth[8] = {0, 1, 1, 1, 0, -1, -1, -1};     // ->
    const int routeHeight[8] ={-1, -1, 0, 1, 1, 1, 0, -1};    // ↓


    int series = 0;
    int generation = 0;

public:
    static int arrPosition[maxPositionWidth][maxPositionHeight];
};

#endif // MAINWINDOW_H
