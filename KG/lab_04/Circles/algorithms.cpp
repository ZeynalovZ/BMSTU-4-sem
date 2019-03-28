#include "algorithms.h"

void draw_library_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    // because addellipse get params of left top point, we subtract a and b from each axis,
    // and set double a and double b width and heigh params
    // With circle we do the same thing
    painter.setPen(pen);
    painter.drawEllipse(xc, yc , a, b);
}

void draw_library_circle(double xc, double yc, double R, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    painter.drawEllipse(xc, yc, R , R );
    // for more control
    //painter->drawLine(xc,  yc, xc + R,  yc);
}

void create_circle_spectr(double xc, double yc, double R, double dr, int N, QPainter &painter, QPen pen, void (*func)(double, double, double, QPainter &, QPen), bool LIB)
{
    double delta = 0;
    for (int i = 0; i < N; i++)
    {
        //painter.drawEllipse(xc - R - delta / 2, yc - R - delta / 2 , R + delta, R + delta);
        if (LIB == true)
        {
            func(xc - R - delta, yc - R - delta, R * 2 + delta * 2, painter, pen);
        }
        else
        {
            func(xc, yc, R + delta , painter, pen);
        }

        //scene->addEllipse(xc - R - delta / 2, yc - R - delta / 2, R * 2 + delta , R * 2 + delta, pen);
        delta += dr;
    }
}

void create_ellipse_spectr(double xc, double yc, double a, double b, int step, int N, QPainter &painter, QPen pen, void (*func)(double, double, double, double,  QPainter &, QPen))
{
    double delta = 0;
    for (int i = 0; i < N; i++)
    {
        //painter.drawEllipse(xc - R - delta / 2, yc - R - delta / 2 , R + delta, R + delta);
        func(xc - a - delta, yc - b - delta, a * 2 + delta * 2, b * 2 + delta * 2, painter, pen);
        //scene->addEllipse(xc - R - delta / 2, yc - R - delta / 2, R * 2 + delta , R * 2 + delta, pen);
        delta += step;
    }
}

void draw_canon_circle(double xc, double yc, double R, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    double r2 = R * R;
    int x, y;
    for ( x = 0; x <= R; x++)
    {
        y = round(sqrt(r2 - x * x));
        painter.drawPoint(xc + x,yc - y);
        painter.drawPoint(xc - x,yc - y);
        painter.drawPoint(xc - x,yc + y);
        painter.drawPoint(xc + x,yc + y);
    }

    for ( y = 0; y <= R; y++)
    {
        x = round(sqrt(r2 - y * y));
        painter.drawPoint(xc + x,yc - y);
        painter.drawPoint(xc - x,yc - y);
        painter.drawPoint(xc - x,yc + y);
        painter.drawPoint(xc + x,yc + y);
    }
}

void draw_param_circle(double xc, double yc, double R, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    double x, y;
    for (double t = 0; t <= M_PI_2; t += 1 / R)
    {
        x = R * cos(t);
        y = R * sin(t);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);
    }
}

void draw_brezenham_circle(double xc, double yc, double R, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    int x = 0, y = R;
    int d = 2 * (1 - R);
    int y_end = 0;
    int d1, d2;
    while (y >= y_end)
    {
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);

        if (d <0)
        {
            d1 = 2 * d + 2 * y - 1;
            if (d1 < 0)
            {
                x = x + 1;
                d = d + 2 * x + 1;
            }
            else
            {
                x = x + 1;
                y = y - 1;
                d = d + 2 * (x - y + 1);
            }
        }
        else if (d == 0)
        {
            x = x + 1;
            y = y - 1;
            d = d + 2 * (x - y + 1);
        }
        else
        {
            d2 = 2 * d - 2 * x - 1;
            if (d2 < 0)
            {
                x = x + 1;
                y = y - 1;
                d = d + 2 * (x - y + 1);
            }
            else
            {
                y = y - 1;
                d = d - 2 * y + 1;
            }
        }
    }


}

