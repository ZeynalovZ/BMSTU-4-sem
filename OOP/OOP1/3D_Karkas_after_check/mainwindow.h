#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "edges.h"
#include "points.h"
#include "init.h"
#include "io.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    edges_t *edges = NULL;
    points_t *points = NULL;
    int n = 0, m = 0;
    points_t center;
    model_t model_param;
    char *str = NULL;
private slots:
    void on_changed();

    void on_download_clicked();

    void on_pushButton_clicked();

    void on_rotate_clicked();

    void on_transfer_clicked();

    void on_scale_clicked();

    void on_upload_clicked();

private:
    int file_success = 0;

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    void set_view(points_t *points, edges_t *edges, int n, int m);
    double get_input(QString string_input);
    double get_input_for_scale(QString string_input);
};

#endif // MAINWINDOW_H
