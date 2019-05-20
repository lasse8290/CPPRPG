#include "Character.h"


Character::Character()
{

    name = " ";
    race = " ";
    sex = " ";

    playerRace = { "elf", "dwarf", "human", "ancient", "golem", "goblin" };

    int level = 0, XP = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;

}

void Character::characterCreation()
{

int counter = 0;

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
    for (int i = 0; i <= counter; i++)
    {
        if (i == 0)
            std::cout << "Creating Character.\n";
        if (i == 1)
            std::cout << "Creating Character..\n";
        if (i == 2)
        {
            std::cout << "Creating Character.\n";
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

}