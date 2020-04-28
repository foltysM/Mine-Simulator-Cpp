#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    game = new Game;
    game->generateMinerList();

    // Settings dialog
    GameDurationDialog dial(this);
    dial.setModal(true);
    if ( dial.exec() == QDialog::Accepted )
    {
        months_overall=dial.getMonths();

    }

    // UI init starts from here
    ui->setupUi(this);

    showNewMinerClothes();
    ui->progressBar->setValue(0);
    ui->labelMoneyMain->setText(QString::fromStdString("0$"));


    game->setMoney(10000);
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextMonth()
{
    if(months_overall==game->getMonths())
    {
        game->deleteMinersList();
        game->deleteMines();
        // GAME END
        QString message = "It's the end of the game. In "+QString::number(months_overall)+" months You earned "+QString::number(game->getMoney())+"$";
        QMessageBox::information(this, "Congratulations!", message);
        exit(0);
    }else{
        ui->progressBar->setValue((game->getMonths()*100)/months_overall);
    }
    // miners seniority up
    game->getBlackCoalMine()->upSeniority();
    game->getMixedCoalMine()->upSeniority();
    game->getBrownCoalMine()->upSeniority();
    displayBlackMineMinersList();
    displayBrownMineMinersList();
    displayMixedMineMinersList();
    game->setSeason();


    // new dialog setup

    NewMonthDialog newDialog(this,game);
    newDialog.setModal(true);
    if(newDialog.exec()==QDialog::Accepted)
    {
        x = newDialog.getStorBlack();
        w = newDialog.getStorBrown();
        z = newDialog.getMoneyBack();

    }
    game->setLastMonthRevenues(z-game->getMoney());
    game->setMoney(z);
    game->getStorage()->setBlackCoalAmount(x);
    game->getStorage()->setBrownCoalAmount(w);

    ui->labelInStorageBlackMain->setNum(x);
    ui->labelInStorageBrownMain->setNum(w);

    game->createAcc();
    //displayAccList();

    ui->labelMoneyMain->setText(QString::fromStdString("$"+std::to_string(game->getMoney())));

}

void MainWindow::on_nextMonthBtn_clicked()
{
     int m = game->getMonths();
     m++;
     game->setMonths(m);
     ui->labelMonths->setText(QString::number(game->getMonths()));
     nextMonth();     
}

void MainWindow::displayBrownMineMinersList()
{
    if(game->getBrownCoalMine()->getMiners()->size()!=0)
    {
        ui->labelNameBrown->setText(QString::fromStdString(game->getBrownCoalMine()->getOneMiner(whichBrown)->getName()));
        ui->labelKidsBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getKids())); // kids
        ui->labelSalaryBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getSalaryAmount())); // salary
        ui->labelProdBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getProductivity())); // productivity
        ui->labelStrikOpBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getSeniority())); // seniority
        if(game->getBrownCoalMine()->getOneMiner(whichBrown)->getUnion()==true)         // union
            ui->labelUnionBrown->setText("Yes");
        else
            ui->labelUnionBrown->setText("No");
        ui->labelHatBrown->setText(QString::fromStdString(game->getBrownCoalMine()->getOneMiner(whichBrown)->getHat()->getName()));
        ui->labelHatSalaryBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getHat()->getSalaryReduction()));
        ui->labelSuitBrown->setText(QString::fromStdString(game->getBrownCoalMine()->getOneMiner(whichBrown)->getSuit()->getName()));
        ui->labelSalarySuitBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getSuit()->getSalaryReduction()));
        ui->labelProductivitySuitBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getSuit()->getAdditionalProductivity()));
        ui->labelLampBrown->setText(QString::fromStdString(game->getBrownCoalMine()->getOneMiner(whichBrown)->getLamp()->getName()));
        ui->labelProductivityLampBrown->setText(QString::number(game->getBrownCoalMine()->getOneMiner(whichBrown)->getLamp()->getAdditionalProductivity()));
    }else{
        ui->labelNameBrown->setText("No miner");
        ui->labelKidsBrown->setText("No data"); // kids
        ui->labelSalaryBrown->setText("No data"); // salary
        ui->labelProdBrown->setText("No data"); // productivity
        ui->labelStrikOpBrown->setText("No data"); // strike opp
        ui->labelUnionBrown->setText("No data");
        ui->labelSeniorityBrown->setText("No data");
        ui->labelHatBrown->setText(QString::fromStdString("No data"));
        ui->labelHatSalaryBrown->setText(QString::fromStdString("No data"));
        ui->labelSuitBrown->setText(QString::fromStdString("No data"));
        ui->labelSalarySuitBrown->setText(QString::fromStdString("No data"));
        ui->labelProductivitySuitBrown->setText(QString::fromStdString("No data"));
        ui->labelLampBrown->setText(QString::fromStdString("No data"));
        ui->labelProductivityLampBrown->setText(QString::fromStdString("No data"));

    }
    ui->labelMinersCountBrown->setText(QString::number(game->getBrownCoalMine()->getMiners()->size()));
}

void MainWindow::displayBlackMineMinersList()
{
    if(game->getBlackCoalMine()->getMiners()->size()!=0)
    {
        ui->labelNameBlack->setText(QString::fromStdString(game->getBlackCoalMine()->getOneMiner(whichBlack)->getName()));
        ui->labelKidsBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getKids())); // kids
        ui->labelSalaryBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getSalaryAmount())); // salary
        ui->labelProdBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getProductivity())); // productivity
        ui->labelStrikOpBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getSeniority()));
        if(game->getBlackCoalMine()->getOneMiner(whichBlack)->getUnion()==true)         // union
            ui->labelUnionBlack->setText("Yes");
        else
            ui->labelUnionBlack->setText("No");
        ui->labelHatBlack->setText(QString::fromStdString(game->getBlackCoalMine()->getOneMiner(whichBlack)->getHat()->getName()));
        ui->labelSalaryHatBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getHat()->getSalaryReduction()));
        ui->labelSuitBlack->setText(QString::fromStdString(game->getBlackCoalMine()->getOneMiner(whichBlack)->getSuit()->getName()));
        ui->labelSalarySuitBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getSuit()->getSalaryReduction()));
        ui->labelProdSuitBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getSuit()->getAdditionalProductivity()));
        ui->labelLampBlack->setText(QString::fromStdString(game->getBlackCoalMine()->getOneMiner(whichBlack)->getLamp()->getName()));
        ui->labelProdLampBlack->setText(QString::number(game->getBlackCoalMine()->getOneMiner(whichBlack)->getLamp()->getAdditionalProductivity()));
    }else{
        ui->labelNameBlack->setText("No miner");
        ui->labelKidsBlack->setText("No data"); // kids
        ui->labelSalaryBlack->setText("No data"); // salary
        ui->labelProdBlack->setText("No data"); // productivity
        ui->labelStrikOpBlack->setText("No data"); // strike opp
        ui->labelUnionBlack->setText("No data");
        ui->labelSeniorityBlack->setText("No data");
        ui->labelHatBlack->setText(QString::fromStdString("No data"));
        ui->labelSalaryHatBlack->setText(QString::fromStdString("No data"));
        ui->labelSuitBlack->setText(QString::fromStdString("No data"));
        ui->labelSalarySuitBlack->setText(QString::fromStdString("No data"));
        ui->labelProdSuitBlack->setText(QString::fromStdString("No data"));
        ui->labelLampBlack->setText(QString::fromStdString("No data"));
        ui->labelProdLampBlack->setText(QString::fromStdString("No data"));
    }
    ui->labelMinersCountBlack->setText(QString::number(game->getBlackCoalMine()->getMiners()->size()));
}

void MainWindow::displayMixedMineMinersList()
{
    if(game->getMixedCoalMine()->getMiners()->size()!=0)
    {
        ui->labelNameMixed->setText(QString::fromStdString(game->getMixedCoalMine()->getOneMiner(whichMixed)->getName()));
        ui->labelKidsMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getKids())); // kids
        ui->labelSalaryMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getSalaryAmount())); // salary
        ui->labelProdMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getProductivity())); // productivity
        ui->labelStrikOpMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getStrikeOpportunity())); // strike opp
        ui->labelSeniorityMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getSeniority()));
        if(game->getMixedCoalMine()->getOneMiner(whichMixed)->getUnion() == true)         // union
            ui->labelUnionMixed->setText("Yes");
        else
            ui->labelUnionMixed->setText("No");
        ui->labelHatMixed->setText(QString::fromStdString(game->getMixedCoalMine()->getOneMiner(whichMixed)->getHat()->getName()));
        ui->labelSalaryHatMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getHat()->getSalaryReduction()));
        ui->labelSuitMixed->setText(QString::fromStdString(game->getMixedCoalMine()->getOneMiner(whichMixed)->getSuit()->getName()));
        ui->labelSalarySuitMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getSuit()->getSalaryReduction()));
        ui->labelProdSuitMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getSuit()->getAdditionalProductivity()));
        ui->labelLampMixed->setText(QString::fromStdString(game->getMixedCoalMine()->getOneMiner(whichMixed)->getLamp()->getName()));
        ui->labelProdLampMixed->setText(QString::number(game->getMixedCoalMine()->getOneMiner(whichMixed)->getLamp()->getAdditionalProductivity()));
    }else{
        ui->labelNameMixed->setText("No miner");
        ui->labelKidsMixed->setText("No data"); // kids
        ui->labelSalaryMixed->setText("No data"); // salary
        ui->labelProdMixed->setText("No data"); // productivity
        ui->labelStrikOpMixed->setText("No data"); // strike opp
        ui->labelUnionMixed->setText("No data");
        ui->labelSeniorityMixed->setText("No data");
        ui->labelHatMixed->setText(QString::fromStdString("No data"));
        ui->labelSalaryHatMixed->setText(QString::fromStdString("No data"));
        ui->labelSuitMixed->setText(QString::fromStdString("No data"));
        ui->labelSalarySuitMixed->setText(QString::fromStdString("No data"));
        ui->labelProdSuitMixed->setText(QString::fromStdString("No data"));
        ui->labelLampMixed->setText(QString::fromStdString("No data"));
        ui->labelProdLampMixed->setText(QString::fromStdString("No data"));
    }
    ui->labelMinersCountMixed->setText(QString::number(game->getMixedCoalMine()->getMiners()->size()));
}



void MainWindow::on_minerListLeftBtnBrown_clicked()
{
    whichBrown--;
        if(whichBrown==-1)
        {
            whichBrown = game->getBrownCoalMine()->getMiners()->size()-1;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_minerListRightBtnBrown_clicked()
{
    whichBrown++;
        if(whichBrown == (int)game->getBrownCoalMine()->getMiners()->size())
        {
            whichBrown=0;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_disFrBrBtn_clicked()
{
    if(game->getBrownCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game->getBrownCoalMine()->eraseMiner(whichBrown-1);
    displayBrownMineMinersList();

    game->refreshOfficeWorkersAmount();
    //displayOffList();
}

void MainWindow::on_disFrBlBtn_clicked()
{
    if(game->getBlackCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game->getBlackCoalMine()->eraseMiner(whichBlack-1);
    displayBlackMineMinersList();

    game->refreshOfficeWorkersAmount();
    //displayOffList();
}

void MainWindow::on_minerListLeftBtnMixed_clicked()
{
    whichMixed--;
        if(whichMixed==-1)
        {
            whichMixed = game->getMixedCoalMine()->getMiners()->size()-1;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_minerListRightBtnMixed_clicked()
{
    whichMixed++;
        if(whichMixed == (int)game->getMixedCoalMine()->getMiners()->size())
        {
            whichMixed=0;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_DisFrMBtn_clicked()
{
    if(game->getMixedCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game->getMixedCoalMine()->eraseMiner(whichMixed-1);
    displayMixedMineMinersList();

    game->refreshOfficeWorkersAmount();
    //displayOffList();
}

void MainWindow::on_minerListLeftBtnBlack_clicked()
{
    whichBlack--;
        if(whichBlack==-1)
        {
            whichBlack = game->getBlackCoalMine()->getMiners()->size()-1;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_minerListRightBtnBlack_clicked()
{
    whichBlack++;
        if(whichBlack == (int)game->getBlackCoalMine()->getMiners()->size())
        {
            whichBlack=0;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_FrBrtoMBtn_clicked()
{
    if(game->getBrownCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getMixedCoalMine()->addMinerToList(game->getBrownCoalMine()->getOneMiner(whichBrown));
        game->getBrownCoalMine()->eraseMiner(whichBrown-1);
        whichMixed = game->getMixedCoalMine()->getMiners()->size()-1;
    }
    displayBrownMineMinersList();
    displayMixedMineMinersList();
}

void MainWindow::on_FrBrToBlBtn_clicked()
{
    if(game->getBrownCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getBlackCoalMine()->addMinerToList(game->getBrownCoalMine()->getOneMiner(whichBrown));
        game->getBrownCoalMine()->eraseMiner(whichBrown-1);
        whichBlack = game->getBlackCoalMine()->getMiners()->size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToBBtn_clicked()
{
    if(game->getBlackCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getBrownCoalMine()->addMinerToList(game->getBlackCoalMine()->getOneMiner(whichBlack));
        game->getBlackCoalMine()->eraseMiner(whichBlack-1);
        whichBrown = game->getBrownCoalMine()->getMiners()->size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToMxBtn_clicked()
{
    if(game->getBlackCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getMixedCoalMine()->addMinerToList(game->getBlackCoalMine()->getOneMiner(whichBlack));
        game->getBlackCoalMine()->eraseMiner(whichBlack-1);
        whichMixed = game->getMixedCoalMine()->getMiners()->size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBlBtn_clicked()
{
    if(game->getMixedCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getBlackCoalMine()->addMinerToList(game->getMixedCoalMine()->getOneMiner(whichMixed));
        game->getMixedCoalMine()->eraseMiner(whichMixed-1);
        whichBlack = game->getBlackCoalMine()->getMiners()->size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBrBtn_clicked()
{
    if(game->getMixedCoalMine()->getMiners()->size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game->getBrownCoalMine()->addMinerToList(game->getMixedCoalMine()->getOneMiner(whichMixed));
        game->getMixedCoalMine()->eraseMiner(whichMixed-1);
        whichBrown = game->getBrownCoalMine()->getMiners()->size()-1;
    }
    displayMixedMineMinersList();
    displayBrownMineMinersList();
}

void MainWindow::showNewMinerClothes()
{
    ui->labelPsblHatName->setText(QString::fromStdString(game->getHat()->getName()));
    ui->labelPsblHatSalary->setText(QString::number(game->getHat()->getSalaryReduction()));
    ui->labelPsblHatPrice->setText(QString::number(game->getHat()->getPrice()));
    ui->labelPsblSuitName->setText(QString::fromStdString(game->getSuit()->getName()));
    ui->labelPsblSuitProd->setText(QString::number(game->getSuit()->getAdditionalProductivity()));
    ui->labelPsblSuitSalary->setText(QString::number(game->getSuit()->getSalaryReduction()));
    ui->labelPsblSuitPrice->setText(QString::number(game->getSuit()->getPrice()));
    ui->labelPsblLampName->setText(QString::fromStdString(game->getLamp()->getName()));
    ui->labelPsblLampProd->setText(QString::number(game->getLamp()->getAdditionalProductivity()));
    ui->labelPsblLampPrice->setText(QString::number(game->getLamp()->getPrice()));
}

void MainWindow::on_buyHatBlackBtn_clicked()
{
    if((game->getBlackCoalMine()->getMiners()->size()!=0))
    {
        if(game->getHat()->getPrice()<=game->getMoney())
        {
            game->getBlackCoalMine()->getOneMiner(whichBlack)->setHat(game->getHat());
            game->subMoney(game->getHat()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setHat(game->generateHat());
            showNewMinerClothes();
            displayBlackMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {        
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buySuitBlackBtn_clicked()
{
    if((game->getBlackCoalMine()->getMiners()->size()!=0))
    {
        if(game->getSuit()->getPrice()<=game->getMoney())
        {
            game->getBlackCoalMine()->getOneMiner(whichBlack)->setSuit(game->getSuit());
            game->subMoney(game->getSuit()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setSuit(game->generateSuit());
            showNewMinerClothes();
            displayBlackMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buyLampBlackBtn_clicked()
{
    if((game->getBlackCoalMine()->getMiners()->size()!=0))
    {
        if(game->getLamp()->getPrice()<=game->getMoney())
        {
            game->getBlackCoalMine()->getOneMiner(whichBlack)->setLamp(game->getLamp());
            game->subMoney(game->getLamp()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setLamp(game->generateLamp());
            showNewMinerClothes();
            displayBlackMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buyHatBrownBtn_clicked()
{
    if((game->getBrownCoalMine()->getMiners()->size()!=0))
    {
        if(game->getHat()->getPrice()<=game->getMoney())
        {
            game->getBrownCoalMine()->getOneMiner(whichBrown)->setHat(game->getHat());
            game->subMoney(game->getHat()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setHat(game->generateHat());
            showNewMinerClothes();
            displayBrownMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buySuitBrownBtn_clicked()
{
    if((game->getBrownCoalMine()->getMiners()->size()!=0))
    {
        if(game->getSuit()->getPrice()<=game->getMoney())
        {
            game->getBrownCoalMine()->getOneMiner(whichBrown)->setSuit(game->getSuit());
            game->subMoney(game->getSuit()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setSuit(game->generateSuit());
            showNewMinerClothes();
            displayBrownMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buyLampBrownBtn_clicked()
{
    if((game->getBrownCoalMine()->getMiners()->size()!=0))
    {
        if(game->getLamp()->getPrice()<=game->getMoney())
        {
            game->getBrownCoalMine()->getOneMiner(whichBrown)->setLamp(game->getLamp());
            game->subMoney(game->getLamp()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setLamp(game->generateLamp());
            showNewMinerClothes();
            displayBrownMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buyHatMixedBtn_clicked()
{
    if((game->getMixedCoalMine()->getMiners()->size()!=0))
    {
        if(game->getHat()->getPrice()<=game->getMoney())
        {
            game->getMixedCoalMine()->getOneMiner(whichMixed)->setHat(game->getHat());
            game->subMoney(game->getHat()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setHat(game->generateHat());
            showNewMinerClothes();
            displayMixedMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buySuitMixedBtn_clicked()
{
    if((game->getMixedCoalMine()->getMiners()->size()!=0))
    {
        if(game->getSuit()->getPrice()<=game->getMoney())
        {
            game->getMixedCoalMine()->getOneMiner(whichMixed)->setSuit(game->getSuit());
            game->subMoney(game->getSuit()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setSuit(game->generateSuit());
            showNewMinerClothes();
            displayMixedMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_buyLampMixedBtn_clicked()
{
    if((game->getMixedCoalMine()->getMiners()->size()!=0))
    {
        if(game->getLamp()->getPrice()<=game->getMoney())
        {
            game->getMixedCoalMine()->getOneMiner(whichMixed)->setLamp(game->getLamp());
            game->subMoney(game->getLamp()->getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
            game->setLamp(game->generateLamp());
            showNewMinerClothes();
            displayMixedMineMinersList();
        }
        else
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok");
        }
    }
    else
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
}

void MainWindow::on_closeBtn_clicked()
{

}

void MainWindow::on_hireNewBtn_clicked()
{
    NewMinerUI newDialog(this, game);
    newDialog.setModal(true);
    if(newDialog.exec()==QDialog::Accepted)
    {
        displayBlackMineMinersList();
        displayBrownMineMinersList();
        displayMixedMineMinersList();
    }
}

void MainWindow::on_aboveUIBtn_clicked()
{
    AboveGroundUI newDialog(this, game);
    newDialog.setModal(true);
    if(newDialog.exec()==QDialog::Accepted)
    {
        ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game->getMoney())+"$"));
    }

}
