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
    explicit NewMonthDialog(QWidget *parent = nullptr);
    ~NewMonthDialog();
    void initData(double bl, double br, double mx, Game &g);

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
    double inStorageBeforeBlack;
    double inStorageBeforeBrown;
    double sumProfitsBlackIronWorks;
    double sumProfitsBrownIronWorks;
    double sumProfitsBlackHeatingPlant;
    double sumProfitsBrownHeatingPlant;
    double sumProfitsBlackCoalStorageSite;
    double sumProfitsBrownCoalStorageSite;
    double sumProfitsBlackPowerStation;
    double sumProfitsBrownPowerStation;
    double sumProfits;
    double storagePrice;
    void storageInit(Game g);
    double officeWorkersSalary;
    double accountantsSalary;
    double finalMoney;
    double minersSalary;
    double storageSumPrice;
};

#endif // NEWMONTHDIALOG_H
