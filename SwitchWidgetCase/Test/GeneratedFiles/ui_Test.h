/********************************************************************************
** Form generated from reading UI file 'Test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestClass
{
public:
    QAction *actionswitch;
    QAction *actionfefe;
    QAction *action77;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuQIEHUAN;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestClass)
    {
        if (TestClass->objectName().isEmpty())
            TestClass->setObjectName(QString::fromUtf8("TestClass"));
        TestClass->resize(647, 597);
        actionswitch = new QAction(TestClass);
        actionswitch->setObjectName(QString::fromUtf8("actionswitch"));
        actionfefe = new QAction(TestClass);
        actionfefe->setObjectName(QString::fromUtf8("actionfefe"));
        action77 = new QAction(TestClass);
        action77->setObjectName(QString::fromUtf8("action77"));
        centralWidget = new QWidget(TestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        TestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 23));
        menuQIEHUAN = new QMenu(menuBar);
        menuQIEHUAN->setObjectName(QString::fromUtf8("menuQIEHUAN"));
        TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestClass->setStatusBar(statusBar);

        menuBar->addAction(menuQIEHUAN->menuAction());
        menuQIEHUAN->addAction(actionswitch);
        menuQIEHUAN->addAction(actionfefe);
        menuQIEHUAN->addAction(action77);

        retranslateUi(TestClass);

        QMetaObject::connectSlotsByName(TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestClass)
    {
        TestClass->setWindowTitle(QApplication::translate("TestClass", "Test", nullptr));
        actionswitch->setText(QApplication::translate("TestClass", "switch", nullptr));
        actionfefe->setText(QApplication::translate("TestClass", "fefe", nullptr));
        action77->setText(QApplication::translate("TestClass", "77", nullptr));
        label->setText(QApplication::translate("TestClass", "\346\265\213\350\257\225", nullptr));
        menuQIEHUAN->setTitle(QApplication::translate("TestClass", "QIEHUAN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestClass: public Ui_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
