#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create an example list of food
    Food* potato = new Food(1.50f, Food::VEGETABLE, QString("POTATO"));
    food.push_back(potato);
    Food* peach = new Food(4.30f, Food::FRUIT, QString("PEACH"));
    food.push_back(peach);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// /Send all food items in list
void MainWindow::SendListData(){
    for(uint i = 0; i < food.size(); i++){
        emit sig_sendFoodItem(food[i]); //What does this do???? Does it add to food list?
    }
}

//Connected to a signal emitted from the line edit widget in the GUI where does the code connect the signals?
void MainWindow::slot_storeNewFoodName(QString s){
    new_food_name = s;
}

//Connected to a signal emitted from the double spin box (number field with up/down arrows) widget in the GUI
void MainWindow::slot_storeNewFoodPrice(double p){
    new_food_price = p;
}

//Connected to a signal emitted from the combo box (drop-down menu) widget in the GUI
void MainWindow::slot_storeNewFoodType(int i){
    new_food_type = (Food::FoodType)i;
}

//Connected to a signal emitted from the Add New Food button in the GUI
void MainWindow::slot_CreateNewFood(){
    Food* f = new Food(new_food_price, new_food_type, new_food_name);
    emit sig_sendFoodItem(f);
}

