#ifndef __IO__H__
#define __IO__H__
#include <stdio.h>
#include "err.h"
typedef struct COORDINATES coordinates;

struct COORDINATES
{
    double x;
    double y;
};

int user_input(double *num);
int count_of_points_in_file(FILE *f, int *n);
int read_coordinates_from_file(FILE *f, coordinates *points, int *count);
void print_in_file();
double func(double x);
#endif
