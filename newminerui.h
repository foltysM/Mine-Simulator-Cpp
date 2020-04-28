#ifndef NEWMINERUI_H
#define NEWMINERUI_H

#include <QDialog>
#include "miner.h"
#include "game.h"

namespace Ui {
class NewMinerUI;
}

class NewMinerUI : public QDialog
{
    Q_OBJECT

public:
    explicit NewMinerUI(QWidget *parent = nullptr, Game *game = nullptr);
    ~NewMinerUI();
    void showNewMinerList(std::vector <Miner*> vectorMiners);
private slots:
    void on_newToBlackBtn_clicked();

    void on_newToBrownBtn_clicked();

    void on_newToUranBtn_clicked();

    void on_minerListLeftBtn_2_clicked();

    void on_minerListRightBtn_2_clicked();

private:
    Ui::NewMinerUI *ui;
    int which = 0;
    Game *game;
};

#endif // NEWMINERUI_H
