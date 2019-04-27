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
#define EPS sqrt(2)

#define FIRST_RECT_XR 600
#define FIRST_RECT_XL 300
#define FIRST_RECT_YH 150
#define FIRST_RECT_YL 300

#define SHIFT_BUTTON 0
#define LEFT_BUTTON 1
#define RIGHT_BUTTON 2
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(QColor(Qt::white));
    this->setWindowTitle("Лр7. Отсечение половинным делением");

    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));

    painter = new QPainter(scene);
    painter->setPen(Qt::red);
    //painter->drawRect(FIRST_RECT_XL, FIRST_RECT_YH, FIRST_RECT_XR - FIRST_RECT_XL, FIRST_RECT_YL - FIRST_RECT_YH);
    ui->draw_label->setPixmap(*scene);
    painter->setPen(Qt::black);
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

int min(int p1, int p2)
{
    if (p1 < p2)
    {
        return p1;
    }
    else
    {
        return p2;
    }
}
int max(int p1, int p2)
{
    if (p1 < p2)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}

void draw_rect(QPainter &painter, int &x, int &y, int &first_rect_x,
               int &first_rect_y, bool &flag_first_rect_touched, bool &flag_rect_set, QVector<edge_t> &rect, int event,
               int &prev_rect_x, int &prev_rect_y)
{
    edge_t edge;
    if (flag_first_rect_touched == false)
    {
        first_rect_x = x;
        first_rect_y = y;
        flag_first_rect_touched = true;
    }
    if (event == LEFT_BUTTON)
    {
        painter.drawPoint(x, y);
        if (prev_rect_x != -1 && prev_rect_y != -1)
        {
            edge.x1 = prev_rect_x;
            edge.y1 = prev_rect_y;
            edge.x2 = x;
            edge.y2 = y;
            painter.drawLine(prev_rect_x, prev_rect_y, x, y);
        }
        qDebug() << "here";
        prev_rect_x = x;
        prev_rect_y = y;
    }
    else if (event == RIGHT_BUTTON)
    {
        if (prev_rect_x != -1 && prev_rect_y != -1)
        {
            edge.x1 = prev_rect_x;
            edge.y1 = prev_rect_y;
            edge.x2 = first_rect_x;
            edge.y2 = first_rect_y;
            painter.drawLine(prev_rect_x, prev_rect_y, first_rect_x, first_rect_y);
            rect.append(edge);
            prev_rect_x = -1;
            prev_rect_y = -1;
            flag_first_rect_touched = false;
            flag_rect_set = true;
        }
    }

}

void draw_line(QPainter &painter, int &x, int &y, int &first_x, int &first_y, bool &flag_first_touched, QVector<QPoint> &lines)
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
    int x = x_value.toInt(&ok1);
    int y = y_value.toInt(&ok2);
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
                draw_rect(*painter, x, y, first_rect_x, first_rect_y, flag_first_rect_touched, flag_rect_set, rect, LEFT_BUTTON, prev_rect_x, prev_rect_y);
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
    int x = event->x();
    int y = event->y();
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
                painter->setRenderHint(QPainter::Antialiasing, true);
                draw_line(*painter, x, y, first_x, first_y, flag_first_touched, lines);
            }
        }
        else if (ui->cutter_radio->isChecked())
        {
            if (flag_rect_set == false)
            {
                painter->setRenderHint(QPainter::Antialiasing, true);
                painter->setPen(cutter_color);
                int action = LEFT_BUTTON;
                if (event->button() == Qt::LeftButton)
                {
                    if (event->modifiers() == Qt::ShiftModifier)
                    {
                        if (fabs(first_x - x) < fabs(first_y - y))
                        {
                            x = prev_rect_x;
                        }
                        else
                        {
                            y = prev_rect_y;
                        }
                    }
                }
                else
                {
                    action = RIGHT_BUTTON;
                }
                draw_rect(*painter, x, y, first_rect_x, first_rect_y, flag_first_rect_touched, flag_rect_set, rect,
                          action, prev_rect_x, prev_rect_y);
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

void set_bits(QVector<int> rect, QPoint point, int *array)
{
    int x = point.x();
    int y = point.y();
    x < rect[0] ? array[3] = 1 : array[3] = 0;
    x > rect[1] ? array[2] = 1 : array[2] = 0;
    y < rect[2] ? array[1] = 1 : array[1] = 0;
    y > rect[3] ? array[0] = 1 : array[0] = 0;
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
    rect.clear();
    ui->draw_label->setPixmap(*scene);
}
