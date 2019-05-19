#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QWidget>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QString>
#include "liftbuttons.h"
#include "liftcabin.h"
#include "liftdoors.h"
#include "neededlibs.h"
#define FLOOR_NUMBERS 10
void reciever(QString string);
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
    void setText(QString string);

    bool TargetExists(int &floor);
public slots:
    void slotAddNewTarget(int floor);
    void passCurrentFloor(int floor, Direction direct);
    void AchieveFloor(int floor);
signals:
    void sendTarget(int floor);
    void nextFloor(int floor);
private:
    QVBoxLayout *layout;
    QHBoxLayout *layoutH;
    QTextEdit *text;
    QLCDNumber *LCD;
    LiftDoors doors;
    LiftButtons *buttons[FLOOR_NUMBERS];
    StateController state;
    bool TargetsArray[FLOOR_NUMBERS] = { false };
    int currentFloor;
    Direction currentDirection;
};

#endif // CONTROLLER_H
