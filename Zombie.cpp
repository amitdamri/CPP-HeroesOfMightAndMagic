
#include "CreaturesHeader.h"
using namespace std;


int Zombie::attack(const int numberOfAttackers, const string creautreToAttack) const{

	if (creautreToAttack == "Zombie")
		return numberOfAttackers*m_powerOfAttack/m_powerOfDefense;

	else if (creautreToAttack == "Vampire"){
		Vampire vampire;
		return numberOfAttackers*m_powerOfAttack/vampire.getPowerOfDefense();
	}

	else if (creautreToAttack == "Archer"){
		Archer archer;
		//power of attack grows by 100 percent against archer
		return numberOfAttackers*(m_powerOfAttack*2)/archer.getPowerOfDefense();
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

