
#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Creature.h"
class Zombie;
class Archer;
class Wizard;
class BlackDragon;

class Vampire : public Creature {

public:

	Vampire() : Creature("Vampire",4,4,80) {};
	virtual ~Vampire() {};
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const;
};

#endif /* VAMPIRE_H_ */
