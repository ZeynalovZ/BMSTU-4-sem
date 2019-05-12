#include "mylift.h"


MyLift::MyLift(QObject *parent) : QObject (parent)
{
    QObject::connect(&controller, SIGNAL(sendTarget(int)), &cabin,  SLOT(slotBusy(int)));
    QObject::connect(&cabin, SIGNAL(AchievedForResetButton(int)), &controller,  SLOT(AchieveFloor(int)));
    QObject::connect(&cabin, SIGNAL(FloorPassed(int, Direction)), &controller,  SLOT(passCurrentFloor(int,Direction)));
}

QWidget *MyLift::getController()
{
    return &controller;
}
