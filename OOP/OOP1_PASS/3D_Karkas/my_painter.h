#ifndef MY_PAINTER_H
#define MY_PAINTER_H
#include <QGraphicsScene>
#define X 1231
#define Y 531
typedef struct PAINTER painter_t;
struct PAINTER
{
    QGraphicsScene *scene;
    int center_x = X / 2;
    int center_y = Y / 2;
};
#endif // MY_PAINTER_H
