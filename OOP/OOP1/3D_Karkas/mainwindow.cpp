#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.h"
#include "errors.h"
#include "edges.h"
#include "points.h"
#include "process.h"
#include <math.h>
#include <QDebug>
#include <QMessageBox>
#define X 1231
#define Y 531

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QRegExp check_file  ("[0-9a-z_]+\\.[a-z]+") ;
    QRegExpValidator *file_validator = new QRegExpValidator(check_file, this);
    // for int "[0-9]+$"
    QRegExp check_double  ("[-+]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    QRegExpValidator *int_validator = new QRegExpValidator(check_double, this);

    ui->line_input_txt->setValidator(file_validator);
    ui->line_output_txt->setValidator(file_validator);

    ui->line_d_1->setValidator(int_validator);
    ui->line_d_2->setValidator(int_validator);
    ui->line_d_3->setValidator(int_validator);

    ui->line_k->setValidator(int_validator);
    ui->line_angle->setValidator(int_validator);

    ui->rotate->setEnabled(false);
    ui->transfer->setEnabled(false);
    ui->scale->setEnabled(false);
    ui->download->setEnabled(false);
    ui->upload->setEnabled(false);

    connect(ui->line_d_1, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_d_2, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_d_3, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_k, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_angle, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_input_txt, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_output_txt, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));


    center.x = X / 2;
    center.y = Y / 2;
    scene->setSceneRect(X - X, Y - Y, X - 20, Y - 20);
    scene->addLine(X / 2, Y - Y, X / 2, Y);
    scene->addLine(X - X, Y / 2, X, Y / 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_changed()
{
    if (ui->line_input_txt->hasAcceptableInput())
    {
        ui->download->setEnabled(true);
    }
    else
    {
        ui->download->setEnabled(false);
    }
    if (file_success == 1)
    {
        if (ui->line_d_1->hasAcceptableInput() || ui->line_d_2->hasAcceptableInput() || ui->line_d_3->hasAcceptableInput())
        {
            ui->transfer->setEnabled(true);
        }
        else
        {
            ui->transfer->setEnabled(false);
        }

        if (ui->line_k->hasAcceptableInput())
        {
            ui->scale->setEnabled(true);
        }
        else
        {
            ui->scale->setEnabled(false);
        }

        if (ui->line_angle->hasAcceptableInput())
        {
            ui->rotate->setEnabled(true);
        }
        else
        {
            ui->rotate->setEnabled(false);
        }
        if (ui->line_output_txt->hasAcceptableInput())
        {
            ui->upload->setEnabled(true);
        }
        else
        {
            ui->upload->setEnabled(false);
        }
    }

}

void MainWindow::on_download_clicked()
{


    int code_error = OK;
    QString filename = ui->line_input_txt->text();
    QByteArray BA = filename.toLatin1();
    char *str = BA.data();
    code_error = read_model_from_file(str, &points, &edges, &n, &m);
    if (code_error == OK)
    {
        // Модель из файла успешно считана
        file_success = 1;
        set_view(points, edges, n, m);
    }
    else
    {
        QString message = "";
        switch (code_error)
        {
        case ERR_OPEN:
            message = "Не удалось найти такой файл!";
            break;
        case ERR_READ:
            message = "Не удалось прочесть данные из файла, проверьте содержимое!";
            break;
        case ERR_MEMORY:
            message = "Произошла системная ошибка, перезапустите приложение или обратитесь в техническую поддержку!";
            break;
        default:
            break;
        }
        if (message != "")
                QMessageBox::information(this, "Ошибка", message);

    }
}

void MainWindow::set_view(points_t *points, edges_t *edges, int n, int m)
{
    points_2d p_res[n];
    scene->addLine(X / 2, Y - Y, X / 2, Y);
    scene->addLine(X - X, Y / 2, X, Y / 2);
    scene->addEllipse(center.x, center.y, 2, 2);
    for (int i = 0; i < n; i++)
    {
        //int z1 = sqrt(2) / 2 * points[i].z;
        double sx = center.x + points[i].x;
        double sy = center.y + points[i].y;
        p_res[i].x = sx;
        p_res[i].y = sy;
        scene->addEllipse(sx, sy, 1, 1);
    }
    for (int i = 0; i < m; i++)
    {
        scene->addLine(p_res[edges[i].first].x, p_res[edges[i].first].y,p_res[edges[i].second].x, p_res[edges[i].second].y);
    }
}

double MainWindow::get_input(QString string_input)
{
    double num = 0;
    QStringList inputed = string_input.split(" ", QString::SkipEmptyParts);
    if (inputed.count() != 1)
    {
        return num;
    }
    num = inputed[0].toDouble();
    return num;
}

double MainWindow::get_input_for_scale(QString string_input)
{
    double num = 1;
    QStringList inputed = string_input.split(" ", QString::SkipEmptyParts);
    if (inputed.count() != 1)
    {
        return num;
    }
    num = inputed[0].toDouble();
    return num;
}




void MainWindow::on_pushButton_clicked()
{
    scene->clear();
}


void MainWindow::on_rotate_clicked()
{
    scene->clear();
    QString entry_angle = ui->line_angle->text();
    double angle = get_input(entry_angle);
    if (ui->radio_X->isChecked())
    {
        rotate_x(points, n, angle);
    }
    else if (ui->radio_Y->isChecked())
    {
        rotate_y(points, n, angle);
    }
    else if (ui->radio_Z->isChecked())
    {
        rotate_z(points, n, angle);
    }
    set_view(points, edges, n, m);

}

void MainWindow::on_transfer_clicked()
{
    scene->clear();
    QString entry_x = ui->line_d_1->text();
    double dx = get_input(entry_x);
    QString entry_y = ui->line_d_2->text();
    double dy = get_input(entry_y);
    QString entry_z = ui->line_d_2->text();
    double dz = get_input(entry_z);

    transform_point(points, n, dx, dy, dz);
    set_view(points, edges, n, m);
}

void MainWindow::on_scale_clicked()
{
    scene->clear();
    QString entry_k = ui->line_k->text();
    double k = get_input_for_scale(entry_k);
    scale(points, n, k);
    set_view(points, edges, n, m);
}

void MainWindow::on_upload_clicked()
{
    int code_error = OK;
    QString filename = ui->line_output_txt->text();
    QByteArray BA = filename.toLatin1();
    char *str = BA.data();
    code_error = save_changes(str, points, edges, n, m);
    if (code_error != OK)
    {
        QString message = "";
        message = "Не удалось сохранить в файл!";
        QMessageBox::information(this, "Ошибка", message);
    }
}
