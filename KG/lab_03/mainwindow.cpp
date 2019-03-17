#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <qpainter.h>
#include <QPainter>
#include <QMessageBox>
#include <iostream>
#include <QColor>
#include <QColorDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QRegExp check ("[-+]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    QRegExpValidator *my_double_validator = new QRegExpValidator(check, this);
    ui->lineX1->setValidator(my_double_validator);
    ui->lineX2->setValidator(my_double_validator);
    ui->lineY1->setValidator(my_double_validator);
    ui->lineY2->setValidator(my_double_validator);
    ui->but_exec->setEnabled(false);

    connect(ui->lineX1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineX2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineY1, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
    connect(ui->lineY2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
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
void MainWindow::draw_brezenham1(QPen pen)
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
        scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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

void MainWindow::draw_brezenham2(QPen pen)
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
        scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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
void MainWindow::draw_cda(QPen pen)
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
        scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
        x = x + sx;
        y = y + sy;
    }
}
// TODO Проверка вырожденности отрезка
void MainWindow::draw_brezenham_gradation(QPen pen)
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
    QColor col = pen.color();

    scene->addEllipse(x, y, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
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
        col.setAlphaF(1 - (e / I));
        scene->addEllipse(x, y, 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
    }

}

float fractionalPart(float x)
{
    int tmp = (int) x;
    return x - tmp; //вернёт дробную часть числа
}

void MainWindow::draw_vu(QPen pen)
{
    double I = 255;
    if (x2 < x1)
    {
        double tmp = x2;
        x2 = x1;
        x1 = tmp;
    }
    double dx = x2 - x1;
    double dy = y2 - y1;
    double gradient = 0;
    QColor col = pen.color();
    if (dx > dy)
    {
        gradient = float(dy / dx);
        float itery = y1 + gradient;
        scene->addEllipse(x1, y1, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
        for (int x = x1; x < x2; ++x)
        {
            col.setAlphaF(((I - fractionalPart(itery) * I)) / I);
            cout << "hey11 " <<1 - ((I - fractionalPart(itery) * I)) / I <<
            scene->addEllipse(x, int(itery), 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
            col.setAlphaF((fractionalPart(itery)));
            cout << "hey12 " <<(fractionalPart(itery)) <<
            scene->addEllipse(x, int(itery) + 1, 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
            itery += gradient;
        }
        scene->addEllipse(x2, y2, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
    }
    else
    {
        gradient = float(dx / dy);
        double iterx = x1 + gradient;
        scene->addEllipse(x1, y1, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
        for (int y = y1; y < y2; ++y)
        {
            col.setAlphaF(1 - ((I - fractionalPart(iterx) * I)) / I);
            cout << "hey21 " <<1 - ((I - fractionalPart(iterx) * I)) / I <<
            scene->addEllipse(int(iterx), y, 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
            col.setAlphaF((fractionalPart(iterx)));
            cout << "hey22 " <<(fractionalPart(iterx)) <<
            scene->addEllipse(int(iterx) + 1, y, 0.1, 0.1, QPen(col,1,Qt::SolidLine), QBrush(Qt::SolidPattern));
            iterx += gradient;
        }
        scene->addEllipse(x2, y2, 0.1, 0.1, pen, QBrush(Qt::SolidPattern));
    }

}

void MainWindow::choose_method()
{
    if (ui->radioButton_3->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_brezenham1(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            draw_brezenham1(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_brezenham2(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            draw_brezenham2(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_cda(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            draw_cda(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_4->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_brezenham_gradation(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            draw_brezenham_gradation(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_5->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            draw_vu(QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            draw_vu(QPen(Qt::white,1,Qt::SolidLine));
        }
    }
    else if (ui->radioButton_6->isChecked())
    {
        if (ui->radioButton_BLACK->isChecked())
        {
            scene->addLine(x1, y1, x2, y2, QPen(color,1,Qt::SolidLine));
        }
        else if (ui->radioButton_WHITE->isChecked())
        {
            scene->addLine(x1, y1, x2, y2, QPen(Qt::white,1,Qt::SolidLine));
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

    choose_method();

    update();
}

void MainWindow::on_pushCOLOR_clicked()
{
    color = QColorDialog::getColor(Qt::yellow, this );
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color);
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(Pal);
    ui->frame->show();
}


void MainWindow::on_pushButton_clicked()
{
    scene->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    on_but_exec_clicked();
    on_pushButton_clicked();

    double distance = sqrt(pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2),2));
    double radius = distance / 2.0;
    double dx1 = x1;
    double dy1 = y1;
    double dx2 = x2;
    double dy2 = y2;
    double xc = (x1 + x2) / 2.0;
    double yc = (y1 + y2) / 2.0;
    cout << distance << endl;
    cout << radius << endl;
    for (int angle = 0; angle <= 180; angle += 30)
    {
        double distance1 = sqrt(pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2),2));
        cout << distance1 << endl;
        choose_method();
        /*
        x1 = x0 + radius * cos(i * PI / 180);
        y1 = y0 + radius * sin(i * PI / 180);
        x2 = x1 + radius * cos(i * PI / 180);
        y2 = y1 + radius * sin(i * PI / 180);
        */
        x1=xc+(dx1-xc)*cos(angle*M_PI/180)-(dy1-yc)*sin(angle*M_PI/180);
        y1=yc+(dx1-xc)*sin(angle*M_PI/180)+(dy1-yc)*cos(angle*M_PI/180);
        x2=xc+(dx2-xc)*cos(angle*M_PI/180)-(dy2-yc)*sin(angle*M_PI/180);
        y2=yc+(dx2-xc)*sin(angle*M_PI/180)+(dy2-yc)*cos(angle*M_PI/180);

    }
}
