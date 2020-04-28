#ifndef ABOVEGROUNDUI_H
#define ABOVEGROUNDUI_H

#include <QDialog>
#include <QMessageBox>
#include "game.h"

namespace Ui {
class AboveGroundUI;
}

class AboveGroundUI : public QDialog
{
    Q_OBJECT

public:
    explicit AboveGroundUI(QWidget *parent = nullptr, Game *g = nullptr);
    ~AboveGroundUI();
private slots:
    void on_AccLeftBtn_clicked();

    void on_AccRightBtn_clicked();

    void on_OffLeftBtn_clicked();

    void on_OffRightBtn_clicked();

    void on_buyChairAccBtn_clicked();

    void on_buyDeskAccBtn_clicked();

    void on_BuyComputerAccBtn_clicked();

    void on_buyChairOffBtn_clicked();

    void on_buyDeskOffBtn_clicked();

    void on_buyComputerOffBtn_clicked();

private:
    Ui::AboveGroundUI *ui;
    void displayAccList();
    void displayOffList();
    Game *game;
    int which_acc = 0;
    int which_off = 0;
};

#endif // ABOVEGROUNDUI_H
