#include "gamedurationdialog.h"
#include "ui_gamedurationdialog.h"

GameDurationDialog::GameDurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDurationDialog)
{

    ui->setupUi(this);
}

GameDurationDialog::~GameDurationDialog()
{
    delete ui;
}

int GameDurationDialog::getMonths()
{
    return ui->spinBox->value();
}

void GameDurationDialog::on_pushButton_clicked()
{

}
