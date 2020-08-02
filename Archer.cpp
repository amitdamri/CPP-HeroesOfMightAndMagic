
#include "CreaturesHeader.h"

using namespace std;


int Archer::attack(const int numberOfAttackers, const string creautreToAttack) const{

	if (creautreToAttack == "Archer")
		return numberOfAttackers*m_powerOfAttack/m_powerOfDefense;

	else if (creautreToAttack == "Zombie"){
		Zombie zombie;
		return numberOfAttackers*m_powerOfAttack/zombie.getPowerOfDefense();
	}

	else if (creautreToAttack == "Vampire"){
		Vampire vampire;
		return numberOfAttackers*m_powerOfAttack/vampire.getPowerOfDefense();
	}

	else if (creautreToAttack == "Wizard"){
		Wizard wizard;
		return numberOfAttackers*m_powerOfAttack/wizard.getPowerOfDefense();
	}

	else if (creautreToAttack == "Black_Dragon"){
		BlackDragon blackDragon;
		//power of attack grows by 20 percent against black dragon
		return numberOfAttackers*(m_powerOfAttack+m_powerOfAttack*0.2)/blackDragon.getPowerOfDefense();
	}

	else
		return 0;

}

