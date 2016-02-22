#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <scene/joint.h>

class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    MyTreeWidget(QWidget* parent = 0);
    ~MyTreeWidget();
    int currentTrans;

public slots:
    void slot_newRootNode(QTreeWidgetItem*);
    void slot_changeCurrentJoint();

    void slot_xAdd();
    void slot_xSub();
    void slot_yAdd();
    void slot_ySub();
    void slot_zAdd();
    void slot_zSub();

    void slot_changeXTrans(double x);
    void slot_changeYTrans(double x);
    void slot_changeZTrans(double x);

signals:
    void sig_update();
    void sig_xRot(double);
    void sig_yRot(double);
    void sig_zRot(double);

    void sig_xTrans(double);
    void sig_yTrans(double);
    void sig_zTrans(double);

    void sig_moveMesh();
    void sig_changeCurrent(Joint*);
};


#endif // MYTREEWIDGET_H
