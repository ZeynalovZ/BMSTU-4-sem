#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>

#define OFFSET_X_MOUSE 10
#define OFFSET_Y_MOUSE 45
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(color_background);
    ui->draw_label->setMouseTracking(true);
    this->setMouseTracking(true);

    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    painter->setPen(QPen(Qt::blue));
    painter->drawLine(50, 300, 599, 300);
    painter->setPen(QPen(Qt::black));
    ui->draw_label->setPixmap(*scene);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);

    ui->border_color->setAutoFillBackground(true);
    ui->border_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->shading_color->setAutoFillBackground(true);
    ui->shading_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::white);
    ui->background_color->setAutoFillBackground(true);
    ui->background_color->setPalette(Pal);

    /* Работающее сравнение
    painter->setPen(QPen(Qt::black));
    painter->drawLine(50, 50, 100, 100);
    ui->draw_label->setPixmap(*scene);
    QImage image = scene->toImage();
    QColor color = image.pixelColor(QPoint(60, 60));
    // Qred
    if (color == QColor(Qt::black))
    {
        qDebug() << color << "everything is good";
    }
    qDebug() << color << "is color";
    */
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    edge_t edge;
    if (ui->with_mouse_radio->isChecked() && flag_first_attained == false)
    {
        painter->setPen(QPen(color_border));
        double x = event->x();
        double y = event->y();
        if (x >= 10 && y >= 20 && x <= 861 && y <= 706)
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
                    if (abs(prev_x - x) < abs(prev_y - prev_x))
                    {
                        x = prev_x;
                    }
                    else
                    {
                        y = prev_y;
                    }
                }
                painter->drawEllipse(x - OFFSET_X_MOUSE, y - OFFSET_Y_MOUSE, 1, 1);
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x - OFFSET_X_MOUSE, prev_y - OFFSET_Y_MOUSE, x - OFFSET_X_MOUSE, y - OFFSET_Y_MOUSE);
                }

                edge.x1 = prev_x - OFFSET_X_MOUSE;
                edge.y1 = prev_y - OFFSET_Y_MOUSE;
                edge.x2 = x - OFFSET_X_MOUSE;
                edge.y2 = y - OFFSET_Y_MOUSE;

                prev_x = x;
                prev_y = y;


            }
            else if (event->button() == Qt::RightButton)
            {
                if (prev_x != -1 && prev_y != -1)
                {
                    painter->drawLine(prev_x - OFFSET_X_MOUSE, prev_y - OFFSET_Y_MOUSE, first_x - OFFSET_X_MOUSE, first_y - OFFSET_Y_MOUSE);

                    edge.x1 = prev_x - OFFSET_X_MOUSE;
                    edge.y1 = prev_y - OFFSET_Y_MOUSE;
                    edge.x2 = first_x - OFFSET_X_MOUSE;
                    edge.y2 = first_y - OFFSET_Y_MOUSE;

                    prev_x = -1;
                    prev_y = -1;
                    flag_first_touched = false;

                    //flag_first_attained = true;
                }
            }
            edges.append(edge);
            ui->draw_label->setPixmap(*scene);
            // добавить алгоритм сканирования
            /* Тут запрет на рисование, после замыкания !!!!!!!!!!!!
            if (x == first_x && y == first_y)
            {
                flag_first_attained = true;
            }
            */
        }

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Подождите!");
        // Тип иконки сообщения
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("Внешняя граница уже построена");
        // На какой кнопке фокусироваться по умолчанию
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();

    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    double x = event->x();
    double y = event->y();
    qDebug() << x << y;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Check_Button_clicked()
{

    QImage image = scene->toImage();
    double y = 300;
    for (double x = 50; x < 600; x++)
    {
        QColor color = image.pixelColor(QPoint(x, y));
        if (color == QColor(Qt::black))
        {
            qDebug() << color << "everything is good" << x << y;
        }
    }

}

void MainWindow::on_make_line_button_clicked()
{

    bool ok1 = true, ok2 = true;
    QString x1_s = ui->lineEdit_1_x->text();
    QString y1_s = ui->lineEdit_2_y->text();
    double x = x1_s.toDouble(&ok1);
    double y = y1_s.toDouble(&ok2);

    if (ui->with_keyboard_radio->isChecked())
    {
        if (ok1 && ok2)
        {
            painter->setPen(QColor(color_border));
            painter->drawEllipse(x, y, 1, 1);
            if (prev_x != -1 && prev_y != -1)
            {
                painter->drawLine(prev_x - OFFSET_X_MOUSE, prev_y - OFFSET_Y_MOUSE, x, y);
            }
            // Для того, чтобы при переключении способов рисования, можно было продолжить отрисовку
            prev_x = x + OFFSET_X_MOUSE;
            prev_y = y + OFFSET_Y_MOUSE;
            ui->draw_label->setPixmap(*scene);
            if (flag_first_touched == false)
            {
                first_x = x + OFFSET_X_MOUSE;
                first_y = y + OFFSET_Y_MOUSE;
                flag_first_touched = true;
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
}

void MainWindow::on_border_button_clicked()
{
    color_border = QColorDialog::getColor(Qt::black, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_border);
    ui->border_color->setAutoFillBackground(true);
    ui->border_color->setPalette(Pal);
    ui->border_color->show();
}

void MainWindow::on_shading_button_clicked()
{
    color_shading = QColorDialog::getColor(Qt::red, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_shading);
    ui->shading_color->setAutoFillBackground(true);
    ui->shading_color->setPalette(Pal);
    ui->shading_color->show();
}

void MainWindow::on_background_button_clicked()
{
    color_background = QColorDialog::getColor(Qt::white, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_background);
    ui->background_color->setAutoFillBackground(true);
    ui->background_color->setPalette(Pal);
    ui->background_color->show();
}
// TODO добавить ввод ребер с клавиатуры

void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
    edges.clear();
    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    prev_x = -1;
    prev_y = -1;
    flag_first_attained = false;
    flag_first_touched = false;
}

void MainWindow::on_make_line_button_2_clicked()
{
    if (prev_x != -1 && prev_y != -1)
    {
        painter->drawLine(prev_x - OFFSET_X_MOUSE, prev_y - OFFSET_Y_MOUSE, first_x - OFFSET_X_MOUSE, first_y - OFFSET_Y_MOUSE);
        //flag_first_attained = true;
        prev_x = -1;
        prev_y = -1;
        flag_first_touched = false;
    }
    ui->draw_label->setPixmap(*scene);
}


void MainWindow::on_pushButton_clicked()
{
    // needed at least 2 points
    if (edges.size() > 2)
    {
        double x_max = 0;
        double y_min = edges[1].y1;
        double y_max = 0;
        for (int i = 1; i < edges.size(); i++)
        {
            qDebug() << edges[i].x1 << edges[i].y1 << edges[i].x2 << edges[i].y2;
            if (edges[i].x1 > x_max)
                x_max = edges[i].x1;

            if (edges[i].y1 > y_max)
                y_max = edges[i].y1;

            if (edges[i].y1 < y_min && edges[i].y1 > 0)
                y_min = edges[i].y1;
        }
        qDebug() << x_max << "x_max" << y_max << "y_max" << y_min << "y_min";
        painter->setPen(QPen(color_border));
        //painter->drawLine(200, y_min, x_max, y_min);
        //painter->drawLine(200, y_max, x_max, y_max);
        painter->drawLine(x_max, y_min, x_max, y_max);
        ui->draw_label->setPixmap(*scene);

        for (int i = 1; i < edges.size(); i++)
        {
            double dx = edges[i].x2 - edges[i].x1;
            double dy = edges[i].y2 - edges[i].y1;
            double k = dx / dy;
            // тут два цикла по у и по х
            // определить коэф наклона и двигаться до границы каждый раз инвертируя цвет
            // Все
        }
    }

}
