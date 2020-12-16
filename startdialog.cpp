#include "startdialog.h"
#include "ui_startdialog.h"

#include <QMessageBox>

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_buttonBox_accepted()
{
    bool notValid = false;
    bool ok = true;

    valahujr = ui->vtext->text().toInt(&ok);
    if((!ok || ui->vtext->text().isEmpty()))
        notValid = true;
    eldrill = ui->eText->text().toInt(&ok);
    if((!ok || ui->eText->text().isEmpty()))
        notValid = true;
    waldemar = ui->wText->text().toInt(&ok);
    if((!ok || ui->wText->text().isEmpty()))
        notValid = true;
    beatrix = ui->bText->text().toInt(&ok);
    if((!ok || ui->bText->text().isEmpty()))
        notValid = true;
    magnus = ui->mText->text().toInt(&ok);
    if((!ok || ui->mText->text().isEmpty()))
        notValid = true;

    if(!notValid)
        accept();
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),
                           tr("Invalid arguments types! Please correct form."), QMessageBox::StandardButtons(), this);
        msgBox.exec();
    }
}
