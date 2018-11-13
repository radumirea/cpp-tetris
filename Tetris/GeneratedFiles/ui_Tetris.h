/********************************************************************************
** Form generated from reading UI file 'Tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TetrisClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TetrisClass)
    {
        if (TetrisClass->objectName().isEmpty())
            TetrisClass->setObjectName(QStringLiteral("TetrisClass"));
        TetrisClass->resize(600, 400);
        menuBar = new QMenuBar(TetrisClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TetrisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TetrisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TetrisClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TetrisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TetrisClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TetrisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TetrisClass->setStatusBar(statusBar);

        retranslateUi(TetrisClass);

        QMetaObject::connectSlotsByName(TetrisClass);
    } // setupUi

    void retranslateUi(QMainWindow *TetrisClass)
    {
        TetrisClass->setWindowTitle(QApplication::translate("TetrisClass", "Tetris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TetrisClass: public Ui_TetrisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
