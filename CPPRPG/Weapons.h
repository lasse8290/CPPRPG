pragma once

#include "Items.h"

class Weapons
 : public Item
{



      public:
          //Available weapon name.
          Weapon(const std::string& name, int id)
           : Item(name, id) { }


          //Weapon Stats.
          virtual int dur(void) const = 0, maxDur(void) const = 0, physDmg(void) const = 0, magDmg(void) const = 0, fireDmg(void) const = 0, poisDmg(void) const = 0;
          virtual int lvlReq, hpReq, mpReq, weapType, weapId;
          virtual int lifeSteal(void) const = 0, attackSpeed(void) const = 0;


}
