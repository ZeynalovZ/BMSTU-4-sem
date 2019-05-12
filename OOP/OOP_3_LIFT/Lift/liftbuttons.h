#ifndef LIFTBUTTONS_H
#define LIFTBUTTONS_H
#include <QPushButton>
#include <QDebug>
#include "QObject"
#include "neededlibs.h"
class LiftButtons : public QPushButton
{
    Q_OBJECT
    enum ButtonState
    {
        PRESSED,
        RELEASED
    };
public:
    LiftButtons(QWidget *parent = 0);
    virtual ~LiftButtons();
    void SetFloorNumber(unsigned int i);

public slots:
    void slotPressed();
    void slotReleased();
signals:
    void resetButton();
    void floorRequest(int floor);
private:

    unsigned int FloorNumber;
    ButtonState state;
};
#endif // LIFTBUTTONS_H
