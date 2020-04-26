#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QMessageBox>
#include <cstdlib>
#include "miner.h"
#include "game.h"
#include "newmonthdialog.h"
#include "gamedurationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void nextMonth();
    void showNewMinerList(std::vector <Miner*> vectorMiners);
    void showNewMinerClothes();

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

    void on_buyHatBlackBtn_clicked();

    void on_buySuitBlackBtn_clicked();

    void on_buyLampBlackBtn_clicked();

    void on_buyHatBrownBtn_clicked();

    void on_buySuitBrownBtn_clicked();

    void on_buyLampBrownBtn_clicked();

    void on_buyHatMixedBtn_clicked();

    void on_buySuitMixedBtn_clicked();

    void on_buyLampMixedBtn_clicked();

    void on_AccLeftBtn_clicked();

    void on_AccRightBtn_clicked();

    void on_OffLeftBtn_clicked();

    void on_OffRightBtn_clicked();

    void on_buyChairAccBtn_clicked();

    void on_buyDeskAccBtn_clicked();

    void on_BuyComputerAccBtn_clicked();

    void on_buyChairOffBtn_clicked();

    void on_buyDeskOffBtn_clicked();

    void on_buyComputerOffBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::MainWindow *ui;
    void displayBlackMineMinersList();
    void displayBrownMineMinersList();
    void displayMixedMineMinersList();
    NewMonthDialog *newMonthDialog;
    GameDurationDialog *gameDurationDialog;
    void displayAccList();
    void displayOffList();
    int which = 0;
    int whichBlack = 0;
    int whichBrown = 0;
    int whichMixed = 0;
    int which_acc = 0;
    int which_off = 0;
    int months_overall = 40;
    double x;
    double w;
    double z;
    Game game;
};
#endif // MAINWINDOW_H
