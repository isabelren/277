/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mygl.h"
#include "scene/mytreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    MyGL *mygl;
    QPushButton *pushButton;
    QPushButton *pushButton_JSON;
    QPushButton *pushButton_meshSkinning;
    QFrame *frame;
    MyTreeWidget *treeWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *xSubPushButton;
    QPushButton *xAddPushButton;
    QPushButton *ySubButton;
    QPushButton *zSubPushButton;
    QPushButton *yAddPushButton;
    QPushButton *zAddPushButton;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *xSpinBox;
    QDoubleSpinBox *ySpinBox;
    QDoubleSpinBox *zSpinBox;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(846, 537);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 432));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 450, 93, 28));
        pushButton_JSON = new QPushButton(centralWidget);
        pushButton_JSON->setObjectName(QStringLiteral("pushButton_JSON"));
        pushButton_JSON->setGeometry(QRect(120, 450, 113, 32));
        pushButton_meshSkinning = new QPushButton(centralWidget);
        pushButton_meshSkinning->setObjectName(QStringLiteral("pushButton_meshSkinning"));
        pushButton_meshSkinning->setGeometry(QRect(20, 480, 141, 31));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(630, 10, 211, 501));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        treeWidget = new MyTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 10, 191, 271));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 290, 111, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 310, 59, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 340, 59, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 370, 59, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 310, 59, 16));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 340, 59, 16));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 370, 51, 21));
        label_7->setAlignment(Qt::AlignCenter);
        xSubPushButton = new QPushButton(frame);
        xSubPushButton->setObjectName(QStringLiteral("xSubPushButton"));
        xSubPushButton->setGeometry(QRect(50, 310, 41, 21));
        xAddPushButton = new QPushButton(frame);
        xAddPushButton->setObjectName(QStringLiteral("xAddPushButton"));
        xAddPushButton->setGeometry(QRect(150, 310, 41, 21));
        ySubButton = new QPushButton(frame);
        ySubButton->setObjectName(QStringLiteral("ySubButton"));
        ySubButton->setGeometry(QRect(50, 340, 41, 21));
        zSubPushButton = new QPushButton(frame);
        zSubPushButton->setObjectName(QStringLiteral("zSubPushButton"));
        zSubPushButton->setGeometry(QRect(50, 370, 41, 21));
        yAddPushButton = new QPushButton(frame);
        yAddPushButton->setObjectName(QStringLiteral("yAddPushButton"));
        yAddPushButton->setGeometry(QRect(150, 340, 41, 21));
        zAddPushButton = new QPushButton(frame);
        zAddPushButton->setObjectName(QStringLiteral("zAddPushButton"));
        zAddPushButton->setGeometry(QRect(150, 370, 41, 21));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 390, 81, 16));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 410, 59, 16));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 440, 61, 20));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 470, 59, 16));
        xSpinBox = new QDoubleSpinBox(frame);
        xSpinBox->setObjectName(QStringLiteral("xSpinBox"));
        xSpinBox->setGeometry(QRect(80, 410, 67, 24));
        xSpinBox->setMinimum(-1000);
        xSpinBox->setMaximum(1000);
        ySpinBox = new QDoubleSpinBox(frame);
        ySpinBox->setObjectName(QStringLiteral("ySpinBox"));
        ySpinBox->setGeometry(QRect(80, 440, 67, 24));
        ySpinBox->setMinimum(-1000);
        ySpinBox->setMaximum(10000);
        zSpinBox = new QDoubleSpinBox(frame);
        zSpinBox->setObjectName(QStringLiteral("zSpinBox"));
        zSpinBox->setGeometry(QRect(80, 470, 67, 24));
        zSpinBox->setMinimum(-10000);
        zSpinBox->setMaximum(10000);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 846, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), mygl, SLOT(slot_LoadOBJ()));
        QObject::connect(pushButton_JSON, SIGNAL(clicked()), mygl, SLOT(slot_LoadJSON()));
        QObject::connect(pushButton_meshSkinning, SIGNAL(clicked()), mygl, SLOT(slot_skinMesh()));
        QObject::connect(mygl, SIGNAL(sig_sendRoot(QTreeWidgetItem*)), treeWidget, SLOT(slot_newRootNode(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), treeWidget, SLOT(slot_changeCurrentJoint()));
        QObject::connect(treeWidget, SIGNAL(sig_xTrans(double)), xSpinBox, SLOT(setValue(double)));
        QObject::connect(treeWidget, SIGNAL(sig_yTrans(double)), ySpinBox, SLOT(setValue(double)));
        QObject::connect(treeWidget, SIGNAL(sig_zTrans(double)), zSpinBox, SLOT(setValue(double)));
        QObject::connect(xSubPushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_xSub()));
        QObject::connect(xAddPushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_xAdd()));
        QObject::connect(ySubButton, SIGNAL(clicked()), treeWidget, SLOT(slot_ySub()));
        QObject::connect(yAddPushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_yAdd()));
        QObject::connect(zSubPushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_zSub()));
        QObject::connect(zAddPushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_zAdd()));
        QObject::connect(treeWidget, SIGNAL(sig_xRot(double)), label_5, SLOT(setNum(double)));
        QObject::connect(treeWidget, SIGNAL(sig_yRot(double)), label_6, SLOT(setNum(double)));
        QObject::connect(treeWidget, SIGNAL(sig_zRot(double)), label_7, SLOT(setNum(double)));
        QObject::connect(treeWidget, SIGNAL(sig_update()), mygl, SLOT(slot_update()));
        QObject::connect(xSpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeXTrans(double)));
        QObject::connect(ySpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeYTrans(double)));
        QObject::connect(zSpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeZTrans(double)));
        QObject::connect(treeWidget, SIGNAL(sig_zRot(double)), label_7, SLOT(setNum(double)));
        QObject::connect(treeWidget, SIGNAL(sig_changeCurrent(Joint*)), mygl, SLOT(slot_updateCurrentJoint(Joint*)));
        QObject::connect(treeWidget, SIGNAL(sig_moveMesh()), mygl, SLOT(slot_moveMesh()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Load OBJ", 0));
        pushButton_JSON->setText(QApplication::translate("MainWindow", "Load JSON", 0));
        pushButton_meshSkinning->setText(QApplication::translate("MainWindow", "Skin Mesh (Linear)", 0));
        label->setText(QApplication::translate("MainWindow", "Current Rotation", 0));
        label_2->setText(QApplication::translate("MainWindow", "X Axis", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y Axis", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z Axis", 0));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        xSubPushButton->setText(QApplication::translate("MainWindow", "-5", 0));
        xAddPushButton->setText(QApplication::translate("MainWindow", "+5", 0));
        ySubButton->setText(QApplication::translate("MainWindow", "-5", 0));
        zSubPushButton->setText(QApplication::translate("MainWindow", "-5", 0));
        yAddPushButton->setText(QApplication::translate("MainWindow", "+5", 0));
        zAddPushButton->setText(QApplication::translate("MainWindow", "+5", 0));
        label_8->setText(QApplication::translate("MainWindow", "Translations", 0));
        label_9->setText(QApplication::translate("MainWindow", "X", 0));
        label_10->setText(QApplication::translate("MainWindow", "Y", 0));
        label_11->setText(QApplication::translate("MainWindow", "Z", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
