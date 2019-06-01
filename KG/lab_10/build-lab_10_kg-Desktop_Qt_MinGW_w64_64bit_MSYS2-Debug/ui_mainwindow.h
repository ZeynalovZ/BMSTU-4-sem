/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *draw_label;
    QLabel *label_6;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelxBegin;
    QLineEdit *xBegin;
    QLabel *LabelxEnd;
    QLineEdit *xEnd;
    QLabel *LabelxDelta;
    QLineEdit *xDelta;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelzBegin;
    QLineEdit *zBegin;
    QLabel *LabelzEnd;
    QLineEdit *zEnd;
    QLabel *LabelzDelta;
    QLineEdit *zDelta;
    QLabel *label;
    QPushButton *drawButton;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLineEdit *tetax;
    QLabel *label_3;
    QLineEdit *tetay;
    QLabel *label_4;
    QLineEdit *tetaz;
    QPushButton *rotateButton;
    QPushButton *clearButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1232, 677);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(241, 241, 241, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(248, 248, 248, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(161, 161, 161, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 881, 561));
        draw_label->setCursor(QCursor(Qt::ArrowCursor));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(510, 590, 241, 21));
        QFont font;
        font.setFamily(QStringLiteral("Blade Runner Movie Font"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral(""));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(910, 30, 291, 41));
        QFont font1;
        font1.setPointSize(14);
        comboBox->setFont(font1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(910, 80, 291, 181));
        groupBox->setFont(font1);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 291, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LabelxBegin = new QLabel(verticalLayoutWidget);
        LabelxBegin->setObjectName(QStringLiteral("LabelxBegin"));
        QFont font2;
        font2.setPointSize(16);
        LabelxBegin->setFont(font2);

        horizontalLayout_2->addWidget(LabelxBegin);

        xBegin = new QLineEdit(verticalLayoutWidget);
        xBegin->setObjectName(QStringLiteral("xBegin"));
        xBegin->setFont(font1);

        horizontalLayout_2->addWidget(xBegin);

        LabelxEnd = new QLabel(verticalLayoutWidget);
        LabelxEnd->setObjectName(QStringLiteral("LabelxEnd"));
        LabelxEnd->setFont(font2);

        horizontalLayout_2->addWidget(LabelxEnd);

        xEnd = new QLineEdit(verticalLayoutWidget);
        xEnd->setObjectName(QStringLiteral("xEnd"));
        xEnd->setFont(font1);

        horizontalLayout_2->addWidget(xEnd);

        LabelxDelta = new QLabel(verticalLayoutWidget);
        LabelxDelta->setObjectName(QStringLiteral("LabelxDelta"));
        LabelxDelta->setFont(font2);

        horizontalLayout_2->addWidget(LabelxDelta);

        xDelta = new QLineEdit(verticalLayoutWidget);
        xDelta->setObjectName(QStringLiteral("xDelta"));
        xDelta->setFont(font1);

        horizontalLayout_2->addWidget(xDelta);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LabelzBegin = new QLabel(verticalLayoutWidget);
        LabelzBegin->setObjectName(QStringLiteral("LabelzBegin"));
        LabelzBegin->setFont(font2);

        horizontalLayout->addWidget(LabelzBegin);

        zBegin = new QLineEdit(verticalLayoutWidget);
        zBegin->setObjectName(QStringLiteral("zBegin"));
        zBegin->setFont(font1);

        horizontalLayout->addWidget(zBegin);

        LabelzEnd = new QLabel(verticalLayoutWidget);
        LabelzEnd->setObjectName(QStringLiteral("LabelzEnd"));
        LabelzEnd->setFont(font2);

        horizontalLayout->addWidget(LabelzEnd);

        zEnd = new QLineEdit(verticalLayoutWidget);
        zEnd->setObjectName(QStringLiteral("zEnd"));
        zEnd->setFont(font1);

        horizontalLayout->addWidget(zEnd);

        LabelzDelta = new QLabel(verticalLayoutWidget);
        LabelzDelta->setObjectName(QStringLiteral("LabelzDelta"));
        LabelzDelta->setFont(font2);

        horizontalLayout->addWidget(LabelzDelta);

        zDelta = new QLineEdit(verticalLayoutWidget);
        zDelta->setObjectName(QStringLiteral("zDelta"));
        zDelta->setFont(font1);

        horizontalLayout->addWidget(zDelta);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(910, 0, 291, 21));
        label->setFont(font1);
        drawButton = new QPushButton(centralWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(980, 270, 161, 41));
        drawButton->setFont(font1);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(910, 320, 291, 151));
        groupBox_2->setFont(font1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 30, 51, 21));
        label_2->setFont(font1);
        tetax = new QLineEdit(groupBox_2);
        tetax->setObjectName(QStringLiteral("tetax"));
        tetax->setGeometry(QRect(20, 60, 71, 31));
        tetax->setFont(font1);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 30, 51, 21));
        label_3->setFont(font1);
        tetay = new QLineEdit(groupBox_2);
        tetay->setObjectName(QStringLiteral("tetay"));
        tetay->setGeometry(QRect(110, 60, 71, 31));
        tetay->setFont(font1);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 30, 51, 21));
        label_4->setFont(font1);
        tetaz = new QLineEdit(groupBox_2);
        tetaz->setObjectName(QStringLiteral("tetaz"));
        tetaz->setGeometry(QRect(200, 60, 71, 31));
        tetaz->setFont(font1);
        rotateButton = new QPushButton(groupBox_2);
        rotateButton->setObjectName(QStringLiteral("rotateButton"));
        rotateButton->setGeometry(QRect(90, 100, 121, 41));
        rotateButton->setFont(font1);
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(930, 490, 251, 51));
        clearButton->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1232, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        draw_label->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Powered by ZZ \302\251\302\256", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "        cos^2(x) - sin^2(z)", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "        sin(x) * cos(z)", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "x * z", nullptr));

        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217", nullptr));
        LabelxBegin->setText(QApplication::translate("MainWindow", "X\320\275", nullptr));
        xBegin->setText(QApplication::translate("MainWindow", "-2", nullptr));
        LabelxEnd->setText(QApplication::translate("MainWindow", "X\320\272", nullptr));
        xEnd->setText(QApplication::translate("MainWindow", "2", nullptr));
        LabelxDelta->setText(QApplication::translate("MainWindow", "X\316\224", nullptr));
        xDelta->setText(QApplication::translate("MainWindow", "0.05", nullptr));
        LabelzBegin->setText(QApplication::translate("MainWindow", "Z\320\275", nullptr));
        zBegin->setText(QApplication::translate("MainWindow", "-2", nullptr));
        LabelzEnd->setText(QApplication::translate("MainWindow", "Z\320\272", nullptr));
        zEnd->setText(QApplication::translate("MainWindow", "2", nullptr));
        LabelzDelta->setText(QApplication::translate("MainWindow", "Z\316\224", nullptr));
        zDelta->setText(QApplication::translate("MainWindow", "0.05", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\321\216 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217:", nullptr));
        drawButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\316\270 X", nullptr));
        tetax->setText(QApplication::translate("MainWindow", "0", nullptr));
        tetax->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\316\270 Y", nullptr));
        tetay->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\316\270 Z", nullptr));
        tetaz->setText(QApplication::translate("MainWindow", "0", nullptr));
        rotateButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
