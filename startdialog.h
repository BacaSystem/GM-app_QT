#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

    int getVInit() {return valahujr;}
    int getEInit() {return eldrill;}
    int getWInit() {return waldemar;}
    int getBInit() {return beatrix;}
    int getMInit() {return magnus;}

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StartDialog *ui;

    int valahujr;
    int eldrill;
    int waldemar;
    int beatrix;
    int magnus;
};

#endif // STARTDIALOG_H
