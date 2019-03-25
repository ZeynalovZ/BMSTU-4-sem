#include "my_controller.h"
#include "io.h"
#include "errors.h"
#include "edges.h"
#include "points.h"
#include "process.h"
#include "init.h"
int controller(points_t **points, edges_t **edges, int *n, int *m, char *filename, model_t model_param, int action)
{
    static model_t model = init(model);

    int code_error = OK;

    points_t *p_temp = *points;
    edges_t *e_temp = *edges;

    if (*n == 0 || *m == 0)
    {
        code_error = ERR_READ;
    }
    switch (action) {
    case LOAD:
        init(model_param);
        code_error = read_model_from_file(filename, &p_temp, &e_temp, n, m);
        **points = *p_temp;
        **edges = *e_temp;
        break;
    case SAVE:
        code_error = save_changes(filename, *points, *edges, *n, *m);
    case ROTATE_X:
        code_error = rotate_x(*points, *n, model_param.angle);
    case ROTATE_Y:
        rotate_y(*points, *n, model_param.angle);
    case ROTATE_Z:
        rotate_z(*points, *n, model_param.angle);
    case SCALE:
        scale(*points, *n, model_param.kx, model_param.ky, model_param.kz);
    case TRANSFORM:
        transform_point(*points, *n, model_param.dx, model_param.dy, model_param.dz);
    default:
        code_error = no params;
        break;
    }
    return code_error;
}
