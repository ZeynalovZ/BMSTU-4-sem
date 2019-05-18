#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>
#include <cmath>
#include <QGraphicsScene>
#include "algorithm.h"
#define X_WIDTH 881
#define Y_WIDTH 561
#define OFFSET_X_MOUSE 10
#define OFFSET_Y_MOUSE 43
#define WINDOW_WIDTH 880
#define WINDOW_HEIGHT 561
#define WINDOW_BEGIN 0
#define BITS_COUNT 4

#define SHIFT_BUTTON 0
#define LEFT_BUTTON 1
#define RIGHT_BUTTON 2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(QColor(Qt::white));
    this->setWindowTitle("Лр8. Отсечение выпуклым многоугольником (Алгоритмом Кируса-Бека)");

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
            rect.append(edge);
            painter.drawLine(prev_rect_x, prev_rect_y, x, y);
        }
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
    painter.setRenderHint(QPainter::Antialiasing, true);
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
        if (ui->polygon_radio->isChecked())
        {
            if (flag_polygon_set == false)
            {
                qDebug() << flag_polygon_set << "flag";
                painter->setPen(QColor(line_color));
                draw_rect(*painter, x, y, first_polygon_x, first_polygon_y, flag_polygon_first_touched, flag_polygon_set, polygon, LEFT_BUTTON, prev_polygon_x, prev_polygon_y);
            }
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

void MainWindow::on_line_color_button_clicked()
{
    line_color = QColorDialog::getColor(line_color, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, line_color);
    ui->line_color_label->setAutoFillBackground(true);
    ui->line_color_label->setPalette(Pal);
    ui->line_color_label->show();
}

double distance(QPoint a, QPoint b)
{
    return sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
}
double CalculateDistance(edge_t edge, int x, int y)
{
    int x1 = edge.x1;
    int x2 = edge.x2;
    int y1 = edge.y1;
    int y2 = edge.y2;
    double ab, bp, ap;
    ab = distance(QPoint(x1, y1), QPoint(x2, y2));
    bp = distance(QPoint(x, y), QPoint(x2, y2));
    ap = distance(QPoint(x, y), QPoint(x1, y1));
    if (bp * bp + ab * ab < ap * ap)
    {
        return bp;
    }
    if (bp * bp > ab * ab + ap * ap)
    {
        return ap;
    }
    double distance = fabs((y2 - y1) * x - (x2 - x1) * y + x2 * y1 - y2 * x1) / ab;
    return distance;
}

int selectParalLine(QVector<edge_t> rect, int x, int y)
{
    int min_index = 0;
    double min = CalculateDistance(rect[0], x, y);  // initialiazing
    for (int i = 1; i < rect.size(); i++)
    {
        double tmp_min = CalculateDistance(rect[i], x, y);
        if (tmp_min < min)
        {
            min_index = i;
            min = tmp_min;
        }
    }
    return min_index;
}

double CalculateKoeffAngle(QVector<edge_t> rect, int index_min)
{
    double dy = rect[index_min].y2 - rect[index_min].y1;
    double dx = rect[index_min].x2 - rect[index_min].x1;
    double k = dy / dx;
    return k;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    x -= OFFSET_X_MOUSE;
    y -= OFFSET_Y_MOUSE;
    if (x >= WINDOW_BEGIN && y >= WINDOW_BEGIN && x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
    {
        if (ui->polygon_radio->isChecked())
        {
            if (flag_polygon_set == false)
            {
                painter->setPen(QPen(line_color));
                int action = LEFT_BUTTON;
                if (event->button() == Qt::LeftButton)
                {
                    if (event->modifiers() == Qt::ShiftModifier)
                    {
                        if (fabs(prev_polygon_x - x) < fabs(prev_polygon_y - y))
                        {
                            x = prev_polygon_x;
                        }
                        else
                        {
                            y = prev_polygon_y;
                        }
                    }
                    painter->setRenderHint(QPainter::Antialiasing, true);
                }
                else
                {
                    action = RIGHT_BUTTON;
                }
                draw_rect(*painter, x, y, first_polygon_x, first_polygon_y, flag_polygon_first_touched, flag_polygon_set, polygon, action, prev_polygon_x, prev_polygon_y);
            }
            else
            {

                QMessageBox msgBox;
                msgBox.setText("Так-с Так-с");
                // Тип иконки сообщения
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setInformativeText("Прямоугольник уже введен, ввести новый?");
                msgBox.setWindowTitle("Внимание !");
                // На какой кнопке фокусироваться по умолчанию
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Yes:
                    delete_current_polygon();
                    break;
                default:
                    break;
                }
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
                        if (fabs(prev_rect_x - x) < fabs(prev_rect_y - y))
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
                msgBox.setWindowTitle("Внимание !");
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
        else if (ui->paralLine_radio->isChecked())
        {
            int paralLineForIndex = 0;
            painter->setRenderHint(QPainter::Antialiasing, true);
            painter->setPen(line_color);
            if (flag_rect_set == true)
            {
                if (first_point_of_paral_line == false)
                {
                    first_paral_x = x;
                    first_paral_y = y;
                    first_point_of_paral_line = true; // first was set
                }
                else
                {
                    paralLineForIndex = selectParalLine(rect, first_paral_x, first_paral_y);
                    first_point_of_paral_line = false; // Todo (here should be multiply of k and prev params)
                    double k = CalculateKoeffAngle(rect, paralLineForIndex);
                    if (k <= 1)
                    {
                        y = round((x - first_paral_x) * k) + first_paral_y;
                    }
                    else
                    {
                        x = round((y - first_paral_y) / k) + first_paral_x;
                    }
                    lines.append(QPoint(x, y));
                    lines.append(QPoint(first_paral_x, first_paral_y));
                    painter->drawLine(x, y, first_paral_x, first_paral_y);
                }
            }
            else
            {
                message_box("Отсекатель не задан!");
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

    prev_polygon_x = -1;
    prev_polygon_y = -1;
    flag_polygon_set = false;
    flag_polygon_first_touched = false;

    prev_rect_y = -1;
    prev_rect_x = -1;
    flag_first_touched = false;
    flag_first_rect_touched = false;
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


void MainWindow::on_cut_button_clicked()
{
    int obhod = 0;
    bool flag = IsConvex(rect, obhod);
    if (flag == true)
    {
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(QPen(outline_color, 2));
        QVector<QPoint> cutter;
        for (int i = 0; i < rect.size(); i++)
        {
            cutter.append(QPoint(rect[i].x1, rect[i].y1));
        }
        QVector<QPoint> poly;
        for (int i = 0; i < polygon.size(); i++)
        {
            poly.append(QPoint(polygon[i].x1, polygon[i].y1));
        }
        QVector<QPoint> res;
        // doesn't work
        SutherlandHodgman(poly, cutter, res);
        for (int i = 0; i < poly.size() - 1; i++)
        {
            painter->drawLine(poly[i], poly[i + 1]);
        }
        //SutherlandHodgman();
        ui->draw_label->setPixmap(*scene);

    }
    else
    {
        message_box("Многоугольник не выпуклый!");
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
    if (flag_polygon_set)
    {
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(line_color);
        for (int i = 0; i < polygon.size(); i++)
        {
            painter->drawLine(polygon[i].x1, polygon[i].y1, polygon[i].x2, polygon[i].y2);
        }
        ui->draw_label->setPixmap(*scene);
    }
    flag_rect_set = false;
    rect.clear();
    ui->draw_label->setPixmap(*scene);
    prev_rect_y = -1;
    prev_rect_x = -1;
    flag_first_rect_touched = false;
}

void MainWindow::delete_current_polygon()
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
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(cutter_color);
        for (int i = 0; i < rect.size(); i++)
        {
            painter->drawLine(rect[i].x1, rect[i].y1, rect[i].x2, rect[i].y2);
        }
        ui->draw_label->setPixmap(*scene);
    }
    flag_polygon_set = false;
    polygon.clear();
    ui->draw_label->setPixmap(*scene);
    prev_polygon_y = -1;
    prev_polygon_x = -1;
    flag_polygon_first_touched = false;
}
