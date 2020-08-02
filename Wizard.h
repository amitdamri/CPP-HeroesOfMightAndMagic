
#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.h"
class Zombie;
class Archer;
class Vampire;
class BlackDragon;

class Wizard :public Creature {

public:

	Wizard() : Creature("Wizard",8,2,150) {};
	virtual ~Wizard() {};
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const;
};

#endif /* WIZARD_H_ */
