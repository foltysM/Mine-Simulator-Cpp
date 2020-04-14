#include "newmonthdialog.h"
#include "ui_newmonthdialog.h"

NewMonthDialog::NewMonthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMonthDialog)
{
    ui->setupUi(this);
}

NewMonthDialog::~NewMonthDialog()
{
    delete ui;
}

void NewMonthDialog::initData(double bl, double br, double mx, Game &g)
{
    ui->labelSeason->setText(QString::fromStdString(g.getSeason()));
    sum_black = 0;
    sum_brown = 0;
    half_mixed = mx/2;




    ui->labelBlackCoalMined->setText(QString::number(bl));
    ui->labelBrownCoalMined->setText(QString::number(br));
    ui->labelBlackMinedMixed->setText(QString::number(half_mixed));
    ui->labelBrownMinedMixed->setText(QString::number(half_mixed));
    sum_black = bl + half_mixed;
    sum_brown = br + half_mixed;
    ui->labelSumBlack->setText(QString::number(sum_black));
    ui->labelSumBrown->setText(QString::number(sum_brown));
    getNeedsAndPrice(g);
    getStorage(g);
    ui->labelNeedsBlackIronworks->setText(QString::number(needsBlackIronWorks));
    ui->labelNeedsBrownIronworks->setText(QString::number(needsBrownIronWorks));
    ui->labelNeedsBlackCoalStorage->setText(QString::number(needsBlackCoalStorageSite));
    ui->labelNeedsBrownCoalStorageSite->setText(QString::number(needsBrownCoalStorageSite));
    ui->labelCashIronWorks->setText(QString::number(priceIronWorks));
    ui->labelCashCoalStorage->setText(QString::number(priceCoalStorageSite));
    g.setSeason();
    ui->labelCashHeatingPlant->setText(QString::number(priceHeatingPlant));
    ui->labelNeedsBrownHeatingPlant->setText(QString::number(needsBrownHeatingPlant));
    ui->labelNeedsBlackHeatingPlant->setText(QString::number(needsBlackHeatingPlant));
    ui->labelCashPowerstation->setText(QString::number(pricePowerStation));
    ui->labelNeedsBlackPowerstation->setText(QString::number(needsBlackPowerStation));
    ui->labelNeedsBrownPowerstation->setText(QString::number(needsBrownPowerStation));
    //money
    ui->labelMoneyDialog->setText(QString::fromStdString("$"+std::to_string(g.getMoney())));


    // Storage init
    storageInit(g);

    // Miners' salary
    ui->labelMinersStriking->setNum(g.randomStrike());
    // Including money for children
    minersSalary = round(g.blackCoalMine.getMinerCosts())+round(g.brownCoalMine.getMinerCosts())+round(g.mixedCoalMine.getMinerCosts())+g.moneyForChildren();
    ui->labelCostsMiners->setNum(minersSalary);

    // Office Workers salary - $50 for every worker
    officeWorkersSalary = (int)g.vectorOfficeWorkers.size()*50;
    ui->labelCostsOfficeWorkers->setNum(officeWorkersSalary);

    // Accountants salary - $20 for every accountant
    accountantsSalary = (int)g.vectorAccountants.size()*20;
    ui->labelCostsAccountants->setNum(accountantsSalary);

    // Final money
    finalMoney = g.getMoney() - accountantsSalary - minersSalary - officeWorkersSalary - storageSumPrice;

}

void NewMonthDialog::on_acceptButton_clicked()
{
    //lastMonthRevenues = 0; TODO ile bylo przychodu
    //g.refreshAccountantsAmount();
    // TODO przekazanie informacji do mainwindow
    blackIronWorks = ui->doubleSpinBlackIronWorks->value();
    brownIronWorks = ui->doubleSpinBrownIronWorks->value();
    blackHeatingPlant = ui->doubleSpinBlackHeatingPlant->value();
    brownHeatingPlant = ui->doubleSpinBrownHeatingPlant->value();
    blackPowerStation = ui->doubleSpinBlackPowerStation->value();
    brownPowerStation = ui->doubleSpinBrownPowerStation->value();
    blackCoalStorageSite = ui->doubleSpinBlackCoalStorageSite->value();
    brownCoalStorageSite = ui->doubleSpinBrownCoalStorageSite->value();

}

void NewMonthDialog::on_doubleSpinBlackIronWorks_valueChanged(double arg1)
{
    if(needsBlackIronWorks<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBlackIronWorks->setValue(0);
    }else{
        double toSet = sum_black + inStorageBeforeBlack - arg1 - ui->doubleSpinBlackHeatingPlant->value() - ui->doubleSpinBlackPowerStation->value() - ui->doubleSpinBlackCoalStorageSite->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBlackIronWorks->setValue(0);
        }else{
            ui->labelToStorageBlack->setNum(toSet);
            sumProfitsBlackIronWorks = priceIronWorks*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBlackIronWorks->setNum(sumProfitsBlackIronWorks);
        }
    }
}

void NewMonthDialog::on_doubleSpinBlackCoalStorageSite_valueChanged(double arg1)
{
    if(needsBlackCoalStorageSite<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBlackCoalStorageSite->setValue(0);

    }else{
        double toSet = sum_black + inStorageBeforeBlack - arg1 - ui->doubleSpinBlackHeatingPlant->value() - ui->doubleSpinBlackPowerStation->value() - ui->doubleSpinBlackIronWorks->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBlackCoalStorageSite->setValue(0);
        }else{
            ui->labelToStorageBlack->setNum(toSet);
            sumProfitsBlackCoalStorageSite = priceCoalStorageSite*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBlackCoalStorageSite->setNum(sumProfitsBlackCoalStorageSite);
        }
    }
}

void NewMonthDialog::on_doubleSpinBlackPowerStation_valueChanged(double arg1)
{
    if(needsBlackPowerStation<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBlackPowerStation->setValue(0);

    }else{
        double toSet = sum_black + inStorageBeforeBlack - arg1 - ui->doubleSpinBlackHeatingPlant->value() - ui->doubleSpinBlackIronWorks->value() - ui->doubleSpinBlackCoalStorageSite->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBlackPowerStation->setValue(0);
        }else{
            ui->labelToStorageBlack->setNum(toSet);
            sumProfitsBlackPowerStation = pricePowerStation*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBlackPowerStation->setNum(sumProfitsBlackPowerStation);
        }
    }
}

void NewMonthDialog::on_doubleSpinBlackHeatingPlant_valueChanged(double arg1)
{
    if(needsBlackHeatingPlant<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBlackHeatingPlant->setValue(0);

    }else{
        double toSet = sum_black + inStorageBeforeBlack - arg1 - ui->doubleSpinBlackIronWorks->value() - ui->doubleSpinBlackPowerStation->value() - ui->doubleSpinBlackCoalStorageSite->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBlackHeatingPlant->setValue(0);
        }else{
            ui->labelToStorageBlack->setNum(toSet);
            sumProfitsBlackHeatingPlant = priceHeatingPlant*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBlackHeatingPlant->setNum(sumProfitsBlackHeatingPlant);
        }
    }
}

void NewMonthDialog::on_doubleSpinBrownCoalStorageSite_valueChanged(double arg1)
{
    if(needsBrownCoalStorageSite<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBrownCoalStorageSite->setValue(0);

    }else{
        double toSet = sum_brown + inStorageBeforeBrown - arg1 - ui->doubleSpinBrownIronWorks->value() - ui->doubleSpinBrownPowerStation->value() - ui->doubleSpinBrownHeatingPlant->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBrownCoalStorageSite->setValue(0);
        }else{
            ui->labelToStorageBrown->setNum(toSet);
            sumProfitsBrownCoalStorageSite = priceCoalStorageSite*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBrownCoalStorageSite->setNum(sumProfitsBrownCoalStorageSite);
        }
    }
}

void NewMonthDialog::on_doubleSpinBrownIronWorks_valueChanged(double arg1)
{
    if(needsBrownIronWorks<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBrownIronWorks->setValue(0);

    }else{
        double toSet = sum_brown + inStorageBeforeBrown - arg1 - ui->doubleSpinBrownCoalStorageSite->value() - ui->doubleSpinBrownPowerStation->value() - ui->doubleSpinBrownHeatingPlant->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBrownIronWorks->setValue(0);
        }else{
            ui->labelToStorageBrown->setNum(toSet);
            sumProfitsBrownIronWorks = priceIronWorks*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBrownIronWorks->setNum(sumProfitsBrownIronWorks);
        }
    }
}

void NewMonthDialog::on_doubleSpinBrownHeatingPlant_valueChanged(double arg1)
{
    if(needsBrownHeatingPlant<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBrownHeatingPlant->setValue(0);

    }else{
        double toSet = sum_brown + inStorageBeforeBrown - arg1 - ui->doubleSpinBrownIronWorks->value() - ui->doubleSpinBrownPowerStation->value() - ui->doubleSpinBrownCoalStorageSite->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBrownHeatingPlant->setValue(0);
        }else{
            ui->labelToStorageBrown->setNum(toSet);
            sumProfitsBrownHeatingPlant = priceHeatingPlant*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBrownHeatingPlant->setNum(sumProfitsBrownHeatingPlant);
        }
    }
}

void NewMonthDialog::on_doubleSpinBrownPowerStation_valueChanged(double arg1)
{
    if(needsBrownPowerStation<arg1)
    {
        QMessageBox::warning(this, "WARNING", "You cannot sell more than the company needs!", "Ok, I'll never do that again");
        ui->doubleSpinBrownPowerStation->setValue(0);

    }else{
        double toSet = sum_brown + inStorageBeforeBrown - arg1 - ui->doubleSpinBrownIronWorks->value() - ui->doubleSpinBrownCoalStorageSite->value() - ui->doubleSpinBrownHeatingPlant->value();
        if(toSet<0)
        {
            QMessageBox::warning(this, "WARNING", "You cannot give to storage negative amount of coal", "Ok, I'll never do that again");
            ui->doubleSpinBrownPowerStation->setValue(0);
        }else{
            ui->labelToStorageBrown->setNum(toSet);
            sumProfitsBrownPowerStation = pricePowerStation*arg1;
            sumProfits = sumProfitsBlackIronWorks+sumProfitsBrownIronWorks+sumProfitsBlackHeatingPlant+sumProfitsBrownHeatingPlant+sumProfitsBlackCoalStorageSite+sumProfitsBrownCoalStorageSite+sumProfitsBlackPowerStation+sumProfitsBrownPowerStation;
            ui->labelMoneySum->setNum(sumProfits);
            ui->labelMoneyBrownPowerStation->setNum(sumProfitsBrownPowerStation);
        }
    }
}

void NewMonthDialog::getNeedsAndPrice(Game g)
{
    //needs
    needsBrownCoalStorageSite = g.getCoalStorageSite().getNeedsBrown();
    needsBlackCoalStorageSite = g.getCoalStorageSite().getNeedsBlack();
    needsBlackIronWorks = g.getIronWorks().getNeedsBlack();
    needsBrownIronWorks = g.getIronWorks().getNeedsBrown();
    needsBlackHeatingPlant = g.getHeatingPlant().getNeedsBlack();
    needsBrownHeatingPlant = g.getHeatingPlant().getNeedsBrown();
    needsBlackPowerStation = g.getPowerStation().getNeedsBlack();
    needsBrownPowerStation = g.getPowerStation().getNeedsBrown();
    //price
    priceIronWorks = g.getIronWorks().getMoneyPayingAmount();
    priceHeatingPlant = g.getHeatingPlant().getMoneyPayingAmount();
    priceCoalStorageSite = g.getCoalStorageSite().getMoneyPayingAmount();
    pricePowerStation = g.getPowerStation().getMoneyPayingAmount();
}

void NewMonthDialog::getStorage(Game g)
{
    inStorageBeforeBlack = g.getStorage().getBlackCoalAmount();
    inStorageBeforeBrown = g.getStorage().getBrownCoalAmount();
    ui->labelInStorageBlack->setNum(inStorageBeforeBlack);
    ui->labelInStorageBrown->setNum(inStorageBeforeBrown);
}

void NewMonthDialog::storageInit(Game g)
{
    ui->labelInStorageBlack->setNum(g.getStorage().getBlackCoalAmount());
    ui->labelInStorageBrown->setNum(g.getStorage().getBrownCoalAmount());
    ui->labelToStorageBlack->setNum(sum_black);
    ui->labelToStorageBrown->setNum(sum_brown);

    //storage price
    storagePrice = g.getStorage().getPrice();
    ui->labelStoragePerUnitPrice->setNum(storagePrice);
    storageSumPrice = storagePrice*sum_black+storagePrice*sum_brown;
    ui->labelCostsStorage->setNum(storageSumPrice);
}
