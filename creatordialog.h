#ifndef CREATORDIALOG_H
#define CREATORDIALOG_H

#include <QDialog>

namespace Ui {
class CreatorDialog;
}

class CreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatorDialog(QWidget *parent = nullptr);
    ~CreatorDialog();

    QString getName() const{return name;}
    int getHp()      const{return hp;}
    int getWt()      const{return wt;}
    int getZr()      const{return zr;}
    int getK10()     const{return k10;}
    int getCount()   const{return count;}
    int getArmorH()  const{return armorH;}
    int getArmorRH() const{return armorRH;}
    int getArmorRL() const{return armorRL;}
    int getArmorB()  const{return armorB;}
    int getArmorLH() const{return armorLH;}
    int getArmorLL() const{return armorLL;}

private slots:
    void on_okButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::CreatorDialog *ui;

    QString name;
    int hp, wt, zr, k10, count;
    int armorH, armorRH, armorRL, armorB, armorLH, armorLL;
};

#endif // CREATORDIALOG_H
