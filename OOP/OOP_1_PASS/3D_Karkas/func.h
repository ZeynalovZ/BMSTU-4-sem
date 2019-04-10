#ifndef FUNC_H
#define FUNC_H
#include "model.h"
#include <QGraphicsScene>
int rotate_x(model_t &model, parameters_t &parameters);
int rotate_y(model_t &model, parameters_t &parameters);
int rotate_z(model_t &model, parameters_t &parameters);
int transform_point(model_t &model, parameters_t &parameters);
int scale(model_t &model, parameters_t &parameters);
double get_x_point(model_t model);
double get_y_point(model_t model);
double get_z_point(model_t model);
int get_count_of_points(model_t model);
int get_count_of_edges(model_t model);
double get_x_index_point(model_t &model, int i);
double get_y_index_point(model_t &model, int i);
double get_z_index_point(model_t &model, int i);
int get_first_index_edge(model_t &model, int i);
int get_second_index_edge(model_t &model, int i);
void set_view(model_t model, QGraphicsScene &scene);
#endif // FUNC_H
