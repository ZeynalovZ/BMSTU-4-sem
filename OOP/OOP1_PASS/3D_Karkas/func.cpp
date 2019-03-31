#include "func.h"
#include "math.h"

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
    float sina, cosa;
    double z, y;
    double angle = get_angle(parameters);
    cosa = cos(angle * M_PI / 180);
    sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        y = get_y_index_point(model, i) * cosa - get_z_index_point(model, i) * sina;
        z = get_y_index_point(model, i) * sina + get_z_index_point(model, i) * cosa;
        fill_y_index_point(model, i, y);
        fill_z_index_point(model, i, z);
    }
    return 0;
}

int rotate_y(model_t &model, parameters_t &parameters)
{
    float sina, cosa;
    double z, x;
    double angle = get_angle(parameters);
    cosa = cos(angle * M_PI / 180);
    sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        x = get_x_index_point(model, i) * cosa - get_z_index_point(model, i) * sina;
        z = get_x_index_point(model, i) * sina + get_z_index_point(model, i) * cosa;
        fill_x_index_point(model, i, x);
        fill_z_index_point(model, i, z);
    }
    return 0;
}

int rotate_z(model_t &model, parameters_t &parameters)
{
    float sina, cosa;
    double x, y;
    double angle = get_angle(parameters);
    cosa = cos(angle * M_PI / 180);
    sina = sin(angle * M_PI / 180);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        x = get_x_index_point(model, i) * cosa - get_y_index_point(model, i) * sina;
        y = get_x_index_point(model, i) * sina + get_y_index_point(model, i) * cosa;
        fill_x_index_point(model, i, x);
        fill_y_index_point(model, i, y);
    }
    return 0;
}

int transform_point(model_t &model, parameters_t &parameters)
{
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        fill_x_index_point(model, i, get_x_index_point(model, i) + parameters.dx);
        fill_y_index_point(model, i, get_y_index_point(model, i) + parameters.dy);
        fill_z_index_point(model, i, get_z_index_point(model, i) + parameters.dz);
        //points[i].x += dx;
        //points[i].y += dy;
        //points[i].z += dz;
    }
    return 0;
}

int scale(model_t &model, parameters_t &parameters)
{
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        fill_x_index_point(model, i, get_x_index_point(model, i) * parameters.kx);
        fill_y_index_point(model, i, get_y_index_point(model, i) * parameters.ky);
        fill_z_index_point(model, i, get_z_index_point(model, i) * parameters.kz);
        //points[i].x = points[i].x * kx;
        //points[i].y = points[i].y * ky;
        //points[i].z = points[i].z * kz;
    }
    return 0;
}
