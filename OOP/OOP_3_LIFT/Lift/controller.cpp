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
    int step = -1;
    if (currentDirection == UP)
        step = 1;
    for (int i = currentFloor; i < FLOOR_NUMBERS && i  >= 0; i += step)
    {
        if (TargetsArray[i])
        {
            floor = i;
            //qDebug() << "first";
            return true;
        }
    }
    step = -step;
    for (int i = currentFloor; i < FLOOR_NUMBERS && i >= 0; i+= step)
    {
        if (TargetsArray[i])
        {
            floor = i;
            //qDebug() << "second" << floor;
            return true;
        }
    }
    return false;
}

void Controller::passCurrentFloor(int floor, Direction direct)
{
    currentFloor = floor;
    currentDirection = direct;
    qDebug() << "floor" << floor << "was passed";
}

void print_targets(bool *targets)
{
    for (int i = 0; i < FLOOR_NUMBERS; i++)
    {
        qDebug() << targets[i];
    }
}
void Controller::AchieveFloor(int floor)
{
    emit buttons[floor]->resetButton();
    TargetsArray[floor] = false;
    //print_targets(TargetsArray);
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
    state = BUSY;
    TargetExists(floor);
    emit sendTarget(floor);


}
