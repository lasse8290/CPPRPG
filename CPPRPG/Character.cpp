#include "Character.h"

Character::Character()
{   
    name = " ";
    race = " ";
    sex = " ";

    playerRace = { "elf", "dwarf", "human", "ancient", "golem", "goblin" };
    playerName = { "guts", "saitama", "mikkel" };

    weapon = nullptr;

    level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0, MP = 0, healMP = 0, totalMP = 0, maxMP = 0, playerGold = 0;

    level = 1, current_XP = 0, base_XP = 83, XP_to_level = base_XP, minLevel = 1, maxLevel = 60;

    playerDamage = 8 * level / 2;

    playerDamageMax = 8 * level / 2 + level;
    
    playerSpellDamage = 11 * level / 1.1;

}

void Character::characterCreation()
{

    int counter = 3;

    //Initialization
    std::ofstream log("logfile.txt", std::ofstream::out | std::ofstream::app);

    system("cls");

    //Character Creation.
    std::cout << "\n~ Enter your Character's Name ~\n\n";
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

                name = "Favourite Meal is Spaghetti Code";
                break;

            }

        else
        {

            break;

        }
            
    }

    log << "        Name: " << name << ". ";

    system("cls");

    std::cout << "\n~ Choose a Race ~\n\n";
    std::cout << "Elf\n";
    std::cout << "Dwarf\n";
    std::cout << "Human\n";
    std::cout << "Ancient\n";
    std::cout << "Golem\n";
    std::cout << "Goblin\n\n";
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

    log << "Race: " << race << ". ";

    system("cls");

    std::cout << "\n";
    std::cout << "~ Enter your Character's Sex ~\n\n";
    std::cin >> sex;

    system("cls");

    log << "Sex: " << sex << "\n";

    //Scam Loading Screen xd.  
    for (int i = 0; i < counter; i++)
    {
        if (i == 0)
            std::cout << "\nCreating Character.";
        if (i == 1)
            std::cout << "\nCreating Character..";
        if (i == 2)
        {
            std::cout << "\nCreating Character...";
            break;
        }

        Sleep(400);
        system("cls");
        counter++;

    }
    
    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    log.close();

    totalHealth = health;
    maxHealth = totalHealth;
    totalMP = MP;
    maxMP = totalMP;

}

void Character::updateStats()
{

    if(this->weapon)
    {

        this->playerDamage += this->weapon->getDamageMin();
        this->playerDamageMax += this->weapon->getDamageMax();

    }

}