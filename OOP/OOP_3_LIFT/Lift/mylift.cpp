#include "mylift.h"


MyLift::MyLift(QObject *parent) : QObject (parent)
{
    QObject::connect(&controller, SIGNAL(sendTarget(int)), &cabin,  SLOT(FloorAchieving(int)));
}

QWidget *MyLift::getController()
{
    return &controller;
}
