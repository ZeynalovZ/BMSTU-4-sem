#ifndef MYLIFT_H
#define MYLIFT_H
#include <QObject>
#include "neededlibs.h"
#include "controller.h"

class MyLift : public QObject
{
public:
    explicit MyLift(QObject *parent = 0);
    QWidget *getController();
private:
    Controller controller;
    LiftCabin cabin;
    LiftDoors Doors;
};

#endif // MYLIFT_H
