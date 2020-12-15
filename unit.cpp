#include "unit.h"

Unit::Unit(QObject *parent) : QObject(parent)
{
    name = "";
    for(int i = 0; i < 100; i++)
        armor[i] = 0;
}

Unit::Unit(const QString &name, const int hp, const int initiative, QObject *parent) : QObject(parent)
{
    this->name = name;
    this->hp = hp;
    this->initiative = initiative;

    for(int i = 0; i < 100; i++)
        armor[i] = 0;
}

Unit::Unit(const QString &name, const int initiative, const int hp, const int wt, const int zr, const int armorH, const int armorLH, const int armorLL, const int armorB, const int armorRH, const int armorRL, QObject *parent) : QObject(parent)
{
    this->name = name;
    this->hp = hp; this->wt = wt; this->zr = zr;
    this->initiative = zr + initiative;

    for (int i = 0; i < 100; i++)
    {
        if (i >= 1 && i <= 15)
            armor[i] = armorH;
        else if (i >= 16 && i <= 35)
            armor[i] = armorLH;
        else if (i >= 36 && i <= 55)
            armor[i] = armorLL;
        else if (i >= 56 && i <= 80)
            armor[i] = armorB;
        else if (i >= 81 && i <= 90)
            armor[i] = armorRH;
        else
            armor[i] = armorRL;
    }
}

Unit::Unit(const Unit& unit)
{
    this->name = unit.name;
    this->hp = unit.hp;
    this->wt = unit.wt;
    this->zr = unit.zr;
    this->initiative = unit.initiative;

    for(int i = 0; i < 100; ++i)
    {
        armor[i] = unit.armor[i];
    }

}

Unit& Unit::operator=(const Unit &unit)
{
    this->name = unit.name;
    this->hp = unit.hp;
    this->wt = unit.wt;
    this->zr = unit.zr;
    this->initiative = unit.initiative;

    for(int i = 0; i < 100; ++i)
    {
        armor[i] = unit.armor[i];
    }
    return *this;
}

void Unit::TakeDmg(int dmg, int location)
{
    if(location == 100)
        location = 0;

    int penetration;
    if((penetration = dmg - wt - armor[location]) < 0)
        penetration = 0;

    hp -= penetration;
}

