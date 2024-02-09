// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

enum typeCharacter {
    warrior,
    wizard,
    archer,
    rogue

};

struct Character {
    int id;
    typeCharacter type;
    float meleeDamage;
    float rangeDamage;
};


Character getTheMostPowerful(std::vector <Character> characterVector) {
    int max = 0;
    Character thePowerfulCharacter;
    for (Character character : characterVector) {
        if (character.meleeDamage + character.rangeDamage > max) {
            thePowerfulCharacter = character;
            max = character.meleeDamage + character.rangeDamage;
        }
    }

    return thePowerfulCharacter;
}

typeCharacter hashit(std::string const& inString) {
    if (inString == "warrior") return warrior;
    if (inString == "wizard") return wizard;
    if (inString == "archer") return archer;
    if (inString == "rogue") return rogue;
}

int main()
{
    
    
    std::vector <Character> characterVector;

    while (1) {
        int id;
        std::string type;
        float meleeAttack;
        float rangedAttack;
        
        std::cout << "Enter an ID for character" << std::endl;
        std::cin >> id;
        std::cout << "Enter a type" << std::endl;
        std::cin >> type;
        std::cout << "Enter a melee attack damage value" << std::endl;
        std::cin >> meleeAttack;
        std::cout << "Enter a ranged attack damage value" << std::endl;
        std::cin >> rangedAttack;

        Character  character;
        character.id = id;
        character.type = hashit(type);
        character.meleeDamage = meleeAttack;
        character.rangeDamage = rangedAttack;

        characterVector.push_back (character);
        std::string str;
        std::cout << "Would you like to continue? Ctrl-Z to end, 'yes' to continue" << std::endl;
        
        if (!(std::cin >> str))
            break;
            

        
    }

    std::cout << "The powerful character has ID: " << getTheMostPowerful(characterVector).id << std::endl;

}


