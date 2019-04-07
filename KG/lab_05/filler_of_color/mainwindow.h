#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include <QVector>

typedef struct EDGE edge_t;
struct EDGE
{
    double x1;
    double y1;
    double x2;
    double y2;
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
    void mouseMoveEvent(QMouseEvent *event);
    double prev_x = -1;
    double prev_y = -1;
    double first_x;
    double first_y;
    bool flag_first_touched = false;
    bool flag_first_attained = false;

private slots:
    void on_Check_Button_clicked();

    void on_make_line_button_clicked();

    void on_border_button_clicked();

    void on_clear_button_clicked();

    void on_shading_button_clicked();

    void on_background_button_clicked();

    void on_make_line_button_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QPainter *painter;
    QImage img;
    QPoint position;
    QColor color_background = Qt::white;
    QColor color_border;
    QColor color_shading;
    QVector <edge_t> edges;
};




#endif // MAINWINDOW_H
