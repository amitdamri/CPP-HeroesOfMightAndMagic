
#ifndef WARRIOR_H_
#define WARRIOR_H_
#include "Hero.h"


class Warrior :public Hero{

public:
	Warrior(): Hero("Warrior") {};
	Warrior(std::string heroName) : Hero(heroName,"Warrior") {};
	virtual ~Warrior();
	virtual void useSpecialAttack(Hero& hero);
};

#endif /* WARRIOR_H_ */
