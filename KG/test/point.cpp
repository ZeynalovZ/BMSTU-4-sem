#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y)
    : x_(x), y_(y)
{}

QRectF Point::boundingRect() const
{
    return QRectF(QPoint(x_ - 2, y_ -2), QPoint(x_ + 2, y_ + 2));
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPoint(QPoint(x_, y_));
    Q_UNUSED(widget);
    Q_UNUSED(option);

}
