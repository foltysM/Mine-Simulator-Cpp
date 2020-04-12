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

    // UI init starts from here
    ui->setupUi(this);
    showNewMinerClothes();
    ui->progressBar->setValue(0);
    ui->labelMoneyMain->setText(QString::fromStdString("0$"));
    showNewMinerList(game.getMinersList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextMonth()
{
    if(months_overall==game.getMonths())
    {
        //Todo koniec gry
    }else{
        ui->progressBar->setValue((game.getMonths()*100)/months_overall);
    }
    // miners seniority up
    //TODO jakos to polimorfizmem, bo nie dzialalo wczesniej
    blackCoalMine.upSeniority();
    mixedCoalMine.upSeniority();
    brownCoalMine.upSeniority();
    displayBlackMineMinersList();
    displayBrownMineMinersList();
    displayMixedMineMinersList();
    game.setSeason();
    newMonthDialog = new NewMonthDialog(this);
    newMonthDialog->initData(blackCoalMine.coalMined(),brownCoalMine.coalMined(),mixedCoalMine.coalMined(),game,game.getMoney());
    newMonthDialog->show();

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
    if(brownCoalMine.miners.size()!=0)
    {
        ui->labelNameBrown->setText(QString::fromStdString(brownCoalMine.miners[whichBrown].getName()));
        ui->labelKidsBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getKids())); // kids
        ui->labelSalaryBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getSalaryAmount())); // salary
        ui->labelProdBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getProductivity())); // productivity
        ui->labelStrikOpBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getSeniority())); // seniority
        if(brownCoalMine.miners[whichBrown].getUnion()==true)         // union
            ui->labelUnionBrown->setText("Yes");
        else
            ui->labelUnionBrown->setText("No");
        ui->labelHatBrown->setText(QString::fromStdString(brownCoalMine.miners[whichBrown].getHat().getName()));
        ui->labelHatSalaryBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getHat().getSalaryReduction()));
        ui->labelSuitBrown->setText(QString::fromStdString(brownCoalMine.miners[whichBrown].getSuit().getName()));
        ui->labelSalarySuitBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getSuit().getSalaryReduction()));
        ui->labelProductivitySuitBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getSuit().getAdditionalProductivity()));
        ui->labelLampBrown->setText(QString::fromStdString(brownCoalMine.miners[whichBrown].getLamp().getName()));
        ui->labelProductivityLampBrown->setText(QString::number(brownCoalMine.miners[whichBrown].getLamp().getAdditionalProductivity()));
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
}

void MainWindow::displayBlackMineMinersList()
{
    if(blackCoalMine.miners.size()!=0)
    {
        ui->labelNameBlack->setText(QString::fromStdString(blackCoalMine.miners[whichBlack].getName()));
        ui->labelKidsBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getKids())); // kids
        ui->labelSalaryBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getSalaryAmount())); // salary
        ui->labelProdBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getProductivity())); // productivity
        ui->labelStrikOpBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getSeniority()));
        if(blackCoalMine.miners[whichBlack].getUnion()==true)         // union
            ui->labelUnionBlack->setText("Yes");
        else
            ui->labelUnionBlack->setText("No");
        ui->labelHatBlack->setText(QString::fromStdString(blackCoalMine.miners[whichBlack].getHat().getName()));
        ui->labelSalaryHatBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getHat().getSalaryReduction()));
        ui->labelSuitBlack->setText(QString::fromStdString(blackCoalMine.miners[whichBlack].getSuit().getName()));
        ui->labelSalarySuitBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getSuit().getSalaryReduction()));
        ui->labelProdSuitBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getSuit().getAdditionalProductivity()));
        ui->labelLampBlack->setText(QString::fromStdString(blackCoalMine.miners[whichBlack].getLamp().getName()));
        ui->labelProdLampBlack->setText(QString::number(blackCoalMine.miners[whichBlack].getLamp().getAdditionalProductivity()));
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
}

void MainWindow::displayMixedMineMinersList()
{
    if(mixedCoalMine.miners.size()!=0)
    {
        ui->labelNameMixed->setText(QString::fromStdString(mixedCoalMine.miners[whichMixed].getName()));
        ui->labelKidsMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getKids())); // kids
        ui->labelSalaryMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getSalaryAmount())); // salary
        ui->labelProdMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getProductivity())); // productivity
        ui->labelStrikOpMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getStrikeOpportunity())); // strike opp
        ui->labelSeniorityMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getSeniority()));
        if(mixedCoalMine.miners[whichMixed].getUnion() == true)         // union
            ui->labelUnionMixed->setText("Yes");
        else
            ui->labelUnionMixed->setText("No");
        ui->labelHatMixed->setText(QString::fromStdString(mixedCoalMine.miners[whichMixed].getHat().getName()));
        ui->labelSalaryHatMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getHat().getSalaryReduction()));
        ui->labelSuitMixed->setText(QString::fromStdString(mixedCoalMine.miners[whichMixed].getSuit().getName()));
        ui->labelSalarySuitMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getSuit().getSalaryReduction()));
        ui->labelProdSuitMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getSuit().getAdditionalProductivity()));
        ui->labelLampMixed->setText(QString::fromStdString(mixedCoalMine.miners[whichMixed].getLamp().getName()));
        ui->labelProdLampMixed->setText(QString::number(mixedCoalMine.miners[whichMixed].getLamp().getAdditionalProductivity()));
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
            whichBrown = brownCoalMine.miners.size()-1;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_minerListRightBtnBrown_clicked()
{
    whichBrown++;
        if(whichBrown == (int)brownCoalMine.miners.size())
        {
            whichBrown=0;
        }
    displayBrownMineMinersList();
}

void MainWindow::on_newToBlackBtn_clicked()
{
    blackCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayBlackMineMinersList();
    showNewMinerList(game.getMinersList());
}

void MainWindow::on_newToBrownBtn_clicked()
{
    brownCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayBrownMineMinersList();
    showNewMinerList(game.getMinersList());
    // TODO odswiezanie i wyswietlanie liczby gornikow
}

void MainWindow::on_newToUranBtn_clicked()
{
    mixedCoalMine.miners.push_back(game.getMinersList()[which]);
    game.eraseMiner(which);
    displayMixedMineMinersList();
    showNewMinerList(game.getMinersList());
}

void MainWindow::on_disFrBrBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        brownCoalMine.miners.erase(brownCoalMine.miners.begin()+whichBrown);
    displayBrownMineMinersList();
}

void MainWindow::on_disFrBlBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        blackCoalMine.miners.erase(blackCoalMine.miners.begin()+whichBlack);
    displayBlackMineMinersList();
}

void MainWindow::on_minerListLeftBtnMixed_clicked()
{
    whichMixed--;
        if(whichMixed==-1)
        {
            whichMixed = mixedCoalMine.miners.size()-1;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_minerListRightBtnMixed_clicked()
{
    whichMixed++;
        if(whichMixed == (int)mixedCoalMine.miners.size())
        {
            whichMixed=0;
        }
    displayMixedMineMinersList();
}

void MainWindow::on_DisFrMBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        mixedCoalMine.miners.erase(mixedCoalMine.miners.begin()+whichMixed);
    displayMixedMineMinersList();
}

void MainWindow::on_minerListLeftBtnBlack_clicked()
{
    whichBlack--;
        if(whichBlack==-1)
        {
            whichBlack = blackCoalMine.miners.size()-1;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_minerListRightBtnBlack_clicked()
{
    whichBlack++;
        if(whichBlack == (int)blackCoalMine.miners.size())
        {
            whichBlack=0;
        }
    displayBlackMineMinersList();
}

void MainWindow::on_FrBrtoMBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        mixedCoalMine.miners.push_back(brownCoalMine.miners[whichBrown]);
        brownCoalMine.miners.erase(brownCoalMine.miners.begin()+whichBrown);
        whichMixed = mixedCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayMixedMineMinersList();
}

void MainWindow::on_FrBrToBlBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        blackCoalMine.miners.push_back(brownCoalMine.miners[whichBrown]);
        brownCoalMine.miners.erase(brownCoalMine.miners.begin()+whichBrown);
        whichBlack = blackCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToBBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        brownCoalMine.miners.push_back(blackCoalMine.miners[whichBlack]);
        blackCoalMine.miners.erase(blackCoalMine.miners.begin()+whichBlack);
        whichBrown = brownCoalMine.miners.size()-1;
    }
    displayBrownMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrBlToMxBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        mixedCoalMine.miners.push_back(blackCoalMine.miners[whichBlack]);
        blackCoalMine.miners.erase(blackCoalMine.miners.begin()+whichBlack);
        whichMixed = mixedCoalMine.miners.size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBlBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        blackCoalMine.miners.push_back(mixedCoalMine.miners[whichMixed]);
        mixedCoalMine.miners.erase(mixedCoalMine.miners.begin()+whichMixed);
        whichBlack = blackCoalMine.miners.size()-1;
    }
    displayMixedMineMinersList();
    displayBlackMineMinersList();
}

void MainWindow::on_FrMToBrBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot move a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
    {
        brownCoalMine.miners.push_back(mixedCoalMine.miners[whichMixed]);
        mixedCoalMine.miners.erase(mixedCoalMine.miners.begin()+whichMixed);
        whichBrown = brownCoalMine.miners.size()-1;
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
    if(blackCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        blackCoalMine.miners[whichBlack].setHat(game.getHat());
        game.setHat(game.generateHat());
        showNewMinerClothes();
        displayBlackMineMinersList();
    }
}

void MainWindow::on_buySuitBlackBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        blackCoalMine.miners[whichBlack].setSuit(game.getSuit());
        game.setSuit(game.generateSuit());
        showNewMinerClothes();
        displayBlackMineMinersList();
    }
}

void MainWindow::on_buyLampBlackBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        blackCoalMine.miners[whichBlack].setLamp(game.getLamp());
        game.setLamp(game.generateLamp());
        showNewMinerClothes();
        displayBlackMineMinersList();
    }
}

void MainWindow::on_buyHatBrownBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        brownCoalMine.miners[whichBrown].setHat(game.getHat());
        game.setHat(game.generateHat());
        showNewMinerClothes();
        displayBrownMineMinersList();
    }
}

void MainWindow::on_buySuitBrownBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        brownCoalMine.miners[whichBrown].setSuit(game.getSuit());
        game.setSuit(game.generateSuit());
        showNewMinerClothes();
        displayBrownMineMinersList();
    }
}

void MainWindow::on_buyLampBrownBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        brownCoalMine.miners[whichBrown].setLamp(game.getLamp());
        game.setLamp(game.generateLamp());
        showNewMinerClothes();
        displayBrownMineMinersList();
    }
}

void MainWindow::on_buyHatMixedBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a hat, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        mixedCoalMine.miners[whichMixed].setHat(game.getHat());
        game.setHat(game.generateHat());
        showNewMinerClothes();
        displayMixedMineMinersList();
    }
}

void MainWindow::on_buySuitMixedBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a suit, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        mixedCoalMine.miners[whichMixed].setSuit(game.getSuit());
        game.setSuit(game.generateSuit());
        showNewMinerClothes();
        displayMixedMineMinersList();
    }
}

void MainWindow::on_buyLampMixedBtn_clicked()
{
    if(mixedCoalMine.miners.size()==0)
    {
        QMessageBox::warning(this, "WARNING", "You cannot buy a lamp, because 0 miners work there.", "Ok, I'll never do that again");
    }
    else
    {
        mixedCoalMine.miners[whichMixed].setLamp(game.getLamp());
        game.setLamp(game.generateLamp());
        showNewMinerClothes();
        displayMixedMineMinersList();
    }
}
