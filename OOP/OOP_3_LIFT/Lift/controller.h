#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "liftbuttons.h"
#include "liftcabin.h"
#include "neededlibs.h"
#define FLOOR_NUMBERS 10
class Controller : public QWidget
{
    Q_OBJECT
    enum StateController {
        NO_TARGET,
        BUSY
    };
public:
    explicit Controller(QWidget *parent = 0);
    virtual ~Controller();

    bool TargetExists();
public slots:
    void slotAddNewTarget(int floor);
    void passCurrentFloor(int floor, Direction direct);
    void AchieveFloor(int floor);
signals:
    void sendTarget(int floor);
    void nextFloor(int floor);
private:
    QVBoxLayout *layout;
    LiftButtons *buttons[FLOOR_NUMBERS];
    StateController state;
    bool TargetsArray[FLOOR_NUMBERS] = { false };
    int currentFloor;
    Direction currentDirection;
};

#endif // CONTROLLER_H
