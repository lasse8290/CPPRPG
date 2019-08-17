#pragma once

#include "Item.h"

class Weapon : 
    public Item
{
private:
    int playerDamage;
    int playerDamageMax;

public:
    Weapon(
        int playerDamage,
        int playerDamageMax,
        std::string name,
        unsigned type,
        unsigned rarity,
        unsigned value);
    virtual ~Weapon();

    //Accessors

    inline const int& getDamageMin() const { return this->playerDamage; }
    inline const int& getDamageMax() const { return this->playerDamageMax; }

    //Modifiers

};
