#include <iostream>
#include "mainwindow.h"
#include "newminerslist.h"
#include "game.h"
#include <QLabel>
#include <QApplication>

// TODO przemioty ksiegowych i officeworkerow
// TODO ksiegowi i office workerzy
// TODO wydajnosc gornika wzrasta wraz ze stazem
// TODO pobieranie pensji przez gornika
// TODO zbugowane przenoszenie a pozniej strzalki
// TODO pieniadze na dzieci
// TODO dzialajace przedmioty gornika
// TODO mozliwosc strajkow
void initializeApp() {
    NewMinersList list;
    list.generateMinerList();
    std::vector <Miner> wektor;
    wektor = list.getMinersList();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initializeApp();
    MainWindow w;
    w.show();
    return a.exec();
}
