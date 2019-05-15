#include "controller.h"
Controller::Controller(QWidget *parent)
{
    layout = new QVBoxLayout;
    this->setLayout(layout);
    for (unsigned int i = 0; i < FLOOR_NUMBERS; i++)
    {
        buttons[i] = new LiftButtons();
        if (i != 0)
        {
            buttons[i]->setText(QString::number(i) + " этаж");
        }
        else
        {
            buttons[i]->setText("Подвал");
        }
        buttons[i]->SetFloorNumber(i);
        layout->addWidget(dynamic_cast<QPushButton*> (buttons[i]));
        QObject::connect(buttons[i], SIGNAL(floorRequest(int)), this, SLOT(slotAddNewTarget(int)));
    }
}

Controller::~Controller()
{
    for (int i = 0; i < FLOOR_NUMBERS; i++)
    {
        delete buttons[i];
    }
    delete layout;
}

bool Controller::TargetExists()
{
    for (int i = 0; i < FLOOR_NUMBERS; i++)
    {
        if (TargetsArray[i] == true)
            return true;
    }
    return false;
}

void Controller::passCurrentFloor(int floor, Direction direct)
{
    currentFloor = floor;
    currentDirection = direct;
    //qDebug() << "floor" << floor << "was passed";
}

void Controller::AchieveFloor(int floor)
{
    emit buttons[floor]->resetButton();
    TargetsArray[floor] = false;
    state = NO_TARGET;
}

void Controller::slotAddNewTarget(int floor)
{
    TargetsArray[floor] = true;
    qDebug() << "slotAddNewFloor" << floor;
    state = BUSY;
    // needed queue here
    emit sendTarget(floor);

}
