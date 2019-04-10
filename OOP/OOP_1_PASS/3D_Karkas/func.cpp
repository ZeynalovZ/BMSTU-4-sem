#include "func.h"
#include "math.h"
#include "errors.h"
#define TO_RAD_180 180
#define X 1231
#define Y 531

// Функция обертка для получения кол-ва точек
int get_count_of_points(model_t model)
{
    return model.count_of_points;
}
// Функция обертка для получения кол-ва ребер
int get_count_of_edges(model_t model)
{
    return model.count_of_edges;
}
// Функция обертка для получения угла поворота
double get_angle(parameters_t parameters)
{
    return parameters.angle;
}
// Функция обертка для получения координаты по индексу
double get_x_index_point(model_t &model, int i)
{
    return model.points[i].x;
}
// Функция обертка для получения координаты по индексу
double get_y_index_point(model_t &model, int i)
{
    return model.points[i].y;
}
// Функция обертка для получения координаты по индексу
double get_z_index_point(model_t &model, int i)
{
    return model.points[i].z;
}
// Функция обертка для заполнения координаты в модель
void fill_x_index_point(model_t &model, int i, double x)
{
    model.points[i].x = x;
}
// Функция обертка для заполнения координаты в модель
void fill_y_index_point(model_t &model, int i, double y)
{
    model.points[i].y = y;
}
// Функция обертка для заполнения координаты в модель
void fill_z_index_point(model_t &model, int i, double z)
{
    model.points[i].z = z;
}
// Функция обертка для получения первого индекса связи
int get_first_index_edge(model_t &model, int i)
{
    return model.edges[i].first;
}
// Функция обертка для получения второго индекса связи
int get_second_index_edge(model_t &model, int i)
{
    return model.edges[i].second;
}
// Функция поворота модели вокруг оси X
int rotate_x(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / TO_RAD_180);
    double sina = sin(angle * M_PI / TO_RAD_180);
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
// Функция поворота модели вокруг оси Y
int rotate_y(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / TO_RAD_180);
    double sina = sin(angle * M_PI / TO_RAD_180);
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
// Функция поворота модели вокруг оси Z
int rotate_z(model_t &model, parameters_t &parameters)
{
    double angle = get_angle(parameters);
    if (angle == 0)
    {
        return WARNING;
    }
    double cosa = cos(angle * M_PI / TO_RAD_180);
    double sina = sin(angle * M_PI / TO_RAD_180);
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
// Функция перноса модели (по координатам)
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
// Функция масштабирования модели
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
// Функция печати модели на сцену
void set_view(model_t model, QGraphicsScene &scene)
{
    double center_x = X / 2;
    double center_y = Y / 2;
    points_2d p_res[get_count_of_points(model)];
    // drawing axis
    scene.addLine(X / 2, Y - Y, X / 2, Y);
    scene.addLine(X - X, Y / 2, X, Y / 2);
    int n = get_count_of_points(model);
    for (int i = 0; i < n; i++)
    {
        double sx = center_x + get_x_index_point(model, i);
        double sy = center_y + get_y_index_point(model, i);
        p_res[i].x = sx;
        p_res[i].y = sy;
        scene.addEllipse(sx, sy, 1, 1);
    }
    int m = get_count_of_edges(model);
    for (int i = 0; i < m; i++)
    {
        int first_x = p_res[model.edges[i].first].x;
        int first_y = p_res[model.edges[i].first].y;
        int second_x = p_res[model.edges[i].second].x;
        int second_y = p_res[model.edges[i].second].y;
        scene.addLine(first_x, first_y, second_x, second_y);
    }
}
