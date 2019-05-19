#ifndef LIFTDOORS_H
#define LIFTDOORS_H
#include "neededlibs.h"
#include <QObject>
#include <Qtimer>
class LiftDoors : public QObject
{
    Q_OBJECT
    enum StateDoor
    {
        OPEN,
        CLOSE,
        OPENING,
        CLOSING
    };
public:
    explicit LiftDoors(QObject *parent = 0);
    void setText(QTextEdit *t);
public slots:
    void DoorsOpenning();
    void DoorsClosing();

    void Open();
    void Close();
signals:
    void DoorsClosed();
    void DoorsOpen();
private:
    StateDoor state;
    QTimer OpenTimer;
    QTimer CloseTimer;
    QTimer OpeningTimer;
    QTimer AddTimer;

};

#endif // LIFTDOORS_H
