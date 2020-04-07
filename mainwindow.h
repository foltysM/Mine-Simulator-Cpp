#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QMessageBox>
#include "miner.h"
#include "newminerslist.h"
#include "game.h"
#include "blackcoalmine.h"
#include "browncoalmine.h"
#include "mixedcoalmine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    NewMinersList list;
    std::vector <Miner> vectorMiners;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void nextMonth();
    void wyswietlListeGornikow(std::vector <Miner> vectorMiners);
    std::vector <Miner> initializeMiners();
    Game game;
    int which = 0;
    int whichBlack = 0;
    int whichBrown = 0;
    int whichMixed = 0;
    BlackCoalMine blackCoalMine;
    BrownCoalMine brownCoalMine;
    MixedCoalMine mixedCoalMine;

private slots:

    void on_nextMonthBtn_clicked();

    void on_minerListLeftBtn_2_clicked();

    void on_minerListRightBtn_2_clicked();

    void on_newToBlackBtn_clicked();

    void on_newToBrownBtn_clicked();

    void on_newToUranBtn_clicked();

    void on_disFrBrBtn_clicked();

    void on_FrBrtoMBtn_clicked();

    void on_FrBrToBlBtn_clicked();

    void on_minerListLeftBtn_4_clicked();

    void on_minerListRightBtn_4_clicked();

    void on_minerListLeftBtn_3_clicked();

    void on_disFrBlBtn_clicked();

    void on_m1b2_3_clicked();

    void on_m1b3_3_clicked();

    void on_minerListRightBtn_3_clicked();

    void on_minerListLeftBtn_5_clicked();

    void on_m1b1_5_clicked();

    void on_m1b2_5_clicked();

    void on_m1b3_5_clicked();

    void on_minerListRightBtn_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
