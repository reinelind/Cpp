// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

int maxDamageNumber(std::vector <int> damage) {
    int max = 0;
    for (int i = 0; i < damage.size(); i++) {
        if (damage[i] > 0)
            if (damage[i] > max)
                max = damage[i];
    }

    return max;
}

int minDamageNumber(std::vector <int> damage) {
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < damage.size(); i++) {
        if (damage[i] > 0)
            if (damage[i] < min)
                min = damage[i];
    }
    return min;
}

std::vector <int> vectorHeal (std::vector <int> damage) {
    std::vector <int> healVectorNumbers;
    for (int i = 0; i < damage.size(); i++) {
        if (damage[i] < 0)
            healVectorNumbers.push_back(i + 1);
    }

    return healVectorNumbers;
}

int sumOfAction(std::vector <int> damage, const std::string & action) {
    int sum = 0;
    std::vector <int> actionBiasedVector;
    for (int i = 0; i < damage.size(); i++) {
        if (action == "damage")
            if (damage[i] > 0)
                actionBiasedVector.push_back(damage[i]);
        if (action == "heal")
            if (damage[i] < 0)
                actionBiasedVector.push_back(abs(damage[i]));
    }

    return std::accumulate(actionBiasedVector.begin(), actionBiasedVector.end(),0);
}

std::vector <int> getNoActionNumbers(std::vector <int> damage) {
    std::vector <int> noActionNumbers;
    for (int i = 0; i < damage.size(); i++) {
        if (damage[i] == 0)
            noActionNumbers.push_back(i + 1);
    }

    return noActionNumbers;
}



int main()
{
    std::vector <int> damageValues;
    int damage;
    int number = 1;
    
    std::cout << "Number " << number << " dealt damage: " << std::endl;

    while (std::cin >> damage) {
        
        damageValues.push_back(damage);
        std::cout << "Number " << ++number << " damage dealt" << std::endl;
    }


    std::cout << "Number of Max Damage: " << maxDamageNumber(damageValues) << std::endl;
    std::cout << "Number of Min Damage: " << minDamageNumber(damageValues) << std::endl;
    std::cout << "Number of Healing Action: ";
    for (int element : vectorHeal(damageValues))
        std::cout << element << " ";
    std::cout << std::endl;

    std::cout << "Sum Of Damage: " << sumOfAction(damageValues, "damage") << std::endl;
    std::cout << "Sum Of Heal " << sumOfAction(damageValues, "heal") << std::endl;
    std::cout << "No damage/heal dealt numbers: ";
    for (int element : getNoActionNumbers(damageValues))
        std::cout << element << " ";
    

    return 0;
}


