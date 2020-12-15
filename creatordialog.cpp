#include "creatordialog.h"
#include "ui_creatordialog.h"

#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>

CreatorDialog::CreatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatorDialog)
{
    ui->setupUi(this);
}

CreatorDialog::~CreatorDialog()
{
    delete ui;
}

void CreatorDialog::on_okButton_clicked()
{
    bool notValid = false;
    bool ok = true;

    name = ui->nameBox->text();
    if(ui->nameBox->text().isEmpty())
        notValid = true;
    hp = ui->hpBox->text().toInt(&ok);
    if(!ok || ui->hpBox->text().isEmpty())
        notValid = true;
    wt = ui->wtBox->text().toInt(&ok);
    if(!ok || ui->wtBox->text().isEmpty())
        notValid = true;
    zr = ui->zrBox->text().toInt(&ok);
    if(!ok || ui->zrBox->text().isEmpty())
        notValid = true;
    k10 = ui->k10Box->text().toInt(&ok);
    if(!ok || ui->k10Box->text().isEmpty())
        notValid = true;
    count = ui->countBox->value();

    armorH = ui->armorHBox->text().toInt(&ok);
    if(!ok || ui->armorHBox->text().isEmpty())
        notValid = true;
    armorRH = ui->armorRHBox->text().toInt(&ok);
    if(!ok || ui->armorRHBox->text().isEmpty())
        notValid = true;
    armorRL = ui->armorRLBox->text().toInt(&ok);
    if(!ok || ui->armorRLBox->text().isEmpty())
        notValid = true;
    armorB = ui->armorBBox->text().toInt(&ok);
    if(!ok || ui->armorBBox->text().isEmpty())
        notValid = true;
    armorLH = ui->armorLHBox->text().toInt(&ok);
    if(!ok || ui->armorLHBox->text().isEmpty())
        notValid = true;
    armorLL = ui->armorLLBox->text().toInt(&ok);
    if(!ok || ui->armorLLBox->text().isEmpty())
        notValid = true;

    if(!notValid)
        accept();
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("Warning"),
                           tr("Values must be an integer type"), QMessageBox::StandardButtons(), this);
        msgBox.exec();
    }
}

void CreatorDialog::on_loadButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Load unit"), "", tr("(*.ini);;All Files (*)"));

    QSettings settings(path, QSettings::IniFormat);
    ui->nameBox->setText(settings.value("name", "").toString());
    ui->hpBox->setText(settings.value("zyw", "").toString());
    ui->wtBox->setText(settings.value("wt", "").toString());
    ui->zrBox->setText(settings.value("zr", "").toString());

    ui->armorHBox->setText(settings.value("armorH", "").toString());
    ui->armorRHBox->setText(settings.value("armorRH", "").toString());
    ui->armorRLBox->setText(settings.value("armorRL", "").toString());
    ui->armorBBox->setText(settings.value("armorB", "").toString());
    ui->armorLHBox->setText(settings.value("armorLH", "").toString());
    ui->armorLLBox->setText(settings.value("armorLL", "").toString());


}
