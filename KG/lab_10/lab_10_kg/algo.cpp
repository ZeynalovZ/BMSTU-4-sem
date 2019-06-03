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
    xi = x1;
    yi = y1;
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
        xi = x1 - static_cast<int>(round(delta_x * (y1 - horizon[x1]) / static_cast<double>(delta_y_c - delta_y_p)));
        yi = static_cast<int>(round((xi - x1) * m + y1));

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
        int x_prev = x1;
        int y_prev = y1;
        double m = (y2 - y1) / static_cast<double>(x2 - x1);
        for (int x = x1; x <= x2; x++)
        {
            int y = static_cast<int>(round(m * (x - x1) + y1));
            TOP[x] = qMax(TOP[x], y);
            DOWN[x] = qMin(DOWN[x], y);
            if (x >= 0 && x <= WINDOW_WIDTH)
            {
                painter.drawLine(x_prev, y_prev, x, y);
            }
        }
    }
}

void EdgeWhatcher(int &x, int &y, int &xEdge, int &yEdge, QVector<int> &TOP, QVector<int> &DOWN, QPainter &painter)
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

    // * это верно!!!
    if (y < TOP[x] && y > DOWN[x]) return 0;
    if (y >= TOP[x]) return 1;
    return -1;

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
    double y_center = WINDOW_WIDTH / 2 - 130;
    double x_tmp = x;
    double y_tmp = y;
    double z_tmp = z;
    rotate_x(y_tmp, z_tmp, tetax);
    rotate_y(x_tmp, z_tmp, tetay);
    rotate_z(x_tmp, y_tmp, tetaz);
    res_x = static_cast<int>(round(x_tmp * 48 + x_center));
    res_y = static_cast<int>(round(y_tmp * 48 + y_center));
}

void HorizonAlgo(NeededParams Params, QPainter &painter, double tetax, double tetay, double tetaz)
{
    {
        qDebug() << Params.xB << Params.xE << Params.xD;
        qDebug() << Params.zB << Params.zE << Params.zD;
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
        int x_prev, y_prev;
        for (double z = Params.zE; z >= Params.zB; z -= Params.zD)
        {
            double y_p = Params.f(Params.xB, z);
            transform(Params.xB, y_p, z, tetax, tetay, tetaz, x_prev, y_prev);
            EdgeWhatcher(x_prev, y_prev, x_left, y_left, TOP, DOWN, painter);
            int Pflag = Visible(x_prev, y_prev, TOP, DOWN);
            for (double x = Params.xB; x <= Params.xE; x += Params.xD)
            {
                int x_curr = 0, y_curr = 0;
                int xi;
                int yi;
                y_p = Params.f(x, z);
                transform(x, y_p, z, tetax, tetay, tetaz, x_curr, y_curr);
                int Tflag = Visible(x_curr, y_curr, TOP, DOWN);
                if (Tflag == Pflag)
                {
                    if (Pflag)
                    {
                        horizon(x_prev, y_prev, x_curr, y_curr, TOP, DOWN, painter);
                    }
                }
                else if (Tflag == 0)
                {
                    if (Pflag == 1)
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                    }
                    else
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, DOWN, xi, yi);
                    }
                    horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                }
                else if (Tflag == 1)
                {
                    if (Pflag == 0)
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                        horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                    }
                    else
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                        horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, DOWN, xi, yi);
                        horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                    }
                }
                else
                {
                    if (Pflag == 0)
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, DOWN, xi, yi);
                        horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                    }
                    else
                    {
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, TOP, xi, yi);
                        horizon(x_prev, y_prev, xi, yi, TOP, DOWN, painter);
                        SearchIntersection(x_prev, y_prev, x_curr, y_curr, DOWN, xi, yi);
                        horizon(xi, yi, x_curr, y_curr, TOP, DOWN, painter);
                    }
                }
                Pflag = Tflag;
                x_prev = x_curr;
                y_prev = y_curr;
            }
            EdgeWhatcher(x_prev, y_prev, x_right, y_right, TOP, DOWN, painter);

        }
    }
}

/*
 *
 * void HorizonAlgo(NeededParams Params, QPainter &painter, double tetax, double tetay, double tetaz)


    int x_left = -1;
    int y_left = -1;
    int x_right = -1;
    int y_right = -1;
    double x_beg = Params.xB;
    double x_end = Params.xE;
    double x_step = Params.xD;
    double z_beg = Params.zB;
    double z_end = Params.zE;
    double z_step = Params.zD;
    int x_prev, y_prev;
    double (*f)(double, double);
    f = Params.f;
    QVector<int> top;
    QVector<int> bottom;
    for (int i = 0; i <= WINDOW_WIDTH; i++)
    {
        top.push_back(0);
        bottom.push_back(WINDOW_HEIGHT);
    }
    for (double z = z_end; z >= z_beg; z -= z_step)
    {
        double y_p = Params.f(Params.xB, z);
        transform(Params.xB, y_p, z, tetax, tetay, tetaz, x_prev, y_prev);
        EdgeWhatcher(x_prev, y_prev, x_left, y_left, top, bottom, painter);
        int prev_flag = Visible(y_prev, x_prev, top, bottom);
        for (double x = x_beg; x < x_end; x += x_step)
        {
            int x_cur = 0, y_cur = 0;
            int xi, yi;
            y_p = Params.f(x, z);
            transform(Params.xB, y_p, z, tetax, tetay, tetaz, x_prev, y_prev);
            int cur_flag = Visible(y_cur, x_cur, top, bottom);
            if (prev_flag == cur_flag)
            {
                if (prev_flag)
                {
                    horizon(x_prev, y_prev, x_cur, y_cur, top, bottom, painter);
                }
            }
            else if (cur_flag == 0)
            {
                if (prev_flag == 1)
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, top, xi, yi);
                }
                else
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, bottom, xi, yi);
                }
                horizon(x_prev, y_prev, xi, yi, top, bottom, painter);
            }
            else if (cur_flag == 1)
            {
                if (prev_flag == 0)
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, top, xi, yi);
                    horizon(x_prev, y_prev, xi, yi, top, bottom, painter);
                }
                else
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, bottom, xi, yi);
                    horizon(x_prev, y_prev, xi, yi, top, bottom, painter);
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, top, xi, yi);
                    horizon(xi, yi, x_cur, y_cur, top, bottom, painter);
                }
            }
            else
            {
                if (prev_flag == 0)
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, bottom, xi, yi);
                    horizon(x_prev, y_prev, xi, yi, top, bottom, painter);
                }
                else
                {
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, top, xi, yi);
                    horizon(x_prev, y_prev, xi, yi, top, bottom, painter);
                    SearchIntersection(x_prev, y_prev, x_cur, y_cur, bottom, xi, yi);
                    horizon(xi, yi, x_cur, y_cur, top, bottom, painter);
                }
            }
            prev_flag = cur_flag;
            x_prev = x_cur;
            y_prev = y_cur;
        }
        EdgeWhatcher(x_prev, y_prev, x_right, y_right, top, bottom, painter);
    }
*/
