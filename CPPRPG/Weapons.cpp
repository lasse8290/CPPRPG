#include "Weapons.h"


class ironSword
 : public Weapons
{

  public:
   ironSword : Weapons("Iron Sword", 0, "A Chipped and Battle-Used Sword.", 47) { };
   virtual int dur(void) const { return 100 }, maxDur(void) const { return 100 },  physDmg(void) const { return 7 }, magDmg(void) const { return 0 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
   virtual int lvlReq(void) const { return 2 }, hpReq(void) { return 0}, mpReq(void) const { return 0 };
   virtual float lifeSteal(void) const { return 0 }, attackSpeed(void) const { return 1 };

}

class saber
 : public Weapons
{

    public:
      saber : Weapons("Saber", 1, "A Light, Curved Sword.", 70) { };
      virtual int dur(void) const { return 90 }, maxDur(void) const { return 90 },  physDmg(void) const { return 9 }, magDmg(void) const { return 2 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
      virtual int lvlReq(void) const { return 3 }, hpReq(void) { return 0}, mpReq(void) const { return 0 };
      virtual float lifeSteal(void) const { return 0 }, attackSpeed(void) const { return 1.4 };

}

class executioners
 : public Weapons
{

  public:
    executioners : Weapons("Executioners Sword", 2, "A Heavy and Black Executioners Sword.", 120) { };
    virtual int dur(void) const { return 90 }, maxDur(void) const { return 90 },  physDmg(void) const { return 17 }, magDmg(void) const { return 0 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
    virtual int lvlReq(void) const { return 5 }, hpReq(void) { return 0}, mpReq(void) const { return 0 };
    virtual float lifeSteal(void) const { return 5 }, attackSpeed(void) const { return 0.7 };

}

class tradMace
 : public Weapons
 {

 public:
   tradMace : Weapons("Traditional Mace", 3, "A Mace used for Traditional Use.", 95) { };
   virtual int dur(void) const { return 120 }, maxDur(void) const { return 120 },  physDmg(void) const { return 13 }, magDmg(void) const { return 5 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
   virtual int lvlReq(void) const { return 4 }, hpReq(void) { return 0 }, mpReq(void) const { return 0 };
   virtual float lifeSteal(void) const { return 0 }, attackSpeed(void) const { return 1.4 };


 }

 class spikMace
  : public Weapons
  {

  public:
    spikMace : Weapons("A Spiked Mace", 3, "A Mace Fitted with Spikes.", 110) { };
    virtual int dur(void) const { return 110 }, maxDur(void) const { return 110 }, physDmg(void) const { return 15 }, magDmg(void) const { return 12 }, fireDmg(void) const { return 0 }, poisDmg(void) const { return 0 };
    virtual int lvlReq(void) const { return 6 }, hpReq(void) const { return 0 }, mpReq(void) const { 40 };
    virtual float lifeSteal(void) const { 0.5 }, attackSpeed(void) const { return 1.5 };
  }
