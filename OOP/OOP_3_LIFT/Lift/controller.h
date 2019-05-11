#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "liftbuttons.h"
#include "liftcabin.h"
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

public slots:
    void slotAddNewTarget(int floor);
signals:
    void sendTarget(int floor);
private:
    QVBoxLayout *layout;
    LiftButtons *buttons[FLOOR_NUMBERS];
    StateController state;
};

#endif // CONTROLLER_H
