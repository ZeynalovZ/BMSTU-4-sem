#include "liftcabin.h"

LiftCabin::LiftCabin(QObject *parent)
{
    state = FREE;
    CurrentFloor = 0;
    TargetFloor = 0;
    QObject::connect(&doors, SIGNAL(DoorsClosed()), this , SLOT(FloorAchieving()));
    currentDirection = NO_DIRECTION;
    QObject::connect(this, SIGNAL(Move()), &doors, SLOT(DoorsClosing()));
    QObject::connect(&floorMoving, SIGNAL(timeout()), this , SLOT(FloorAchieving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this , SLOT(Stay()));
    QObject::connect(this, SIGNAL(cabinStopped(int)), &doors , SLOT(DoorsOpenning()));
    floorMoving.setSingleShot(true);
}

LiftCabin::~LiftCabin()
{

}

void LiftCabin::FloorAchieving()
{
    if (state == MOVING || state == BUSY)
    {
        state = MOVING;
        if (CurrentFloor == TargetFloor)
        {
            emit FloorAchieved();
        }
        else
        {
            if (!floorMoving.isActive())
            {
                floorMoving.start(TIME_MOVING_FLOOR);
                emit FloorPassed(CurrentFloor, currentDirection);
                if (CurrentFloor < TargetFloor)
                {
                    currentDirection = UP;
                    CurrentFloor += currentDirection;
                }
                else
                {
                    currentDirection = DOWN;
                    CurrentFloor += currentDirection;
                }
            }

        }
    }
}

void LiftCabin::slotBusy(int floor)
{
    state = BUSY;
    TargetFloor = floor;
    if (CurrentFloor == TargetFloor)
    {
        emit FloorAchieved();
    }
    else
    {
        if (CurrentFloor < TargetFloor)
        {
            currentDirection = UP;
        }
        else
        {
            currentDirection = DOWN;
        }
        emit Move();
    }
}

// здесь нужен контроль за таргетами, если направления все еще совпадают, то сначала на ближний


void LiftCabin::Stay()
{
    state = FREE;
    qDebug() << "floor " << CurrentFloor << "achieved";
    floorMoving.stop();
    emit cabinStopped(CurrentFloor);
    //emit AchievedForResetButton(CurrentFloor);

}


