#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QtCore>
#include <QtGui>
enum {BREZENHAM, CANON, PARAM, MIDDLEPOINT, LIBRARY};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QColor color;

    void clear_circle_input();

    double xc, yc, R, a, b;

    int line_width = 1;


private slots:
    void on_draw_button_clicked();
    //void autofill_in_circle_mod_rx();
    //void autofill_in_circle_mod_ry();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_circle_spectr_button_clicked();

    void on_ellipse_spectr_button_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    QPixmap *scene;
    QPainter *painter;
};

#endif // MAINWINDOW_H
