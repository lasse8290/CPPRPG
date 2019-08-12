#include "Header.h"
#include "Character.h"

// cd "d:\CPP\txtAdv\CPPRPG\CPPRPG\" && g++ -std=c++11 Main.cpp Character.cpp -o Main && "d:\CPP\txtAdv\CPPRPG\CPPRPG\Main"

void HUD();
void HUDcity();
void City();
void Combat();
void CombatHUD();
void Animation();
void Moving();
void CreateMonster();
void CreateTreasure();
void LevelUp();

int monsterHP = 0;
int monsterXP = 0;
int monsterLevel = 0;
int monsterGold = 0;

int treasureXP = 0;
int treasureGold = 0;

//Monster names, int amount.
std::string monsterName[] = { "Goblin", "Spider", "Troll", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
std::string currentMonster = " ";

int counter = 3;

Character character;

int main()
{

    srand(time(0));

    character.characterCreation();

    HUD();
    Moving();

    system("pause");

    return 0;

}

void HUD()
{
    //Our HUD for Name, Health, Race, Sex, Level.
    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      Health: " << character.totalHealth << "\nRace: " << character.race << "      MP: " << character.totalMP << "\nSex: " << character.sex << "      Gold: " << character.playerGold << "\nLevel: " << character.level << "\nXP: " << character.current_XP << "\nTotal XP required for Level-up: " << character.XP_to_level << std::endl;

    Moving();

}

void HUDcity()
{
    //Our HUD for Name, Health, Race, Sex, Level in the City.
    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      Health: " << character.totalHealth << "\nRace: " << character.race << "      MP: " << character.totalMP << "\nSex: " << character.sex << "      Gold: " << character.playerGold << "\nLevel: " << character.level << "\nXP: " << character.current_XP << "\nTotal XP required for Level-up: " << character.XP_to_level << std::endl;

    City();

}

void CombatHUD()
{

    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      |       Monster Name: " << currentMonster << "\nHealth: " << character.totalHealth << "    |       Monster Health: " <<
        monsterHP << "\nMP: " << character.totalMP << "      |       Monster Level: " << monsterLevel << "\nLevel: " << character.level << std::endl;

}

void Animation()
{

    std::cout << "" << std::endl;

}

void Combat()
{

    CombatHUD();
    Animation();
    int playerAttack;
    int playerSpell;
    int playerDamage = 8 * character.level / 2;
    int playerSpellDamage = 11 * character.level / 1.1;
    int monsterAttack = 6 * monsterLevel / 2;

    if (character.totalHealth <= 0) {
        character.totalHealth = 0;
        system("cls");
        std::cout << "You have been Slayed!\n\n" << character.race<< " " << character.name << " lvl" << character.level << ", was slain by a " << currentMonster << std::endl;
        Sleep(5000);
        exit(0);
    } else if(character.totalHealth >= 1 && monsterHP > 1)
    {

        std::cout << "\n";
        std::cout << "1. Attack.\n";
        std::cout << "2. Block.\n";
        std::cout << "3. Spells.\n";
        std::cout << "4. Run!\n";
        std::cout << "\n";
        std::cin >> playerAttack;

        if(playerAttack == 1)
        {
            //Attack
            std::cout << "Attacking... you dealt " << playerDamage << " Damage to the " << currentMonster << "." << std::endl;
            monsterHP = monsterHP - playerDamage;
            Sleep(2500);
            CombatHUD();
            if (monsterHP >= 1)
            {

                std::cout << "\n";
                std::cout << "Monster is Attacking...\n";
                character.totalHealth = character.totalHealth - monsterAttack;
                std::cout << "You lose " << monsterAttack << " HP. Your total HP is " << character.totalHealth << " points." << std::endl;
            }
            else if (monsterHP <= 0)
            {

                monsterHP = 0;
                std::cout << "\n";
                std::cout << "You've defeated the " << currentMonster << ". You've got " << monsterXP << " XP and " << monsterGold << " Gold!\nWell Done.\n";

                if(character.level != character.maxLevel)
                {

                    character.current_XP += monsterXP;
                    character.playerGold += monsterGold;
                    LevelUp();

                }

                Sleep(2000);
                HUD();

            }

            Sleep(2000);
            Combat();

        }
        else if(playerAttack == 2)
        {
            //Block
            std::cout << "Blocking...\n";
            int i = rand() % 100 + 1;
            if (i >= 50)
            {

                std::cout << "You Successfully Block the Attack!\n";
                character.heal = character.level * 10 / 2;
                std::cout << "You have been Healed for " << character.heal << " HP." << std::endl;
                character.totalHealth += character.heal;
                Sleep(2500);
                Combat();

            }
            else
            {

                std::cout << "You Fail to Block!\n";
                character.totalHealth -= monsterAttack;
                std::cout << "You lost " << monsterAttack << " HP. Your total HP is " << character.totalHealth << " points." << std::endl;
                Sleep(2500);
                Combat();

            }

        }
        else if (playerAttack == 3)
        {

            //Spells
            std::cout << "\n";
            std::cout << "8. Fireball - Cost 8 MP.\n";
            std::cout << "9. Heal Spell - Cost 5 MP.\n";
            std::cout << "\n";
            std::cin >> playerSpell;

            if(playerSpell == 8)
            {
                if (character.totalMP >= 8)
                {
                    std::cout << "You cast a Fireball!\n";
                    character.totalMP -= 8;
                    std::cout << "Attacking... you dealt " << playerSpellDamage << " Fire Damage.\n" << std::endl;
                    monsterHP = monsterHP - playerSpellDamage;
                    Sleep(3000);
                    CombatHUD();
                    if (monsterHP >= 1)
                    {

                        std::cout << "\n";
                        std::cout << "Monster is Attacking...\n";
                        character.totalHealth = character.totalHealth - monsterAttack;
                        std::cout << "You lose " << monsterAttack << " HP. Your total HP is " << character.totalHealth << " points." << std::endl;
                    }
                    else if (monsterHP <= 0)
                    {

                        monsterHP = 0;
                        std::cout << "\n";
                        std::cout << "You've defeated the " << currentMonster << ". You've got " << monsterXP << "XP!\nWell Done.\n";

                        if(character.level != character.maxLevel)
                        {

                            character.current_XP += monsterXP;
                            LevelUp();

                        }

                        Sleep(2000);
                        HUD();

                    }

                    Sleep(2000);
                    Combat();
                }
                else if (character.totalMP <= 4)
                {
                    std::cout << "The Spell requires 8 MP. \nYou only have " << character.totalMP << " MP.";
                    Sleep(3000);
                    Combat();
                }
                else
                {
                    std::cout << "Invalid number, try again.";
                    Sleep(1500);
                    Combat();
                }

            }
            else if(playerSpell == 9)
            {
                if (character.totalHealth >= 99)
                {

                    std::cout << "You can't heal anymore." << std::endl;
                    Sleep(3000);
                    Combat();

                }
                else if (character.totalMP >= 5)
                {

                    std::cout << "You cast a Healing Spell!\n";
                    character.heal = character.level * 13 / 1.5;
                    if(character.totalHealth <= 99)
                    {

                        std::cout << "You have been Healed for " << character.heal << " HP." << std::endl;
                        character.totalHealth += character.heal;

                    }

                    Sleep(3000);
                    Combat();

                }
                else if (character.totalMP <= 4)
                {

                    std::cout << "The Spell requires 5 MP. \nYou only have " << character.totalMP << " MP.";
                    Sleep(3000);
                    Combat();

                }
                else
                {

                    std::cout << "Invalid number, try again.";
                    Sleep(1500);
                    Combat();

                }

            }
            else
            {

                std::cout << "Invalid number, try again.";
                Sleep(1500);
                Combat();

            }

        }
        else if(playerAttack == 4)
        {
            //Run
            std::cout << "You attempt to run\n";
            int x = rand() % 100 + 1;
            if (x >= 50)
            {

                std::cout << "You successfully run away.\n";
                HUD();

            }
            else
            {

                std::cout << "You've failed to run!\n";
                character.totalHealth -= monsterAttack + 10;
                std::cout << "You lose " << monsterAttack + 10 << " HP. Your total HP is " << character.totalHealth << " points." << std::endl;
                Sleep(4000);
                Combat();
            }


        }
        else
        {

            std::cout << "Invalid number, try again.";
            Sleep(1500);
            Combat();

        }

    } else if (character.totalHealth >= 0) {
        character.totalHealth = 0;
        system("cls");
        std::cout << "You've Died!\n" << character.name << ", lvl " << character.level << ", was slain by a " << currentMonster << std::endl;
        Sleep(5000);
        exit(0);
    }
}

void Moving()
{

    int choice;

    std::cout << "\n\n";
    std::cout << "1. Walk Forward.\n";
    std::cout << "2. Walk Backwards.\n";
    std::cout << "\n\n";

    std::cin >> choice;

    if(choice == 1)
    {

        int temp = rand() % 100 + 1;
        std::cout << "You start walking Forward...\n";
        if (temp < 50)
        {
            //Monster Encounter
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << " Ambushes you!\n";
            currentMonster = tempName;
            Sleep(1400);
            Combat();

        }
        else if (temp > 50 && temp < 60)
        {

            CreateTreasure();
            std::cout << "You find A Treasure Box! \nInside of it is " << treasureXP << " XP and " << treasureGold << " Gold!\n" << std::endl;
            Sleep (2500);
            HUD();
        }
        else if (temp > 60 && temp < 70)
        {

            std::cout << "You find the entrance to a City, and walk inside.\n";
            Sleep(1500);
            HUDcity();

        }

        std::cout << "You find nothing of interest.\n";
        Sleep(1500);
        HUD();

    }
    else if(choice == 2)
    {

        int temp = rand() % 100 + 1;
        std::cout << "You start walking Backwards...\n";
        if (temp >= 50)
        {
            //Monster Encounter
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << " Ambushes you!\n";
            currentMonster = tempName;
            Sleep(2000);
            Combat();

        }

        std::cout << "You find nothing of interest.\n";
        Sleep(1500);
        HUD();

    }
    else
    {

        std::cout << "Invalid Number, try again.\n";
        Sleep(1000);
        Moving();

    }

}

void City()
{

    int cityChoice;
    int armorChoice;
    int weaponChoice;

    std::cout << "\n\n";
    std::cout << "The City of Solidan.\n";
    std::cout << "\n";
    std::cout << "1. Rest.\n";
    std::cout << "2. Armor Shop.\n";
    std::cout << "3. Weapon Shop.\n";
    std::cout << "4. Back.\n";
    std::cout << "\n\n";

    std::cin >> cityChoice;

    if (cityChoice == 1)
    {

        std::cout << "You find a hostel, and rest for the evening.\n";
        if(character.totalHealth <= 99)
        {

            character.totalHealth += 10 * character.level;

        }

        if(character.totalMP <= 50)
        {

            character.totalMP += 5 * character.level;

        }

        std::cout << "You feel energized and healthy.\n" << "You have " << character.totalHealth << " HP and " << character.totalMP << " MP." << std::endl;
        Sleep(3500);
        HUDcity();
    }
    if (cityChoice == 2)
    {
      
      system("cls");
      std::cout << "\n\n";
      std::cout << "The Black Sheep's Blacksmithery.\n";
      std::cout << "\n";
      std::cout << "1. Shop\n";
      std::cout << "2. Enchant\n";
      std::cout << "3. Repair\n";
      std::cout << "4. Back.\n";
      std::cout << "\n\n";

      std::cin >> armorChoice;

      if (armorChoice == 1)
      {

        system("cls");
        std::cout << "\n\n";
        std::cout << "The Black Sheep's Blacksmithery.\n";
        std::cout << "\n";
        std::cout << "1. Chestplates.\n";
        std::cout << "2. Shields.\n";
        std::cout << "3 Back.";
        std::cout << "\n\n";

        std::cin >> armorChoice;

      }
      if (armorChoice == 2)
      {



      }
      if (armorChoice == 3)
      {



      }
      if (armorChoice == 4)
      {



      }
    }
    if (cityChoice == 3)
    {

      system("cls");
      std::cout << "\n\n";
      std::cout << "The White Wolf's Blacksmithery.\n";
      std::cout << "\n";
      std::cout << "1. Swords.\n";
      std::cout << "2. Axes.\n";
      std::cout << "3. Maces.\n";
      std::cout << "4. Back\n";
      std::cout << "\n\n";

      std::cin >> weaponChoice;

    }
    if (cityChoice == 4)
    {

        std::cout << "\nYou exit the City of Solidan.";
        Sleep(1250);
        HUD();

    }

}

void LevelUp()
{

    if(character.current_XP >= character.XP_to_level)
    {

        character.XP_to_level += floor(character.level + 25 * pow(2, character.level / 7));
        character.totalHealth = floor(character.totalHealth + 13 * pow(2, character.level / 8));

        if(character.level >= character.minLevel && character.level <= character.maxLevel)
        {

            character.level++;

        }
        else
        {

            character.level = 60;

        }

        character.maxHealth = character.totalHealth;
        std::cout << "You've leveled-up! You are now Level " << character.level << "." << std::endl;
        std::cout << "Your total health has increased by 20 Points! Total max health is now " << character.totalHealth << ".\n" << std::endl;
        Sleep(5000);
        LevelUp();

    }

    Sleep(2000);
    HUD();

}

void CreateMonster()
{

    monsterHP = 30;
    monsterLevel = (rand() % 3) + character.level;

    if(monsterLevel == 0)
    {

        monsterLevel = (rand() % 3) + character.level;

    }

    //fix senere.
    monsterHP = (rand() % 30) * monsterLevel;

    //if(monsterHP == 0)
    //{

    //    monsterHP = (rand() % 30) * totalHealth;

    //}

    monsterXP = monsterHP;
    monsterGold = monsterHP - 5;

    if(monsterHP == 0)
        CreateMonster();
    if(monsterLevel == 0)
        CreateMonster();


}

void CreateTreasure()
{

    treasureXP = character.level * (rand() % 30);
    treasureGold = character.level * (rand() % 31);

    character.current_XP += treasureXP;
    character.playerGold += treasureGold;

}
