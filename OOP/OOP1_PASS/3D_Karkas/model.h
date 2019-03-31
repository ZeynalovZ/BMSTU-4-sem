#ifndef MODEL_H
#define MODEL_H
#define MAX_FILE_LENGHT
#include "points.h"
#include "edges.h"
#include <iostream>
typedef struct MODEL model_t;
struct MODEL
{
    points_t *points;
    edges_t *edges;
    int count_of_points;
    int count_of_edges;
};

typedef struct PARAM parameters_t;
struct PARAM
{
    double kx = 1;
    double ky = 1;
    double kz = 1;
    double dx = 0;
    double dy = 0;
    double dz = 0;
    double angle = 0;
    char *filename;
};

model_t init();
#endif // MODEL_H
