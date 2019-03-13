#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <qpainter.h>
#include <QPainter>
#include <QMessageBox>
#include <iostream>
#include <QColor>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    QPixmap bkgnd("фон4.PNG");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

int sign(double num)
{
    if (num < 0)
    {
        return -1;
    }
    else if (num > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            painter.setPen(QPen(Qt::black,1,Qt::SolidLine));
            painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
            draw_brezenham1(painter);
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            draw_brezenham1(painter);
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
            draw_brezenham2(painter);
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            draw_brezenham2(painter);
        }
    }
    else if (ui->radioButton->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
            draw_cda(painter);
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            draw_cda(painter);
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        cout << "here, check it" << endl;
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_brezenham_gradation(painter);
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            painter.setPen(QPen(Qt::white,1,Qt::SolidLine));
            draw_brezenham_gradation(painter);
        }
    }
}



void MainWindow::draw_brezenham1(QPainter &painter)
{
    double x = x1;
    double y = y1;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double sx = sign(dx);
    double sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    double obmen;
    if (dx > dy)
    {
        obmen = 0;
    }
    else
    {
        obmen = 1;
        double temp = dx;
        dx = dy;
        dy = temp;
    }
    double m = dy / dx;
    double e = m - 0.5;
    for (int i = 0; i <= dx; i++)
    {
        painter.drawPoint(x, y);
        if (e >= 0)
        {
            if (obmen == 0)
            {
                y = y + sy;
            }
            else
            {
                x = x + sx;
            }
            e--;
        }
        if (e < 0)
        {
            if (obmen == 0)
            {
                x = x + sx;
            }
            else
            {
                y = y + sy;
            }
            e += m;
        }
    }
}

void MainWindow::draw_brezenham2(QPainter &painter)
{
    double x = x1;
    double y = y1;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double sx = sign(dx);
    double sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    double obmen;
    if (dx > dy)
    {
        obmen = 0;
    }
    else
    {
        obmen = 1;
        double temp = dx;
        dx = dy;
        dy = temp;
    }
    double fl = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        painter.drawPoint(x, y);
        if (fl >= 0)
        {
            if (obmen == 0)
            {
                y = y + sy;
            }
            else
            {
                x = x + sx;
            }
            fl -= 2 * dx;
        }
        if (fl < 0)
        {
            if (obmen == 0)
            {
                x = x + sx;
            }
            else
            {
                y = y + sy;
            }
            fl += 2 * dy;
        }
    }
}
// Анализ отрезка на вырожденность
void MainWindow::draw_cda(QPainter &painter)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double l;
    if (fabs(dx) > fabs(dy))
    {
        l = fabs(dx);
    }
    else
    {
        l = fabs(dy);
    }
    double sx = dx / l;
    double sy = dy / l;
    double x = x1;
    double y = y1;
    for (int i = 0; i <= l; i++)
    {
        painter.drawPoint(round(x), round(y));
        x = x + sx;
        y = y + sy;
    }
}
// TODO Проверка вырожденности отрезка
void MainWindow::draw_brezenham_gradation(QPainter &painter)
{
    int I = 255;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double sx = sign(dx);
    double sy = sign(dy);
    dx = fabs(dx);
    dy = fabs(dy);
    double e;
    double obmen = 0;
    double m = dy / dx;
    if (m > 1)
    {
        double temp = dx;
        dx = dy;
        dy = temp;
        m = 1 / m;
        obmen = 1;
    }
    else
    {
        obmen = 0;
    }
    e = I / 2;
    double x = x1;
    double y = y1;
    m = m * I;
    double W = I - m;
    painter.setBrush(QBrush(QColor(0, 0, 0, I ), Qt::SolidPattern));
    painter.drawPoint(x, y);
    for (int i = 0; i < dx; i++)
    {
        if (e <= W)
        {
            if (obmen == 0)
            {
                x = x + sx;
            }
            else
            {
                y = y + sy;
            }
            e += m;
        }
        else
        {
            x = x + sx;
            y = y + sy;
            e  = e - W;
        }
        painter.setBrush(QBrush(QColor(0, 0, 0, I), Qt::SolidPattern));
        painter.drawPoint(x, y);
    }

}



/* Как только один из радиобаттонов оказывается нажатым,
 * вызываем перерисовку содержимого виджета,
 * с которым работаем.
 * */

void MainWindow::on_but_exec_clicked()
{
    QString entry_x1 = ui->lineX1->text();
    QString entry_y1 = ui->lineY1->text();
    QString entry_x2 = ui->lineX2->text();
    QString entry_y2 = ui->lineY2->text();
    QStringList X1 = entry_x1.split(" ", QString::SkipEmptyParts);
    QStringList Y1 = entry_y1.split(" ", QString::SkipEmptyParts);
    QStringList X2 = entry_x2.split(" ", QString::SkipEmptyParts);
    QStringList Y2 = entry_y2.split(" ", QString::SkipEmptyParts);

    if (X1.count() != 1 || Y1.count() != 1 || X2.count() != 1 || Y2.count() != 1)
    {
        ui->lineX1->clear();
        ui->lineX2->clear();
        ui->lineY1->clear();
        ui->lineY2->clear();
        QMessageBox msgBox;
        msgBox.setText("Wait!");
        // Тип иконки сообщения
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("You entered wrong params");
        // На какой кнопке фокусироваться по умолчанию
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    x1 = X1[0].toDouble();
    y1 = Y1[0].toDouble();
    x2 = X2[0].toDouble();
    y2 = Y2[0].toDouble();


    if (x1 < x2)
    {
        step_x = 1;
    }
    else
    {
        step_x = -1;
    }

    if (y1 < y2)
    {
        step_y = 1;
    }
    else
    {
        step_y = -1;
    }

    update();
}
