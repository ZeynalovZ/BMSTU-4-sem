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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *Check_Button;
    QGroupBox *groupBox;
    QRadioButton *with_mouse_radio;
    QRadioButton *with_keyboard_radio;
    QLabel *label;
    QPushButton *make_line_button;
    QPushButton *make_line_button_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_1_x;
    QLabel *label_3;
    QLineEdit *lineEdit_2_y;
    QGroupBox *groupBox_2;
    QRadioButton *external_border;
    QRadioButton *internal_border;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *border_color;
    QLabel *shading_color;
    QLabel *background_color;
    QPushButton *border_button;
    QPushButton *shading_button;
    QPushButton *background_button;
    QGroupBox *groupBox_4;
    QRadioButton *without_delay_radio;
    QRadioButton *with_delay_radio;
    QPushButton *pushButton;
    QPushButton *clear_button;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1221, 757);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 851, 691));
        draw_label->setCursor(QCursor(Qt::PointingHandCursor));
        draw_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Check_Button = new QPushButton(centralWidget);
        Check_Button->setObjectName(QStringLiteral("Check_Button"));
        Check_Button->setGeometry(QRect(1010, 670, 71, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(880, 20, 331, 191));
        with_mouse_radio = new QRadioButton(groupBox);
        with_mouse_radio->setObjectName(QStringLiteral("with_mouse_radio"));
        with_mouse_radio->setGeometry(QRect(10, 30, 121, 19));
        with_mouse_radio->setChecked(true);
        with_keyboard_radio = new QRadioButton(groupBox);
        with_keyboard_radio->setObjectName(QStringLiteral("with_keyboard_radio"));
        with_keyboard_radio->setGeometry(QRect(10, 60, 151, 19));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 90, 131, 16));
        make_line_button = new QPushButton(groupBox);
        make_line_button->setObjectName(QStringLiteral("make_line_button"));
        make_line_button->setGeometry(QRect(40, 150, 91, 31));
        make_line_button_2 = new QPushButton(groupBox);
        make_line_button_2->setObjectName(QStringLiteral("make_line_button_2"));
        make_line_button_2->setGeometry(QRect(170, 150, 91, 31));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 120, 260, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_1_x = new QLineEdit(widget);
        lineEdit_1_x->setObjectName(QStringLiteral("lineEdit_1_x"));

        horizontalLayout->addWidget(lineEdit_1_x);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2_y = new QLineEdit(widget);
        lineEdit_2_y->setObjectName(QStringLiteral("lineEdit_2_y"));

        horizontalLayout->addWidget(lineEdit_2_y);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(880, 220, 331, 101));
        external_border = new QRadioButton(groupBox_2);
        external_border->setObjectName(QStringLiteral("external_border"));
        external_border->setEnabled(true);
        external_border->setGeometry(QRect(10, 30, 211, 31));
        external_border->setChecked(true);
        internal_border = new QRadioButton(groupBox_2);
        internal_border->setObjectName(QStringLiteral("internal_border"));
        internal_border->setEnabled(false);
        internal_border->setGeometry(QRect(10, 60, 151, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(880, 330, 331, 121));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 81, 16));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 81, 16));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 90, 81, 16));
        border_color = new QLabel(groupBox_3);
        border_color->setObjectName(QStringLiteral("border_color"));
        border_color->setGeometry(QRect(110, 32, 21, 21));
        shading_color = new QLabel(groupBox_3);
        shading_color->setObjectName(QStringLiteral("shading_color"));
        shading_color->setGeometry(QRect(110, 60, 21, 21));
        background_color = new QLabel(groupBox_3);
        background_color->setObjectName(QStringLiteral("background_color"));
        background_color->setGeometry(QRect(110, 90, 21, 21));
        border_button = new QPushButton(groupBox_3);
        border_button->setObjectName(QStringLiteral("border_button"));
        border_button->setGeometry(QRect(160, 30, 80, 21));
        shading_button = new QPushButton(groupBox_3);
        shading_button->setObjectName(QStringLiteral("shading_button"));
        shading_button->setGeometry(QRect(160, 60, 80, 21));
        background_button = new QPushButton(groupBox_3);
        background_button->setObjectName(QStringLiteral("background_button"));
        background_button->setGeometry(QRect(160, 90, 80, 21));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(880, 460, 331, 91));
        without_delay_radio = new QRadioButton(groupBox_4);
        without_delay_radio->setObjectName(QStringLiteral("without_delay_radio"));
        without_delay_radio->setGeometry(QRect(10, 30, 101, 19));
        without_delay_radio->setChecked(true);
        with_delay_radio = new QRadioButton(groupBox_4);
        with_delay_radio->setObjectName(QStringLiteral("with_delay_radio"));
        with_delay_radio->setGeometry(QRect(10, 60, 101, 19));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(970, 570, 151, 41));
        clear_button = new QPushButton(centralWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(970, 620, 151, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1221, 20));
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
        Check_Button->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\222\320\262\320\276\320\264\320\260", nullptr));
        with_mouse_radio->setText(QApplication::translate("MainWindow", "\320\241 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\274\321\213\321\210\320\270", nullptr));
        with_keyboard_radio->setText(QApplication::translate("MainWindow", "\320\241 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\276\320\264 (\320\264\320\273\321\217 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213)", nullptr));
        make_line_button->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        make_line_button_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "X\320\275", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y\320\275", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\263\321\200\320\260\320\275\320\270\321\206\321\213", nullptr));
        external_border->setText(QApplication::translate("MainWindow", "\320\222\320\275\320\265\321\210\320\275\321\217\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 ( \320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274 1 \321\210\321\202)", nullptr));
        internal_border->setText(QApplication::translate("MainWindow", "\320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\321\217\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\276\320\262", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        border_color->setText(QString());
        shading_color->setText(QString());
        background_color->setText(QString());
        border_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        shading_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        background_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        without_delay_radio->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270", nullptr));
        with_delay_radio->setText(QApplication::translate("MainWindow", "\320\241 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\276\320\271", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        clear_button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
