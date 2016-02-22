#include "mylistwidget.h"

MyListWidget::MyListWidget(QWidget* parent) : QListWidget(parent)
{

}

MyListWidget::~MyListWidget()
{

}

void MyListWidget::slot_receiveFoodItem(QListWidgetItem* f){
    QListWidget::addItem(f);
}

void MyListWidget::slot_processClickedItem(QListWidgetItem* i){
    Food* f = (Food*)i;
    QString p = QString::number(f->price);
    if(p.length() < 4){
        p.append(QChar('0'));
    }
    emit sig_sendPrice(p);

    //This could be done smarter/more dynamically, but for the purposes
    //of this example this implementation of enum->string will suffice
    Food::FoodType t = f->type;
    QString s;
    if(t == Food::VEGETABLE){
        s = QString("VEGETABLE");
    }
    else if(t == Food::FRUIT){
        s = QString("FRUIT");
    }
    else if(t == Food::MEAT){
        s = QString("MEAT");
    }
    emit sig_sendType(s);
}
