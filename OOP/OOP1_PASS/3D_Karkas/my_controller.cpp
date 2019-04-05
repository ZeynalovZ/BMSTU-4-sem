#include <QGraphicsScene>
#include "my_controller.h"
#include "io.h"
#include <QDebug>
#include "errors.h"
#include "func.h"
#include "model.h"

// Функция - контроллер (управляющая фунция, связывающая инетрфейс и бэкэнд)
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
        break;
    case ROTATE_X:
        code_error = rotate_x(model, parametrs);
        break;
    case ROTATE_Y:
        code_error = rotate_y(model, parametrs);
        break;
    case ROTATE_Z:
        code_error = rotate_z(model, parametrs);
        break;
    case SCALE:
        code_error = scale(model, parametrs);
        break;
    case TRANSFORM:
        code_error = transform_point(model, parametrs);
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
