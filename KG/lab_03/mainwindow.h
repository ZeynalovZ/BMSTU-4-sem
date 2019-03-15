#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void draw_brezenham1(QPainter &painter);
    void draw_brezenham2(QPainter &painter);
    void draw_cda(QPainter &painter);
    void draw_brezenham_gradation(QPainter &painter);

protected:

    void paintEvent(QPaintEvent *event);

private slots:
    void on_but_exec_clicked();


    void on_pushButton_clicked();

    void on_pushCOLOR_clicked();

private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
