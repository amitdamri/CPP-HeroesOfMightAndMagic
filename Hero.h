
#ifndef HERO_H_
#define HERO_H_

#include <iostream>
#include <string.h>
#include <map>
#include "Exception.h"
#include "Creature.h"
class Zombie;
class Archer;
class Wizard;
class Vampire;
class BlackDragon;


class Hero {

private:
	std::string m_heroName;
	std::string m_heroType;
	int m_numberOfGold;

	void printCreatures() const; // print the creatures according to the  required format
	int convertCreatureToNumber(const std::string creatureType) const; //converts creature to number in order to insert to the map
	void fightAttackUpdateCreature(int numberOfKillings,const std::string creatureToUpdate); //updates the map of the creatures

protected:
	//ID's of creatures : 1=Zombie, 2=Vampire, 3=Archer, 4=Wizard, 5=Black_Dragon
	std::map<int,std::pair<std::string,int>,std::greater<int> > m_creatureList;

public:
	//Constructors
	Hero();
	Hero(std::string heroName,std::string heroType);
	Hero(std::string heroType);

	virtual ~Hero() {};
	//adds the requested number of creature to the player army
	void buyCreature(const Creature& creatureToBuy, const int numberOfCreature);
	//gets 100 golds per turn
	void getDailyGolds();
	//attacks other hero with the required creature against the required creature
	void fightAttack(Hero&,const std::string,const std::string);
	//shows the information of the hero according to the attack format
	void attackDetails() const;
	//shows all of the details about the hero
	void showDetails() const;
	//shows information according to the opponents print format
	void opponentsDetails() const;
	//turn ends
	void endOfTurn() {};
	//use the special attack of this hero
	virtual void useSpecialAttack(Hero& hero)=0;
	//returns the hero name
	std::string getHeroName() const;
	//returns the hero type
	std::string getHeroType() const;
	//returns the number of gold that the hero has
	int getHeroGold() const;
	//returns the number of creatures that the hero has
	int getNumberOfCreatures() const;
	//subtracts the amount of gold from the hero's gold after he was robbed or after he lose in a fight
	void lostGold(int amount);
	//adds to the hero's gold the required amount of gold - after he was win or after he robbed another hero
	void takeGold(int amount);
	//check if the hero has the given creature
	bool creatureExist(const std::string creatureType) const;
	//writes all of the information about the hero to his log file
	void writeInfo() const;
	//loads from the log file all of the information about the hero
	void readLogFile();
};

#endif /* HERO_H_ */
