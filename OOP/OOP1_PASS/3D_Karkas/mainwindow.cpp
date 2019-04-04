#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.h"
#include "errors.h"
#include "edges.h"
#include "points.h"
#include "func.h"
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
    this->setWindowTitle("Вьювер каркасной модели");
    this->setWindowIcon(QIcon("icon1.png"));
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
    ui->line_k_2->setValidator(int_validator);
    ui->line_k_3->setValidator(int_validator);

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
    connect(ui->line_k_2, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_k_3, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

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

        if (ui->line_k->hasAcceptableInput() || ui->line_k_2->hasAcceptableInput() || ui->line_k_3->hasAcceptableInput())
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
    else
    {
        ui->transfer->setEnabled(false);
        ui->scale->setEnabled(false);
        ui->rotate->setEnabled(false);
        ui->upload->setEnabled(false);
    }

}

void MainWindow::on_download_clicked()
{
    if (file_success == 1)
    {
        scene->clear();
    }

    int code_error = OK;
    QString filename = ui->line_input_txt->text();
    QByteArray BA = filename.toLatin1();
    char *str = BA.data();
    parameters.filename = strdup(str);
    code_error = controller(parameters, *scene, LOAD);
    qDebug() << code_error << "is code error";
    if (code_error == OK)
    {
        code_error = controller(parameters, *scene, DRAW);
        // Модель из файла успешно считана
        file_success = 1;
    }
    else
    {
        show_error(code_error);
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

void MainWindow::show_error(int code_error)
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
    case ERR_SAVE:
        message = "Не удалось записать данные в файл, попробуйте еще раз! Если ошибка повторяется, обратитесь в техническую поддержку!";
        break;
    case NO_NEEDED_PARAM:
        message = "Упс!";
        break;
    default:
        break;
    }
    if (message != "")
            QMessageBox::information(this, "Ошибка", message);
}


void MainWindow::on_pushButton_clicked()
{
    file_success = 0;
    on_changed();
    scene->clear();
    scene->addLine(X / 2, Y - Y, X / 2, Y);
    scene->addLine(X - X, Y / 2, X, Y / 2);
}


void MainWindow::on_rotate_clicked()
{
    int code_error = OK;
    scene->clear();
    QString entry_angle = ui->line_angle->text();
    double angle = get_input(entry_angle);
    parameters.angle = angle;
    if (ui->radio_X->isChecked())
    {
        code_error = controller(parameters, *scene, ROTATE_X);
    }
    else if (ui->radio_Y->isChecked())
    {
        code_error = controller(parameters, *scene, ROTATE_Y);
    }
    else if (ui->radio_Z->isChecked())
    {
        code_error = controller(parameters, *scene, ROTATE_Z);
    }
    if (code_error != OK)
    {
        show_error(code_error);
    }
    else
    {
        code_error = controller(parameters, *scene, DRAW);
    }

}

void MainWindow::on_transfer_clicked()
{
    int code_error = OK;
    scene->clear();
    QString entry_x = ui->line_d_1->text();
    double dx = get_input(entry_x);
    QString entry_y = ui->line_d_2->text();
    double dy = get_input(entry_y);
    QString entry_z = ui->line_d_2->text();
    double dz = get_input(entry_z);
    parameters.dx = dx;
    parameters.dy = dy;
    parameters.dz = dz;
    code_error = controller(parameters, *scene, TRANSFORM);

    if (code_error != OK)
    {
        show_error(code_error);
    }
    else
    {
        code_error = controller(parameters, *scene, DRAW);
    }
}

void MainWindow::on_scale_clicked()
{
    int code_error = OK;
    scene->clear();
    QString entry_kx = ui->line_k->text();
    double kx = get_input_for_scale(entry_kx);
    QString entry_ky = ui->line_k_2->text();
    double ky = get_input_for_scale(entry_ky);
    QString entry_kz = ui->line_k_3->text();
    double kz = get_input_for_scale(entry_kz);
    parameters.kx = kx;
    parameters.ky = ky;
    parameters.kz = kz;
    code_error = controller(parameters, *scene, SCALE);

    if (code_error != OK)
    {
        show_error(code_error);
    }
    else
    {
        code_error = controller(parameters, *scene, DRAW);
    }
}

void MainWindow::on_upload_clicked()
{
    int code_error = OK;
    QString filename = ui->line_output_txt->text();
    QByteArray BA = filename.toLatin1();
    char *str = BA.data();
    parameters.filename = strdup(str);
    code_error = controller(parameters, *scene, SAVE);
    code_error = controller(parameters, *scene, DRAW);
    if (code_error != OK)
    {
        show_error(code_error);
    }
    else
    {
        code_error = controller(parameters, *scene, DRAW);
    }
}

