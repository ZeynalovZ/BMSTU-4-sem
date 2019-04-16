#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmapCache>
#include <iostream>
#include <windows.h>
#include <math.h>


#define OFFSET_X_MOUSE 8
#define OFFSET_Y_MOUSE 44


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

    ui->border_color_label->setAutoFillBackground(true);
    ui->border_color_label->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::blue);
    ui->filling_color_label->setAutoFillBackground(true);
    ui->filling_color_label->setPalette(Pal);

    border_color = Qt::black;
    filling_color = Qt::blue;

}

MainWindow::~MainWindow()
{
    delete ui;
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
        if (ui->polygon_radio->isChecked())
        {
            painter->setPen(QColor(border_color));
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
        else if (ui->pixel_radio->isChecked())
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

void MainWindow::on_border_color_button_clicked()
{
    border_color = QColorDialog::getColor(Qt::black, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, border_color);
    ui->border_color_label->setAutoFillBackground(true);
    ui->border_color_label->setPalette(Pal);
    ui->border_color_label->show();
}

void MainWindow::on_filing_color_button_clicked()
{
    filling_color = QColorDialog::getColor(filling_color, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, filling_color);
    ui->filling_color_label->setAutoFillBackground(true);
    ui->filling_color_label->setPalette(Pal);
    ui->filling_color_label->show();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    painter->setPen(QPen(border_color));
    double x = event->x();
    double y = event->y();
    x -= OFFSET_X_MOUSE;
    y -= OFFSET_Y_MOUSE;
    // where to draw // right border x0 + 10  y0 + 40 (Offset from begining of window)
    if (ui->polygon_radio->isChecked())
    {
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
    else if (ui->pixel_radio->isChecked())
    {
        pixel_begin_x = x;
        pixel_begin_y = y;
        flag_pixel_set = true;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->polygon1_radio->isChecked())
    {
        painter->setPen(QPen(border_color));
        double x = event->x();
        double y = event->y();
        x -= OFFSET_X_MOUSE;
        y -= OFFSET_Y_MOUSE;
        if (x >= 0 && y >= 0 && x <= 880 && y <= 561)
        {
            if (event->modifiers() == Qt::ShiftModifier)
            {
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x, prev_y, first_x, first_y);
                    prev_x = -1;
                    prev_y = -1;
                    flag_first_touched = false;
                }
            }
            else
            {
                painter->drawPoint(x, y);
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x, prev_y, x, y);
                }
                else
                {
                    first_x = x;
                    first_y = y;
                }
                prev_x = x;
                prev_y = y;
            }
            ui->draw_label->setPixmap(*scene);
        }
    }
}
void MainWindow::find_next_pixel(QStack<points_t> &stack, int &x_left, int &x_right, const int &y)
{
    bool flag;
    int x = x_left;
    int x_temp;
    while (x <= x_right)
    {
        flag = false;
        while ((x <= x_right) && img.pixelColor(x, y) != border_color && img.pixelColor(x, y) != filling_color)
        {
            flag = true;
            x++;
        }
        if (flag == true)
        {
            if ((x == x_right) && img.pixelColor(x, y) != border_color && img.pixelColor(x, y) != filling_color)
            {
                points_t point;
                point.x = x;
                point.y = y;
                stack.push(point);
            }
            else
            {
                points_t point;
                point.x = x - 1;
                point.y = y;
                stack.push(point);
            }
        }
        x_temp = x;

        while ((x < x_right) && (img.pixelColor(x, y) == border_color || img.pixelColor(x, y) == filling_color))
        {
            x++;
        }

        if (x == x_temp)
        {
            x++;
        }
    }
}
void MainWindow::on_fill_button_clicked()
{

    if (!flag_pixel_set)
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
    else
    {
        img = scene->toImage();
        points_t point;
        point.x = pixel_begin_x;
        int x_left, x_right;
        point.y = pixel_begin_y;
        QStack<points_t> stack;
        painter->setPen(filling_color);
        stack.push(point);
        while (!stack.isEmpty())
        {
            point = stack.pop();

            int x = point.x;
            int y = point.y;
            painter->drawPoint(x, y);
            x++;
            ui->draw_label->setPixmap(*scene);
            img = scene->toImage();
            while (x < 881 && img.pixelColor(x, y) != border_color)
            {
                painter->drawPoint(x, y);
                x++;
            }
            x_right = x - 1;
            x = point.x - 1;
            while (x >= 0 && img.pixelColor(x, y) != border_color)
            {
                painter->drawPoint(x, y);
                x--;
            }
            x_left = x + 1;

            if (point.y < 561 - 1)
            {
                double y = point.y + 1;
                find_next_pixel(stack, x_left, x_right, y);
            }
            if (point.y > 0)
            {
                double y = point.y - 1;
                find_next_pixel(stack, x_left, x_right, y);
            }
            if (ui->without_delay_radio->isChecked())
            {
                Sleep(20);
                repaint();

            }
            ui->draw_label->setPixmap(*scene);
        }
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
/*
void MainWindow::on_fill_button_clicked()
{
    stack_c stack;
    points_t point;
    point.x = pixel_begin_x;
    point.y = pixel_begin_y;
    stack.push(point);
    // if pixel was set
    if (flag_pixel_set)
    {
        // drawing with algorithm
        while (!stack.is_empty())
        {

            point = stack.pop();
            double x = point.x;
            double y = point.y;
            double x_temp = x;
            int flag = 0;
            painter->setPen(QColor(filling_color));
            painter->drawPoint(x, y);
            x--;
            img = scene->toImage();
            QColor color = img.pixelColor(x, y);
            while (color != border_color)
            {
                color = img.pixelColor(x, y);
                qDebug() << "1";
                painter->drawPoint(x, y);
                x--;
            }
            double xl = x + 1;
            x = x_temp;
            x++;
            qDebug() << "2";
            color = img.pixelColor(x, y);
            while (color != border_color)
            {
                color = img.pixelColor(x, y);
                painter->drawPoint(x, y);
                x++;
            }
            double xr = x - 1;
            y = y + 1;
            x = xl;
            while (x <= xr)
            {
                flag = 0;
                color = img.pixelColor(x, y);
                while (color != border_color && color != filling_color && x <= xr)
                {
                    color = img.pixelColor(x, y);
                    if (flag == 0)
                        flag = 1;
                    x++;
                }

                if (flag == 1)
                {
                    if (x == xr && color != filling_color && color != border_color)
                    {
                        point.x = x;
                        point.y = y;
                        stack.push(point);
                    }
                    else
                    {
                        point.x = x - 1;
                        point.y = y;
                        stack.push(point);
                    }
                    flag = 0;
                }
                x_temp = x;
                while (color != border_color && color != filling_color && x < xr)
                {
                    color = img.pixelColor(x, y);
                    x++;
                }

                if (x == x_temp)
                {
                    x++;
                }
            }
            y = y - 2;
            x = xl;
            while (x <= xr)
            {
                flag = 0;
                color = img.pixelColor(x, y);
                while (color != border_color && color != filling_color && x <= xr)
                {
                    color = img.pixelColor(x, y);
                    if (flag == 0)
                        flag = 1;
                    x++;
                }

                if (flag == 1)
                {
                    if (x == xr && color != filling_color && color != border_color)
                    {
                        point.x = x;
                        point.y = y;
                        stack.push(point);
                    }
                    else
                    {
                        point.x = x - 1;
                        point.y = y;
                        stack.push(point);
                    }
                    flag = 0;
                }
                x_temp = x;
                while (color != border_color && color != filling_color && x < xr)
                {
                    color = img.pixelColor(x, y);
                    x++;
                }

                if (x == x_temp)
                {
                    x++;
                }
            }

        }
        ui->draw_label->setPixmap(*scene);

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Подождите!");
        // Тип иконки сообщения
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("Затравочный пиксель не установлен");
        // На какой кнопке фокусироваться по умолчанию
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}
*/
