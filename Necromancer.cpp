
#include "Necromancer.h"
using namespace std;


Necromancer::~Necromancer(){
	if (!m_creatureList.empty())
		m_creatureList.clear();
}

//adds zombie to his army
void Necromancer::useSpecialAttack(Hero& hero){
		if (m_creatureList.count(1)==1)
			++m_creatureList[1].second;
		else {
			m_creatureList.insert(make_pair(1,make_pair("Zombie",1)));
		}
		cout << "Zombie added successfully" << endl;
}
