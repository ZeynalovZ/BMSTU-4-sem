#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>

#include "algorithm.h"

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
    int prev_polygon_x = -1;
    int prev_polygon_y = -1;
    int first_polygon_x; // first points
    int first_polygon_y;
    bool flag_polygon_first_touched = false;
    bool flag_polygon_set = false;

    int prev_rect_x = -1;
    int prev_rect_y = -1;
    int first_rect_x;
    int first_rect_y;
    int first_paral_x;
    int first_paral_y;
    bool first_point_of_paral_line = false;
    bool flag_line_exist = false;
    bool flag_first_touched = false;
    bool flag_first_rect_touched = false;
    bool flag_rect_set = false; // for cutting may be only 1
    bool flag_delete_cutter = false;
private slots:
    void on_add_point_button_clicked();

    void on_cutter_color_button_clicked();

    void on_line_color_button_clicked();

    void on_clear_button_clicked();

    void on_outline_color_button_clicked();

    void on_cut_button_clicked();

    void on_delete_cutter_button_clicked();

    void delete_current_polygon();
private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QColor cutter_color;
    QColor line_color;
    QColor outline_color;
    QPainter *painter;
    QImage img;
    QVector<QPoint> edges;
    QVector<QPoint> lines;
    QVector<QPoint> outlines;
    QVector<edge_t> rect;
    QVector<edge_t> polygon;
};

#endif // MAINWINDOW_H
