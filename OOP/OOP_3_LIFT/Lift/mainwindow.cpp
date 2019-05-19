#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "liftbuttons.h"
#include "mylift.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(250, 530);
    layout = new QVBoxLayout;
    this->setLayout(layout);
    ui->centralWidget->setLayout(layout);
    layout->addWidget(lift.getController());
}

MainWindow::~MainWindow()
{
    delete ui;
}
