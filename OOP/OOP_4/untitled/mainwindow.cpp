#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QObject>
void use();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    use();
}

MainWindow::~MainWindow()
{
    delete ui;
}

class strategy
{
public:

    virtual void execute(int a, int b) = 0;
};

class ConcreteStrategyMultiply : public strategy
{
public:
    void execute(int a, int b)
    {
        qDebug() << "a * b = " << a * b;

    }
};

class ConcreteStrategySum : public strategy
{
public:
    void execute(int a, int b)
    {
        qDebug() << "a + b = " << a + b;
    }
};

class Context
{
public:

    void SetStrategy(strategy *str_)
    {
        this->str = str_;
    }
    void executeStrategy(int a, int b)
    {
        this->str->execute(a, b);
    }
private:
    strategy *str;
};

void use()
{
    Context cntxt;
    cntxt.SetStrategy(new ConcreteStrategyMultiply);
    cntxt.executeStrategy(1, 1);

    cntxt.SetStrategy(new ConcreteStrategySum);
    cntxt.executeStrategy(11, 2);

}
