#include "mainwindow.h"
#include "ui_mainwindow.h"
#define SPEED 10
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(QColor(Qt::white));
    this->setWindowTitle("Лр10. Алгоритм плавающего горизонта");
    this->setMouseTracking(true);
    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));

    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
    painter->setPen(Qt::black);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();
    if (x > 0 && x < 882 && y > 0 && y < 562)
    {
        if (first_set == true)
        {
            int dx = x - prevPoint.x();
            int dy = y - prevPoint.y();
            if (figureExists)
            {
                qDebug() << "exist";
                on_clearButton_clicked();
                double (*f)(double, double);
                NeededParams Params(xBegin, xEnd, xDelta, zBegin, zEnd, zDelta);
                int FuncIndex = ui->comboBox->currentIndex();
                f = FunctionHolder.GetFunc(FuncIndex);
                Params.f = f;
                tetax += dx;
                tetay += dy;
                HorizonAlgo(Params, *painter, tetax, tetay, tetaz);
                ui->draw_label->setPixmap(*scene);
            }
        }
        else
        {
            first_set = true;
        }
        prevPoint.setX(x);
        prevPoint.setY(y);
        qDebug() << "Mouse moving at" << x << y;
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (figureExists)
    {
        on_clearButton_clicked();
        double (*f)(double, double);
        NeededParams Params(xBegin, xEnd, xDelta, zBegin, zEnd, zDelta);
        int FuncIndex = ui->comboBox->currentIndex();
        f = FunctionHolder.GetFunc(FuncIndex);
        Params.f = f;
        if (event->key() == Qt::Key_S)
        {
            tetax -= 5;
        }
        else if (event->key() == Qt::Key_D)
        {
            tetay -= 5;
        }
        else if (event->key() == Qt::Key_A)
        {
            tetay += 5;
        }
        else if (event->key() == Qt::Key_W)
        {
            tetax += 5;
        }
        else if (event->key() == Qt::Key_E)
        {
            tetaz += 5;
        }
        else if (event->key() == Qt::Key_Z)
        {
            tetaz -= 5;
        }
        HorizonAlgo(Params, *painter, tetax, tetay, tetaz);
        ui->draw_label->setPixmap(*scene);
    }


}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QCursor c = Qt::ArrowCursor;
    //this->setCursor(c);
    //emit ChangeCursor(c);
}

void MainWindow::on_clearButton_clicked()
{
    qDebug() << "all cleared";
    delete painter;
    delete scene;
    //figureExists = false;
    first_set = false;
    ui->draw_label->clear();
    scene = new QPixmap(881, 561);
    scene->fill(QColor(Qt::white));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_drawButton_clicked()
{
    tetax = 0;
    tetay = 0;
    tetaz = 0;
    on_clearButton_clicked();
    double (*f)(double, double);
    if (checkInput())
    {
        NeededParams Params(xBegin, xEnd, xDelta, zBegin, zEnd, zDelta);
        int FuncIndex = ui->comboBox->currentIndex();
        qDebug() << FuncIndex;
        f = FunctionHolder.GetFunc(FuncIndex);
        Params.f = f;
        //qDebug() << f(1, 2);
        figureExists = true;
        HorizonAlgo(Params, *painter, tetax, tetay, tetaz);
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        qDebug() << "input is NOT OK";
    }
}

void MainWindow::on_rotateButton_clicked()
{
    bool ok1 = true, ok2 = true, ok3 = true;
    QString tx = ui->tetax->text();
    QString ty = ui->tetay->text();
    QString tz = ui->tetaz->text();
    double tmp1 = tx.toDouble(&ok1);
    double tmp2 = ty.toDouble(&ok2);
    double tmp3 = tz.toDouble(&ok3);
    if (ok1 && ok2 && ok3)
    {
        double (*f)(double, double);
        tetax += tmp1;
        tetay += tmp2;
        tetaz += tmp3;
        on_clearButton_clicked();
        NeededParams Params(xBegin, xEnd, xDelta, zBegin, zEnd, zDelta);
        int FuncIndex = ui->comboBox->currentIndex();
        f = FunctionHolder.GetFunc(FuncIndex);
        Params.f = f;
        HorizonAlgo(Params, *painter, tetax, tetay, tetaz);
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        qDebug() << "tetas not right";
    }
}

bool MainWindow::checkInput()
{
    bool ok1 = true, ok2 = true, ok3 = true;
    double tmp1 = 0.0, tmp2 = 0.0, tmp3 = 0.0;
    double tmp4 = 0.0, tmp5 = 0.0, tmp6 = 0.0;
    QString xB = ui->xBegin->text();
    QString xE = ui->xEnd->text();
    QString xD = ui->xDelta->text();
    QString zB = ui->zBegin->text();
    QString zE = ui->zEnd->text();
    QString zD = ui->zDelta->text();
    tmp1 = xB.toDouble(&ok1);
    tmp2 = xE.toDouble(&ok2);
    tmp3 = xD.toDouble(&ok3);
    if (!ok1 || !ok2 || !ok3) return false;

    tmp4 = zB.toDouble(&ok1);
    tmp5 = zE.toDouble(&ok2);
    tmp6 = zD.toDouble(&ok3);
    if (!ok1 || !ok2 || !ok3) return false;
    xBegin = tmp1;
    xEnd = tmp2;
    xDelta = tmp3;
    zBegin = tmp4;
    zEnd = tmp5;
    zDelta = tmp6;
    //qDebug() << xBegin << xEnd << xDelta;
    //qDebug() << zBegin << zBegin << zDelta;
    return true;
}
