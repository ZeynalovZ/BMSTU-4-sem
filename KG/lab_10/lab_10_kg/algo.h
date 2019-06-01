#ifndef ALGO_H
#define ALGO_H
#include <QPainter>
#include <QDebug>

struct Point
{
    Point(double x_, double y_, double z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
    double x;
    double y;
    double z;
};

struct NeededParams
{
    NeededParams(double X1, double X2, double X3, double Z1, double Z2, double Z3)
    {
        xB = X1;
        xE = X2;
        xD = X3;
        zB = Z1;
        zE = Z2;
        zD = Z3;
    }
    double (*f)(double, double);
    double xB;
    double xE;
    double xD;
    double zB;
    double zE;
    double zD;
};
void HorizonAlgo(NeededParams Params, QPainter &painter, double tetax, double tetay, double tetaz);
#endif // ALGO_H
