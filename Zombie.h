
#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include "Creature.h"
class Archer;
class Wizard;
class Vampire;
class BlackDragon;

class Zombie : public Creature {

public:
	Zombie() : Creature("Zombie",2,5,50) {};
	virtual ~Zombie(){};
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const;
};

#endif /* ZOMBIE_H_ */
