#ifndef PROCESS_H
#define PROCESS_H
#include "points.h"
#include "edges.h"
void rotate_x(points_t *points, int n, float angle, points_t center);
void rotate_y(points_t *points, int n, float angle, points_t center);
void rotate_z(points_t *points, int n, float angle, points_t center);
void transform_point(points_t *points, int n, double dx, double dy, double dz);
void scale(points_t *points, int n, double koef);
#endif // PROCESS_H
