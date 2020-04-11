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

void NewMonthDialog::initData(double bl, double br, double mx, Game g)
{
    ui->labelSeason->setText(QString::fromStdString(g.getSeason()));
    double sum_black = 0;
    double sum_brown = 0;
    double half_mixed = mx/2;
    //TODO zamiana na stringi
    ui->labelBlackCoalMined->setText(QString::number(bl));
    ui->labelBrownCoalMined->setText(QString::number(br));
    ui->labelBlackMinedMixed->setText(QString::number(half_mixed));
    ui->labelBrownMinedMixed->setText(QString::number(half_mixed));
    sum_black = bl + half_mixed;
    sum_brown = br + half_mixed;
    ui->labelSumBlack->setText(QString::number(sum_black));
    ui->labelSumBrown->setText(QString::number(sum_brown));
    ui->labelNeedsIronworks->setText(QString::number(g.getIronWorks().getNeeds())); // TODO pamietac ze to sie losuje z kazdym gettem
    ui->labelNeedsCoalStorage->setText(QString::number(g.getCoalStorageSite().getNeeds()));
    ui->labelCashIronWorks->setText(QString::number(g.getIronWorks().getMoneyPayingAmount()));
    ui->labelCashCoalStorage->setText(QString::number(g.getCoalStorageSite().getMoneyPayingAmount()));
    g.setSeason();
    ui->labelCashHeatingPlant->setText(QString::number(g.getHeatingPlant().getMoneyPayingAmount()));
    ui->labelNeedsHeatingPlant->setText(QString::number(g.getHeatingPlant().getNeeds()));
    ui->labelCashPowerstation->setText(QString::number(g.getPowerStation().getMoneyPayingAmount()));
    ui->labelNeedsPowerstation->setText(QString::number(g.getPowerStation().getNeeds()));
}

void NewMonthDialog::on_acceptButton_clicked()
{
    // TODO przekazanie informacji do mainwindow
}
