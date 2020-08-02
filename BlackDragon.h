
#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_

#include "Creature.h"
class Zombie;
class Archer;
class Wizard;
class Vampire;

class BlackDragon : public Creature {

public:
	BlackDragon() : Creature("Black_Dragon",9,10,200) {};
	virtual ~BlackDragon() {};
	virtual int attack(const int numberOfAttackers, const std::string creautreToAttack) const;
};

#endif /* BLACKDRAGON_H_ */
