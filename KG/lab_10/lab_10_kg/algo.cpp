#include "algo.h"
#include <QtGlobal>
#include <cmath>
#define WINDOW_HEIGHT 561
#define WINDOW_WIDTH 881

int sign(double x)
{
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

void SearchIntersection(int x1, int y1, int x2, int y2, QVector<int> &horizon, int &xi, int &yi)
{
    int delta_x = x2 - x1;
    int delta_y_c = y2 - y1;
    int delta_y_p = horizon[x2] - horizon[x1];
    double m = delta_y_c / static_cast<double>(delta_x);
    if (delta_x == 0)
    {
        xi = x2;
        yi = horizon[x2];
    }
    else if (y1 == horizon[x1] && y2 == horizon[x2])
    {
        xi = x1;
        yi = y1;
    }
    else
    {
        xi = x1 - static_cast<int>(round(delta_x * (horizon[x1] - y1) / static_cast<double>(delta_y_p - delta_y_c)));
        yi =  static_cast<int>(round((xi - x1) * m + y1));
    }
}



void horizon(int x1, int y1, int x2, int y2, QVector<int> &TOP, QVector<int> &DOWN, QPainter &painter)
{
    if (x2 < x1)
    {
        qSwap(x1, x2);
        qSwap(y1, y2);
    }
    if (x2 - x1 == 0)
    {
        TOP[x2]  = qMax(TOP[x2], y2);
        DOWN[x2] = qMin(DOWN[x2], y2);
        if (x2 >= 0 && x2 <= WINDOW_WIDTH)
        {
            painter.drawLine(x1, y1, x2, y2);
        }
    }
    else
    {
        double m = (y2 - y1) / static_cast<double>(x2 - x1);
        //qDebug() << m;
        for (int x = x1; x <= x2; x++)
        {
            int y = static_cast<int>(round(m * (x - x1) + y1));
            TOP[x] = qMax(TOP[x], y);
            DOWN[x] = qMin(DOWN[x], y);
            if (x2 >= 0 && x2 <= WINDOW_WIDTH)
            {
                painter.drawLine(x1, y1, x2, y2);
            }
        }
    }
}

void EdgeWhatcher(int x, int y, int &xEdge, int &yEdge, QVector<int> &TOP, QVector<int> &DOWN, QPainter &painter)
{
    if (xEdge != -1)
    {
        horizon(xEdge, yEdge, x , y, TOP, DOWN, painter);
    }
    xEdge = x;
    yEdge = y;
}

int Visible(int x, int y, QVector<int> TOP, QVector<int> DOWN)
{
    int Tflag;
    if (y <= TOP[x] && y > DOWN[x]) Tflag = 0;
    if (y >= TOP[x]) Tflag = 1;
    Tflag = -1;
    return Tflag;
}

void transform_begin(NeededParams &Params)
{
    double x_center = WINDOW_WIDTH / 2;
    double y_center = WINDOW_WIDTH / 2;

    Params.xB *= 48;
    Params.xE *= 48;
    Params.zB *= 48;
    Params.zE *= 48;
    Params.xD *= 48;
    Params.zD *= 48;

    Params.xB += x_center;
    Params.xE += x_center;
    Params.zB += y_center;
    Params.zE += y_center;
}
void rotate_x(double &y, double &z, double tetax)
{
    tetax = tetax * M_PI / 180;
    double buf = y;
    y = cos(tetax) * y - sin(tetax) * z;
    z = cos(tetax) * z + sin(tetax) * buf;
}
void rotate_y(double &x, double &z, double tetay)
{
    tetay = tetay * M_PI / 180;
    double buf = x;
    x = cos(tetay) * x - sin(tetay) * z;
    z = cos(tetay) * z + sin(tetay) * buf;
}
void rotate_z(double &x, double &y, double tetaz)
{
    tetaz = tetaz * M_PI / 180;
    double buf = x;
    x = cos(tetaz) * x - sin(tetaz) * y;
    y = cos(tetaz) * y + sin(tetaz) * buf;
}
void transform(double &x, double &y, double &z, double tetax, double tetay, double tetaz, int &res_x, int &res_y)
{
    double x_center = WINDOW_WIDTH / 2;
    double y_center = WINDOW_WIDTH / 2;
    double x_tmp = x;
    double y_tmp = y;
    double z_tmp = z;
    rotate_x(y_tmp, z_tmp, tetax);
    rotate_y(x_tmp, z_tmp, tetay);
    rotate_z(x_tmp, y_tmp, tetaz);
    res_x = static_cast<int>(round(x_tmp * 100 + x_center));
    res_y = static_cast<int>(round(y_tmp * 100 + y_center));
}

void HorizonAlgo(NeededParams Params, QPainter &painter, double tetax, double tetay, double tetaz)
{
    //transform_begin(Params);
    QVector<int> TOP;
    QVector<int> DOWN;
    for (int i = 0; i <= WINDOW_WIDTH; i++)
    {
        TOP.push_back(0);
        DOWN.push_back(WINDOW_HEIGHT);
    }
    int x_left = -1;
    int y_left = -1;
    int x_right = -1;
    int y_right = -1;
    int Pflag = 0;
    int Tflag = 0;
    double x, y;
    int x_prev, y_prev;
    for (double z = Params.zE; z > Params.zB; z -= Params.zD)
    {
        //double x_prev = Params.xB;
        double y_p = Params.f(Params.xB, z);
        transform(Params.xB, y_p, z, tetax, tetay, tetaz, x_prev, y_prev);
        EdgeWhatcher(x_prev, y_prev, x_left, y_left, TOP, DOWN, painter);
        Pflag = Visible(x_prev, y_prev, TOP, DOWN);
        for (x = Params.xB; x < Params.xE; x += Params.xD)
        {
            int x_curr, y_curr;
            int xi;
            int yi;
            y_p = Params.f(x, z);
            transform(x, y_p, z, tetax, tetay, tetaz, x_curr, y_curr);
            Tflag = Visible(x_curr, y_curr, TOP, DOWN);
            if (Tflag == Pflag)
            {
                if (Tflag == 1 || Tflag == -1)
                {
                    //painter.drawLine(x_prev, y_prev, x, y);
                    horizon(x_prev, y_prev, x_curr, y_curr, TOP, DOWN, painter);
                }
            }
            else
            {
                if (Tflag == 0)
                {
                    if (Pflag == 1)
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                    }
                    else
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, DOWN, xi, yi);
                    }
                    //painter.drawLine(x_prev, y_prev, xi, yi);
                    horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                }
                else
                {
                    if (Tflag == 1)
                    {
                        if (Pflag == 0)
                        {
                            SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                            //painter.drawLine(xi, yi, x, y);
                            horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                        }
                        else
                        {
                            SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                            //painter.drawLine(x_prev, y_prev, xi, yi);
                            horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);

                            SearchIntersection(x_prev, y_prev, x, y, TOP, xi, yi);
                            //painter.drawLine(xi, yi, x, y);
                            horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                        }
                    }
                    else
                    {
                        if (Pflag == 0)
                        {
                            SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                            //painter.drawLine(xi, yi, x, y);
                            horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                        }
                        else
                        {
                            SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                            //painter.drawLine(x_prev, y_prev, xi, yi);
                            horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);

                            SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                            //painter.drawLine(xi, yi, x, y);
                            horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                        }
                    }
                }
            }
            Pflag = Tflag;
            x_prev = x_curr;
            y_prev = y_curr;
        }
        EdgeWhatcher(x, y, x_right, y_right, TOP, DOWN, painter);
    }
}
