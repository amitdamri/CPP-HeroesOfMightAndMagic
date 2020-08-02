
#ifndef NECROMANCER_H_
#define NECROMANCER_H_
#include "Hero.h"

class Necromancer : public Hero{

public:
	Necromancer(): Hero("Necromancer") {};
	Necromancer(std::string heroName) : Hero(heroName,"Necromancer") {};
	virtual ~Necromancer();
	virtual void useSpecialAttack(Hero& hero);
};

#endif /* NECROMANCER_H_ */
