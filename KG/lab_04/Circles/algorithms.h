#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QPainter>
#include <QPen>
#include <math.h>
void draw_library_ellipse(double xc, double yc, double a, double b, QPainter &painter, QPen pen);
void draw_library_circle(double xc, double yc, double R, QPainter &painter, QPen pen);
void create_circle_spectr(double xc, double yc, double R, double dr, int N, QPainter &painter, QPen pen, void (*func)(double, double, double, QPainter &, QPen ), bool LIB);
void create_ellipse_spectr(double xc, double yc, double a, double b, int step, int N, QPainter &painter, QPen pen, void (*func)(double, double, double, double,  QPainter &, QPen));
void draw_canon_circle(double xc, double yc, double R, QPainter &painter, QPen pen);
void draw_param_circle(double xc, double yc, double R, QPainter &painter, QPen pen);
void draw_brezenham_circle(double xc, double yc, double R, QPainter &painter, QPen pen);
#endif // ALGORITHMS_H
