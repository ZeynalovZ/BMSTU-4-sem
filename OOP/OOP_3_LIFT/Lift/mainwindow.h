#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#define FLOOR_NUMBERS 10
#include "liftbuttons.h"
#include "mylift.h"
#include "neededlibs.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    MyLift lift;
    QTextEdit *text;
};

#endif // MAINWINDOW_H
