#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <scene/node.h>

class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    MyTreeWidget(QWidget* parent = 0);
    ~MyTreeWidget();
    int currentTrans;

public slots:
    void slot_newRootNode(QTreeWidgetItem*);

    void slot_changeTrans(int i);
    void slot_addChildNode(ShaderProgram::Drawable* shape);
    void slot_removeSingleChild();
    void slot_removeAllChildren();
    void slot_changeCurrentNode();
    void slot_changeXTrans(double x);
    void slot_changeYTrans(double x);
    void slot_changeZTrans(double x);
    void slot_rename(QString s);
signals:
    void sig_newTrans(int);
    void sig_XTrans(double);
    void sig_YTrans(double);
    void sig_ZTrans(double);

};


#endif // MYTREEWIDGET_H
