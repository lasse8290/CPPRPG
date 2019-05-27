#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <vector>

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();

//Available special races & names.
std::string name = " ", race = " ", sex = " ";
std::string playerRace[] = { "elf", "dwarf", "human", "ancient", "golem", "goblin" };
std:: string playerName[] = { "guts", "saitama", "mikkel" };

//Basic stats, feel free to add more, but don't change the values, change them in main.
int level = 0, XP = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0, MP = 0, healMP = 0, totalMP = 0, maxMP = 0;
int monsterHP = 0;
int monsterXP = 0;
int monsterLevel = 0;

//Monster names, int amount.
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

    std::for_each(name.begin(), name.end(), [](char & c){

        c = ::tolower(c);

    });

    //Special Names.
    for (int i = 0; i < sizeof(playerName); i++) 
    {

        if (name == "guts")
            {

                name = "GRIFFITHHHHH!";
                break;

            }
        
        if (name == "saitama")
            {

                name = "ONE-PUNCH!";
                break;

            }

        if (name == "mikkel")
            {

                name = "Weakling";
                break;

            }

        if (name == "lasse")
            {

                name = "Spaghetti kode er min livret";
                break;

            }

        else
        {

            break;

        }
            
    }

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
                MP = 40;
                break;

            }
        
        if (race == "dwarf")
            {

                health = 75;
                MP = 25;
                break;

            }

        if (race == "human")
            {

                health = 100;
                MP = 20;
                break;

            }
        
        if (race == "ancient")
            {

                health = 110;
                MP = 15;
                break;

            }

        if (race == "golem")
            {

                health = 125;
                MP = 10;
                break;

            }
        
        if (race == "goblin")
            {

                health = 60;
                MP = 8;
                break;

            }

        else
        {

            health = 100;
            MP = 25;
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
    totalMP = MP;
    maxMP = totalMP;

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
    std::cout << "Name: " << name << "      Health: " << totalHealth << "\nRace: " << race << "      MP: " << totalMP << "\nSex: " << sex << "\nLevel: " << level << "\nXP: " << XP << "\nTotal XP required for Level-up: " << nextLevel << std::endl;

    Moving();

}

void CombatHUD()
{

    Sleep(500);
    system("cls");
    std::cout << "Name: " << name << "      |       Monster Name: " << currentMonster << "\nHealth: " << totalHealth << "    |       Monster Health: " <<
        monsterHP << "\nMP: " << totalMP << "      |       Monster Level: " << monsterLevel << "\nLevel: " << level << std::endl;

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
    int playerDamage = 8 * level / 2;
    int playerSpellDamage = 11 * level / 1.1;
    int monsterAttack = 6 * monsterLevel / 2;

    if(totalHealth >= 1 && monsterHP > 1)
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
        else if (playerAttack == 3)
        {

            //Spells
            std::cout << "\n";
            std::cout << "8. Fireball - Cost 5 MP.\n";
            std::cout << "9. Heal Spell - Cost 4 MP.\n";
            std::cout << "\n";
            std::cin >> playerSpell;

            if(playerSpell == 8)
            {
                if (totalMP >= 8)
                {
                    std::cout << "You cast a Fireball!\n";
                    totalMP -= 8;
                    std::cout << "Attacking... you dealt " << playerSpellDamage << " Fire Damage to the " << currentMonster << ".\n" << "You now have " << totalMP << " MP left." << std::endl;
                    monsterHP = monsterHP - playerSpellDamage;
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
                else if (totalMP <= 4)
                {
                    std::cout << "The Spell requires 8 MP. \nYou only have " << totalMP << " MP.";
                    Sleep(2000);
                    Combat();
                }
                else
                {
                    std::cout << "Invalid number, try again.";
                    Sleep(500);
                    Combat();
                }

            }
            else if(playerSpell == 9)
            {



            }
            else
            {
                std::cout << "lol";
                exit(1);
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