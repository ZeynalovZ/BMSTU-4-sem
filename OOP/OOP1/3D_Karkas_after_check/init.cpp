#include "init.h"

void init(model_t model_param)
{
    model_param.angle = 0;
    model_param.dx = 0;
    model_param.dy = 0;
    model_param.dz = 0;
    model_param.kx = 1;
    model_param.ky = 1;
    model_param.kz = 1;
}
