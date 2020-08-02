
#ifndef ARCHER_H_
#define ARCHER_H_

#include "Creature.h"
class Zombie;
class Wizard;
class Vampire;
class BlackDragon;

class Archer : public Creature {

public:
	Archer() : Creature("Archer",5,4,90) {};
	virtual ~Archer() {};
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const;
};

#endif /* ARCHER_H_ */
