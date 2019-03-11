#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    for (int i = 0; i < 100; i++)
    {
        Point *p = new Point(i*5, i*5);
        point.push_back(p);
        scene->addItem(point[i]);
    }


    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
