/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *imageLabel_after;
    QProgressBar *progressBar;
    QLabel *imageLabel_before;
    QPushButton *pushButton_loadImage;
    QPushButton *pushButton_saveImage;
    QPushButton *pushButton_loadVideo;
    QPushButton *pushButton_saveVideo;
    QPushButton *pushButton_genImage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(804, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 40, 80, 23));
        imageLabel_after = new QLabel(centralwidget);
        imageLabel_after->setObjectName("imageLabel_after");
        imageLabel_after->setGeometry(QRect(410, 170, 381, 341));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 490, 781, 23));
        progressBar->setValue(24);
        imageLabel_before = new QLabel(centralwidget);
        imageLabel_before->setObjectName("imageLabel_before");
        imageLabel_before->setGeometry(QRect(10, 170, 381, 341));
        pushButton_loadImage = new QPushButton(centralwidget);
        pushButton_loadImage->setObjectName("pushButton_loadImage");
        pushButton_loadImage->setGeometry(QRect(120, 10, 80, 23));
        pushButton_saveImage = new QPushButton(centralwidget);
        pushButton_saveImage->setObjectName("pushButton_saveImage");
        pushButton_saveImage->setGeometry(QRect(220, 10, 80, 23));
        pushButton_loadVideo = new QPushButton(centralwidget);
        pushButton_loadVideo->setObjectName("pushButton_loadVideo");
        pushButton_loadVideo->setGeometry(QRect(120, 40, 80, 23));
        pushButton_saveVideo = new QPushButton(centralwidget);
        pushButton_saveVideo->setObjectName("pushButton_saveVideo");
        pushButton_saveVideo->setGeometry(QRect(220, 40, 80, 23));
        pushButton_genImage = new QPushButton(centralwidget);
        pushButton_genImage->setObjectName("pushButton_genImage");
        pushButton_genImage->setGeometry(QRect(20, 10, 80, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 804, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Gen Video", nullptr));
        imageLabel_after->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        imageLabel_before->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_loadImage->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        pushButton_saveImage->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        pushButton_loadVideo->setText(QCoreApplication::translate("MainWindow", "Load Video", nullptr));
        pushButton_saveVideo->setText(QCoreApplication::translate("MainWindow", "Save Video", nullptr));
        pushButton_genImage->setText(QCoreApplication::translate("MainWindow", "Gen Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
