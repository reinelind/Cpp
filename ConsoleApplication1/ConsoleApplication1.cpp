// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

class Building {
public:
	Building(int id, int maxAge = 0, int initialCost = 0) : Id(id), MaxAge(maxAge), InitialCost(initialCost) {};

	int GetCost() {
		return InitialCost - (InitialCost * currentAge) / MaxAge;
	}
	void ToAge(int years) {
		if (years > MaxAge) {
			Destroy();
			MaxAge = 0;
		}
		else
			currentAge = years;
	}
	void Destroy() {
		std::cout << "Id of destroyed building: " << Id << std::endl;
	}

	~Building() {
		Destroy();
	}

private:
	int Id;
	int MaxAge;
	int InitialCost;
	int currentAge = 0;
};


int main() {
	Building* building1 = new Building(1, 5, 1000);
	building1->ToAge(2);
	std::cout << "Cost of building is " << building1->GetCost() << "$" << std::endl;
	delete building1;



}


