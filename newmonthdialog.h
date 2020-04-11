#ifndef NEWMONTHDIALOG_H
#define NEWMONTHDIALOG_H

#include <QDialog>
#include "game.h"

namespace Ui {
class NewMonthDialog;
}

class NewMonthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMonthDialog(QWidget *parent = nullptr);
    ~NewMonthDialog();
    void initData(double bl, double br, double mx, Game g);

private slots:
    void on_acceptButton_clicked();

private:
    Ui::NewMonthDialog *ui;
};

#endif // NEWMONTHDIALOG_H
