#include "Weapons.h"


class ironSword : public Weapons
{

  public:
   ironSword : Weapons("Iron Sword", 0) { }
   virtual int dur(void) const { return 100 }, maxDur(void) const { return 100 },  physDmg(void) const { return 7 }, magDmg(void) const { return 0 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
   virtual int lvlReq(void) const { return 3 }, hpReq(void) { return 0}, mpReq(void) const { return 0 };
   virtual float lifeSteal(void) const { return 0 }, attackSpeed(void) const { return 1 };

} class executionersSword : public Weapons {

  public:
    executionersSword : Weapons("executionersSword", 1) { }
    virtual int dur(void) const { return 90 }, maxDur(void) const { return 90 },  physDmg(void) const { return 15 }, magDmg(void) const { return 0 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
    virtual int lvlReq(void) const { return 3 }, hpReq(void) { return 0}, mpReq(void) const { return 0 };
    virtual float lifeSteal(void) const { return 0.2 }, attackSpeed(void) const { return 0.7 };

}
