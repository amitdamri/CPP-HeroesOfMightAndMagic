
#include "Warrior.h"
using namespace std;


Warrior::~Warrior(){
	if (!m_creatureList.empty())
		m_creatureList.clear();
}

//adds 50 golds
void Warrior::useSpecialAttack(Hero& hero){
		(*this).takeGold(50);
		cout << "Gold added successfully" << endl;
}
