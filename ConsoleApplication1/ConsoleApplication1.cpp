// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
int main()
{

    enum characterClass {
        wizard,
        warrior
    } character;
    std::string name;
    float health;
    float thirdOfHealth;
    int power;

    
    
    unsigned int inputClass;

    std::cout << "Enter a name of character" << std::endl;
    std::cin >> name; 
    std::cout << "Enter health as an int number (0-200)" << std::endl;
    std::cin >> health;
    if (health < 0 || health > 200) {
        std::cerr << "Health is not valid (0 - 200)" << std::endl;
        return 1;
    }

    std::cout << "Enter power as an int number (0-100)" << std::endl;
    std::cin >> power;
    if (power < 0 || power > 100) {
        std::cerr << "Power is not valid (0 - 100)" << std::endl;
        return 2;
    }

    std::cout << "Enter a class of character (1 - wizard, 2 - warrior)" << std::endl;
    std::cin >> inputClass;

    switch (inputClass) {
        case 1: 
            character = wizard;
            break;
        case 2:
            character = warrior;
            break;
        default:
            std::cerr << "Character type is not valid!" << std::endl;
            return 2;
    }

    thirdOfHealth = health * 0.3;

    while (health > 0) {
        int damage; 
        float oldHealth = health;

        std::cout << "Enter damage dealt to character" << std::endl;
        std::cin >> damage;
        if (character == wizard) {
            if (damage > 2 * power) {
                if (rand() % 2)
                    health = health - (damage % 2 == 0 ? damage * 2 : damage);
                else std::cout << "No damage dealt" << std::endl;
            } else health = health - (damage % 2 == 0 ? damage * 2 : damage);
        }

        if (character == warrior) {
            if (health < thirdOfHealth) {
                damage = damage - power;
                std::cout << "Damage decreased to " << damage << std::endl;
            }
            health = health - (damage % 2 == 1 ? damage * 3 : 0);
        }

        std::cout << "Character " << name << " stats:" << std::endl;
        std::cout << "Health is " << health << std::endl;
        std::cout << "Power is " << power << std::endl;
        std::cout << "Damage dealt " << oldHealth - health << std::endl;
    }

    return 0;
}


