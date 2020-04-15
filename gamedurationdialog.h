#ifndef GAMEDURATIONDIALOG_H
#define GAMEDURATIONDIALOG_H

#include <QDialog>

namespace Ui {
class GameDurationDialog;
}

class GameDurationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDurationDialog(QWidget *parent = nullptr, int y = 0);
    ~GameDurationDialog();
    void initData(int m);
    int getMonths();
    int *y;

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameDurationDialog *ui;
};

#endif // GAMEDURATIONDIALOG_H
