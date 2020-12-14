#include "unit.h"

Unit::Unit(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 100; i++)
        armor[i] = 0;
}

Unit::Unit(const QString &name, const int initiative, QObject *parent)
{
    this->name = name;
    this->initiative = initiative;

    for(int i = 0; i < 100; i++)
        armor[i] = 0;
}

Unit::Unit(const QString &name, const int initiative, const int hp, const int wt, const int zr, const int armorH, const int armorLH, const int armorLL, const int armorB, const int armorRH, const int armorRL, QObject *parent)
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

void Unit::SetInit(int k10)
{
    initiative = zr + k10;
}

void Unit::TakeDmg(int dmg, int location)
{
    if(location == 100)
        location = 0;

    hp -= (dmg - wt - armor[location]);
}

