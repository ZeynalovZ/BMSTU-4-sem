#include "algorithms.h"
#include <QDebug>

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

void create_ellipse_spectr(double xc, double yc, double a, double b, int step, int N, QPainter &painter, QPen pen, void (*func)(double, double, double, double,  QPainter &, QPen), bool LIB)
{
    double delta = 0;
    qDebug() << N << " is N";
    double koef = b / a;
    for (int i = 0; i < N; i++)
    {
        //painter.drawEllipse(xc - R - delta / 2, yc - R - delta / 2 , R + delta, R + delta);
        if (LIB == true)
        {
            func(xc - a - delta, yc - b - delta * koef, a * 2 + delta * 2, b * 2 + delta * koef * 2, painter, pen);
        }
        else
        {
            func(xc, yc, a + delta, b + delta * koef, painter, pen);
        }

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
        x = round(R * cos(t));
        y = round(R * sin(t));
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

        if (d < 0)
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

void draw_brezenham_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    int x = 0, y = b;
    int y_end = 0;
    int a2 = a * a;
    int b2 = b * b;
    int d1, d2;
    int d = a2 + b2 - 2 * a2 * y;
    while (y >= y_end)
    {
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);

        if (d < 0)
        {
            d1 = 2 * d + 2 * a2 * y - 1;
            if (d1 < 0)
            {
                x = x + 1;
                d = d + 2 * b2 * x + b2;
            }
            else
            {
                x = x + 1;
                y = y - 1;
                d = d + 2 * b2 * x + b2 + a2 - 2 * a2 * y;

            }
        }
        else if (d == 0)
        {
            x = x + 1;
            y = y - 1;
            d = d + 2 * b2 * x + b2 + a2 - 2 * a2 * y;
        }
        else
        {
            d2 = 2 * d - 2 * b2 * x - 1;
            if (d2 < 0)
            {
                x = x + 1;
                y = y - 1;
                d = d + 2 * b2 * x + b2 + a2 - 2 * a2 * y;
            }
            else
            {
                y = y - 1;
                d = d - 2 * a2 * y + a2;
            }
        }
    }
}

void draw_canon_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    int x, y;
    painter.setPen(pen);
    if (a != 0 && b != 0)
    {
        for (y = 0; y <= b; y++)
        {
            x = round(a * sqrt(1 - y * y / (b * b)));
            painter.drawPoint(xc + x, yc - y);
            painter.drawPoint(xc - x, yc - y);
            painter.drawPoint(xc - x, yc + y);
            painter.drawPoint(xc + x, yc + y);
        }
        for (x = 0; x <= a; x++)
        {
            y = round(b * sqrt(1 - x * x / (a * a)));
            painter.drawPoint(xc + x, yc - y);
            painter.drawPoint(xc - x, yc - y);
            painter.drawPoint(xc - x, yc + y);
            painter.drawPoint(xc + x, yc + y);
        }
    }
}

void draw_param_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    double x, y;
    double max_r = (a > b) ? a : b;
    for (double t = 0; t <= M_PI_2; t += 1 / max_r)
    {
        x = round(a * cos(t));
        y = round(b * sin(t));
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);
    }
}
/*
void draw_midpoint_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    double x = 0;
    double y = b;
    double a2 = a * a;
    double b2 = a * b;
    double prob = b2 - a2 * b + 0.25 * a2;
    while (2 * b2 * x < 2 * a2 * y)
    {
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);
        x++;
        if (prob < 0) //средняя точка внутри эллипса, ближе верхний пиксел, горизонтальный шаг
        {
            prob += 2 * b2 * x + b2;
        }
        else
        {
            y--;
            prob += 2 * b2 * x - 2 * a2 * y + b2;
        }
    }

    prob = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0)
    {
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc + y);
        y--;
        if (prob > 0) //средняя точка внутри эллипса, ближе верхний пиксел, горизонтальный шаг
        {
            prob -= 2 * a2 * y + a2;
        }
        else
        {
            x++;
            prob += 2 * b2 * x - 2 * a2 * y + a2;
        }
    }
}
*/

void draw_midpoint_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    int cx = xc;
    int cy = yc;

    int xr;
    int yr;
    int rx2 = a * a;
    int ry2 = b * b;
    int r2y2 = 2 * ry2;
    int r2x2 = 2 * rx2;
    int rdel2 = rx2 / sqrt(rx2 + ry2);

    int x = 0;
    int y = b;

    int df = 0;
    int f = (ry2 - rx2 * y + 0.25 * rx2 + 0.5);

    int delta = -r2x2 * y;
    for(x = 0; x <= rdel2; x += 1) {
        xr = x + cx;
        yr = y + cy;
        painter.drawPoint(xr, yr);
        painter.drawPoint(cx - x, yr);
        painter.drawPoint(xr, cy - y);
        painter.drawPoint(cx - x, cy - y);
        if(f >= 0) {
            y -= 1;
            delta += r2x2;
            f += delta;
        }
        df += r2y2;;
        f  += df + ry2;
    }
    delta = r2y2 * x;
    f += -ry2 * (x + 0.75) - rx2 * (y - 0.75);
    df = -r2x2 * y;
    for(; y >= 0; y -= 1) {
        xr = x + cx;
        yr = y + cy;
        painter.drawPoint(xr, yr);
        painter.drawPoint(cx - x, yr);
        painter.drawPoint(xr, cy - y);
        painter.drawPoint(cx - x, cy - y);

        if(f < 0) {
            x += 1;
            delta += r2y2;
            f += delta;
        }
        df += r2x2;
        f  += df + rx2;
    }
}

void draw_midpoint_circle(double xc, double yc, double R, QPainter &painter, QPen pen)
{
    painter.setPen(pen);
    int cx = xc;
    int cy = yc;

    int xr;
    int yr;
    int r2 = R * R;
    int r22 = 2 * r2;
    int rdel2 = round(R / sqrt(2));

    int x = 0;
    int y = R;

    int f = (r2 - r2 * y + 0.25 * r2 + 0.5);
    int df = 0;

    int delta = -r22 * y;

    while(x <= rdel2) {
        xr = x + cx;
        yr = y + cy;
        painter.drawPoint(xr, yr);
        painter.drawPoint(cx - x, yr);
        painter.drawPoint(xr, cy - y);
        painter.drawPoint(cx - x, cy - y);

        x += 1;
        if(f >= 0) {
            y -= 1;
            delta += r22;
            f += delta;
        }
        df += r22;
        f  += df + r2;
    }
    delta = r22 * x;
    f += - r2 * (x + y);
    df = -r22 * y;
    while(y >= 0) {
        xr = x + cx;
        yr = y + cy;
        painter.drawPoint(xr, yr);
        painter.drawPoint(cx - x, yr);
        painter.drawPoint(xr, cy - y);
        painter.drawPoint(cx - x, cy - y);
        y -= 1;
        if(f < 0) {
            x += 1;
            delta += r22;
            f += delta;
        }
        df += r22;
        f  += df + r2;//
    }
}

