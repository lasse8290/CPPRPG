#include "Weapon.h"

Weapon::Weapon(
    int playerDamage,
    int playerDamageMax,
    std::string name,
    unsigned type,
    unsigned rarity,
    unsigned value)
    : Item(name, type, rarity, value)
{
    this->playerDamage = playerDamage;
    this->playerDamageMax = playerDamageMax;
}

Weapon::~Weapon()
{

}

//Functions