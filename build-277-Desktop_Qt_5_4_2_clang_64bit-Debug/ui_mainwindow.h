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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"
#include "scene/mytreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    MyTreeWidget *treeWidget;
    QTabWidget *tabWidget;
    QWidget *transform;
    QComboBox *TransComboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *XDoubleSpinBox;
    QDoubleSpinBox *YDoubleSpinBox;
    QDoubleSpinBox *ZDoubleSpinBox;
    QWidget *additional;
    QLabel *label_5;
    QComboBox *GeomComboBox;
    QLabel *label_6;
    QPushButton *addButton;
    QLabel *label_7;
    QPushButton *renameButton;
    QLabel *label_8;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QWidget *tab;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    MyGL *mygl;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(694, 398);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        treeWidget = new MyTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 10, 201, 141));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 160, 191, 191));
        transform = new QWidget();
        transform->setObjectName(QStringLiteral("transform"));
        TransComboBox = new QComboBox(transform);
        TransComboBox->setObjectName(QStringLiteral("TransComboBox"));
        TransComboBox->setGeometry(QRect(40, 20, 104, 26));
        TransComboBox->setMaxVisibleItems(3);
        TransComboBox->setInsertPolicy(QComboBox::NoInsert);
        label = new QLabel(transform);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 0, 101, 21));
        label_2 = new QLabel(transform);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 16, 16));
        label_3 = new QLabel(transform);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 80, 21, 16));
        label_4 = new QLabel(transform);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 110, 16, 16));
        XDoubleSpinBox = new QDoubleSpinBox(transform);
        XDoubleSpinBox->setObjectName(QStringLiteral("XDoubleSpinBox"));
        XDoubleSpinBox->setGeometry(QRect(70, 50, 67, 24));
        XDoubleSpinBox->setMinimum(-1000);
        XDoubleSpinBox->setMaximum(1000);
        YDoubleSpinBox = new QDoubleSpinBox(transform);
        YDoubleSpinBox->setObjectName(QStringLiteral("YDoubleSpinBox"));
        YDoubleSpinBox->setGeometry(QRect(70, 80, 67, 24));
        YDoubleSpinBox->setMinimum(-1000);
        YDoubleSpinBox->setMaximum(1000);
        ZDoubleSpinBox = new QDoubleSpinBox(transform);
        ZDoubleSpinBox->setObjectName(QStringLiteral("ZDoubleSpinBox"));
        ZDoubleSpinBox->setGeometry(QRect(70, 110, 67, 24));
        ZDoubleSpinBox->setMinimum(-1000);
        ZDoubleSpinBox->setMaximum(1000);
        tabWidget->addTab(transform, QString());
        additional = new QWidget();
        additional->setObjectName(QStringLiteral("additional"));
        label_5 = new QLabel(additional);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 0, 59, 16));
        GeomComboBox = new QComboBox(additional);
        GeomComboBox->setObjectName(QStringLiteral("GeomComboBox"));
        GeomComboBox->setGeometry(QRect(80, 20, 104, 26));
        label_6 = new QLabel(additional);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 71, 16));
        addButton = new QPushButton(additional);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(40, 70, 113, 32));
        label_7 = new QLabel(additional);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 120, 81, 16));
        renameButton = new QPushButton(additional);
        renameButton->setObjectName(QStringLiteral("renameButton"));
        renameButton->setGeometry(QRect(110, 140, 71, 21));
        label_8 = new QLabel(additional);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 40, 59, 16));
        comboBox = new QComboBox(additional);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 40, 104, 26));
        lineEdit = new QLineEdit(additional);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 140, 101, 21));
        tabWidget->addTab(additional, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 113, 32));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 50, 151, 31));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(frame, 0, 2, 1, 1);

        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));

        gridLayout->addWidget(mygl, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 694, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(mygl, SIGNAL(sig_sendRoot(QTreeWidgetItem*)), treeWidget, SLOT(slot_newRootNode(QTreeWidgetItem*)));
        QObject::connect(GeomComboBox, SIGNAL(currentIndexChanged(int)), mygl, SLOT(slot_changeGeom(int)));
        QObject::connect(addButton, SIGNAL(clicked()), mygl, SLOT(slot_addNewNode()));
        QObject::connect(mygl, SIGNAL(sig_nodeGeom(ShaderProgram::Drawable*)), treeWidget, SLOT(slot_addChildNode(ShaderProgram::Drawable*)));
        QObject::connect(treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), treeWidget, SLOT(slot_changeCurrentNode()));
        QObject::connect(treeWidget, SIGNAL(sig_XTrans(double)), XDoubleSpinBox, SLOT(setValue(double)));
        QObject::connect(treeWidget, SIGNAL(sig_YTrans(double)), YDoubleSpinBox, SLOT(setValue(double)));
        QObject::connect(treeWidget, SIGNAL(sig_ZTrans(double)), ZDoubleSpinBox, SLOT(setValue(double)));
        QObject::connect(TransComboBox, SIGNAL(currentIndexChanged(int)), treeWidget, SLOT(slot_changeTrans(int)));
        QObject::connect(treeWidget, SIGNAL(sig_newTrans(int)), treeWidget, SLOT(slot_changeCurrentNode()));
        QObject::connect(XDoubleSpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeXTrans(double)));
        QObject::connect(YDoubleSpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeYTrans(double)));
        QObject::connect(ZDoubleSpinBox, SIGNAL(valueChanged(double)), treeWidget, SLOT(slot_changeZTrans(double)));
        QObject::connect(treeWidget, SIGNAL(clicked(QModelIndex)), mygl, SLOT(setFocus()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), mygl, SLOT(slot_changeColor(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), mygl, SLOT(slot_changeNameString(QString)));
        QObject::connect(renameButton, SIGNAL(clicked()), mygl, SLOT(slot_rename()));
        QObject::connect(mygl, SIGNAL(sig_rename(QString)), treeWidget, SLOT(slot_rename(QString)));
        QObject::connect(treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), mygl, SLOT(slot_changeCurrentNode(QTreeWidgetItem*)));
        QObject::connect(pushButton, SIGNAL(clicked()), treeWidget, SLOT(slot_removeAllChildren()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), treeWidget, SLOT(slot_removeSingleChild()));

        tabWidget->setCurrentIndex(0);
        TransComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        TransComboBox->clear();
        TransComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Translation", 0)
         << QApplication::translate("MainWindow", "Rotation", 0)
         << QApplication::translate("MainWindow", "Scale", 0)
        );
        TransComboBox->setCurrentText(QApplication::translate("MainWindow", "Translation", 0));
        label->setText(QApplication::translate("MainWindow", "Transformation:", 0));
        label_2->setText(QApplication::translate("MainWindow", "X:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z:", 0));
        tabWidget->setTabText(tabWidget->indexOf(transform), QApplication::translate("MainWindow", "Transform", 0));
        label_5->setText(QApplication::translate("MainWindow", "Add Child", 0));
        GeomComboBox->clear();
        GeomComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "No Geometry", 0)
         << QApplication::translate("MainWindow", "Sphere", 0)
         << QApplication::translate("MainWindow", "Cylinder", 0)
         << QApplication::translate("MainWindow", "Cube", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "Geometry:", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add Child", 0));
        label_7->setText(QApplication::translate("MainWindow", "Node Name:", 0));
        renameButton->setText(QApplication::translate("MainWindow", "Rename", 0));
        label_8->setText(QApplication::translate("MainWindow", "Color:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "White", 0)
         << QApplication::translate("MainWindow", "Red", 0)
         << QApplication::translate("MainWindow", "Blue", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(additional), QApplication::translate("MainWindow", "Add", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Remove Single Node", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Delete", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
