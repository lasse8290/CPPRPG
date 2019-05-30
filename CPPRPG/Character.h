#pragma once

#include "Header.h"

class Character
{


    public:
        Character();

        //Available special races & names.
        std::string name, race, sex;
        std::vector<std::string> playerRace;
        std::vector<std::string> playerName;

        //Basic stats.
        int level, XP, health, totalHealth, maxHealth, nextLevel, heal, MP, healMP, totalMP, maxMP;

        void characterCreation();

};