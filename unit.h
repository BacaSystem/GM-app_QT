#ifndef UNIT_H
#define UNIT_H

#include <QObject>

class Unit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(int hp READ getHp WRITE setHp)
    Q_PROPERTY(int init READ getInitiative)

public:
    explicit Unit(QObject *parent = nullptr);
    explicit Unit(const QString& name, const int initiative, QObject* parent = nullptr);
    explicit Unit(const QString& name, const int initiative, const int hp, const int wt, const int zr
                  , const int armorH, const int armorLH, const int armorLL, const int armorB, const int armorRh, const int armorRl
                  , QObject* parent = nullptr);

    explicit Unit(const Unit& unit);

    Unit& operator= (const Unit& unit);

    void SetInit(int k10);
    void TakeDmg(int dmg, int location);


    QString getName() const{return name;}
    void setName(const QString &name){if(this->name != name){this->name = name;}}

    int getHp() const{return hp;}
    void setHp(int value){hp = value;}

    int getInitiative() const{return initiative;}

signals:

private:
    QString name;
    int armor[100];
    int hp = 0, wt = 0, zr = 0;
    int initiative;

};

#endif // UNIT_H
