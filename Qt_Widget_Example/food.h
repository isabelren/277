#ifndef FOOD_H
#define FOOD_H

#include <QListWidgetItem>
#include <QMetaEnum>

//I've made Food a subclass of QListWidgetItem so I can display Food items
//in MyListWidget. I can pass Food items to MyListWidget through MainWindow::sig_sendFoodItem(QListWIdgetItem*),
//which has been connected to MyListWidget::slot_receiveFoodItem(QListWidgetItem*).
//In turn, MyListWidget::slot_receiveFoodItem calls QListWidget::addItem(QListWidgetItem*),
//which puts our Food item into the QListWidget in our GUI and lets us see it.

class Food : public QListWidgetItem
{
public:
    enum FoodType{VEGETABLE, FRUIT, MEAT};

    Food(QString name = QString("FOOD"));
    Food(float price = 0, FoodType t = VEGETABLE, QString name = QString("FOOD"));
    ~Food();

    float price;
    QString name;
    FoodType type;

};

#endif // FOOD_H
