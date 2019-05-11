#include "liftbuttons.h"

LiftButtons::LiftButtons(QWidget *parent) : QPushButton(parent)
{
    state = RELEASED;
    FloorNumber = 0;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(slotPressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(slotReleased()));
}

LiftButtons::~LiftButtons()
{

}

void LiftButtons::SetFloorNumber(unsigned int i)
{
    this->FloorNumber = i;
}

void LiftButtons::slotPressed()
{
    if (state == RELEASED)
    {
        qDebug() << "press";
        state = PRESSED;
        this->setEnabled(false);
        emit floorRequest(FloorNumber);
    }
}

void LiftButtons::slotReleased()
{
    if (state == PRESSED)
    {
        qDebug() << "released";
        state = RELEASED;
        this->setEnabled(true);
    }
}
