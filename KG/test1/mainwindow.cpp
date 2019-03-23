#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <qpainter.h>
#include <QPainter>
#include <QMessageBox>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegExp check ("[-+]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    QRegExpValidator *my_double_validator = new QRegExpValidator(check, this);
    ui->lineX1->setValidator(my_double_validator);
    ui->lineX2->setValidator(my_double_validator);
    ui->lineY1->setValidator(my_double_validator);
    ui->lineY2->setValidator(my_double_validator);

    connect(ui->lineX1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineX2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineY1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineY2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));

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
    else
    {
        return 1;
    }
}



void MainWindow::draw_brezenham1(QPainter *painter)
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
        painter->drawPoint(x, y);
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

void MainWindow::draw_brezenham2(QPainter *painter)
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
        painter->drawPoint(x, y);
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
    QPainter *painter = new QPainter(this);
    if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
            draw_brezenham1(painter);
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
            draw_brezenham1(painter);
        }
        cout << "brezenham1" << endl;
    }
    else if (ui->radioButton_6->isChecked())
    {
        painter->drawLine(x1, y1, x2, y2);
        update();
    }
    update();
}

void MainWindow::on_changed()
{
    if (ui->lineX1->hasAcceptableInput() && ui->lineX2->hasAcceptableInput()\
            &&ui->lineY1->hasAcceptableInput() && ui->lineY2->hasAcceptableInput())
    {
        ui->but_exec->setEnabled(true);
    }
    else
    {
        ui->but_exec->setEnabled(false);
    }
}
