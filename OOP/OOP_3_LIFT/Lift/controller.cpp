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

bool Controller::TargetExists(int &floor)
{
    /*
    for (int i = 0; i < FLOOR_NUMBERS; i++)
    {
        if (TargetsArray[i] == true)
        {
            floor = i;
            return true;
        }
    }*/
    int step = -1;
    if (currentDirection == UP)
        step = 1;
    for (int i = currentFloor; i <= FLOOR_NUMBERS && i > 0; i += step)
    {
        if (TargetsArray[i - 1])
        {
            floor = i;
            return true;
        }
    }
    step = -step;
    for (int i = currentFloor; i <= FLOOR_NUMBERS && i > 0; i+= step)
    {
        if (TargetsArray[i - 1])
        {
            floor = i;
            return true;
        }
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
    /*
    for (int i = 0; i < FLOOR_NUMBERS; i++)
    {
        qDebug() << TargetsArray[i];
    }
    */
    emit buttons[floor]->resetButton();
    TargetsArray[floor] = false;
    if (TargetExists(floor))
    {
        emit sendTarget(floor);
    }
    else
    {
        state = NO_TARGET;
    }

}

void Controller::slotAddNewTarget(int floor)
{
    TargetsArray[floor] = true;
    qDebug() << "slotAddNewFloor" << floor;
    // needed queue here
    state = BUSY;
    TargetExists(floor);
    emit sendTarget(floor);

}
