#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>
#include <cmath>
#include <QGraphicsScene>
#define X_WIDTH 881
#define Y_WIDTH 561
#define OFFSET_X_MOUSE 10
#define OFFSET_Y_MOUSE 23
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(QColor(Qt::white));


    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));

    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->draw_label->setPixmap(*scene);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);

    ui->line_color_label->setAutoFillBackground(true);
    ui->line_color_label->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->cutter_color_label->setAutoFillBackground(true);
    ui->cutter_color_label->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::blue);
    ui->outline_color_label->setAutoFillBackground(true);
    ui->outline_color_label->setPalette(Pal);

    line_color = Qt::black;
    cutter_color = Qt::red;
    outline_color = Qt::blue;

}

void MainWindow::on_add_point_button_clicked()
{
    bool ok1 = true, ok2 = false;
    QString x_value = ui->entry_x->text();
    QString y_value = ui->entry_y->text();
    double x = x_value.toDouble(&ok1);
    double y = y_value.toDouble(&ok2);
    if (ok1 && ok2)
    {
        if (ui->line_radio->isChecked())
        {
            painter->setPen(QColor(line_color));
            if (prev_x == -1 && prev_y == -1)
            {
                first_x = x;
                first_y = y;
            }
            else
            {
                painter->drawLine(x, y, prev_x, prev_y);
            }
            painter->drawPoint(x, y);
            prev_x = x;
            prev_y = y;
            ui->draw_label->setPixmap(*scene);
        }
        else if (ui->cutter_radio->isChecked())
        {
            pixel_begin_x = x;
            pixel_begin_y = y;
            flag_pixel_set = true;
        }

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Подождите!");
        // Тип иконки сообщения
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("Введены неверные параметры");
        // На какой кнопке фокусироваться по умолчанию
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void MainWindow::on_close_point_button_clicked()
{
    if (prev_x != -1 && prev_y != -1)
    {
        painter->drawLine(prev_x, prev_y, first_x, first_y);
        ui->draw_label->setPixmap(*scene);
        prev_x = -1;
        prev_y = -1;
    }
}

void MainWindow::on_line_color_button_clicked()
{
    line_color = QColorDialog::getColor(line_color, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, line_color);
    ui->line_color_label->setAutoFillBackground(true);
    ui->line_color_label->setPalette(Pal);
    ui->line_color_label->show();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    double x = event->x();
    double y = event->y();
    x -= OFFSET_X_MOUSE;
    y -= OFFSET_Y_MOUSE;
    // where to draw // right border x0 + 10  y0 + 40 (Offset from begining of window)
    if (ui->line_radio->isChecked())
    {
        painter->setPen(QPen(line_color));
        if (x >= 0 && y >= 0 && x <= 880 && y <= 561)
        {
            if (flag_first_touched == false)
            {
                first_x = x;
                first_y = y;
                flag_first_touched = true;
            }
            if (event->button() == Qt::LeftButton)
            {
                if (event->modifiers() == Qt::ShiftModifier)
                {
                    if (fabs(prev_x - x) < fabs(prev_y - prev_x))
                    {
                        x = prev_x;
                    }
                    else
                    {
                        y = prev_y;
                    }
                }
                painter->drawPoint(x, y);
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x, prev_y, x, y);
                }
                prev_x = x;
                prev_y = y;
            }
            else if (event->button() == Qt::RightButton)
            {
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x, prev_y, first_x, first_y);
                    prev_x = -1;
                    prev_y = -1;
                    flag_first_touched = false;
                }
            }
        }
        ui->draw_label->setPixmap(*scene);
    }
    else if (ui->cutter_radio->isChecked())
    {
        pixel_begin_x = x;
        pixel_begin_y = y;
        flag_pixel_set = true;
    }
}

void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
    edges.clear();
    ui->draw_label->clear();
    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    prev_x = -1;
    prev_y = -1;
    flag_first_attained = false;
    flag_first_touched = false;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_outline_color_button_clicked()
{
    outline_color = QColorDialog::getColor(outline_color, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, outline_color);
    ui->outline_color_label->setAutoFillBackground(true);
    ui->outline_color_label->setPalette(Pal);
    ui->outline_color_label->show();
}

void MainWindow::on_cutter_color_button_clicked()
{
    cutter_color = QColorDialog::getColor(cutter_color, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, cutter_color);
    ui->cutter_color_label->setAutoFillBackground(true);
    ui->cutter_color_label->setPalette(Pal);
    ui->cutter_color_label->show();
}

void MainWindow::on_cut_button_clicked()
{
    qDebug() << "hello";
}
