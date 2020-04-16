#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    game.generateMinerList();
    MinerHat hat = game.generateHat();
    MinerSuit suit = game.generateSuit();
    MinerLamp lamp = game.generateLamp();

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
    showNewMinerList(game.getMinersList());

    game.setMoney(10000);
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextMonth()
{
    if(months_overall==game.getMonths())
    {
        // GAME END
        QString message = "It's the end of the game. In "+QString::number(months_overall)+" months You earned "+QString::number(game.getMoney())+"$";
        QMessageBox::information(this, "Congratulations!", message);
        exit(0);
    }else{
        ui->progressBar->setValue((game.getMonths()*100)/months_overall);
    }
    // miners seniority up
    game.blackCoalMine.upSeniority();
    game.mixedCoalMine.upSeniority();
    game.brownCoalMine.upSeniority();
    displayBlackMineMinersList();
    displayBrownMineMinersList();
    displayMixedMineMinersList();
    game.setSeason();


    // new dialog setup

    NewMonthDialog newDialog(this,game);
    newDialog.setModal(true);
    if(newDialog.exec()==QDialog::Accepted)
    {
        x = newDialog.getStorBlack();
        w = newDialog.getStorBrown();
        z = newDialog.getMoneyBack();

    }
    game.setLastMonthRevenues(z-game.getMoney());
    game.setMoney(z);
    game.storage.setBlackCoalAmount(x);
    game.storage.setBrownCoalAmount(w);

    ui->labelInStorageBlackMain->setNum(x);
    ui->labelInStorageBrownMain->setNum(w);

    game.createAcc();
    displayAccList();

    ui->labelMoneyMain->setText(QString::fromStdString("$"+std::to_string(game.getMoney())));

}

void MainWindow::on_nextMonthBtn_clicked()
{
     int m = game.getMonths();
     m++;
     game.setMonths(m);
     ui->labelMonths->setText(QString::number(game.getMonths()));
     nextMonth();     
}

void MainWindow::showNewMinerList(std::vector <Miner> vectorMiners)
{

    ui->labelName->setText(QString::fromStdString(vectorMiners[which].getName())); // name
    ui->labelKids->setText(QString::number(vectorMiners[which].getKids())); // kids
    ui->labelSalary->setText(QString::number(vectorMiners[which].getSalaryAmount())); // salary
    ui->labelProd->setText(QString::number(vectorMiners[which].getProductivity())); // productivity
    ui->labelStrikOp->setText(QString::number(vectorMiners[which].getStrikeOpportunity())); // strike opp
    if(vectorMiners[which].getUnion()==true)         // union
        ui->labelUnion->setText("Yes");
    else
        ui->labelUnion->setText("No");
}

void MainWindow::displayBrownMineMinersList()
{
    if(game.brownCoalMine.miners.size()!=0)
    {
        ui->labelNameBrown->setText(QString::fromStdString(game.brownCoalMine.miners[whichBrown].getName()));
        ui->labelKidsBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getKids())); // kids
        ui->labelSalaryBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getSalaryAmount())); // salary
        ui->labelProdBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getProductivity())); // productivity
        ui->labelStrikOpBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getSeniority())); // seniority
        if(game.brownCoalMine.miners[whichBrown].getUnion()==true)         // union
            ui->labelUnionBrown->setText("Yes");
        else
            ui->labelUnionBrown->setText("No");
        ui->labelHatBrown->setText(QString::fromStdString(game.brownCoalMine.miners[whichBrown].getHat().getName()));
        ui->labelHatSalaryBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getHat().getSalaryReduction()));
        ui->labelSuitBrown->setText(QString::fromStdString(game.brownCoalMine.miners[whichBrown].getSuit().getName()));
        ui->labelSalarySuitBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getSuit().getSalaryReduction()));
        ui->labelProductivitySuitBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getSuit().getAdditionalProductivity()));
        ui->labelLampBrown->setText(QString::fromStdString(game.brownCoalMine.miners[whichBrown].getLamp().getName()));
        ui->labelProductivityLampBrown->setText(QString::number(game.brownCoalMine.miners[whichBrown].getLamp().getAdditionalProductivity()));
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
    ui->labelMinersCountBrown->setText(QString::number(game.brownCoalMine.miners.size()));
}

void MainWindow::displayBlackMineMinersList()
{
    if(game.blackCoalMine.miners.size()!=0)
    {
        ui->labelNameBlack->setText(QString::fromStdString(game.blackCoalMine.miners[whichBlack].getName()));
        ui->labelKidsBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getKids())); // kids
        ui->labelSalaryBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getSalaryAmount())); // salary
        ui->labelProdBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getProductivity())); // productivity
        ui->labelStrikOpBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getSeniority()));
        if(game.blackCoalMine.miners[whichBlack].getUnion()==true)         // union
            ui->labelUnionBlack->setText("Yes");
        else
            ui->labelUnionBlack->setText("No");
        ui->labelHatBlack->setText(QString::fromStdString(game.blackCoalMine.miners[whichBlack].getHat().getName()));
        ui->labelSalaryHatBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getHat().getSalaryReduction()));
        ui->labelSuitBlack->setText(QString::fromStdString(game.blackCoalMine.miners[whichBlack].getSuit().getName()));
        ui->labelSalarySuitBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getSuit().getSalaryReduction()));
        ui->labelProdSuitBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getSuit().getAdditionalProductivity()));
        ui->labelLampBlack->setText(QString::fromStdString(game.blackCoalMine.miners[whichBlack].getLamp().getName()));
        ui->labelProdLampBlack->setText(QString::number(game.blackCoalMine.miners[whichBlack].getLamp().getAdditionalProductivity()));
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
    ui->labelMinersCountBlack->setText(QString::number(game.blackCoalMine.miners.size()));
}

void MainWindow::displayMixedMineMinersList()
{
    if(game.mixedCoalMine.miners.size()!=0)
    {
        ui->labelNameMixed->setText(QString::fromStdString(game.mixedCoalMine.miners[whichMixed].getName()));
        ui->labelKidsMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getKids())); // kids
        ui->labelSalaryMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getSalaryAmount())); // salary
        ui->labelProdMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getProductivity())); // productivity
        ui->labelStrikOpMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getSeniority()));
        if(game.mixedCoalMine.miners[whichMixed].getUnion() == true)         // union
            ui->labelUnionMixed->setText("Yes");
        else
            ui->labelUnionMixed->setText("No");
        ui->labelHatMixed->setText(QString::fromStdString(game.mixedCoalMine.miners[whichMixed].getHat().getName()));
        ui->labelSalaryHatMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getHat().getSalaryReduction()));
        ui->labelSuitMixed->setText(QString::fromStdString(game.mixedCoalMine.miners[whichMixed].getSuit().getName()));
        ui->labelSalarySuitMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getSuit().getSalaryReduction()));
        ui->labelProdSuitMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getSuit().getAdditionalProductivity()));
        ui->labelLampMixed->setText(QString::fromStdString(game.mixedCoalMine.miners[whichMixed].getLamp().getName()));
        ui->labelProdLampMixed->setText(QString::number(game.mixedCoalMine.miners[whichMixed].getLamp().getAdditionalProductivity()));
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
    ui->labelMinersCountMixed->setText(QString::number(game.mixedCoalMine.miners.size()));
}

void MainWindow::on_minerListLeftBtn_2_clicked()
{
    which--;
    if (which==-1)
        which=9;
    showNewMinerList(game.getMinersList());
}

void MainWindow::on_minerListRightBtn_2_clicked()
{
    which++;
    if(which==10)
        which=0;
    showNewMinerList(game.getMinersList());
}

void MainWindow::on_minerListLeftBtnBrown_clicked()
{
    whichBrown--;
        if(whichBrown==-1)
        {
            whichBrown = game.brownCoalMine.miners.size()-1;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_minerListRightBtnBrown_clicked()
{
    whichBrown++;
        if(whichBrown == (int)game.brownCoalMine.miners.size())
        {
            whichBrown=0;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_newToBlackBtn_clicked()
{
    game.blackCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayBlackMineMinersList();
    showNewMinerList(game.getMinersList());

    //office workers
    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_newToBrownBtn_clicked()
{
    game.brownCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayBrownMineMinersList();
    showNewMinerList(game.getMinersList());

    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_newToUranBtn_clicked()
{
    game.mixedCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayMixedMineMinersList();
    showNewMinerList(game.getMinersList());

    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_disFrBrBtn_clicked()
{
    if(game.brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game.brownCoalMine.miners.erase(game.brownCoalMine.miners.begin()+whichBrown);
    displayBrownMineMinersList();

    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_disFrBlBtn_clicked()
{
    if(game.blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game.blackCoalMine.miners.erase(game.blackCoalMine.miners.begin()+whichBlack);
    displayBlackMineMinersList();

    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_minerListLeftBtnMixed_clicked()
{
    whichMixed--;
        if(whichMixed==-1)
        {
            whichMixed = game.mixedCoalMine.miners.size()-1;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_minerListRightBtnMixed_clicked()
{
    whichMixed++;
        if(whichMixed == (int)game.mixedCoalMine.miners.size())
        {
            whichMixed=0;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_DisFrMBtn_clicked()
{
    if(game.mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        game.mixedCoalMine.miners.erase(game.mixedCoalMine.miners.begin()+whichMixed);
    displayMixedMineMinersList();

    game.refreshOfficeWorkersAmount();
    displayOffList();
}

void MainWindow::on_minerListLeftBtnBlack_clicked()
{
    whichBlack--;
        if(whichBlack==-1)
        {
            whichBlack = game.blackCoalMine.miners.size()-1;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_minerListRightBtnBlack_clicked()
{
    whichBlack++;
        if(whichBlack == (int)game.blackCoalMine.miners.size())
        {
            whichBlack=0;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_FrBrtoMBtn_clicked()
{
    if(game.brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.mixedCoalMine.miners.push_back(game.brownCoalMine.miners[whichBrown]);
        game.brownCoalMine.miners.erase(game.brownCoalMine.miners.begin()+whichBrown);
        whichMixed = game.mixedCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayMixedMineMinersList();
}

void MainWindow::on_FrBrToBlBtn_clicked()
{
    if(game.brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.blackCoalMine.miners.push_back(game.brownCoalMine.miners[whichBrown]);
        game.brownCoalMine.miners.erase(game.brownCoalMine.miners.begin()+whichBrown);
        whichBlack = game.blackCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToBBtn_clicked()
{
    if(game.blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.brownCoalMine.miners.push_back(game.blackCoalMine.miners[whichBlack]);
        game.blackCoalMine.miners.erase(game.blackCoalMine.miners.begin()+whichBlack);
        whichBrown = game.brownCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToMxBtn_clicked()
{
    if(game.blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.mixedCoalMine.miners.push_back(game.blackCoalMine.miners[whichBlack]);
        game.blackCoalMine.miners.erase(game.blackCoalMine.miners.begin()+whichBlack);
        whichMixed = game.mixedCoalMine.miners.size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBlBtn_clicked()
{
    if(game.mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.blackCoalMine.miners.push_back(game.mixedCoalMine.miners[whichMixed]);
        game.mixedCoalMine.miners.erase(game.mixedCoalMine.miners.begin()+whichMixed);
        whichBlack = game.blackCoalMine.miners.size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBrBtn_clicked()
{
    if(game.mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        game.brownCoalMine.miners.push_back(game.mixedCoalMine.miners[whichMixed]);
        game.mixedCoalMine.miners.erase(game.mixedCoalMine.miners.begin()+whichMixed);
        whichBrown = game.brownCoalMine.miners.size()-1;
    }
    displayMixedMineMinersList();
    displayBrownMineMinersList();
}

void MainWindow::showNewMinerClothes()
{
    ui->labelPsblHatName->setText(QString::fromStdString(game.getHat().getName()));
    ui->labelPsblHatSalary->setText(QString::number(game.getHat().getSalaryReduction()));
    ui->labelPsblHatPrice->setText(QString::number(game.getHat().getPrice()));
    ui->labelPsblSuitName->setText(QString::fromStdString(game.getSuit().getName()));
    ui->labelPsblSuitProd->setText(QString::number(game.getSuit().getAdditionalProductivity()));
    ui->labelPsblSuitSalary->setText(QString::number(game.getSuit().getSalaryReduction()));
    ui->labelPsblSuitPrice->setText(QString::number(game.getSuit().getPrice()));
    ui->labelPsblLampName->setText(QString::fromStdString(game.getLamp().getName()));
    ui->labelPsblLampProd->setText(QString::number(game.getLamp().getAdditionalProductivity()));
    ui->labelPsblLampPrice->setText(QString::number(game.getLamp().getPrice()));
}

void MainWindow::on_buyHatBlackBtn_clicked()
{
    if((game.blackCoalMine.miners.size()!=0))
    {
        if(game.getHat().getPrice()<=game.getMoney())
        {
            game.blackCoalMine.miners[whichBlack].setHat(game.getHat());
            game.subMoney(game.getHat().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setHat(game.generateHat());
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
    if((game.blackCoalMine.miners.size()!=0))
    {
        if(game.getSuit().getPrice()<=game.getMoney())
        {
            game.blackCoalMine.miners[whichBlack].setSuit(game.getSuit());
            game.subMoney(game.getSuit().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setSuit(game.generateSuit());
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
    if((game.blackCoalMine.miners.size()!=0))
    {
        if(game.getLamp().getPrice()<=game.getMoney())
        {
            game.blackCoalMine.miners[whichBlack].setLamp(game.getLamp());
            game.subMoney(game.getLamp().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setLamp(game.generateLamp());
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
    if((game.brownCoalMine.miners.size()!=0))
    {
        if(game.getHat().getPrice()<=game.getMoney())
        {
            game.brownCoalMine.miners[whichBrown].setHat(game.getHat());
            game.subMoney(game.getHat().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setHat(game.generateHat());
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
    if((game.brownCoalMine.miners.size()!=0))
    {
        if(game.getSuit().getPrice()<=game.getMoney())
        {
            game.brownCoalMine.miners[whichBrown].setSuit(game.getSuit());
            game.subMoney(game.getSuit().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setSuit(game.generateSuit());
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
    if((game.brownCoalMine.miners.size()!=0))
    {
        if(game.getLamp().getPrice()<=game.getMoney())
        {
            game.brownCoalMine.miners[whichBrown].setLamp(game.getLamp());
            game.subMoney(game.getLamp().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setLamp(game.generateLamp());
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
    if((game.mixedCoalMine.miners.size()!=0))
    {
        if(game.getHat().getPrice()<=game.getMoney())
        {
            game.mixedCoalMine.miners[whichMixed].setHat(game.getHat());
            game.subMoney(game.getHat().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setHat(game.generateHat());
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
    if((game.mixedCoalMine.miners.size()!=0))
    {
        if(game.getSuit().getPrice()<=game.getMoney())
        {
            game.mixedCoalMine.miners[whichMixed].setSuit(game.getSuit());
            game.subMoney(game.getSuit().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setSuit(game.generateSuit());
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
    if((game.mixedCoalMine.miners.size()!=0))
    {
        if(game.getLamp().getPrice()<=game.getMoney())
        {
            game.mixedCoalMine.miners[whichMixed].setLamp(game.getLamp());
            game.subMoney(game.getLamp().getPrice());
            ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
            game.setLamp(game.generateLamp());
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

void MainWindow::on_AccLeftBtn_clicked()
{
    which_acc--;
        if(which_acc==-1)
        {
            which_acc = game.vectorAccountants.size()-1;
        }
    displayAccList();
}

void MainWindow::on_AccRightBtn_clicked()
{
    which_acc++;
        if(which_acc == (int)game.vectorAccountants.size())
        {
            which_acc=0;
        }
    displayAccList();
}

void MainWindow::on_OffLeftBtn_clicked()
{
    which_off--;
        if(which_off==-1)
        {
            which_off = game.vectorOfficeWorkers.size()-1;
        }
    displayOffList();
}

void MainWindow::on_OffRightBtn_clicked()
{
    which_off++;
        if(which_off == (int)game.vectorOfficeWorkers.size())
        {
            which_off=0;
        }
    displayOffList();
}

void MainWindow::displayAccList()
{
    ui->labelAccSize->setNum((int)game.vectorAccountants.size());
    if((int)game.vectorAccountants.size()!=0)
    {
        ui->labelChairAcc->setNum(game.vectorAccountants[which_acc].getChair().getReduction());
        ui->labelComputerAcc->setNum(game.vectorAccountants[which_acc].getComputer().getReduction());
        ui->labelDeskAcc->setNum(game.vectorAccountants[which_acc].getDesk().getReduction());
    }else{
        ui->labelChairAcc->setText("No Accountant");
        ui->labelComputerAcc->setText("No Accountant");
        ui->labelDeskAcc->setText("No Accountant");
    }
}

void MainWindow::displayOffList()
{
    ui->labelOffSize->setNum((int)game.vectorOfficeWorkers.size());
    if((int)game.vectorOfficeWorkers.size()!=0)
    {
        ui->labelChairOff->setNum(game.vectorOfficeWorkers[which_off].getChair().getReduction());
        ui->labelDeskOff->setNum(game.vectorOfficeWorkers[which_off].getDesk().getReduction());
        ui->labelComputerOff->setNum(game.vectorOfficeWorkers[which_off].getComputer().getReduction());
    }else{
        ui->labelChairOff->setText("No office worker");
        ui->labelDeskOff->setText("No office worker");
        ui->labelComputerOff->setText("No office worker");
    }
}

void MainWindow::on_buyChairAccBtn_clicked()
{
    if((int)game.vectorAccountants.size()!=0)
    {
        if(game.getMoney()<1000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Chair chair;
            game.vectorAccountants[which_acc].setChair(chair);
            game.subMoney(1000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_buyDeskAccBtn_clicked()
{
    if((int)game.vectorAccountants.size()!=0)
    {
        if(game.getMoney()<3000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Desk desk;
            game.vectorAccountants[which_acc].setDesk(desk);
            game.subMoney(3000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_BuyComputerAccBtn_clicked()
{
    if((int)game.vectorAccountants.size()!=0)
    {
        if(game.getMoney()<5000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Computer computer;
            game.vectorAccountants[which_acc].setComputer(computer);
            game.subMoney(5000);
            displayAccList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Accountant", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_buyChairOffBtn_clicked()
{
    if((int)game.vectorOfficeWorkers.size()!=0)
    {
        if(game.getMoney()<1000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Chair chair;
            game.vectorOfficeWorkers[which_off].setChair(chair);
            game.subMoney(1000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_buyDeskOffBtn_clicked()
{
    if((int)game.vectorOfficeWorkers.size()!=0)
    {
        if(game.getMoney()<3000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Desk desk;
            game.vectorOfficeWorkers[which_off].setDesk(desk);
            game.subMoney(3000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_buyComputerOffBtn_clicked()
{
    if((int)game.vectorOfficeWorkers.size()!=0)
    {
        if(game.getMoney()<5000)
        {
            QMessageBox::warning(this, "WARNING", "You don't have enough money", "Ok.");
        }else{
            Computer computer;
            game.vectorOfficeWorkers[which_off].setComputer(computer);
            game.subMoney(5000);
            displayOffList();
        }
    }else{
        QMessageBox::warning(this, "WARNING", "There is no Office Worker", "Ok.");
    }
    ui->labelMoneyMain->setText(QString::fromStdString(std::to_string(game.getMoney())+"$"));
}

void MainWindow::on_closeBtn_clicked()
{

}
