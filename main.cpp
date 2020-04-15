#include <iostream>
#include "mainwindow.h"
#include "game.h"
#include <QLabel>
#include <QApplication>

// TODO ksiegowi
// TODO odswiezenie kwoty za storage + final przy zmianie editline
// Brak mozliwosci uzywania mainwindow po wywolaniu dialogu

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
