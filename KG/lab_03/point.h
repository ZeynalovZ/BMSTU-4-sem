#ifndef POINT_H
#define POINT_H

#include <QGraphicsItem>
#include <Qpainter>

class Point
{
public:
    Point();
    Point(int x, int y);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int x_;
    int y_;
};

#endif // POINT_H
