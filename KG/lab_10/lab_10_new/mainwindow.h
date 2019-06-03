#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include "func.h"
#include "algo.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *event);
    bool first_set = false;
    QPoint prevPoint;
    bool figureExists = false;
private slots:

    void on_clearButton_clicked();

    void on_drawButton_clicked();

    void on_rotateButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QPainter *painter;
    Functions FunctionHolder;
    double xBegin, xEnd, xDelta;
    double zBegin, zEnd, zDelta;
    double tetax = 0, tetay = 0, tetaz = 0;
    bool checkInput();
};

#endif // MAINWINDOW_H
