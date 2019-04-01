#include <QGraphicsScene>
#include "my_controller.h"
#include "io.h"
#include <QDebug>
#include "errors.h"
#include "edges.h"
#include "points.h"
#include "func.h"
#include "model.h"
#define X 1231
#define Y 531


// TODO

static void set_view(model_t model, QGraphicsScene &scene)
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

int controller(parameters_t parametrs, QGraphicsScene &scene, int action)
{
    static model_t model = init();

    int code_error = OK;

    switch (action) {
    case LOAD:
        code_error = read_model_from_file(model, parametrs);
        set_view(model, scene);
        break;
    case SAVE:
        code_error = save_changes(model, parametrs);
        set_view(model, scene);
        break;
    case ROTATE_X:
        code_error = rotate_x(model, parametrs);
        set_view(model, scene);
        break;
    case ROTATE_Y:
        code_error = rotate_y(model, parametrs);
        set_view(model, scene);
        break;
    case ROTATE_Z:
        code_error = rotate_z(model, parametrs);
        set_view(model, scene);
        break;
    case SCALE:
        code_error = scale(model, parametrs);
        set_view(model, scene);
        break;
    case TRANSFORM:
        code_error = transform_point(model, parametrs);
        set_view(model, scene);
        break;
    case DRAW:
        set_view(model, scene);
        break;
    default:
        code_error = NO_NEEDED_PARAM;
        break;
    }
    return code_error;
}
