#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y)
    : x_(x), y_(y)
{}


QRectF Point::boundingRect() const
{
    return QRectF(QPoint(x_,y_), QPoint(x_, y_));
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPoint(x_, y_);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
