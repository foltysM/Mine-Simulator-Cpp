#include "gamedurationdialog.h"
#include "ui_gamedurationdialog.h"

GameDurationDialog::GameDurationDialog(QWidget *parent, int y) :
    QDialog(parent),
    ui(new Ui::GameDurationDialog)
{

    ui->setupUi(this);
}

GameDurationDialog::~GameDurationDialog()
{
    delete ui;
}

void GameDurationDialog::initData(int m)
{

}

int GameDurationDialog::getMonths()
{
    return ui->spinBox->value();
}

void GameDurationDialog::on_pushButton_clicked()
{
//    this->y = ui->spinBox->value();

}
