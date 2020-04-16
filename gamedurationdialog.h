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
    explicit GameDurationDialog(QWidget *parent = nullptr);
    ~GameDurationDialog();
    int getMonths();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameDurationDialog *ui;
};

#endif // GAMEDURATIONDIALOG_H
