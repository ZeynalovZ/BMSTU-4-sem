#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QPoint>
#include <QPainter>
typedef struct EDGE edge_t;
struct EDGE
{
    int x1;
    int y1;
    int x2;
    int y2;
};
void CyrusBekaAlgorithm(QPoint P1, QPoint P2, int obhod, QVector<edge_t> rect, QPainter &painter);
bool IsConvex(QVector<edge_t> rect, int &obhod);
#endif // ALGORITHM_H
