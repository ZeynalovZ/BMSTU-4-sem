#include <QGraphicsScene>
#include "my_controller.h"
#include "io.h"
#include "errors.h"
#include "edges.h"
#include "points.h"
#include "functions.h"
#include "model.h"
#include "functions.h"


// TODO
// add drawing model
// static void set_view(model_t model, parameters_t parameters, )

static void set_view(model_t model, QGraphicsScene &scene)
{
    points_2d p_res[get_count_of_points(model)];
    // drawing axis
    scene->addLine(X / 2, Y - Y, X / 2, Y);
    scene->addLine(X - X, Y / 2, X, Y / 2);
    for (int i = 0; i < n; i++)
    {
        double sx = center.x + get_x_point(model);
        double sy = center.y + get_y_point(model);
        p_res[i].x = sx;
        p_res[i].y = sy;
        scene->addEllipse(sx, sy, 1, 1);
    }
    for (int i = 0; i < m; i++)
    {
        int first_x = p_res[model.edges[i].first].x;
        int first_y = p_res[model.edges[i].first].y;
        int second_x = p_res[model.edges[i].second].x;
        int second_y = p_res[model.edges[i].second].y;
        scene->addLine(first_x, first_y, second_x, second_y);
    }
}

int controller(parameters_t parametrs, QGraphicsScene &scene, int action)
{
    static model_t model = init();

    int code_error = OK;

    switch (action) {
    case LOAD:
        code_error = read_model_from_file(model, parametrs);
        break;
    case SAVE:
        code_error = save_changes(model, parametrs);
    case ROTATE_X:
        code_error = rotate_x(model, parametrs);
    case ROTATE_Y:
        code_error = rotate_y(model, parametrs);
    case ROTATE_Z:
        code_error = rotate_z(model, parametrs);
    case SCALE:
        code_error = scale(model, parametrs);
    case TRANSFORM:
        code_error = transform_point(model, parametrs);
    default:
        code_error = NO_NEEDED_PARAM;
        break;
    }

    if (code_error == OK)
    {
        set_view(model, scene);
    }
    return code_error;
}
