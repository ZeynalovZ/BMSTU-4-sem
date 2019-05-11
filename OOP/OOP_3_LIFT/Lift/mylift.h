#ifndef MYLIFT_H
#define MYLIFT_H
#include <QObject>
#define TIME_DOOR         500
#define TIME_DOOR_WAIT    500
#define TIME_MOVING_FLOOR 1000
#include "controller.h"
#include "liftcabin.h"

class MyLift : public QObject
{
public:
    explicit MyLift(QObject *parent = 0);
    QWidget *getController();
private:
    Controller controller;
    LiftCabin cabin;
};

#endif // MYLIFT_H
