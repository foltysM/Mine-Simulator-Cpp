#include "abovegroundui.h"
#include "ui_abovegroundui.h"

AboveGroundUI::AboveGroundUI(QWidget *parent, Game *g) :
    QDialog(parent),
    ui(new Ui::AboveGroundUI)
{
    game = g;
    ui->setupUi(this);
    displayAccList();
    displayOffList();
}

AboveGroundUI::~AboveGroundUI()
{
    delete ui;
}

void AboveGroundUI::displayOffList()
{
    ui->labelOffSize->setNum((int)game->getOfficeWorkersVector().size());
    if((int)game->getOfficeWorkersVector().size()!=0)
    {
        ui->labelChairOff->setNum(game->getOneOfficeWorker(which_off)->getChair()->getReduction());
        ui->labelDeskOff->setNum(game->getOneOfficeWorker(which_off)->getDesk()->getReduction());
        ui->labelComputerOff->setNum(game->getOneOfficeWorker(which_off)->getComputer()->getReduction());
    }else{
        ui->labelChairOff->setText("No office worker");
        ui->labelDeskOff->setText("No office worker");
        ui->labelComputerOff->setText("No office worker");
    }
}

void AboveGroundUI::displayAccList()
{
    ui->labelAccSize->setNum((int)game->getAccountantsVector().size());
    if((int)game->getAccountantsVector().size()!=0)
    {
        ui->labelChairAcc->setNum(game->getOneAccountant(which_acc)->getChair()->getReduction());
        ui->labelComputerAcc->setNum(game->getOneAccountant(which_acc)->getComputer()->getReduction());
        ui->labelDeskAcc->setNum(game->getOneAccountant(which_acc)->getDesk()->getReduction());
    }else{
        ui->labelChairAcc->setText("No Accountant");
        ui->labelComputerAcc->setText("No Accountant");
        ui->labelDeskAcc->setText("No Accountant");
    }
}

void AboveGroundUI::on_AccLeftBtn_clicked()
{
    which_acc--;
        if(which_acc==-1)
        {
            which_acc = game->getAccountantsVector().size()-1;
        }
    displayAccList();
}

void AboveGroundUI::on_AccRightBtn_clicked()
{
    which_acc++;
        if(which_acc == (int)game->getAccountantsVector().size())
        {
            which_acc=0;
        }
    displayAccList();
}

void AboveGroundUI::on_OffLeftBtn_clicked()
{
    which_off--;
        if(which_off==-1)
        {
            which_off = game->getOfficeWorkersVector().size()-1;
        }
    displayOffList();
}

void AboveGroundUI::on_OffRightBtn_clicked()
{
    which_off++;
        if(which_off == (int)game->getOfficeWorkersVector().size())
        {
            which_off=0;
        }
    displayOffList();
}

void AboveGroundUI::on_buyChairAccBtn_clicked()
{
    if((int)game->getAccountantsVector().size()!=0)
    {
        if(game->getMoney()<1000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Chair chair;
            game->getOneAccountant(which_acc)->setChair(&chair);
            game->subMoney(1000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    //ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}

void AboveGroundUI::on_buyDeskAccBtn_clicked()
{
    if((int)game->getAccountantsVector().size()!=0)
    {
        if(game->getMoney()<3000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Desk desk;
            game->getOneAccountant(which_acc)->setDesk(&desk);
            game->subMoney(3000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    //ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}

void AboveGroundUI::on_BuyComputerAccBtn_clicked()
{
    if((int)game->getAccountantsVector().size()!=0)
    {
        if(game->getMoney()<5000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Computer computer;
            game->getOneAccountant(which_acc)->setComputer(&computer);
            game->subMoney(5000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    //ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}

void AboveGroundUI::on_buyChairOffBtn_clicked()
{
    if((int)game->getOfficeWorkersVector().size()!=0)
    {
        if(game->getMoney()<1000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Chair *chair = new Chair;
            game->getOneOfficeWorker(which_off)->setChair(chair);
            game->subMoney(1000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
    //ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}

void AboveGroundUI::on_buyDeskOffBtn_clicked()
{
    if((int)game->getOfficeWorkersVector().size()!=0)
    {
        if(game->getMoney()<3000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Desk *desk = new Desk;
            game->getOneOfficeWorker(which_off)->setDesk(desk);
            game->subMoney(3000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
}

void AboveGroundUI::on_buyComputerOffBtn_clicked()
{
    if((int)game->getOfficeWorkersVector().size()!=0)
    {
        if(game->getMoney()<5000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Computer *computer = new Computer;
            game->getOneOfficeWorker(which_off)->setComputer(computer);
            game->subMoney(5000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
    //ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}
