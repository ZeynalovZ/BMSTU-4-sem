#ifndef INIT_H
#define INIT_H
typedef struct MODEL model_t;
void init(model_t model_param);
struct MODEL
{
    double kx;
    double ky;
    double kz;
    double dx;
    double dy;
    double dz;
    double angle;
};
#endif // INIT_H
