#ifndef MODEL_H
#define MODEL_H
#define MAX_FILE_LENGHT
#include <iostream>

typedef struct POINTS points_t;
struct POINTS
{
    double x;
    double y;
    double z;
};

typedef struct EDGES edges_t;
struct EDGES
{
    int first;
    int second;
};


typedef struct MODEL model_t;
struct MODEL
{
    points_t *points;
    edges_t *edges;
    int count_of_points;
    int count_of_edges;
};


typedef struct POINTS_2D points_2d;
struct POINTS_2D
{
    double x;
    double y;
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
