pragma once

#include "Header.h"

class Weapons
{



      public:

          //Available weapon id's and types..
          std::string weapName, id, type;
          std::vector<std::string> weapNames;
          std::vector<std::string> playerName;

          //Weapon Stats.
          int durability, physDmg, magDmg, fireDmg, poisDmg, lifeSteal, attackSpeed;



}
