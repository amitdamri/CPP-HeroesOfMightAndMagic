
#include "CreaturesHeader.h"

using namespace std;


int BlackDragon::attack(const int numberOfAttackers, const string creautreToAttack) const{

	if (creautreToAttack == "Black_Dragon")
		return numberOfAttackers*m_powerOfAttack/m_powerOfDefense;

	else if (creautreToAttack == "Vampire"){
		Vampire vampire;
		return numberOfAttackers*m_powerOfAttack/vampire.getPowerOfDefense();
	}

	else if (creautreToAttack == "Archer"){
		Archer archer;
		return numberOfAttackers*(m_powerOfAttack*2)/archer.getPowerOfDefense();
	}

	else if (creautreToAttack == "Wizard"){
		Wizard wizard;
		//power of defense of the wizard grows by 100 percent against black dragon
		return numberOfAttackers*m_powerOfAttack/(wizard.getPowerOfDefense()*2);
	}

	else if (creautreToAttack == "Zombie"){
		Zombie zombie;
		return numberOfAttackers*m_powerOfAttack/zombie.getPowerOfDefense();
	}

	else
		return 0;
}

