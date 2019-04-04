#include "func.h"
#include "math.h"
#include "errors.h"

// Функции обертки
double get_x_point(model_t model)
{
    return model.points->x;
}

double get_y_point(model_t model)
{
    return model.points->y;
}

double get_z_point(model_t model)
{
    return model.points->z;
}

int get_count_of_points(model_t model)
{
    return model.count_of_points;
}
int get_count_of_edges(model_t model)
{
    return model.count_of_edges;
}

double get_angle(parameters_t parameters)
{
    return parameters.angle;
}

double get_x_index_point(model_t &model, int i)
{
    return model.points[i].x;
}

double get_y_index_point(model_t &model, int i)
{
    return model.points[i].y;
}

double get_z_index_point(model_t &model, int i)
{
    return model.points[i].z;
}

void fill_x_index_point(model_t &model, int i, double x)
{
    model.points[i].x = x;
}
void fill_y_index_point(model_t &model, int i, double y)
{
    model.points[i].y = y;
}
void fill_z_index_point(model_t &model, int i, double z)
{
    model.points[i].z = z;
}

int get_first_index_edge(model_t &model, int i)
{
    return model.edges[i].first;
}

int get_second_index_edge(model_t &model, int i)
{
    return model.edges[i].second;
}

int rotate_x(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / 180);
    double sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        double y = get_y_index_point(model, i) * cosa - get_z_index_point(model, i) * sina;
        double z = get_y_index_point(model, i) * sina + get_z_index_point(model, i) * cosa;
        fill_y_index_point(model, i, y);
        fill_z_index_point(model, i, z);
    }
    return OK;
}

int rotate_y(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / 180);
    double sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        double x = get_x_index_point(model, i) * cosa - get_z_index_point(model, i) * sina;
        double z = get_x_index_point(model, i) * sina + get_z_index_point(model, i) * cosa;
        fill_x_index_point(model, i, x);
        fill_z_index_point(model, i, z);
    }
    return OK;
}

int rotate_z(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / 180);
    double sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        double x = get_x_index_point(model, i) * cosa - get_y_index_point(model, i) * sina;
        double y = get_x_index_point(model, i) * sina + get_y_index_point(model, i) * cosa;
        fill_x_index_point(model, i, x);
        fill_y_index_point(model, i, y);
    }
    return OK;
}

int transform_point(model_t &model, parameters_t &parameters)
{
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        fill_x_index_point(model, i, get_x_index_point(model, i) + parameters.dx);
        fill_y_index_point(model, i, get_y_index_point(model, i) + parameters.dy);
        fill_z_index_point(model, i, get_z_index_point(model, i) + parameters.dz);
    }
    return OK;
}

int scale(model_t &model, parameters_t &parameters)
{
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        fill_x_index_point(model, i, get_x_index_point(model, i) * parameters.kx);
        fill_y_index_point(model, i, get_y_index_point(model, i) * parameters.ky);
        fill_z_index_point(model, i, get_z_index_point(model, i) * parameters.kz);
    }
    return OK;
}
