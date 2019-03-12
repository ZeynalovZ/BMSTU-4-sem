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
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1085, 616);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        but_exec->setGeometry(QRect(830, 490, 201, 61));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(830, 50, 16, 16));
        lineX1 = new QLineEdit(centralWidget);
        lineX1->setObjectName(QStringLiteral("lineX1"));
        lineX1->setGeometry(QRect(850, 51, 31, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(830, 70, 121, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(890, 110, 16, 16));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(830, 140, 201, 80));
        groupBox->setStyleSheet(QStringLiteral(""));
        radioButton_BLACK = new QRadioButton(groupBox);
        radioButton_BLACK->setObjectName(QStringLiteral("radioButton_BLACK"));
        radioButton_BLACK->setGeometry(QRect(10, 20, 84, 19));
        radioButton_WHITE = new QRadioButton(groupBox);
        radioButton_WHITE->setObjectName(QStringLiteral("radioButton_WHITE"));
        radioButton_WHITE->setGeometry(QRect(10, 50, 84, 19));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(830, 240, 201, 231));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 84, 19));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 60, 191, 19));
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1085, 20));
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
        radioButton_BLACK->setText(QApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\321\213\320\271 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        radioButton_WHITE->setText(QApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "1) \320\246\320\224\320\236", Q_NULLPTR));
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
