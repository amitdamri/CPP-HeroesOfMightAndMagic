
#include "CreaturesHeader.h"
using namespace std;


int Wizard::attack(const int numberOfAttackers, const string creautreToAttack) const{

	if (creautreToAttack == "Wizard")
		return numberOfAttackers*m_powerOfAttack/m_powerOfDefense;

	else if (creautreToAttack == "Zombie"){
		Zombie zombie;
		return numberOfAttackers*m_powerOfAttack/zombie.getPowerOfDefense();
	}

	else if (creautreToAttack == "Vampire"){
		Vampire vampire;
		return numberOfAttackers*m_powerOfAttack/vampire.getPowerOfDefense();
	}

	else if (creautreToAttack == "Archer"){
		Archer archer;
		return numberOfAttackers*m_powerOfAttack/archer.getPowerOfDefense();
	}

	else if (creautreToAttack == "Black_Dragon"){
		BlackDragon blackDragon;
		return numberOfAttackers*m_powerOfAttack/blackDragon.getPowerOfDefense();
	}

	else
		return 0;

}

