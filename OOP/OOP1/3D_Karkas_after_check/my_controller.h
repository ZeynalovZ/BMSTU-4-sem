#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H
#include "points.h"
#include "edges.h"
#include "init.h"
enum {LOAD, SAVE, ROTATE_X, ROTATE_Y, ROTATE_Z, SCALE, TRANSFORM};
int controller(points_t **points, edges_t **edges, int *n, int *m,char *filename, model_t model_param, int action);
#endif // MY_CONTROLLER_H
