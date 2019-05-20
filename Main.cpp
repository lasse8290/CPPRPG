#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <vector>

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();

std::string name = " ", race = " ", sex = " ";
std::string playerRace[] = { "elf", "dwarf", "human", "ancient", "golem", "goblin" };
int level = 0, XP = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;
int monsterHP = 0;
int monsterXP = 0;
int monsterLevel = 0;

std::string monsterName[] = { "Goblin", "Spider", "Troll", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
std::string currentMonster = " ";

int counter = 3;

int main()
{

    //Initialization
    level = 1;
    XP = 0;
    nextLevel = 76;

    //Character Creation.
    std::cout << "Enter your Character's Name: ";
    std::cin >> name;

    std::cout << "\n~ Choose a Race ~\n";
    std::cout << "Elf\n";
    std::cout << "Dwarf\n";
    std::cout << "Human\n";
    std::cout << "Ancient\n";
    std::cout << "Golem\n";
    std::cout << "Goblin\n";
    std::cout << "Enter a Race below: \n\n";
    std::cin >> race;

    std::for_each(race.begin(), race.end(), [](char & c) {

    c = ::tolower(c);

    });

    //Available Races.
    for (int i = 0; i < sizeof(playerRace); i++) 
    {

        if (race == "elf")
            {

                health = 105;
                break;

            }
        
        if (race == "dwarf")
            {

                health = 75;
                break;

            }

        if (race == "human")
            {

                health = 100;
                break;

            }
        
        if (race == "ancient")
            {

                health = 110;
                break;

            }

        if (race == "golem")
            {

                health = 125;
                break;

            }
        
        if (race == "goblin")
            {

                health = 60;
                break;

            }

        else
        {

            health = 100;
            break;

        }
            
    }

    std::cout << "\n";
    std::cout << "Enter your Character's Sex: ";
    std::cin >> sex;
    system("cls");

    //Scam Loading Screen xd.  
    for (int i = 0; i < counter; i++)
    {
        if (i == 0)
            std::cout << "Creating Character.\n";
        if (i == 1)
            std::cout << "Creating Character..\n";
        if (i == 2)
        {
            std::cout << "Creating Character...\n";
            break;
        }

        Sleep(400);
        system("cls");
        counter++;

    }
    
    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    totalHealth = health;
    maxHealth = totalHealth;

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
    std::cout << "Name: " << name << "      Health: " << totalHealth << "\nRace: " << race 
        << "\nSex: " << sex << "\nLevel: " << level << "\nXP: " << XP << "\nTotal XP required for Level-up: " 
        << nextLevel << std::endl;

    Moving();

}

void CombatHUD()
{

    Sleep(500);
    system("cls");
    std::cout << "Name: " << name << "      |       Monster Name: " << currentMonster << "\nHealth: " << totalHealth << "       |       Monster Health: " <<
        monsterHP << "\nLevel: " << level << "      |       Monster Level: " << monsterLevel << std::endl;

}

void Combat()
{

    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * level / 2;
    int monsterAttack = 6 * monsterLevel / 2;

    if(totalHealth >= 1 && monsterHP > 1)
    {

        std::cout << "\n";
        std::cout << "1. Attack.\n";
        std::cout << "2. Block.\n";
        std::cout << "3. Run!\n";
        std::cout << "\n";
        std::cin >> playerAttack;

        if(playerAttack == 1)
        {
            //Attack
            std::cout << "Attacking... you dealt " << playerDamage << " Damage to the " << currentMonster << "." << std::endl;
            monsterHP = monsterHP - playerDamage;
            Sleep(1500);
            CombatHUD();
            if (monsterHP >= 1)
            {

                std::cout << "\n";
                std::cout << "Monster is Attacking...\n";
                totalHealth = totalHealth - monsterAttack;
                std::cout << "You lose " << monsterAttack << " HP. Your total HP is " << totalHealth << " points." << std::endl;
                if (totalHealth <= 0)
                {

                    totalHealth = 0;
                    system("cls");
                    std::cout << "You've Died!\n" << name << ", lvl " << level << ", was slain by a " << currentMonster << std::endl;
                    Sleep(2500);
                    exit(0);

                }
            }
            else if (monsterHP <= 0)
            {

                monsterHP = 0;
                LevelUp();
                std::cout << "\n";
                std::cout << "You've defeated the " << currentMonster << ". You've got " << monsterXP << "XP!\nWell Done.\n";
                Sleep(1500);
                HUD();

            }

            Sleep(1500);
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
                heal = level * 10 / 2;
                std::cout << "You have been Healed for " << heal << " HP." << std::endl;
                totalHealth += heal;
                Sleep(1500);
                Combat();

            }
            else
            {

                std::cout << "You Fail to Block!\n";
                totalHealth -= monsterAttack;
                std::cout << "You lost " << monsterAttack << " HP. Your total HP is " << totalHealth << " points." << std::endl;
                Sleep(1500);
                Combat();

            }

        }
        else if(playerAttack == 3)
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
                std::cout << "You get hit by the enemy.\n";
                totalHealth -= monsterAttack + 10;
                std::cout << "You lost " << monsterAttack + 10 << " HP. Your total HP is " << totalHealth << " points." << std::endl;
                Sleep(1500);
                Combat();
            }
            

        }
        else
        {

            std::cout << "Invalid number, try again.";
            Sleep(500);
            Combat();

        }

    }
}

void Moving() 
{

    int choice;

    std::cout << "\n\n";
    std::cout << "1. Walk Forward.\n";
    std::cout << "2. Rest.\n";
    std::cout << "3. Walk Backwards.\n";
    std::cout << "\n\n";

    std::cin >> choice;

    if(choice == 1)
    {

        int temp = rand() % 100 + 1;
        std::cout << "You start walking Forward...\n";
        if (temp >= 50) 
        {
            //Monster Encounter
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << " Ambushes you!\n";
            currentMonster = tempName;
            Sleep(1000);
            Combat();

        }

        std::cout << "You find nothing of interest.\n";
        Sleep(1000);
        HUD();

    }
    
    else if(choice == 2)
    {

        std::cout << "You set up a camp, and rest for the evening.\n";
        if(totalHealth <= 99)
        {

            totalHealth += 10 * level;

        }

        std::cout << "You awake feel energized and healthy. Your HP is now " << totalHealth << std::endl;
        Sleep(1000);
        HUD();

    }
    else if(choice == 3)
    {

        int temp = rand() % 100 + 1;
        std::cout << "You start walking Backwards...\n";
        if (temp >= 50) 
        {
            //Monster Encounter
            CreateMonster();
            std::string tempName = monsterName[rand() % currentMonsterNames];
            std::cout << "A " << tempName << "Ambushes you!\n";
            currentMonster = tempName;
            Sleep(1500);
            Combat();

        }

        std::cout << "You find nothing of interest.\n";
        Sleep(1000);
        HUD();

    }
    else
    {

        std::cout << "Invalid Number, try again.\n";
        Sleep(500);
        Moving();

    }

}

void LevelUp()
{

    XP = XP + monsterXP;

    if(XP >= nextLevel)
    {

        level++;
        nextLevel = nextLevel * 3 / 2;
        totalHealth = totalHealth + 20;
        maxHealth = totalHealth;
        std::cout << "You've leveled-up! You are now Level " << level << "." << std::endl;
        std::cout << "Your total health has increased by 20 Points! Total max health is " << totalHealth << "." << std::endl;
        Sleep(2500);
        HUD();

    }

}

void CreateMonster()
{

    monsterHP = 30;
    monsterLevel = (rand() % 3) + level;

    if(monsterLevel == 0)
    {

        monsterLevel = (rand() % 3) + level;

    }

    //fix senere.
    monsterHP = (rand() % 30) * monsterLevel;

    //if(monsterHP == 0)
    //{

    //    monsterHP = (rand() % 30) * totalHealth;

    //}

    monsterXP = monsterHP;

    if(monsterHP == 0)
        CreateMonster();
    if(monsterLevel == 0)
        CreateMonster();


}