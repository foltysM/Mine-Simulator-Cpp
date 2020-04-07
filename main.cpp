#include <iostream>
#include "mainwindow.h"
#include "newminerslist.h"
#include "game.h"
#include <QLabel>
#include <QApplication>

void initializeApp() {
    NewMinersList list;

    list.generateMinerList();
    std::vector <Miner> wektor;
    wektor = list.getMinersList();
//    std::string stringi = wektor[0].getName();
//    std::cout<<"whatever";
    int months;
}





int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    initializeApp();





    //std::cout<<"Hello"<<std::endl;



    MainWindow w;
    w.show();
    return a.exec();
}
