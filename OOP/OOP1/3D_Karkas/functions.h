#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "points.h"
#include "edges.h"
#include "model.h"
void rotate_x(model_t &model, parameters_t &parameters);
void rotate_y(model_t &model, parameters_t &parameters);
void rotate_z(model_t &model, parameters_t &parameters);
void transform_point(model_t &model, parameters_t &parameters);
void scale(model_t &model, parameters_t &parameters);
double get_x_point(model_t model);
double get_y_point(model_t model);
double get_z_point(model_t model);
double get_count_of_points(model_t model);
double get_count_of_edges(model_t model);
double get_x_index_point(model_t &model, int i);
double get_y_index_point(model_t &model, int i);
double get_z_index_point(model_t &model, int i);
void get_first_index_edge(model_t &model, int i);
void get_second_index_edge(model_t &model, int i);
#endif // PROCESS_H
