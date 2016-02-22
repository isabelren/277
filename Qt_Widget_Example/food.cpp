#include "food.h"

Food::Food(QString name)
{
    QListWidgetItem::setText(name);
}

Food::Food(float price, FoodType t, QString name){
    this->price = price;
    this->type = t;
    this->name = name;
    QListWidgetItem::setText(name);
}

Food::~Food()
{

}

