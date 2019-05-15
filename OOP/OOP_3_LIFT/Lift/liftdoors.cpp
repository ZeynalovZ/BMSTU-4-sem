#include "liftdoors.h"
#include <QDebug>
LiftDoors::LiftDoors(QObject *parent)
{
    state = CLOSE;
    QObject::connect(this, SIGNAL(DoorsOpen()), this, SLOT(DoorsOpenning()));
    QObject::connect(&OpeningTimer, SIGNAL(timeout()), this, SLOT(Open()));
    QObject::connect(&OpenTimer, SIGNAL(timeout()), this, SLOT(DoorsClosing()));
    QObject::connect(&CloseTimer, SIGNAL(timeout()), this, SLOT(Close()));
}

void LiftDoors::DoorsOpenning()
{
    if (state == CLOSE)
    {
        state = OPENING;
        qDebug() << "Doors opening";
        OpeningTimer.start(TIME_DOOR_WAIT);
    }
}

void LiftDoors::DoorsClosing()
{
    if (state == OPEN)
    {
        state = CLOSING;
        CloseTimer.start(TIME_DOOR);
        qDebug() << "Doors closing";
    }
}

void LiftDoors::Open()
{
    if (state == OPENING)
    {
        state = OPEN;
        qDebug() << "Doors are open";
        OpenTimer.start(TIME_DOOR);
    }
}

void LiftDoors::Close()
{
    if (state == CLOSING)
    {
        state = CLOSE;
        qDebug() << "doors closed";
    }
    emit DoorsClosed();
}
