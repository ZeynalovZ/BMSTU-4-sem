#ifndef LIFTCABIN_H
#define LIFTCABIN_H
#include <QObject>
#include <QTimer>
#include <liftbuttons.h>
#include "controller.h"
#include "neededlibs.h"
#include "liftdoors.h"
class LiftCabin : public QObject
{
    Q_OBJECT
    enum CabinState
    {
        MOVING,
        BUSY,
        FREE
    };

public:
    explicit LiftCabin(QObject *parent = 0);
    virtual ~LiftCabin();

public slots:
    void FloorAchieving();
    void slotBusy(int floor);
    void Stay();

signals:
    void FloorAchieved();
    void FloorPassed(int floor, Direction direction);
    void Move();
    void AchievedForResetButton(int floor);
    void cabinStopped();
private:
    CabinState state;
    int CurrentFloor;
    unsigned int TargetFloor;
    Direction currentDirection;
    QTimer floorMoving;
    LiftDoors doors;
};

#endif // LIFTCABIN_H
