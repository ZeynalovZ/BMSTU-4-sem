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
#define OFFSET_Y_MOUSE 43
#define WINDOW_WIDTH 880
#define WINDOW_HEIGHT 561
#define WINDOW_BEGIN 0
#define BITS_COUNT 4
#define EPS 0.0001
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
void message_box(QString message)
{
    QMessageBox msgBox;
    msgBox.setText("Так-с Так-с");
    // Тип иконки сообщения
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText(message);
    // На какой кнопке фокусироваться по умолчанию
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

double min(double p1, double p2)
{
    if ((p1 - p2) < EPS)
    {
        return p1;
    }
    else
    {
        return p2;
    }
}
double max(double p1, double p2)
{
    if ((p1 - p2) < EPS)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}
void draw_rect(QPainter &painter, double &x, double &y, double &first_rect_x,
               double &first_rect_y, bool &flag_first_rect_touched, bool &flag_rect_set, QVector<double> &rect)
{
    painter.drawPoint(x, y);
    if (flag_first_rect_touched == false)
    {
        first_rect_x = x;
        first_rect_y = y;
        flag_first_rect_touched = true;
    }
    else
    {
        flag_first_rect_touched = false;
        flag_rect_set = true;
        double width_rect = x - first_rect_x;
        double height_rect = y - first_rect_y;
        painter.drawRect(first_rect_x, first_rect_y, width_rect, height_rect);
        rect.append(min(first_rect_x, first_rect_x + width_rect));
        rect.append(max(first_rect_x, first_rect_x + width_rect));
        rect.append(min(first_rect_y, first_rect_y + height_rect));
        rect.append(max(first_rect_y, first_rect_y + height_rect));
    }
}

void draw_line(QPainter &painter, double &x, double &y, double &first_x, double &first_y, bool &flag_first_touched, QVector<QPoint> &lines)
{
    painter.drawPoint(x, y);
    if (flag_first_touched == false)
    {
        first_x = x;
        first_y = y;
        flag_first_touched = true;
    }
    else
    {
        flag_first_touched = false;
        lines.append(QPoint(first_x, first_y));
        lines.append(QPoint(x, y));
        painter.drawLine(x, y, first_x, first_y);
    }
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
            flag_line_exist = true;
            painter->setPen(QColor(line_color));
            draw_line(*painter, x, y, first_x, first_y, flag_first_touched, lines);
        }
        else if (ui->cutter_radio->isChecked())
        {
            if (flag_rect_set == false)
            {
                painter->setPen(QColor(cutter_color));
                draw_rect(*painter, x, y, first_rect_x, first_rect_y, flag_first_rect_touched, flag_rect_set, rect);
            }
        }
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        if (ok1 && !ok2)
        {
            message_box(QString("Координата по Y введена не корректно"));
        }
        else if (!ok1 && ok2)
        {
            message_box(QString("Координата по X введена не корректно"));
        }
        else
        {
            message_box(QString("Введены неверные Координаты точки"));
        }

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
    if (x >= WINDOW_BEGIN && y >= WINDOW_BEGIN && x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
    {
        if (ui->line_radio->isChecked())
        {
            painter->setPen(QPen(line_color));
            if (event->button() == Qt::LeftButton)
            {
                if (event->modifiers() == Qt::ShiftModifier)
                {
                    if (fabs(first_x - x) < fabs(first_y - y))
                    {
                        x = first_x;
                    }
                    else
                    {
                        y = first_y;
                    }
                }
                flag_line_exist = true;
                draw_line(*painter, x, y, first_x, first_y, flag_first_touched, lines);
            }
        }
        else if (ui->cutter_radio->isChecked())
        {
            if (flag_rect_set == false)
            {
                painter->setPen(cutter_color);
                draw_rect(*painter, x, y, first_rect_x, first_rect_y, flag_first_rect_touched, flag_rect_set, rect);
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Так-с Так-с");
                // Тип иконки сообщения
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setInformativeText("Отсекатель уже введен, ввести новый?");
                // На какой кнопке фокусироваться по умолчанию
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Yes:
                    on_delete_cutter_button_clicked();
                    break;
                default:
                    break;
                }
            }
        }
        ui->draw_label->setPixmap(*scene);
    }

}
void MainWindow::on_clear_button_clicked()
{
    delete painter;
    delete scene;
    ui->draw_label->clear();
    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    prev_x = -1;
    prev_y = -1;
    flag_first_touched = false;
    flag_rect_set = false;
    flag_line_exist = false;
    rect.clear();
    lines.clear();
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

void set_bits(QVector<double> rect, QPoint point, int *array)
{
    double x = point.x();
    double y = point.y();
    x < rect[0] ? array[0] = 1 : array[0] = 0;
    x > rect[1] ? array[1] = 1 : array[1] = 0;
    y > rect[3] ? array[2] = 1 : array[2] = 0;
    y < rect[2] ? array[3] = 1 : array[3] = 0;
}

int get_sum(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
int get_p(int *array1, int *array2,  int size)
{
    int p = 0;
    for (int i = 0; i < size; i++)
    {
        p += array1[i] * array2[i];
    }
    return p;
}

void MainWindow::on_cut_button_clicked()
{
    if (flag_line_exist && flag_rect_set)
    {
        // here algorithm
        qDebug() << "hohohoho";
        for (int j = 0; j < lines.size(); j += 2)
        {
            // lines[i] = P1 and lines[i + 1] = P2 // P1, P2 - points
            int i = 1; // шаг отсечения
            int T1[BITS_COUNT];
            int T2[BITS_COUNT];
            int S1, S2; // Summ of BITS T1 and BITS T2
            set_bits(rect, lines[j], T1);
            set_bits(rect, lines[j + 1], T2);
            for (int i = 0; i < 4; i++)
            {
                qDebug() << T1[i];
            }
            qDebug() << "second";
            for (int i = 0; i < 4; i++)
            {
                qDebug() << T2[i];
            }
            S1 = get_sum(T1, BITS_COUNT);
            S2 = get_sum(T2, BITS_COUNT);
            qDebug() << S1 << "S1";
            qDebug() << S2 << "S2";
            if (S1 == 0 && S2 == 0)
            {
                ;// Визуализация
            }
            else
            {
                double P = get_p(T1, T2, BITS_COUNT);
                if (P == 0)
                {
                    QPoint R = lines[j];
                    if (i > 2)
                    {
                        double P = get_p(T1, T2, BITS_COUNT);
                        if (P == 0)
                        {
                            ;// визуализация;
                        }
                        else
                        {
                            ;// конец;
                        }

                    }
                }
                else
                {
                    ;// Конец
                }
            }



        }
    }
    else
    {
        if (!flag_rect_set && flag_line_exist)
        {
            message_box(QString("Вы не ввели отсекатель!"));
        }
        else if (!flag_line_exist && flag_rect_set)
        {
            message_box(QString("Вы не нарисовали линии!"));
        }
        else
        {
            message_box(QString("Вы не нарисовали линии и не ввели отсекатель!"));
        }

    }
}

void MainWindow::on_delete_cutter_button_clicked()
{
    delete painter;
    delete scene;
    ui->draw_label->clear();
    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    // here i draw everything that was in scene besides cutter (lines)
    if (flag_rect_set)
    {
        painter->setPen(line_color);
        for (int i = 0; i < lines.size(); i += 2)
        {
            painter->drawLine(lines[i], lines[i + 1]);
        }
        ui->draw_label->setPixmap(*scene);
    }
    flag_rect_set = false;
    ui->draw_label->setPixmap(*scene);
}
