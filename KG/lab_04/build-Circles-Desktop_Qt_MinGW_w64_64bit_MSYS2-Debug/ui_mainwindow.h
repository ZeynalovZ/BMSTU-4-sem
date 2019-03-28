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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QRadioButton *radio_circle;
    QRadioButton *radio_ellipse;
    QLineEdit *Xcc;
    QLineEdit *Ycc;
    QLineEdit *Rc;
    QComboBox *comboBox;
    QPushButton *draw_button;
    QLineEdit *Yce;
    QLineEdit *Xce;
    QLineEdit *ae;
    QFrame *line;
    QLineEdit *be;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *circle_spectr_button;
    QLineEdit *delta_R;
    QLineEdit *Ycc_2;
    QLineEdit *Xcc_2;
    QLineEdit *Rc_2;
    QLineEdit *N_circle;
    QWidget *tab_2;
    QPushButton *ellipse_spectr_button;
    QLineEdit *ne_2;
    QLineEdit *Yce_2;
    QLineEdit *Xce_2;
    QLineEdit *ae_2;
    QLineEdit *be_2;
    QLineEdit *step;
    QLabel *draw_label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1290, 762);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(870, 270, 391, 151));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 90, 81, 31));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 31, 31));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 30, 101, 16));
        spinBox = new QSpinBox(groupBox_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 30, 43, 22));
        spinBox->setMinimum(1);
        spinBox->setValue(1);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 141, 16));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 30, 80, 21));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(870, 20, 391, 241));
        radio_circle = new QRadioButton(groupBox);
        radio_circle->setObjectName(QStringLiteral("radio_circle"));
        radio_circle->setGeometry(QRect(20, 30, 121, 19));
        radio_circle->setChecked(true);
        radio_ellipse = new QRadioButton(groupBox);
        radio_ellipse->setObjectName(QStringLiteral("radio_ellipse"));
        radio_ellipse->setGeometry(QRect(180, 30, 121, 19));
        Xcc = new QLineEdit(groupBox);
        Xcc->setObjectName(QStringLiteral("Xcc"));
        Xcc->setGeometry(QRect(20, 60, 113, 21));
        Ycc = new QLineEdit(groupBox);
        Ycc->setObjectName(QStringLiteral("Ycc"));
        Ycc->setGeometry(QRect(20, 90, 111, 21));
        Rc = new QLineEdit(groupBox);
        Rc->setObjectName(QStringLiteral("Rc"));
        Rc->setGeometry(QRect(20, 120, 113, 21));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 150, 341, 22));
        draw_button = new QPushButton(groupBox);
        draw_button->setObjectName(QStringLiteral("draw_button"));
        draw_button->setGeometry(QRect(120, 190, 141, 41));
        Yce = new QLineEdit(groupBox);
        Yce->setObjectName(QStringLiteral("Yce"));
        Yce->setGeometry(QRect(280, 60, 81, 21));
        Xce = new QLineEdit(groupBox);
        Xce->setObjectName(QStringLiteral("Xce"));
        Xce->setGeometry(QRect(180, 60, 81, 21));
        ae = new QLineEdit(groupBox);
        ae->setObjectName(QStringLiteral("ae"));
        ae->setGeometry(QRect(180, 120, 81, 21));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(143, 20, 20, 131));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        be = new QLineEdit(groupBox);
        be->setObjectName(QStringLiteral("be"));
        be->setGeometry(QRect(280, 120, 81, 21));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(890, 650, 331, 51));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(870, 430, 401, 201));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        circle_spectr_button = new QPushButton(tab_1);
        circle_spectr_button->setObjectName(QStringLiteral("circle_spectr_button"));
        circle_spectr_button->setGeometry(QRect(260, 60, 111, 41));
        delta_R = new QLineEdit(tab_1);
        delta_R->setObjectName(QStringLiteral("delta_R"));
        delta_R->setGeometry(QRect(10, 100, 113, 21));
        Ycc_2 = new QLineEdit(tab_1);
        Ycc_2->setObjectName(QStringLiteral("Ycc_2"));
        Ycc_2->setGeometry(QRect(10, 40, 111, 21));
        Xcc_2 = new QLineEdit(tab_1);
        Xcc_2->setObjectName(QStringLiteral("Xcc_2"));
        Xcc_2->setGeometry(QRect(10, 10, 113, 21));
        Rc_2 = new QLineEdit(tab_1);
        Rc_2->setObjectName(QStringLiteral("Rc_2"));
        Rc_2->setGeometry(QRect(10, 70, 113, 21));
        N_circle = new QLineEdit(tab_1);
        N_circle->setObjectName(QStringLiteral("N_circle"));
        N_circle->setGeometry(QRect(10, 130, 113, 21));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ellipse_spectr_button = new QPushButton(tab_2);
        ellipse_spectr_button->setObjectName(QStringLiteral("ellipse_spectr_button"));
        ellipse_spectr_button->setGeometry(QRect(260, 60, 111, 41));
        ne_2 = new QLineEdit(tab_2);
        ne_2->setObjectName(QStringLiteral("ne_2"));
        ne_2->setGeometry(QRect(10, 110, 113, 21));
        Yce_2 = new QLineEdit(tab_2);
        Yce_2->setObjectName(QStringLiteral("Yce_2"));
        Yce_2->setGeometry(QRect(10, 40, 111, 21));
        Xce_2 = new QLineEdit(tab_2);
        Xce_2->setObjectName(QStringLiteral("Xce_2"));
        Xce_2->setGeometry(QRect(10, 10, 113, 21));
        ae_2 = new QLineEdit(tab_2);
        ae_2->setObjectName(QStringLiteral("ae_2"));
        ae_2->setGeometry(QRect(130, 10, 111, 21));
        be_2 = new QLineEdit(tab_2);
        be_2->setObjectName(QStringLiteral("be_2"));
        be_2->setGeometry(QRect(130, 40, 111, 21));
        step = new QLineEdit(tab_2);
        step->setObjectName(QStringLiteral("step"));
        step->setGeometry(QRect(10, 80, 113, 21));
        tabWidget->addTab(tab_2, QString());
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 851, 691));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1290, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\321\211\320\270\320\272\320\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\273\320\270\320\275\320\270\320\270:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\206\320\262\320\265\321\202 \321\200\320\270\321\201\320\276\320\262\320\260\320\275\320\270\321\217:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\321\211\320\270\320\272", nullptr));
        radio_circle->setText(QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        radio_ellipse->setText(QApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        Xcc->setPlaceholderText(QApplication::translate("MainWindow", "X center", nullptr));
        Ycc->setPlaceholderText(QApplication::translate("MainWindow", "Y center", nullptr));
        Rc->setPlaceholderText(QApplication::translate("MainWindow", "R", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271", nullptr));

        draw_button->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        Yce->setPlaceholderText(QApplication::translate("MainWindow", "Y center", nullptr));
        Xce->setPlaceholderText(QApplication::translate("MainWindow", "X center", nullptr));
        ae->setPlaceholderText(QApplication::translate("MainWindow", "a", nullptr));
        be->setPlaceholderText(QApplication::translate("MainWindow", "b", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        circle_spectr_button->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        delta_R->setText(QString());
        delta_R->setPlaceholderText(QApplication::translate("MainWindow", "delta R", nullptr));
        Ycc_2->setPlaceholderText(QApplication::translate("MainWindow", "Y center", nullptr));
        Xcc_2->setPlaceholderText(QApplication::translate("MainWindow", "X center", nullptr));
        Rc_2->setPlaceholderText(QApplication::translate("MainWindow", "R", nullptr));
        N_circle->setPlaceholderText(QApplication::translate("MainWindow", "N", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\321\202\321\200 \320\264\320\273\321\217 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        ellipse_spectr_button->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        ne_2->setPlaceholderText(QApplication::translate("MainWindow", "N", nullptr));
        Yce_2->setPlaceholderText(QApplication::translate("MainWindow", "Y center", nullptr));
        Xce_2->setPlaceholderText(QApplication::translate("MainWindow", "X center", nullptr));
        ae_2->setPlaceholderText(QApplication::translate("MainWindow", "a", nullptr));
        be_2->setPlaceholderText(QApplication::translate("MainWindow", "b", nullptr));
        step->setPlaceholderText(QApplication::translate("MainWindow", "step", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\321\202\321\200 \320\264\320\273\321\217 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        draw_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
