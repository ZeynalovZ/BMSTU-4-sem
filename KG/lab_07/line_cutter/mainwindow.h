#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    double prev_x = -1;
    double prev_y = -1;
    double pixel_begin_x = -1;
    double pixel_begin_y = -1;
    double first_x;
    double first_y;
    double first_rect_x;
    double first_rect_y;
    bool flag_line_exist = false;
    bool flag_first_touched = false;
    bool flag_first_rect_touched = false;
    bool flag_rect_set = false; // for filling may be only 1
    bool flag_delete_cutter = false;
private slots:
    void on_add_point_button_clicked();

    void on_close_point_button_clicked();

    void on_cutter_color_button_clicked();

    void on_line_color_button_clicked();

    void on_clear_button_clicked();

    void on_outline_color_button_clicked();

    void on_cut_button_clicked();

    void on_delete_cutter_button_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QColor cutter_color;
    QColor line_color;
    QColor outline_color;
    QPainter *painter;
    QImage img;
    QVector<QPoint> lines;
    QVector<QPoint> outlines;
    QVector<double> rect;
};

#endif // MAINWINDOW_H
