#pragma once

#include "Header.h"

class Character
{
public:

    Character();

    std::string name, race, sex;
    std::vector<std::string> playerRace;
    int level, XP, health, totalHealth, maxHealth, nextLevel, heal;

    void characterCreation();

};

