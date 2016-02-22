#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <food.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    //This macro tells Qt's Meta-Object Compiler to produce a source file with Qt meta-object data in it,
                //such as signal and slot data with which other Qt classes can interface.
                //In this case, the file created is moc_mainwindow.cpp, where the moc stands for meta-object compiler.
                //You should never have to make changes to this type of file, and in fact any changes you make will be reverted
                //when Qt re-compiles the class.

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SendListData();

private:
    Ui::MainWindow *ui;

    std::vector<Food*> food;

    QString new_food_name;
    float new_food_price;
    Food::FoodType new_food_type;

public slots:                           // Slots are callable just like regular functions, but they can also be
                                        // linked to signals emitted from other Q_OBJECTs, or even this Q_OBJECT itself.
                                        // When linked to a signal, a slot gets called any time that signal is emitted,
                                        // and it is called on the data passed by the emitted signal.
                                        // For organizational purposes, I like to preface all my slot names with slot_.

    void slot_storeNewFoodName(QString);
    void slot_storeNewFoodPrice(double);
    void slot_storeNewFoodType(int);

    void slot_CreateNewFood();

signals:                                // Signals are just constructs used to pass data. They are not callable like functions.
                                        // However, they can be "emitted" by saying emit Signal_Name, as can be seen in the
                                        // body of SendListData().
                                        // For organizational purposes, I like to preface all my signal names with sig_.
    void sig_sendFoodItem(QListWidgetItem*);
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
