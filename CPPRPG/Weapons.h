pragma once

#include "Header.h"

class Weapons
{



      public:

        Weapons(const std::string& name, int id, int type)
        : weapName(name), weapId(id), weapType(type) { }

          //Available weapon names and types..
          std::string weapName;


          //Weapon Stats.
          virtual int dur(void) const = 0, maxDur(void) const = 0, physDmg(void) const = 0, magDmg(void) const = 0, fireDmg(void) const = 0, poisDmg(void) const = 0;
          virtual int lvlReq, hpReq, mpReq, weapType, weapId;
          virtual float lifeSteal(void) const = 0, attackSpeed(void) const = 0;



}
