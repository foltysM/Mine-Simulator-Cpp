#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    list.generateMinerList();
    vectorMiners = list.getMinersList();
    // UI init starts from here
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    showNewMinerList(vectorMiners);
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
    // TODO dzialanie po nastepnym miesiacu
    // TODO WYWOLANIE OKNA Z WYBOREM CO Z WEGLEM

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
        if(brownCoalMine.miners[whichBrown].getUnion()==true)         // union
            ui->labelUnionBrown->setText("Yes");
        else
            ui->labelUnionBrown->setText("No");
    }else{
        ui->labelNameBrown->setText("No miner");
        ui->labelKidsBrown->setText("No data"); // kids
        ui->labelSalaryBrown->setText("No data"); // salary
        ui->labelProdBrown->setText("No data"); // productivity
        ui->labelStrikOpBrown->setText("No data"); // strike opp
        ui->labelUnionBrown->setText("No data");
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
        if(blackCoalMine.miners[whichBlack].getUnion()==true)         // union
            ui->labelUnionBlack->setText("Yes");
        else
            ui->labelUnionBlack->setText("No");
    }else{
        ui->labelNameBlack->setText("No miner");
        ui->labelKidsBlack->setText("No data"); // kids
        ui->labelSalaryBlack->setText("No data"); // salary
        ui->labelProdBlack->setText("No data"); // productivity
        ui->labelStrikOpBlack->setText("No data"); // strike opp
        ui->labelUnionBlack->setText("No data");
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
        if(mixedCoalMine.miners[whichMixed].getUnion() == true)         // union
            ui->labelUnionMixed->setText("Yes");
        else
            ui->labelUnionMixed->setText("No");
    }else{
        ui->labelNameMixed->setText("No miner");
        ui->labelKidsMixed->setText("No data"); // kids
        ui->labelSalaryMixed->setText("No data"); // salary
        ui->labelProdMixed->setText("No data"); // productivity
        ui->labelStrikOpMixed->setText("No data"); // strike opp
        ui->labelUnionMixed->setText("No data");
    }
}

void MainWindow::on_minerListLeftBtn_2_clicked()
{
    which--;
    if (which==-1)
        which=9;
    showNewMinerList(vectorMiners);
}

void MainWindow::on_minerListRightBtn_2_clicked()
{
    which++;
    if(which==10)
        which=0;
    showNewMinerList(vectorMiners);

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
    blackCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);    
    displayBlackMineMinersList();
    // TODO uzupelnianie do 10 ponownie
    // Odświeżenie listy do wyboru po usunięciu
}

void MainWindow::on_newToBrownBtn_clicked()
{
    brownCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);
    displayBrownMineMinersList();
    // TODO uzupelnianie do 10 ponownie
    // Odświeżenie listy do wyboru po usunięciu
}

void MainWindow::on_newToUranBtn_clicked()
{
    mixedCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);
    displayMixedMineMinersList();
    // TODO uzupelnianie do 10 ponownie
    // Odświeżenie listy do wyboru po usunięciu
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
