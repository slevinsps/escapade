#ifndef MAIN_CPP
#define MAIN_CPP


#include "mainwindow.h"
#include <QApplication>

int main2(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif
