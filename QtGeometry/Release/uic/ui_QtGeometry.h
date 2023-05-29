/********************************************************************************
** Form generated from reading UI file 'QtGeometry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGEOMETRY_H
#define UI_QTGEOMETRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGeometryClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGeometryClass)
    {
        if (QtGeometryClass->objectName().isEmpty())
            QtGeometryClass->setObjectName(QString::fromUtf8("QtGeometryClass"));
        QtGeometryClass->resize(600, 400);
        menuBar = new QMenuBar(QtGeometryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtGeometryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGeometryClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGeometryClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGeometryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtGeometryClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGeometryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGeometryClass->setStatusBar(statusBar);

        retranslateUi(QtGeometryClass);

        QMetaObject::connectSlotsByName(QtGeometryClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGeometryClass)
    {
        QtGeometryClass->setWindowTitle(QCoreApplication::translate("QtGeometryClass", "QtGeometry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGeometryClass: public Ui_QtGeometryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGEOMETRY_H
