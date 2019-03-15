/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_4;
    QFrame *line_2;
    QLineEdit *lineY2;
    QLineEdit *lineX2;
    QLabel *label_3;
    QLineEdit *lineY1;
    QFrame *line_1;
    QLabel *label;
    QPushButton *but_exec;
    QLabel *label_2;
    QLineEdit *lineX1;
    QLabel *label_6;
    QLabel *label_5;
    QGroupBox *groupBox;
    QRadioButton *radioButton_BLACK;
    QRadioButton *radioButton_WHITE;
    QPushButton *pushCOLOR;
    QFrame *frame;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1083, 619);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(139, 167, 184, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(214, 240, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(176, 203, 219, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(69, 83, 92, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(93, 111, 123, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(197, 211, 219, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        QBrush brush9(QColor(127, 127, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(170, 170, 170, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        centralWidget->setPalette(palette1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(830, 110, 16, 16));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 490, 811, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineY2 = new QLineEdit(centralWidget);
        lineY2->setObjectName(QStringLiteral("lineY2"));
        lineY2->setGeometry(QRect(910, 110, 31, 21));
        lineX2 = new QLineEdit(centralWidget);
        lineX2->setObjectName(QStringLiteral("lineX2"));
        lineX2->setGeometry(QRect(850, 110, 31, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(890, 50, 16, 16));
        lineY1 = new QLineEdit(centralWidget);
        lineY1->setObjectName(QStringLiteral("lineY1"));
        lineY1->setGeometry(QRect(910, 50, 31, 20));
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(800, 0, 20, 501));
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(830, 10, 121, 31));
        but_exec = new QPushButton(centralWidget);
        but_exec->setObjectName(QStringLiteral("but_exec"));
        but_exec->setGeometry(QRect(830, 510, 201, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush11(QColor(255, 170, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush11);
        QBrush brush12(QColor(255, 213, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush12);
        QBrush brush13(QColor(255, 191, 63, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(127, 85, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(170, 113, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush16(QColor(255, 212, 127, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        but_exec->setPalette(palette2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(830, 50, 16, 16));
        lineX1 = new QLineEdit(centralWidget);
        lineX1->setObjectName(QStringLiteral("lineX1"));
        lineX1->setGeometry(QRect(850, 51, 31, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(830, 70, 121, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_6->setPalette(palette3);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(890, 110, 16, 16));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(830, 140, 231, 131));
        groupBox->setStyleSheet(QStringLiteral(""));
        radioButton_BLACK = new QRadioButton(groupBox);
        radioButton_BLACK->setObjectName(QStringLiteral("radioButton_BLACK"));
        radioButton_BLACK->setGeometry(QRect(20, 60, 121, 19));
        radioButton_WHITE = new QRadioButton(groupBox);
        radioButton_WHITE->setObjectName(QStringLiteral("radioButton_WHITE"));
        radioButton_WHITE->setGeometry(QRect(20, 20, 84, 19));
        pushCOLOR = new QPushButton(groupBox);
        pushCOLOR->setObjectName(QStringLiteral("pushCOLOR"));
        pushCOLOR->setGeometry(QRect(80, 90, 101, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        pushCOLOR->setPalette(palette4);
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 90, 31, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        frame->setPalette(palette5);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(830, 270, 231, 231));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(170, 255, 255, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush18(QColor(212, 255, 255, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        QBrush brush19(QColor(85, 127, 127, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush19);
        QBrush brush20(QColor(113, 170, 170, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox_2->setPalette(palette6);
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 84, 19));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 60, 161, 19));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 120, 181, 41));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 80, 191, 41));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 160, 84, 19));
        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 190, 141, 19));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 791, 491));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1083, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \n"
" \320\277\320\265\321\200\320\262\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", Q_NULLPTR));
        but_exec->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \n"
" \320\262\321\202\320\276\321\200\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\206\320\262\320\265\321\202:", Q_NULLPTR));
        radioButton_BLACK->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        radioButton_WHITE->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", Q_NULLPTR));
        pushCOLOR->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "1) \320\246\320\224\320\220", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "2) \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\206\320\265\320\273\321\213\320\274\320\270", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "4) \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\203\321\201\321\202\321\200\320\260\320\275\320\265\320\275\320\270\320\265\320\274 \n"
" \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "3) \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \n"
"\320\264\320\265\320\271\321\202\321\201\320\262\320\270\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "5) \320\222\320\243", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("MainWindow", "6) \320\222\321\201\321\202\321\200\320\276\320\265\320\275\320\275\321\213\320\265 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\270", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
