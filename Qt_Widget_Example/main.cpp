#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.SendListData();//This must be called from main rather than MainWindow's constructor
                    //because we can't be certain that the object(s) that receive MainWindow's signals
                    //have been created at that point.

    return a.exec();
}
