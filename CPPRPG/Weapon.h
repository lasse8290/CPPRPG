#include "Header.h"
#include "Item.h"

class Weapon :
	public Item
{
private:
	int playerDamage;
	int playerDamageMax;

public:
	Weapon();
	Weapon(
		int level, 
		int rarity
	);
	Weapon(
		int damageMin, 
		int damageMax,
		std::string name, 
		int level, 
		int buyValue, 
		int sellValue, 
		int rarity);
	virtual ~Weapon();

	//Pure virtual
	virtual Weapon* clone()const;

	//Functions
	std::string toString()const;
	std::string toStringSave()const;

	//Accessors
	inline int getDamageMin()const { return this->playerDamage; }
	inline int getDamageMax()const { return this->playerDamageMax; }

	//Modifiers

	//Static
	static dArr<std::string> names;
	static void initNames();
};