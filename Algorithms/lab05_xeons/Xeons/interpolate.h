#ifndef INTERPOLATE_H
#define INTERPOLATE_H
#include <math.h>
#include <stdlib.h>

#define EPS_DOUBLE 1e-10
#define IS_EQUAL(x, y) (fabs((x) - (y)) <= EPS_DOUBLE)

#define OK               0
#define NOT_ENOUGH_DATA -5
#define MEMORY_ERROR   -10
#define ZERO_DEVISION  -15
#define EXTRAPOLATION  -20
#define FOUND          -25
#define IN_TABLE       -30

typedef struct data_t
{
    double *data_x;
    double *data_y;
    int count;
} data_d;

double interpolate(double *argument, double *value, int size, int degree, double search);
#endif // INTERPOLATE_H
