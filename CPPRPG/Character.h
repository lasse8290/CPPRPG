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
        int health, totalHealth, maxHealth, heal, MP, healMP, totalMP, maxMP;
        int level, current_XP, base_XP, XP_to_level, minLevel, maxLevel;

        void characterCreation();

};