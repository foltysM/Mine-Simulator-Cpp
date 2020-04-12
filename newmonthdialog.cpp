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

void NewMonthDialog::initData(double bl, double br, double mx, Game g, double m) // TODO czy na pewno money potrzebne skoro jest w game?
{
//    g.getIronWorks().randNeedsAndCash();
//    g.getHeatingPlant().randNeedsAndCash();
//    g.getPowerStation().randNeedsAndCash();
//    g.getCoalStorageSite().randNeedsAndCash(); TODO to nie dziala trzeba rand w needsach poki co

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
    ui->labelNeedsBlackIronworks->setText(QString::number(g.getIronWorks().getNeedsBlack())); // TODO pamietac ze to sie losuje z kazdym gettem
    ui->labelNeedsBrownIronworks->setText(QString::number(g.getIronWorks().getNeedsBrown()));
    ui->labelNeedsBlackCoalStorage->setText(QString::number(g.getCoalStorageSite().getNeedsBlack()));
    ui->labelNeedsBrownCoalStorageSite->setText(QString::number(g.getCoalStorageSite().getNeedsBrown()));
    ui->labelCashIronWorks->setText(QString::number(g.getIronWorks().getMoneyPayingAmount()));
    ui->labelCashCoalStorage->setText(QString::number(g.getCoalStorageSite().getMoneyPayingAmount()));
    g.setSeason();
    ui->labelCashHeatingPlant->setText(QString::number(g.getHeatingPlant().getMoneyPayingAmount()));
    ui->labelNeedsBrownHeatingPlant->setText(QString::number(g.getHeatingPlant().getNeedsBrown()));
    ui->labelNeedsBlackHeatingPlant->setText(QString::number(g.getHeatingPlant().getNeedsBlack()));
    ui->labelCashPowerstation->setText(QString::number(g.getPowerStation().getMoneyPayingAmount()));
    ui->labelNeedsBlackPowerstation->setText(QString::number(g.getPowerStation().getNeedsBlack()));
    ui->labelNeedsBrownPowerstation->setText(QString::number(g.getPowerStation().getNeedsBrown()));
    //TODO tu skonczylem
    //ui->labelMoneyDialog->setText(QString::fromStdString((std::string)m+"$"));
}

void NewMonthDialog::on_acceptButton_clicked()
{
    // TODO przekazanie informacji do mainwindow
}
