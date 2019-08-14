#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <cell.h>
#include <time.h>
#include <windows.h>

enum obje {cageNull = 1, cageLet, cageObj, cageFood};   //обекты

enum direction {N_ = 1, NE_, E_, SE_, S_, SW_, W_, NW_};

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

    int N (int i);          //напраление по компасу
    int NE(int i);
    int E (int i);
    int SE(int i);
    int S (int i);
    int SW(int i);
    int W (int i);
    int NW(int i);

    int Route( int obj, int index, int *Width, int *Height);

    void ChangArr(int index, int status);
    int NextStatus(int GetWidthPosition, int GetHeightPosition);

    void MotionOption();            //вариант движения

    void FirstInstallElement();     //задание координат элементов
    void SetLet();
    void SetObj(int pos);
    void SetFood();
    void Breed();                   //новое поколение

private:
    Ui::MainWindow *ui;

    //const short cageNull = 0;           //пустая клетка
   //const short cageLet = 1;            //препядствие
   // const short cageObj = 2;            //клетка с обектом
    //const short cageFood = 3;           //клетка с едой


    const int width = 800;        //ширина окна
    const int height = 650;       //высота окна

    const static int widthWorker = 600;        //ширина окна
    const static int heightWorker = 600;       //высота окна

    const static int widthCell = 50;    //ширина ячейки
    const static int heightCell = 50;   //высота ячейки

    const static int maxPositionWidth = widthWorker/widthCell;          //количесво ячеек
    const static int maxPositionHeight = heightWorker/heightCell;



    const static int quantityCell = 5;         //количесво обектов
    Cell *CellObj[quantityCell];

    //const static int routeWidth[8]  ={0, 1, 1, 1, 0, -1, -1, -1};     // ->
    //const static int routeHeight[8] ={-1, -1, 0, 1, 1, 1, 0, -1};    // ↓

    const int routeWidth[8] = {0, 1, 1, 1, 0, -1, -1, -1};     // ->
    const int routeHeight[8] ={-1, -1, 0, 1, 1, 1, 0, -1};    // ↓


public:
     static int arrPosition[maxPositionWidth][maxPositionHeight];
};

#endif // MAINWINDOW_H
