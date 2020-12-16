#include "damagedialog.h"
#include "ui_damagedialog.h"

#include <qmessagebox.h>

DamageDialog::DamageDialog(const QVector<Unit>& targets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DamageDialog),
    units(targets)
{
    ui->setupUi(this);
    QStringList list;

    for (int i = 0; i < units.count(); i++) {
        list += units.at(i).getName();
    }
    ui->targetBox->addItems(list);
}

DamageDialog::~DamageDialog()
{
    delete ui;
}

void DamageDialog::on_buttonBox_accepted()
{
    bool notValid = false;
    bool ok = true;

    index = ui->targetBox->currentIndex();
    if(index < 0)
        notValid = true;
    dmg = ui->dmgBox->text().toInt(&ok);
    if((!ok || ui->dmgBox->text().isEmpty()))
        notValid = true;
    loc = ui->locationBox->text().toInt(&ok);
    if((!ok || ui->locationBox->text().isEmpty()))
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
