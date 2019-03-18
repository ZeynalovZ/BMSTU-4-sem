#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "point.h"
#define PI 3.14159265
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double step_x;
    double step_y;
    double x1;
    double y1;
    double x2;
    double y2;
    QColor color;
    void draw_brezenham1(QPen pen);
    void draw_brezenham2(QPen pen);
    void draw_cda(QPen pen);
    void draw_brezenham_gradation(QPen pen);
    void draw_vu(QPen pen);
    void choose_method();

private slots:
    void on_but_exec_clicked();

    void on_changed();
    void on_spectr_changed();
    void on_pushCOLOR_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector<Point*> point;
};

#endif // MAINWINDOW_H
