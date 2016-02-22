#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>
#include <food.h>

//In mainwindow.ui, you'll see a QListWidget in the GUI. That QListWidget
//has been "promoted" to a MyListWidget, which inherits from QListWidget
//but can implement its own functions, signals, and slots for
//our own more specific functionality

//The GUI also contains many other widgets which have NOT been promoted.
//These widgets have their built-in signals and slots linked to the
//signals and slots of our promoted classes, namely MainWindow and MyListWidget.

class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    MyListWidget(QWidget* parent = NULL);
    ~MyListWidget();

public slots:
    void slot_receiveFoodItem(QListWidgetItem*);
    void slot_processClickedItem(QListWidgetItem*);
signals:
    void sig_sendPrice(QString s);
    void sig_sendType(QString s);
};

#endif // MYLISTWIDGET_H
