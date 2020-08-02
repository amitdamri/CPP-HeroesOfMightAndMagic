
#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <string.h>
#include <stdlib.h>


class Creature {

protected:
	std::string m_CreatureType;
	int m_powerOfAttack;
	int m_powerOfDefense;
	int m_price;

public:
	Creature() : m_CreatureType("Creature"),m_powerOfAttack(0),m_powerOfDefense(0),m_price(0) {};
	Creature(std::string CreatureType,int powerOfAttack, int powerOfDefense, int price);
	virtual ~Creature() {};
	//attacks with the given creature the other creature and calcluate how much creatures has defeated
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const=0;
	//prints information about the creature
	void showDetails() const;
	//returns the price of the creature
	int getPrice() const;
	//returns the type of the creature
	std::string getType() const;
	//returns the power of defense of the creature
	int getPowerOfDefense() const;
};

#endif /* CREATURE_H_ */
