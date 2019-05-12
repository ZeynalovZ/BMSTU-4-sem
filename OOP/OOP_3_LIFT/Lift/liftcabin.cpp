#include "liftcabin.h"

LiftCabin::LiftCabin(QObject *parent)
{
    state = FREE;
    CurrentFloor = 0;
    TargetFloor = 0;
    currentDirection = NO_DIRECTION;
    QObject::connect(this, SIGNAL(Move()), this, SLOT(FloorAchieving()));
    QObject::connect(&floorMoving, SIGNAL(timeout()), this , SLOT(FloorAchieving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this , SLOT(Stay()));
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
            qDebug() << "Floor achieved:" << CurrentFloor;
            emit FloorAchieved();
        }
        else
        {
            qDebug() << "Floor achieving. Now at" << CurrentFloor;
            floorMoving.start(TIME_MOVING_FLOOR);
            if (CurrentFloor < TargetFloor)
            {
                currentDirection = UP;
                emit FloorPassed(CurrentFloor, currentDirection);
                CurrentFloor += currentDirection;
            }
            else
            {
                currentDirection = DOWN;
                emit FloorPassed(CurrentFloor, currentDirection);
                CurrentFloor += currentDirection;
            }
        }
    }
}

void LiftCabin::slotBusy(int floor)
{
    state = BUSY;
    qDebug() << "slot moving to" << floor;
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
            CurrentFloor += currentDirection;
        }
        else
        {
            currentDirection = DOWN;
            CurrentFloor += currentDirection;
        }
        emit Move();
    }
}

// здесь нужен контроль за таргетами, если направления все еще совпадают, то сначала на ближний


void LiftCabin::Stay()
{
    state = FREE;
    floorMoving.stop();
    emit AchievedForResetButton(CurrentFloor);
    emit doors.DoorsOpen();
}
