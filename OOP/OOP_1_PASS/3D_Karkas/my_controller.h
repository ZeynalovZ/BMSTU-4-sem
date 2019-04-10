#ifndef MY_CONTROLLER_H
#define MY_CONTROLLER_H
#include "model.h"
#include <QGraphicsScene>
enum {LOAD, SAVE, ROTATE_X, ROTATE_Y, ROTATE_Z, SCALE, TRANSFORM, DRAW};
int controller(parameters_t parametrs, QGraphicsScene &scene, int action);
#endif // MY_CONTROLLER_H
