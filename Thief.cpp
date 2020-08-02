
#include "Thief.h"


Thief::~Thief(){
	if (!m_creatureList.empty())
		m_creatureList.clear();
}

//steal gold from another hero
void Thief::useSpecialAttack(Hero& stealHero){
	if (stealHero.getHeroGold() <70){
		if ((*this).getHeroGold()+stealHero.getHeroGold()>2500){
			int goldToTake = stealHero.getHeroGold() - (getHeroGold()+stealHero.getHeroGold()-2500);
			(*this).takeGold(goldToTake);
			stealHero.lostGold(goldToTake);
		}
		else {
			(*this).takeGold(stealHero.getHeroGold());
			stealHero.lostGold(stealHero.getHeroGold());
		}
	}
	else {
		if ((*this).getHeroGold()+70>2500){
			int goldToTake = 70-(getHeroGold()+70-2500); // amount of gold the hero can take
			(*this).takeGold(goldToTake);
			stealHero.lostGold(goldToTake);
		}
		else {
			(*this).takeGold(70);
			stealHero.lostGold(70);
		}
	}
;
}
