/********************************************************************************
** Form generated from reading UI file 'recursionsec4.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECURSIONSEC4_H
#define UI_RECURSIONSEC4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recursionSec4
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *recursionSec4)
    {
        if (recursionSec4->objectName().isEmpty())
            recursionSec4->setObjectName(QString::fromUtf8("recursionSec4"));
        recursionSec4->resize(800, 600);
        centralwidget = new QWidget(recursionSec4);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        recursionSec4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(recursionSec4);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        recursionSec4->setMenuBar(menubar);
        statusbar = new QStatusBar(recursionSec4);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        recursionSec4->setStatusBar(statusbar);

        retranslateUi(recursionSec4);

        QMetaObject::connectSlotsByName(recursionSec4);
    } // setupUi

    void retranslateUi(QMainWindow *recursionSec4)
    {
        recursionSec4->setWindowTitle(QCoreApplication::translate("recursionSec4", "recursionSec4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recursionSec4: public Ui_recursionSec4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECURSIONSEC4_H
