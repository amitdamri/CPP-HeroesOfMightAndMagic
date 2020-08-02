
#ifndef THIEF_H_
#define THIEF_H_
#include "Hero.h"

class Thief : public Hero {

public:
	Thief(): Hero("Thief") {};
	Thief(std::string heroName) : Hero(heroName,"Thief") {};
	virtual ~Thief();
	virtual void useSpecialAttack(Hero& stealHero);
};

#endif /* THIEF_H_ */
