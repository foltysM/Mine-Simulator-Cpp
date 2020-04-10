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
    void showNewMinerList(std::vector <Miner> vectorMiners);
    std::vector <Miner> initializeMiners();
    Game game;
    int which = 0;
    int months_overall = 100; //TODO wprowadzane przez uzytkownika
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

    void on_disFrBlBtn_clicked();

    void on_minerListLeftBtnMixed_clicked();

    void on_minerListRightBtnMixed_clicked();

    void on_DisFrMBtn_clicked();

    void on_minerListRightBtnBrown_clicked();

    void on_minerListLeftBtnBrown_clicked();

    void on_minerListLeftBtnBlack_clicked();

    void on_minerListRightBtnBlack_clicked();

    void on_FrBrtoMBtn_clicked();

    void on_FrBrToBlBtn_clicked();

    void on_FrBlToBBtn_clicked();

    void on_FrBlToMxBtn_clicked();

    void on_FrMToBlBtn_clicked();

    void on_FrMToBrBtn_clicked();

private:
    Ui::MainWindow *ui;
    void displayBlackMineMinersList();
    void displayBrownMineMinersList();
    void displayMixedMineMinersList();
};
#endif // MAINWINDOW_H
