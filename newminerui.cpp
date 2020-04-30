#include "newminerui.h"
#include "ui_newminerui.h"

NewMinerUI::NewMinerUI(QWidget *parent, Game *g) :
    QDialog(parent),
    ui(new Ui::NewMinerUI)
{
    game = g;
    ui->setupUi(this);
    showNewMinerList(game->getMinersList());
}

NewMinerUI::~NewMinerUI()
{
    delete ui;
}

void NewMinerUI::showNewMinerList(std::vector <Miner*> vectorMiners)
{

    ui->labelName->setText(QString::fromStdString(vectorMiners[which]->getName())); // name
    ui->labelKids->setText(QString::number(vectorMiners[which]->getKids())); // kids
    ui->labelSalary->setText(QString::number(vectorMiners[which]->getSalaryAmount())); // salary
    ui->labelProd->setText(QString::number(vectorMiners[which]->getProductivity())); // productivity
    ui->labelStrikOp->setText(QString::number(vectorMiners[which]->getStrikeOpportunity())); // strike opp
    if(vectorMiners[which]->getUnion()==true)         // union
        ui->labelUnion->setText("Yes");
    else
        ui->labelUnion->setText("No");
}

void NewMinerUI::on_minerListLeftBtn_2_clicked()
{
    which--;
    if (which==-1)
        which=9;
    showNewMinerList(game->getMinersList());
}

void NewMinerUI::on_minerListRightBtn_2_clicked()
{
    which++;
    if(which==10)
        which=0;
    showNewMinerList(game->getMinersList());
}

void NewMinerUI::on_newToBlackBtn_clicked()
{
    game->getBlackCoalMine()->addMinerToList(game->getOneMinerFromList(which));
    game->eraseMiner(which);
    //displayBlackMineMinersList();
    showNewMinerList(game->getMinersList());

    //office workers
    game->refreshOfficeWorkersAmount();
    //displayOffList();
}

void NewMinerUI::on_newToBrownBtn_clicked()
{
    game->getBrownCoalMine()->addMinerToList(game->getMinersList()[which]);
    game->eraseMiner(which);
    //displayBrownMineMinersList();
    showNewMinerList(game->getMinersList());
    game->refreshOfficeWorkersAmount();
    //displayOffList();
}

void NewMinerUI::on_newToUranBtn_clicked()
{
    game->getMixedCoalMine()->addMinerToList(game->getMinersList()[which]);
    game->eraseMiner(which);
    //displayMixedMineMinersList();
    showNewMinerList(game->getMinersList());
    game->refreshOfficeWorkersAmount();
    //displayOffList();
}
