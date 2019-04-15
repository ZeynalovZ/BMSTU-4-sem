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
    QLabel *draw_label;
    QGroupBox *groupBox;
    QLineEdit *entry_x;
    QLineEdit *entry_y;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *add_point_button;
    QPushButton *close_point_button;
    QGroupBox *groupBox_2;
    QRadioButton *polygon_radio;
    QRadioButton *polygon1_radio;
    QRadioButton *pixel_radio;
    QGroupBox *groupBox_3;
    QRadioButton *without_delay_radio;
    QRadioButton *with_delay_radio;
    QFrame *line;
    QLabel *border_color_label;
    QLabel *filling_color_label;
    QPushButton *border_color_button;
    QPushButton *filing_color_button;
    QPushButton *fill_button;
    QPushButton *clear_button;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1216, 682);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(198, 198, 188, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(226, 226, 221, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(99, 99, 94, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(132, 132, 125, 255));
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
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush7(QColor(127, 127, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush7);
        QBrush brush8(QColor(170, 170, 170, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        draw_label->setPalette(palette1);
        draw_label->setCursor(QCursor(Qt::CrossCursor));
        draw_label->setMouseTracking(true);
        draw_label->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(910, 10, 291, 131));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        entry_x = new QLineEdit(groupBox);
        entry_x->setObjectName(QStringLiteral("entry_x"));
        entry_x->setGeometry(QRect(30, 50, 101, 21));
        entry_y = new QLineEdit(groupBox);
        entry_y->setObjectName(QStringLiteral("entry_y"));
        entry_y->setGeometry(QRect(170, 50, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 31, 31));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 40, 31, 31));
        label_3->setFont(font1);
        add_point_button = new QPushButton(groupBox);
        add_point_button->setObjectName(QStringLiteral("add_point_button"));
        add_point_button->setGeometry(QRect(30, 90, 111, 31));
        add_point_button->setFont(font);
        add_point_button->setCursor(QCursor(Qt::PointingHandCursor));
        close_point_button = new QPushButton(groupBox);
        close_point_button->setObjectName(QStringLiteral("close_point_button"));
        close_point_button->setGeometry(QRect(170, 90, 111, 31));
        close_point_button->setFont(font);
        close_point_button->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(910, 150, 291, 131));
        groupBox_2->setFont(font);
        polygon_radio = new QRadioButton(groupBox_2);
        polygon_radio->setObjectName(QStringLiteral("polygon_radio"));
        polygon_radio->setGeometry(QRect(10, 30, 141, 19));
        polygon_radio->setFont(font);
        polygon_radio->setChecked(true);
        polygon1_radio = new QRadioButton(groupBox_2);
        polygon1_radio->setObjectName(QStringLiteral("polygon1_radio"));
        polygon1_radio->setGeometry(QRect(10, 60, 281, 19));
        polygon1_radio->setFont(font);
        pixel_radio = new QRadioButton(groupBox_2);
        pixel_radio->setObjectName(QStringLiteral("pixel_radio"));
        pixel_radio->setGeometry(QRect(10, 90, 161, 19));
        pixel_radio->setFont(font);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(910, 290, 291, 211));
        groupBox_3->setFont(font);
        without_delay_radio = new QRadioButton(groupBox_3);
        without_delay_radio->setObjectName(QStringLiteral("without_delay_radio"));
        without_delay_radio->setGeometry(QRect(10, 30, 131, 19));
        without_delay_radio->setFont(font);
        without_delay_radio->setChecked(true);
        with_delay_radio = new QRadioButton(groupBox_3);
        with_delay_radio->setObjectName(QStringLiteral("with_delay_radio"));
        with_delay_radio->setGeometry(QRect(10, 60, 131, 19));
        with_delay_radio->setFont(font);
        line = new QFrame(groupBox_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 80, 271, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        border_color_label = new QLabel(groupBox_3);
        border_color_label->setObjectName(QStringLiteral("border_color_label"));
        border_color_label->setGeometry(QRect(20, 110, 31, 31));
        border_color_label->setStyleSheet(QStringLiteral(""));
        filling_color_label = new QLabel(groupBox_3);
        filling_color_label->setObjectName(QStringLiteral("filling_color_label"));
        filling_color_label->setGeometry(QRect(20, 150, 31, 31));
        filling_color_label->setStyleSheet(QStringLiteral(""));
        border_color_button = new QPushButton(groupBox_3);
        border_color_button->setObjectName(QStringLiteral("border_color_button"));
        border_color_button->setGeometry(QRect(80, 110, 191, 31));
        border_color_button->setFont(font);
        border_color_button->setCursor(QCursor(Qt::PointingHandCursor));
        filing_color_button = new QPushButton(groupBox_3);
        filing_color_button->setObjectName(QStringLiteral("filing_color_button"));
        filing_color_button->setGeometry(QRect(80, 150, 191, 31));
        filing_color_button->setFont(font);
        filing_color_button->setCursor(QCursor(Qt::PointingHandCursor));
        fill_button = new QPushButton(centralWidget);
        fill_button->setObjectName(QStringLiteral("fill_button"));
        fill_button->setGeometry(QRect(910, 520, 121, 51));
        fill_button->setFont(font);
        fill_button->setCursor(QCursor(Qt::PointingHandCursor));
        clear_button = new QPushButton(centralWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(1060, 520, 121, 51));
        clear_button->setFont(font);
        clear_button->setCursor(QCursor(Qt::PointingHandCursor));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 590, 241, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Blade Runner Movie Font"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1216, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        draw_label->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        add_point_button->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        close_point_button->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\320\262\320\276\320\264\320\260", nullptr));
        polygon_radio->setText(QApplication::translate("MainWindow", "\320\234\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        polygon1_radio->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\273\321\214\320\275\320\260\321\217 \321\204\320\270\320\263\321\203\321\200\320\260 (\320\274\321\213\321\210\321\214\321\216)", nullptr));
        pixel_radio->setText(QApplication::translate("MainWindow", "\320\237\320\270\320\272\321\201\320\265\320\273\321\214 \320\267\320\260\321\202\321\200\320\260\320\262\320\272\320\270", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\321\211\320\270\320\272\320\260", nullptr));
        without_delay_radio->setText(QApplication::translate("MainWindow", "C \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\276\320\271", nullptr));
        with_delay_radio->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270", nullptr));
        border_color_label->setText(QString());
        filling_color_label->setText(QString());
        border_color_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213", nullptr));
        filing_color_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270", nullptr));
        fill_button->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        clear_button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Powered by ZZ \302\251\302\256", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
