#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "my_controller.h"
#include <string.h>
#include "io.h"
#include "model.h"
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
    parameters_t parameters;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    painter_t painter;
    void set_view(points_t *points, edges_t *edges, int n, int m);
    double get_input(QString string_input);
    double get_input_for_scale(QString string_input);
    void show_error(int code_error);
};

#endif // MAINWINDOW_H
