
#include "CreaturesHeader.h"
using namespace std;


int Vampire::attack(const int numberOfAttackers, const string creautreToAttack) const{

	if (creautreToAttack == "Vampire")
		return numberOfAttackers*m_powerOfAttack/m_powerOfDefense;

	else if (creautreToAttack == "Zombie"){
		Zombie zombie;
		return numberOfAttackers*m_powerOfAttack/zombie.getPowerOfDefense();
	}

	else if (creautreToAttack == "Archer"){
		Archer archer;
		return numberOfAttackers*m_powerOfAttack/archer.getPowerOfDefense();
	}

	else if (creautreToAttack == "Wizard"){
		Wizard wizard;
		return numberOfAttackers*m_powerOfAttack/wizard.getPowerOfDefense();
	}

	else if (creautreToAttack == "Black_Dragon"){
		BlackDragon blackDragon;
		return numberOfAttackers*m_powerOfAttack/blackDragon.getPowerOfDefense();
	}

	else
		return 0;

}

