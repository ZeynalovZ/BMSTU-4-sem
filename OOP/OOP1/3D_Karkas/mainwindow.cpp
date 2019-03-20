#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp check_file  ("[0-9a-z_]+\\.[a-z]+") ;
    QRegExpValidator *file_validator = new QRegExpValidator(check_file, this);

    QRegExp check_int  ("[0-9]+$");
    QRegExpValidator *int_validator = new QRegExpValidator(check_int, this);

    ui->line_input_txt->setValidator(file_validator);
    ui->line_output_txt->setValidator(file_validator);

    ui->line_d_1->setValidator(int_validator);
    ui->line_d_2->setValidator(int_validator);
    ui->line_d_3->setValidator(int_validator);

    ui->line_k_1->setValidator(int_validator);
    ui->line_k_2->setValidator(int_validator);
    ui->line_k_3->setValidator(int_validator);

    ui->line_angle_x->setValidator(int_validator);
    ui->line_angle_y->setValidator(int_validator);
    ui->line_angle_z->setValidator(int_validator);

    ui->rotate->setEnabled(false);
    ui->transfer->setEnabled(false);
    ui->scale->setEnabled(false);
    ui->download->setEnabled(false);
    ui->upload->setEnabled(false);

    connect(ui->line_d_1, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_d_2, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_d_3, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_k_1, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_k_2, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_k_3, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_angle_x, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_angle_y, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_angle_z, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

    connect(ui->line_input_txt, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));
    connect(ui->line_output_txt, SIGNAL(textChanged(QString)),this, SLOT(on_changed()));

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
        file_success = 1;
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

        if (ui->line_k_1->hasAcceptableInput() || ui->line_k_2->hasAcceptableInput() || ui->line_k_3->hasAcceptableInput())
        {
            ui->scale->setEnabled(true);
        }
        else
        {
            ui->scale->setEnabled(false);
        }

        if (ui->line_angle_x->hasAcceptableInput() || ui->line_angle_y->hasAcceptableInput() || ui->line_angle_z->hasAcceptableInput())
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
