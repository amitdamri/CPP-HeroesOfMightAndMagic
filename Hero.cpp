
#include "Hero.h"
#include "CreaturesHeader.h"
#include <fstream>

using namespace std;


//Default constructor
Hero::Hero(){
	m_heroName="";
	m_heroType="Hero";
	m_numberOfGold =750;
}

//Constructor with parameters
Hero::Hero(string heroName,string heroType){
	m_numberOfGold = 750;
	m_heroType = heroType;
	if (heroName.length()>31)
		throw PlayerNameError();
	for (unsigned int i=0;i<heroName.length();i++){
		if (!((heroName[i]>='0' && heroName[i]<='9') || (heroName[i]>='a' && heroName[i]<='z') ||
				(heroName[i]>='A' && heroName[i]<='Z')))
			throw PlayerNameError();
	}
	m_heroName = heroName;
}

//Constructor only with hero type
Hero::Hero(string heroType){
	m_heroName = "";
	m_heroType = heroType;
	m_numberOfGold = 750;
}

//buy creatures according to the type and number of the request
void Hero::buyCreature(const Creature& creatureToBuy,const int numberOfCreatures){

	if (creatureToBuy.getType() == "Zombie"){
		if (m_numberOfGold < numberOfCreatures*creatureToBuy.getPrice())
			throw PurchaseError();
		m_numberOfGold -=numberOfCreatures*creatureToBuy.getPrice();
		if (m_creatureList.count(1)==1){
			m_creatureList[1].second += numberOfCreatures;
		}
		else {
			m_creatureList.insert(make_pair(1,make_pair("Zombie",numberOfCreatures)));
		}
	}
	else if (creatureToBuy.getType() == "Archer"){
		if (m_numberOfGold < numberOfCreatures*creatureToBuy.getPrice())
			throw PurchaseError();
		m_numberOfGold -=numberOfCreatures*creatureToBuy.getPrice();
		if (m_creatureList.count(3)==1){
			m_creatureList[3].second += numberOfCreatures;
		}
		else {
			m_creatureList.insert(make_pair(3,make_pair("Archer",numberOfCreatures)));
		}
	}
	else if (creatureToBuy.getType() == "Vampire"){
		if (m_numberOfGold < numberOfCreatures*creatureToBuy.getPrice())
			throw PurchaseError();
		m_numberOfGold -=numberOfCreatures*creatureToBuy.getPrice();
		if (m_creatureList.count(2)==1){
			m_creatureList[2].second += numberOfCreatures;
		}
		else {
			m_creatureList.insert(make_pair(2,make_pair("Vampire",numberOfCreatures)));
		}
	}
	else if (creatureToBuy.getType() == "Wizard"){
		if (m_numberOfGold < numberOfCreatures*creatureToBuy.getPrice())
			throw PurchaseError();
		m_numberOfGold -=numberOfCreatures*creatureToBuy.getPrice();
		if (m_creatureList.count(4)==1){
			m_creatureList[4].second += numberOfCreatures;
		}
		else {
			m_creatureList.insert(make_pair(4,make_pair("Wizard",numberOfCreatures)));
		}
	}
	else if (creatureToBuy.getType() == "Black_Dragon"){
		if (m_numberOfGold < numberOfCreatures*creatureToBuy.getPrice())
			throw PurchaseError();
		m_numberOfGold -=numberOfCreatures*creatureToBuy.getPrice();
		if (m_creatureList.count(5)==1){
			m_creatureList[5].second += numberOfCreatures;
		}
		else {
			m_creatureList.insert(make_pair(5,make_pair("Black_Dragon",numberOfCreatures)));
		}
	}
	else {
		throw CreatureError();
	}
}

//adds hundred golds
void Hero::getDailyGolds(){
	m_numberOfGold +=100;
	if (m_numberOfGold>2500)
		m_numberOfGold=2500;
}

//attacks other hero with the required creature against the required creature
void Hero::fightAttack(Hero& heroToFight,const string fightWith,const string fightAgainst){

	int numberOfKillings = 0;

	if (!heroToFight.creatureExist(fightAgainst) || !this->creatureExist(fightWith))
		throw AttackingError();

	if (fightWith == "Zombie"){
		Zombie zombie;
		numberOfKillings = zombie.attack(m_creatureList[1].second,fightAgainst);
		heroToFight.fightAttackUpdateCreature(numberOfKillings,fightAgainst);
	}

	else if (fightWith == "Vampire"){
		Vampire vampire;
		numberOfKillings = vampire.attack(m_creatureList[2].second,fightAgainst);
		heroToFight.fightAttackUpdateCreature(numberOfKillings,fightAgainst);
	}

	else if (fightWith == "Archer"){
		Archer archer;
		numberOfKillings = archer.attack(m_creatureList[3].second,fightAgainst);
		heroToFight.fightAttackUpdateCreature(numberOfKillings,fightAgainst);
	}

	else if (fightWith == "Wizard"){
		Wizard wizard;
		numberOfKillings = wizard.attack(m_creatureList[4].second,fightAgainst);
		heroToFight.fightAttackUpdateCreature(numberOfKillings,fightAgainst);
	}

	else if (fightWith == "Black_Dragon"){
		BlackDragon blackDragon;
		numberOfKillings = blackDragon.attack(m_creatureList[5].second,fightAgainst);
		heroToFight.fightAttackUpdateCreature(numberOfKillings,fightAgainst);
	}

	else
		throw CreatureError();

}

//print for attack
void Hero::attackDetails() const{
	cout << m_heroName << " " << m_heroType << ":" << endl;
	printCreatures();
}

//shows the details of the hero
void Hero::showDetails() const{

	cout << m_heroName << " " << m_heroType << ":" << endl;
	cout << m_numberOfGold << " gold" << endl;
	printCreatures();
}

//print for attack show opponents
void Hero::opponentsDetails() const{
	cout << getHeroName() << " " << getHeroType() << endl;
}

//prints the creature list
void Hero::printCreatures() const{
	if (!m_creatureList.empty()){

		map<int,pair<string,int> >::const_iterator it = m_creatureList.begin();
		cout << it->second.second << " " << it->second.first;
		++it;
		for (;it != m_creatureList.end(); ++it){
			cout << " " << it->second.second << " " << it->second.first;
		}

		cout << "." << endl;
	}
}


//getters

//returns the hero name
string Hero::getHeroName() const{
	return m_heroName;
}

//returns the hero type
string Hero::getHeroType() const{
	return m_heroType;
}

//returns the number of gold that the hero has
int Hero::getHeroGold() const{
	return m_numberOfGold;
}

//returns the number of creatures that the hero has
int Hero::getNumberOfCreatures() const{
	return m_creatureList.size();
}

//subtracts the amount of gold from the hero's gold after he was robbed or after he lose in a fight
void Hero::lostGold(int amount){
	m_numberOfGold -= amount;
	if (m_numberOfGold<0)
		m_numberOfGold =0;
}

//adds to the hero's gold the required amount of gold - after he was win or after he robbed another hero
void Hero::takeGold(int amount){
	m_numberOfGold += amount;
	if (m_numberOfGold >2500)
		m_numberOfGold = 2500;
}

//check if the hero has the given creature
bool Hero::creatureExist(const string creatureType) const{

	int creatureNumber = convertCreatureToNumber(creatureType);
	if (m_creatureList.count(creatureNumber) == 1)
		return true;
	return false;
}

//converts creature to number in order to insert the creature to the map - key of the creature
int Hero::convertCreatureToNumber(const string creatureType) const{

	if (creatureType == "Zombie")
		return 1;
	else if (creatureType == "Vampire")
		return 2;
	else if (creatureType == "Archer")
		return 3;
	else if (creatureType == "Wizard")
		return 4;
	else if (creatureType == "Black_Dragon")
		return 5;
	else
		throw CreatureError();
}

//updates the map after a fight
void Hero::fightAttackUpdateCreature(int numberOfKillings,const string creatureToUpdate){
	int index = 0,numberOfDefendings=0;

	if (numberOfKillings>0){

		//number of defending creatures
		index = convertCreatureToNumber(creatureToUpdate);
		numberOfDefendings = m_creatureList[index].second;
		if (numberOfDefendings>numberOfKillings) // have more creatures
			m_creatureList[index].second -= numberOfKillings;
		else {
			m_creatureList[index].second = 0;
			m_creatureList.erase(index);
		}
	}

}

//writes all of the information about the hero to his log file
void Hero::writeInfo() const{

	//writes hero log
	string path = "HeroesOfTheGame/"+ m_heroName +"/HeroLog.txt";
	ofstream heroLog (path.c_str());
	heroLog << "HeroName:" << m_heroName << endl;
	heroLog << "HeroType:" << m_heroType << endl;
	heroLog << "HeroGold:" << m_numberOfGold << endl;
	heroLog << "PlayerCreatures:" << endl;
	if (!m_creatureList.empty()){
		map<int,pair<string,int> >::const_iterator it = m_creatureList.begin();
		for (;it != m_creatureList.end(); ++it){
			heroLog << it->second.first << "," << it->second.second << endl;
		}

	}
	else
		heroLog << "0" << endl;
	heroLog.close();
}

//loads from the log file all of the information about the hero
void Hero::readLogFile() {

	string path = "HeroesOfTheGame/" + m_heroName +"/HeroLog.txt";
	string line ="";
	int amountOfCreature = 0;
	ifstream readHeroLog(path.c_str());

	if (!readHeroLog.is_open()){
		throw ReadFileError();
	}

	while (getline(readHeroLog,line)){

		if (line.substr(0,line.find(":")) == "HeroName")
			m_heroName = line.substr(line.find(":")+1);

		else if (line.substr(0,line.find(":")) == "HeroType")
			m_heroType = line.substr(line.find(":")+1);

		else if (line.substr(0,line.find(":")) == "HeroGold")
			m_numberOfGold = atoi(line.substr(line.find(":")+1).c_str());

		else if (line == "PlayerCreatures:")
				continue;

		//creatures
		else if (line.substr(0,line.find(",")) == "Zombie"){
			amountOfCreature = atoi(line.substr(line.find(",")+1).c_str());
			m_creatureList.insert(make_pair(1, make_pair("Zombie",amountOfCreature)));
		}

		else if (line.substr(0,line.find(",")) == "Vampire"){
			amountOfCreature = atoi(line.substr(line.find(",")+1).c_str());
			m_creatureList.insert(make_pair(2, make_pair("Vampire",amountOfCreature)));
		}

		else if (line.substr(0,line.find(",")) == "Archer"){
			amountOfCreature = atoi(line.substr(line.find(",")+1).c_str());
			m_creatureList.insert(make_pair(3, make_pair("Archer",amountOfCreature)));
		}

		else if (line.substr(0,line.find(",")) == "Wizard"){
			amountOfCreature = atoi(line.substr(line.find(",")+1).c_str());
			m_creatureList.insert(make_pair(4, make_pair("Wizard",amountOfCreature)));
		}

		else if (line.substr(0,line.find(",")) == "Black_Dragon"){
			amountOfCreature = atoi(line.substr(line.find(",")+1).c_str());
			m_creatureList.insert(make_pair(5, make_pair("Black_Dragon",amountOfCreature)));
		}

	}

	readHeroLog.close();
}
