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
    Unit(QObject *parent = nullptr);
    Unit(const QString& name, const int hp, const int initiative, QObject* parent = nullptr);
    Unit(const QString& name, const int initiative, const int hp, const int wt, const int zr
                  , const int armorH, const int armorLH, const int armorLL, const int armorB, const int armorRh, const int armorRl
                  , QObject* parent = nullptr);

    Unit(const Unit& unit);

    Unit& operator= (const Unit& unit);
    bool operator< (const Unit& other) const {return other.initiative < initiative;}

    void TakeDmg(int dmg, int location);


    QString getName() const{return name;}
    void setName(const QString &name){if(this->name != name){this->name = name;}}

    int getHp() const{return hp;}
    void setHp(int value){hp = value;}

    int getInitiative() const{return initiative;}
    void setInitiative(int init) {initiative = init;}

    int getWt() const{return wt;}
    void setWt(int w) {wt = w;}

    int getZr() const{return zr;}
    void setZr(int z) {zr = z;}

    std::array<int, 100> getArmor() const{return armor;}

    void setHArmor(int a)
    {
        for (int i = 1; i <= 15 ; i++)
                armor[i] = a;
    }
    void setRHArmor(int a)
    {
        for (int i = 16; i <= 35 ; i++)
                armor[i] = a;
    }
    void setRLArmor(int a)
    {
        for (int i = 81; i <= 90 ; i++)
                armor[i] = a;
    }
    void setBArmor(int a)
    {
        for (int i = 56; i <= 80 ; i++)
                armor[i] = a;
    }
    void setLHArmor(int a)
    {
        for (int i = 36; i <= 55 ; i++)
                armor[i] = a;
    }
    void setLLArmor(int a)
    {
        for (int i = 91; i <= 99 ; i++)
                armor[i] = a;
        armor[0] = a;
    }





signals:

private:
    QString name;
    std::array<int, 100> armor;
    int hp = 0, wt = 0, zr = 0;
    int initiative = 30;

};

Q_DECLARE_METATYPE(Unit)

#endif // UNIT_H
