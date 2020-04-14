#include <iostream>
#include "mainwindow.h"
#include "game.h"
#include <QLabel>
#include <QApplication>

// TODO przemioty ksiegowych i officeworkerow
// TODO ksiegowi i office workerzy
// TODO zbugowane przenoszenie a pozniej strzalki
// TODO storage
// TODO faktyczne działanie przedmiotow pracownikow gornych
// TODO odswiezenie kwoty za storage + final przy zmianie editline


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
