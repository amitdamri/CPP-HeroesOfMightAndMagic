
#include "Creature.h"
using namespace std;

Creature::Creature(string CreatureType,int powerOfAttack, int powerOfDefense, int price){
	m_CreatureType = CreatureType;
	m_powerOfAttack = powerOfAttack;
	m_powerOfDefense = powerOfDefense;
	m_price = price;
}

//prints information about the creature
void Creature::showDetails() const{
	cout << "Attack level: " << m_powerOfAttack << ", Defense level: " << m_powerOfDefense << endl;
}

//returns the type of the creature
string Creature::getType() const{
	return m_CreatureType;
}

//returns the price of the creature
int Creature::getPrice() const {
	return m_price;
}

//returns the power of defense of the creature
int Creature::getPowerOfDefense() const{
	return m_powerOfDefense;
}
