#include "liftcabin.h"

LiftCabin::LiftCabin(QObject *parent)
{
    state = FREE;
    CurrentFloor = 0;
    TargetFloor = 0;
    QObject::connect(this, SIGNAL(sendTarget(int)), this, SLOT(FloorAchieving(int)));
}

LiftCabin::~LiftCabin()
{

}

void LiftCabin::FloorAchieving(int floor)
{
    if (state == FREE)
    {
        qDebug() << "going to" << floor;
        state == MOVING;
    }
}

void LiftCabin::Stay()
{

}
