#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

namespace Ui {
class MainWindow;
}

void set_validator();

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
    void draw_brezenham1(QPainter *painter);
    void draw_brezenham2(QPainter *painter);

protected:

private slots:
    void on_but_exec_clicked();
    void on_changed();


private:

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
