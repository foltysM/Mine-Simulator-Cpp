#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    list.generateMinerList();
    vectorMiners = list.getMinersList();


    ui->setupUi(this);
    wyswietlListeGornikow(vectorMiners);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextMonth() {

}


void MainWindow::on_nextMonthBtn_clicked()
{
    // auto mth = std::to_string(game.getMonths());
     int m = game.getMonths();
     m++;
     game.setMonths(m);
     ui->labelMonths->setText(QString::number(game.getMonths()));
     nextMonth();
}


void MainWindow::wyswietlListeGornikow(std::vector <Miner> vectorMiners)
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

void MainWindow::on_minerListLeftBtn_2_clicked()
{
    which--;
    if (which==-1)
        which=9;
    wyswietlListeGornikow(vectorMiners);
}

void MainWindow::on_minerListRightBtn_2_clicked()
{
    which++;
    if(which==10)
        which=0;
    wyswietlListeGornikow(vectorMiners);

}

void MainWindow::on_newToBlackBtn_clicked()
{
    blackCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);
    // TODO uzupelnianie do 10 ponownie
    // TODO odswieżenie nowej kopalni po przeniesieniu
    // Odświeżenie listy do wyboru po usunięciu
}

void MainWindow::on_newToBrownBtn_clicked()
{
    brownCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);
}

void MainWindow::on_newToUranBtn_clicked()
{
    mixedCoalMine.miners.push_back(vectorMiners[which]);
    vectorMiners.erase(vectorMiners.begin()+which);
}

void MainWindow::on_disFrBrBtn_clicked()
{
    if(brownCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        brownCoalMine.miners.erase(brownCoalMine.miners.begin()+whichBrown);
    //TODO odświeżenie widoku
}

void MainWindow::on_FrBrtoMBtn_clicked()
{

}

void MainWindow::on_FrBrToBlBtn_clicked()
{

}

void MainWindow::on_minerListLeftBtn_4_clicked()
{

}

void MainWindow::on_minerListRightBtn_4_clicked()
{

}

void MainWindow::on_minerListLeftBtn_3_clicked()
{

}

void MainWindow::on_disFrBlBtn_clicked()
{
    if(blackCoalMine.miners.size()==0)
        QMessageBox::warning(this, "WARNING", "You cannot dismiss a miner, because 0 miners work there.", "Ok, I'll never do that again");
    else
        blackCoalMine.miners.erase(blackCoalMine.miners.begin()+whichBlack);
    //TODO odswieżenie widoku

}


void MainWindow::on_minerListRightBtn_3_clicked()
{

}

void MainWindow::on_minerListLeftBtn_5_clicked()
{

}



void MainWindow::on_minerListRightBtn_5_clicked()
{

}
