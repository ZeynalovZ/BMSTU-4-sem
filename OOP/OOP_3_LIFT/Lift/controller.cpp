#include "controller.h"
Controller::Controller(QWidget *parent)
{
    layout = new QVBoxLayout;
    layoutH = new QHBoxLayout;
    this->setLayout(layout);
    LCD = new QLCDNumber;
    layout->addWidget(dynamic_cast<QLCDNumber*>(LCD));
    QPushButton *p_open = new QPushButton;
    QPushButton *p_close = new QPushButton;
    p_open->setText("<|>");
    p_close->setText(">|<");
    QObject::connect(p_open, SIGNAL(pressed()), &doors, SLOT(DoorsOpenning()));
    QObject::connect(p_close, SIGNAL(pressed()), &doors, SLOT(DoorsClosing()));
    layoutH->addWidget(dynamic_cast<QPushButton*> (p_open));
    layoutH->addWidget(dynamic_cast<QPushButton*> (p_close));
    text = new QTextEdit;
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
    layout->addLayout(dynamic_cast<QHBoxLayout*> (layoutH));
    text->setFixedHeight(80);
    text->setPlainText("Лифт работает в штатном режиме");

    layout->addWidget(dynamic_cast<QTextEdit*> (text));
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
    LCD->display(floor);
    text->append("Этаж " + QString::number(floor) + " пройден");
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
    LCD->display(floor);
    text->append("Этаж " + QString::number(floor) + " Достигнут ");
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
