#ifndef DAMAGEDIALOG_H
#define DAMAGEDIALOG_H

#include <QDialog>
#include "unit.h"

namespace Ui {
class DamageDialog;
}

class DamageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DamageDialog(const QVector<Unit>& targets, QWidget *parent = nullptr);
    ~DamageDialog();

    int getTarget() const{return index;}
    int getDmg() const{return dmg;}
    int getLoc() const{return loc;}

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DamageDialog *ui;
    QVector<Unit> units;
    int index, dmg, loc;
};

#endif // DAMAGEDIALOG_H
