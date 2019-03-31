#ifndef IO_H
#define IO_H
#include "edges.h"
#include "points.h"
#include "model.h"
int read_model_from_file(model_t &model, parameters_t &parameters);
//void print_points(points_t *points, int n);
//void print_edges(edges_t *edges, int n);
int save_changes(model_t &model, parameters_t &parameters);
#endif // IO_H
