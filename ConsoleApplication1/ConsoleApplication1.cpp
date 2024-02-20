// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>


class Weapon {
public:
	virtual float GetDamage() = 0;
	virtual std::string GetName() = 0;
};

class MeleeWeapon : public Weapon {
public:

	MeleeWeapon(float _damage = 0, std::string _name = "sample") : damage(_damage), name(_name) {};

	float GetDamage() {
		std::cout << "This melee weapon deals " << damage << " damage points" << std::endl;
		return damage;
	}

	std::string GetName() {
		std::cout << "This melee weapon is " << name << std::endl;
		return name;
	}

private:
	float damage;
	std::string name;
};

class RangedWeapon : public Weapon {
public:

	RangedWeapon(float _damage = 0, std::string _name = "sample") : damage(_damage), name(_name) {};

	float GetDamage() {
		std::cout << "This ranged weapon deals " << damage << " damage points" << std::endl;
		return damage;
	}

	std::string GetName() {
		std::cout << "This ranged weapon is " << name << std::endl;
		return name;
	}

private:
	float damage;
	std::string name;
};

class MagicalRangedWeapon : public RangedWeapon {
public:

	MagicalRangedWeapon(float _damage = 0, std::string _name = "sample", float _mana = 0) : damage(_damage), name(_name), mana(_mana) {};

	float GetDamage() {
		std::cout << "This ranged weapon deals " << damage << " damage points" << "and requires " << mana <<" mana" << std::endl;
		return damage;
	}

private:
	float damage;
	float mana;
	std::string name;
};


class DamageModifier {
public:
	virtual float CalculateDamage(float CurrentHealth, float Damage) = 0;
};

class MultiplicationDamageModifier : public DamageModifier {
public:
	MultiplicationDamageModifier(float _multiplicator = 0) : multiplicator(_multiplicator) {};
	float CalculateDamage(float CurrentHealth, float Damage) {
		return CurrentHealth - Damage * multiplicator;
	};

private:
	float multiplicator;
};

class AdditionDamageModifier : public DamageModifier {
public:
	AdditionDamageModifier(float _addition = 0) : addition(_addition) {};
	float CalculateDamage(float CurrentHealth, float Damage) {
		return CurrentHealth - (Damage + addition);
	};

private:
	float addition;
};

class ParityDamageModifier : public DamageModifier {
public:


	ParityDamageModifier(float _multiplicator = 0) : multiplicator(_multiplicator) {};
	float CalculateDamage(float CurrentHealth, float Damage) {

		if (counter++ % 2 == 0) {
			return CurrentHealth - Damage * multiplicator;
		}

		
	};

	static int counter;
private:
	
	float multiplicator;
};



class Character {
public:

	Character(DamageModifier* _modifier, Weapon* _weapon, std::string _name, float _health) : modifier(_modifier), weapon(_weapon), name(_name), enemyHealth(_health) {};
	void SetWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}

	Weapon* GetWeapon() const {
		return weapon;
	}

	float GetModifiedDamage() {

		float damage = modifier->CalculateDamage(enemyHealth, weapon->GetDamage());
		std::cout << "Damage dealt to character with " << enemyHealth << " enemyHealth is " << damage << std::endl;

		return damage;
	}

	void setModifier(DamageModifier* modifier) {
		this->modifier = modifier;
	}

	std::string getName() {
		std::cout << "This character called " << name << std::endl;
	}

private:
	DamageModifier* modifier;
	Weapon* weapon;
	std::string name;
	float enemyHealth;
};

int ParityDamageModifier::counter = 0;

int main() {
	

	Character* druid = new Character(new ParityDamageModifier(1.25), new MeleeWeapon(25, "claws"), "Lone Druid", 100);

	druid->GetModifiedDamage();

	std::cout << ParityDamageModifier::counter;
	druid->GetModifiedDamage();

	std::cout << ParityDamageModifier::counter;
	druid->GetModifiedDamage();

	

	Character* sorcerer = new Character(new AdditionDamageModifier(25), new MagicalRangedWeapon(10, "rog"), "Crystal Maiden", 100);
	sorcerer->GetModifiedDamage();


	DamageModifier* modifier = nullptr;
	Character* soldier = new Character(nullptr, new RangedWeapon(35, "bow"), "Bob", 100);;
	int num;
	std::cout << "Select modifier 1: Multiplication; 2: Addition; 3: Parity" << std::endl;
	while (std::cin >> num) {
		switch (num) {
			case 1:
				soldier->setModifier(new MultiplicationDamageModifier(1.2));
				soldier->GetModifiedDamage();
				break;
			case 2:
				soldier->setModifier(new AdditionDamageModifier(10));
				soldier->GetModifiedDamage();
				break;
			case 3:
				soldier->setModifier(new ParityDamageModifier(1.5));
				soldier->GetModifiedDamage();
				break;
		}
		std::cout << "Select modifier 1: Multiplication; 2: Addition; 3: Parity" << std::endl;
	}
}