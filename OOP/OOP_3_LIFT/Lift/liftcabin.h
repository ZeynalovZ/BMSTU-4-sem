#ifndef LIFTCABIN_H
#define LIFTCABIN_H
#include <QObject>
#include <liftbuttons.h>
#include "controller.h"

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
    void FloorAchieving(int floor);
    void Stay();

signals:
    void FloorAchieved();

private:
    CabinState state;
    unsigned int CurrentFloor;
    unsigned int TargetFloor;
};

#endif // LIFTCABIN_H
