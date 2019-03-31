#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include "algorithms.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setStyleSheet("QLabel { background-color : white; }");

    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(Pal);

    //connect(ui->Rx, SIGNAL(textChanged(QString)), this, SLOT(autofill_in_circle_mod_rx()));
    //connect(ui->Ry, SIGNAL(textChanged(QString)), this, SLOT(autofill_in_circle_mod_ry()));


}
/*
void MainWindow::autofill_in_circle_mod_rx()
{
    if (ui->radio_circle->isChecked())
    {
        ui->Ry->setText(ui->Rx->text());
    }
}

void MainWindow::autofill_in_circle_mod_ry()
{
    if (ui->radio_circle->isChecked())
    {
        ui->Rx->setText(ui->Ry->text());
    }
}
*/
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clear_circle_input()
{
    //ui->Xcc->clear();
    //ui->Ycc->clear();
    //ui->Rc->clear();
    QMessageBox msgBox;
    msgBox.setText("Wait!");
    // Тип иконки сообщения
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText("You entered wrong params");
    // На какой кнопке фокусироваться по умолчанию
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_draw_button_clicked()
{
    int algorithm_index = ui->comboBox->currentIndex();
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true;
    if (ui->radio_circle->isChecked())
    {

        QString entry_xc = ui->Xcc->text();
        QString entry_yc = ui->Ycc->text();
        QString entry_rx = ui->Rc->text();
        QStringList xc1 = entry_xc.split(" ", QString::SkipEmptyParts);
        QStringList yc1 = entry_yc.split(" ", QString::SkipEmptyParts);
        QStringList rx1 = entry_rx.split(" ", QString::SkipEmptyParts);
        if (xc1.count() != 1 || yc1.count() != 1 || rx1.count() != 1)
        {
            clear_circle_input();
            return;
        }
        xc = xc1[0].toDouble(&ok1);
        yc = yc1[0].toDouble(&ok2);
        R = rx1[0].toDouble(&ok3);
        if (ok1 && ok2 && ok3 && ok4)
        {
            switch (algorithm_index)
            {
            case BREZENHAM:
                draw_brezenham_circle(xc, yc, R, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case CANON:
                draw_canon_circle(xc, yc, R, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case PARAM:
                draw_param_circle(xc, yc, R, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case MIDDLEPOINT:

                break;
            case LIBRARY:
                draw_library_circle(xc - R, yc - R, R * 2, *painter, QPen(color,line_width,Qt::SolidLine));
                ui->draw_label->setPixmap(*scene);
                break;
            default:
                break;
            }
            ui->draw_label->setPixmap(*scene);
        }
        else
        {
            clear_circle_input();
        }
    }
    else if (ui->radio_ellipse->isChecked())
    {
        QString entry_xc = ui->Xce->text();
        QString entry_yc = ui->Yce->text();
        QString entry_ax = ui->ae->text();
        QString entry_by = ui->be->text();
        QStringList xc1 = entry_xc.split(" ", QString::SkipEmptyParts);
        QStringList yc1 = entry_yc.split(" ", QString::SkipEmptyParts);
        QStringList ax1 = entry_ax.split(" ", QString::SkipEmptyParts);
        QStringList by1 = entry_by.split(" ", QString::SkipEmptyParts);
        if (xc1.count() != 1 || yc1.count() != 1 || ax1.count() != 1 || by1.count() != 1)
        {
            clear_circle_input();
            return;
        }
        xc = xc1[0].toDouble(&ok1);
        yc = yc1[0].toDouble(&ok2);
        a = ax1[0].toDouble(&ok3);
        b = by1[0].toDouble(&ok4);
        if (ok1 && ok2 && ok3 && ok4)
        {
            switch (algorithm_index)
            {
            case BREZENHAM:
                draw_brezenham_ellipse(xc, yc, a, b, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case CANON:
                draw_canon_ellipse(xc, yc, a, b, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case PARAM:
                draw_param_ellipse(xc, yc, a, b, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            case MIDDLEPOINT:
                break;
            case LIBRARY:
                draw_library_ellipse(xc - a, yc - b, a * 2, b * 2, *painter, QPen(color,line_width,Qt::SolidLine));
                break;
            default:
                break;
            }
            ui->draw_label->setPixmap(*scene);
        }
        else
        {
            clear_circle_input();
        }
    }
}


// clear button
void MainWindow::on_pushButton_3_clicked()
{
    delete painter;
    delete scene;
    scene = new QPixmap(851, 691);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    ui->draw_label->setPixmap(*scene);
}

// change color style button
void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor(Qt::yellow, this );
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(Pal);
    ui->label->show();
}
// line width changer button
void MainWindow::on_pushButton_2_clicked()
{
    line_width = ui->spinBox->value();
    qDebug() << line_width;
    QMessageBox msgBox;
    msgBox.setText("SUCCESS");
    // Тип иконки сообщения
    msgBox.setIcon(QMessageBox::Information);
    QString message = "line width is " + QString::number(line_width);
    msgBox.setInformativeText(message);
    // На какой кнопке фокусироваться по умолчанию
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

}

void MainWindow::on_circle_spectr_button_clicked()
{
    int algorithm_index = ui->comboBox->currentIndex();
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true, ok5 = true;
    QString xc1 = ui->Xcc_2->text();
    QString yc1 = ui->Ycc_2->text();
    QString rc1 = ui->Rc_2->text();
    QString drc = ui->delta_R->text();
    QString Nc = ui->N_circle->text();
    xc = xc1.toDouble(&ok1);
    yc = yc1.toDouble(&ok2);
    R = rc1.toDouble(&ok3);
    double dR = drc.toDouble(&ok4);
    int N = Nc.toInt(&ok5);

    if (ok1 && ok2 && ok3 && ok4 && ok5)
    {
        // was LIBRARY method choosed
        bool LIB = false;
        switch (algorithm_index)
        {
        case BREZENHAM:
            create_circle_spectr(xc, yc, R, dR, N, *painter, QPen(color,line_width,Qt::SolidLine), draw_brezenham_circle, LIB);
            break;
        case CANON:
            create_circle_spectr(xc, yc, R, dR, N, *painter, QPen(color,line_width,Qt::SolidLine), draw_canon_circle, LIB);
            break;
        case PARAM:
            create_circle_spectr(xc, yc, R, dR, N, *painter, QPen(color,line_width,Qt::SolidLine), draw_param_circle, LIB);
            break;
        case MIDDLEPOINT:
            break;
        case LIBRARY:
            // here Library method is choosing
            LIB = true;
            create_circle_spectr(xc, yc, R, dR, N, *painter, QPen(color,line_width,Qt::SolidLine), draw_library_circle, LIB);
            break;
        default:
            break;
        }
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        clear_circle_input();
    }

}

void MainWindow::on_ellipse_spectr_button_clicked()
{
    int algorithm_index = ui->comboBox->currentIndex();
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true, ok5 = true, ok6 = true;
    QString xc1 = ui->Xce_2->text();
    QString yc1 = ui->Yce_2->text();
    QString ae1 = ui->ae_2->text();
    QString be1 = ui->be_2->text();
    QString Ne1 = ui->ne_2->text();
    QString step1 = ui->step->text();
    xc = xc1.toDouble(&ok1);
    yc = yc1.toDouble(&ok2);
    double ae = ae1.toDouble(&ok3);
    double be = be1.toDouble(&ok4);
    double ne = Ne1.toDouble(&ok5);
    double step = step1.toDouble(&ok6);
    if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6)
    {
        bool LIB = false;
        switch (algorithm_index)
        {
        case BREZENHAM:
            create_ellipse_spectr(xc, yc, ae, be, ne, step, *painter, QPen(color,line_width,Qt::SolidLine), draw_brezenham_ellipse, LIB);
            break;
        case CANON:
            create_ellipse_spectr(xc, yc, ae, be, ne, step, *painter, QPen(color,line_width,Qt::SolidLine), draw_canon_ellipse, LIB);
            break;
        case PARAM:
            create_ellipse_spectr(xc, yc, ae, be, ne, step, *painter, QPen(color,line_width,Qt::SolidLine), draw_param_ellipse, LIB);
            break;
        case MIDDLEPOINT:
            break;
        case LIBRARY:
            // here Library method is choosing
            LIB = true;
            create_ellipse_spectr(xc, yc, ae, be, ne, step, *painter, QPen(color,line_width,Qt::SolidLine), draw_library_ellipse, LIB);
            break;
        default:
            break;
        }

        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        clear_circle_input();
    }
}
