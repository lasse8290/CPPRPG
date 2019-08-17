#include"Weapon.h"

dArr<std::string> Weapon::names;

void Weapon::initNames()
{
	Weapon::names.push("Butter-Knife");
	Weapon::names.push("Leaf-Cutter");
	Weapon::names.push("Face-Shredder");
	Weapon::names.push("Bro-Knife");
	Weapon::names.push("Katana-Sword");
	Weapon::names.push("Brutal-Murder");
}

Weapon::Weapon()
	:Item()
{
	this->playerDamageMax = 0;
	this->playerDamage = 0;
}

Weapon::Weapon(int level, int rarity)
	:Item(itemTypes::WEAPON, level, rarity)
{
	this->playerDamageMax = rand() % level * (rarity+1);
	this->playerDamageMax += (rarity+1) * 5;
	this->setName(Weapon::names[rand() % Weapon::names.size()]);

	if (rarity == 3)
		this->playerDamageMax += level * 5;
	else if (rarity == 4)
		this->playerDamageMax += level * 10;

	this->playerDamage = this->playerDamageMax / 2;
}

Weapon::Weapon(int damageMin, int damageMax, std::string name, int level, int buyValue, int sellValue, int rarity)
	: Item(itemTypes::WEAPON, name, level, buyValue, sellValue, rarity)
{
	this->playerDamage = playerDamage;
	this->playerDamageMax = playerDamageMax;
}

Weapon::~Weapon()
{

}

Weapon* Weapon::clone()const
{
	return new Weapon(*this);
}

std::string Weapon::toString()const
{
	std::string str =
		this->getName()
		+ " | Lvl: "
		+ std::to_string(this->getLevel())
		+ " | Rarity: "
		+ std::to_string(this->getRarity())
		+ " | Damage: "
		+ std::to_string(this->playerDamage)
		+ " - "
		+ std::to_string(this->playerDamageMax);

	return str;
}

std::string Weapon::toStringSave()const
{
	std::string str =
		std::to_string(this->getItemType())
		+ " "
		+ this->getName()
		+ " "
		+ std::to_string(this->getLevel())
		+ " "
		+ std::to_string(this->getRarity())
		+ " "
		+ std::to_string(this->getBuyValue())
		+ " "
		+ std::to_string(this->getSellValue())
		+ " "
		+ std::to_string(this->playerDamage)
		+ " "
		+ std::to_string(this->playerDamageMax)
		+ " ";

	return str;
}