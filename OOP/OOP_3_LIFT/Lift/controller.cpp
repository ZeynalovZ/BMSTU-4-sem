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

}

void Controller::slotAddNewTarget(int floor)
{
    qDebug() << "slotAddNewFloor" << floor;
    state = BUSY;
    // needed queue here
    emit sendTarget(floor);

}
