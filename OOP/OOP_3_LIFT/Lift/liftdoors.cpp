#include "liftdoors.h"
#include <QDebug>
LiftDoors::LiftDoors(QObject *parent)
{
    state = CLOSE;
    QObject::connect(this, SIGNAL(DoorsOpen()), this, SLOT(DoorsOpenning()));
    QObject::connect(&OpeningTimer, SIGNAL(timeout()), this, SLOT(Open()));
    QObject::connect(&OpenTimer, SIGNAL(timeout()), this, SLOT(DoorsClosing()));
    QObject::connect(&CloseTimer, SIGNAL(timeout()), this, SLOT(Close()));
    QObject::connect(&AddTimer, SIGNAL(timeout()), this, SLOT(DoorsClosing()));
    OpeningTimer.setSingleShot(true);
    OpenTimer.setSingleShot(true);
    CloseTimer.setSingleShot(true);
    AddTimer.setSingleShot(true);
}

void LiftDoors::DoorsOpenning()
{
    if (state == CLOSE)
    {
        state = OPENING;
        qDebug() << "Doors opening";
        OpeningTimer.start(TIME_DOOR_WAIT);
    }
    if (state == CLOSING)
    {
        state = OPENING;
        qDebug() << "Doors opening";
        CloseTimer.stop();
        OpeningTimer.start(TIME_DOOR_WAIT);
    }
}

void LiftDoors::DoorsClosing()
{
    switch (state)
    {
    case OPEN:
        state = CLOSING;
        CloseTimer.start(TIME_DOOR);
        qDebug() << "Doors closing";
        break;
    case CLOSE:
        qDebug() << "==================";
        emit DoorsClosed();
        break;
    case CLOSING:
        CloseTimer.stop();
        this->Close();
        break;
    default:
        break;
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
