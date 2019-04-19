#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>

typedef struct EDGE edge_t;
struct EDGE
{
    double x1;
    double y1;
    double x2;
    double y2;
};

typedef struct POINT1 points_t;
struct POINT1
{
    double x;
    double y;
};
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
    // -1 means start status
    double prev_x = -1;
    double prev_y = -1;
    double pixel_begin_x = -1;
    double pixel_begin_y = -1;
    double first_x;
    double first_y;
    bool flag_first_touched = false;
    bool flag_first_attained = false;
    bool flag_pixel_set = false; // for filling may be only 1
private slots:
    void on_add_point_button_clicked();

    void on_close_point_button_clicked();

    void on_cutter_color_button_clicked();

    void on_line_color_button_clicked();

    void on_clear_button_clicked();

    void on_outline_color_button_clicked();

    void on_cut_button_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QColor cutter_color;
    QColor line_color;
    QColor outline_color;
    QPainter *painter;
    QImage img;
    QVector <edge_t> edges;
};

#endif // MAINWINDOW_H
