#ifndef NEWMONTHDIALOG_H
#define NEWMONTHDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <cmath>
#include "game.h"

namespace Ui {
class NewMonthDialog;
}

class NewMonthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMonthDialog(QWidget *parent = nullptr, Game *g = nullptr);
    ~NewMonthDialog();
    double getStorBlack();
    double getStorBrown();
    double getMoneyBack();

private slots:
    void on_acceptButton_clicked();

    void on_doubleSpinBlackIronWorks_valueChanged(double arg1);

    void on_doubleSpinBrownIronWorks_valueChanged(double arg1);

    void on_doubleSpinBlackCoalStorageSite_valueChanged(double arg1);

    void on_doubleSpinBrownCoalStorageSite_valueChanged(double arg1);

    void on_doubleSpinBlackPowerStation_valueChanged(double arg1);

    void on_doubleSpinBlackHeatingPlant_valueChanged(double arg1);

    void on_doubleSpinBrownHeatingPlant_valueChanged(double arg1);

    void on_doubleSpinBrownPowerStation_valueChanged(double arg1);

private:
    Ui::NewMonthDialog *ui;
    double blackIronWorks;
    double brownIronWorks;
    double blackHeatingPlant;
    double brownHeatingPlant;
    double blackPowerStation;
    double brownPowerStation;
    double blackCoalStorageSite;
    double brownCoalStorageSite;
    double sum_black;
    double sum_brown;
    double half_mixed;
    double needsBlackIronWorks;
    double needsBrownIronWorks;
    double needsBlackPowerStation;
    double needsBrownPowerStation;
    double needsBlackCoalStorageSite;
    double needsBrownCoalStorageSite;
    double needsBlackHeatingPlant;
    double needsBrownHeatingPlant;
    void getNeedsAndPrice(Game g);
    double priceHeatingPlant;
    double priceIronWorks;
    double priceCoalStorageSite;
    double pricePowerStation;
    void getStorage(Game g);
    double sumProfitsBlackIronWorks = 0;
    double sumProfitsBrownIronWorks = 0;
    double sumProfitsBlackHeatingPlant = 0;
    double sumProfitsBrownHeatingPlant = 0;
    double sumProfitsBlackCoalStorageSite = 0;
    double sumProfitsBrownCoalStorageSite = 0;
    double sumProfitsBlackPowerStation = 0;
    double sumProfitsBrownPowerStation = 0;
    double sumProfits = 0;
    double storagePrice;
    void storageInit(Game g);
    double officeWorkersSalary;
    double accountantsSalary;
    double finalMoney;
    double minersSalary;
    double inStorageBeforeBlack = 0;
    double inStorageBeforeBrown = 0;
    double storageSumPrice;
    double countFinal();
    double moneyBefore;
    double toStorageBlack = 0;
    double toStorageBrown = 0;

};

#endif // NEWMONTHDIALOG_H
