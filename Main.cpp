
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
#include "Exception.h"
#include "CreaturesHeader.h"
#include <dirent.h>
#include <sys/stat.h>
#include <fstream>


using namespace std;

//function declarations
void createNewGame(Hero** gameHeroes,int,int,int);
void writeGameLog(int ,int ,int ,int ,int ,int ,int ,int ,int ,int ,Hero* gameHeroes[]);

//Main function
int main (int argc, char* argv[]) {

	//variables for the game
	int numOfWarrior = 0, numOfThief = 0, numOfNacromancer = 0;
	int gameHeroSize = 0; // total number of heroes
	int numberOfLivePlayers = 0;
	//dailyGold = 1 if the player already got gold at his current turn,
	//specialSkill = 1 if the player already used it at the current turn
	int dailyGold = 0,specialSkill = 0, round = 0;
	int playerTurn = 0, first =0; // first player to start the round, and current player turn
	int input = 0;
	Hero** gameHeroes = NULL; //heroes of the game


	/**********************************************************************************************************
	 ******************************************Continue last game**********************************************
	 **********************************************************************************************************/

	if(argc == 2){

		string line ="";
		string heroName="", heroType = "";
		int playerPlaceInArray=0;

		ifstream readGameLog("game/gameLog.txt");

		//problem with the text file
		if (!readGameLog.is_open()){
			throw  "Sorry, Can't reload the game. please try again";
		}

		//reading the log file and loading the information of the previous game
		while (getline(readGameLog,line)){

			if (line.substr(0,line.find(":")) == "PlayerTurn")
				playerTurn = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "FirstPlayerToPLay")
				first = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "RoundNumber")
				round = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "GotDailyGold")
				dailyGold = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "UsedSpecialSkill")
				specialSkill = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "NumberOfLivePlayers")
				numberOfLivePlayers = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "NumberOfWarriors")
				numOfWarrior = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "NumberOfThieves")
				numOfThief = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "NumberOfNacromancers")
				numOfNacromancer = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "TotalNumberOfHeroes"){
				gameHeroSize = atoi((line.substr(line.find(":")+1)).c_str());
				gameHeroes = new Hero*[gameHeroSize];
			}

			//players list
			else if (line == "Players:")
				continue;

			else if (line.substr(0,line.find(":")) == "PlayerNumber")
				playerPlaceInArray = atoi((line.substr(line.find(":")+1)).c_str());

			else if (line.substr(0,line.find(":")) == "PlayerName")
				heroName = line.substr(line.find(":")+1);

			else if (line.substr(0,line.find(":")) == "PlayerType"){

				heroType = line.substr(line.find(":")+1);
				if (heroType == "Warrior"){
					Warrior* warrior = new Warrior(heroName);
					gameHeroes[playerPlaceInArray] = warrior;
				}
				else if (heroType == "Thief"){
					Thief* thief = new Thief(heroName);
					gameHeroes[playerPlaceInArray] = thief;
				}
				else if (heroType == "Necromancer"){
					Necromancer* nacro = new Necromancer(heroName);
					gameHeroes[playerPlaceInArray] = nacro;
				}
				//reset
				heroName = "";
				heroType = "";
				playerPlaceInArray = 0;
			}
		}
		readGameLog.close();
		//loads the information about every hero
		try{
			for (int i=0; i<gameHeroSize;i++){
				gameHeroes[i]->readLogFile();
			}
		}
		catch (Exception& e){
			e.handle();
			return 1;
		}
	}

	/**********************************************************************************************************
	 ******************************************Create new game*************************************************
	 **********************************************************************************************************/

	else if (argc == 5){

		//initialize variables for the program
		numOfWarrior = *argv[2] - '0';
		numOfThief = *argv[3] - '0';
		numOfNacromancer = *argv[4] - '0';
		try{
			if (numOfWarrior >3 || numOfThief >3 || numOfNacromancer >3)
				throw ParamatersError();
		}
		catch(Exception& e){
			e.handle();
			return 1;
		}
		gameHeroSize = numOfNacromancer + numOfThief + numOfWarrior;
		numberOfLivePlayers = gameHeroSize;
		dailyGold = 0,specialSkill = 0, round = 0;
		srand(time(NULL)); // function to randomize the seed if random
		playerTurn = rand() % gameHeroSize;
		first = playerTurn;
		gameHeroes = new Hero*[gameHeroSize];
		createNewGame(gameHeroes,numOfWarrior,numOfThief,numOfNacromancer);
	}

	/**********************************************************************************************************
	 ******************************************Game progress***************************************************
	 **********************************************************************************************************/


	while (input != 7 ){
		cout << "Welcome " << gameHeroes[playerTurn]->getHeroName() << endl;
		cout << "What is your next step in the path to victory?" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Get daily gold" << endl;
		cout << "3. Buy creatures" << endl;
		cout << "4. Show details" << endl;
		cout << "5. Special skill" << endl;
		cout << "6. End of my turn" << endl;
		cout << "7. Exit" << endl;
		cin >> input;

		switch (input) {

		case 1:

			cout << "1. Show me my opponents" << endl;
			cout << "2. Attack hero" << endl;
			cin >> input;

			switch (input){

			case 1:
				for (int i=0; i<gameHeroSize ;i++){
					if (gameHeroes[i]->getHeroName() != gameHeroes[playerTurn]->getHeroName()
							&& ((gameHeroes[i]->getNumberOfCreatures()>0 && round>=3)|| round<3))
						gameHeroes[i]->opponentsDetails();
				}
				cin.ignore();
				cin.get();
				break;

			case 2:
				if (round >=3){
					bool validCreature = false;
					string name = "";
					string attacking="",defending="";
					bool heroExists = false;
					cout << "Please insert your opponent name:" << endl;
					while (!heroExists){
						try {
							cin >> name;
							cin.ignore();
							for (int i=0;i<gameHeroSize;i++){
								if (gameHeroes[i]->getHeroName() == name && i != playerTurn){
									heroExists = true;
									if(gameHeroes[i]->getNumberOfCreatures()>0){
										//players have more creatures
										while(gameHeroes[playerTurn]->getNumberOfCreatures()>0 &&gameHeroes[i]->getNumberOfCreatures()>0){

											//first player attack
											while (!validCreature){
												try{
													gameHeroes[playerTurn]->attackDetails();
													cout << endl;
													gameHeroes[i]->attackDetails();
													cout << gameHeroes[playerTurn]->getHeroName() << "'s turn:" << endl;
													//try catch


													getline(cin, name);
													attacking = name.substr(0,name.find(" "));
													defending = name.substr(name.find(" ")+1);
													gameHeroes[playerTurn]->fightAttack(*gameHeroes[i],attacking,defending);
													validCreature = true;
												}
												catch(Exception& e){
													e.handle();
												}
											}
											validCreature = false; //reset

											//second player attack
											if (gameHeroes[i]->getNumberOfCreatures()<=0)
												break;
											while (!validCreature){
												try{
													gameHeroes[i]->attackDetails();
													cout << endl;
													gameHeroes[playerTurn]->attackDetails();
													cout << gameHeroes[i]->getHeroName() << "'s turn:" << endl;
													name = "";
													getline(cin, name);
													attacking = name.substr(0,name.find(" "));
													defending = name.substr(name.find(" ")+1);
													gameHeroes[i]->fightAttack(*gameHeroes[playerTurn],attacking,defending);
													validCreature = true;
												}
												catch (Exception &e){
													e.handle();
												}
											}
											validCreature = false; //reset
										}
										//checks if the attacking player won
										if (gameHeroes[playerTurn]->getNumberOfCreatures()>0){
											cout << "You have been victorious" << endl;
											--numberOfLivePlayers;//one player dead
											gameHeroes[playerTurn]->takeGold(gameHeroes[i]->getHeroGold());//takes gold from the loser
											gameHeroes[i]->lostGold(gameHeroes[i]->getHeroGold());
											//if only one player is alive - player won end of the game.
											if(numberOfLivePlayers==1){
												cout << gameHeroes[playerTurn]->getHeroName() << " is the winner!" << endl;
												for (int i=0;i<gameHeroSize;i++){
													delete gameHeroes[i];
													gameHeroes[i] = NULL;
												}
												delete[] gameHeroes;
												gameHeroes = NULL;
												input = 7; //end of game
											}
										}
										//if the defending player won
										else {
											cout << "You have been perished" << endl;
											--numberOfLivePlayers;
											gameHeroes[i]->takeGold(gameHeroes[playerTurn]->getHeroGold());//takes gold from the loser
											gameHeroes[playerTurn]->lostGold(gameHeroes[playerTurn]->getHeroGold());
											//if only one player is alive - player won end of the game.
											if(numberOfLivePlayers==1){
												cout << gameHeroes[i]->getHeroName() << " is the winner!" << endl;
												for (int i=0;i<gameHeroSize;i++){
													delete gameHeroes[i];
													gameHeroes[i] = NULL;
												}
												delete[] gameHeroes;
												gameHeroes = NULL;
												input = 7; //end of game
											}
											//return to the first player
											++playerTurn;
											if(playerTurn >= gameHeroSize)
												playerTurn =0;;
										}
										break;
									}
									else{
										//no hero with this name or he is trying to attack himself or a dead player
										heroExists = false;
										throw HeroExistenceError();
									}
								}
							}
							//no hero with this name or he is trying to attack himself or a dead player
							if (heroExists == false)
								throw HeroExistenceError();
						}
						catch(Exception& e){
							e.handle();
						}
					}
					break;
				}//round<3
				else
					cout << "You can't attack before round number 3." << endl;
			} // inner switch
			break;

			case 2:
				if(dailyGold ==0){
					gameHeroes[playerTurn]->getDailyGolds();
					dailyGold =1;
				}
				break;

			case 3:
				try{
					int amountToBuy = 0;
					cout << "1. Buy Zombies." << endl;
					cout << "2. Buy Archers." << endl;
					cout << "3. Buy Vampire." << endl;
					cout << "4. Buy Wizard." << endl;
					cout << "5. Buy Black Dragon." << endl;
					cin >> input;

					switch (input) {

					case 1:
					{
						Zombie zombie;
						Creature &creature = zombie;
						creature.showDetails();
						cin >> amountToBuy;
						gameHeroes[playerTurn]->buyCreature(creature,amountToBuy);
						break;
					}

					case 2:
					{
						Archer archer;
						Creature &creature = archer;
						creature.showDetails();
						cin >> amountToBuy;
						gameHeroes[playerTurn]->buyCreature(creature,amountToBuy);
						break;
					}

					case 3:
					{
						amountToBuy = 0;
						Vampire vampire;
						Creature &creature = vampire;
						creature.showDetails();
						cin >> amountToBuy;
						gameHeroes[playerTurn]->buyCreature(creature,amountToBuy);
						break;
					}

					case 4:
					{
						Wizard wizard;
						Creature &creature = wizard;
						creature.showDetails();
						cin >> amountToBuy;
						gameHeroes[playerTurn]->buyCreature(creature,amountToBuy);
						break;
					}

					case 5:
					{
						BlackDragon blackDragon;
						Creature &creature = blackDragon;
						creature.showDetails();
						cin >> amountToBuy;
						gameHeroes[playerTurn]->buyCreature(creature,amountToBuy);
						break;
					} //case 5
					} //inner switch
				}
				catch(Exception& e){
					e.handle();
				}
				break;

			case 4:
				gameHeroes[playerTurn]->showDetails();
				break;

			case 5:
				if (specialSkill == 0){
					//checks if the hero is warrior or thief or necromancer and activates his special skill
					Hero* hero = dynamic_cast<Warrior*>(*&gameHeroes[playerTurn]);
					if (hero != NULL)
						hero->useSpecialAttack(*gameHeroes[playerTurn]);
					else {
						hero = dynamic_cast<Thief*>(*&gameHeroes[playerTurn]);
						if (hero != NULL){
							string name = "";
							cout << "Please insert hero name:" << endl;
							bool heroExists =false;
							while (!heroExists){
								try{
									cin >> name;
									for (int i=0;i<gameHeroSize;i++){
										if (gameHeroes[i]->getHeroName() == name && i != playerTurn){
											if( round <3){
												hero->useSpecialAttack(*gameHeroes[i]);
												heroExists =true;
											}
											else if (gameHeroes[i]->getNumberOfCreatures()<=0) //hero dead
												throw HeroExistenceError();
											else{
												hero->useSpecialAttack(*gameHeroes[i]);
												heroExists =true;
											}
										}
									}
									if (heroExists == false)
										throw HeroExistenceError();
								}
								catch (Exception& e){
									e.handle();
								}
							}
						}
						else {
							hero = dynamic_cast<Necromancer*>(*&gameHeroes[playerTurn]);
							if (hero != NULL)
								hero->useSpecialAttack(*gameHeroes[playerTurn]);
						}
					}
					++specialSkill;
				}
				break;

			case 6 :
				++playerTurn;
				if (playerTurn >= gameHeroSize)
					playerTurn =0;
				if (playerTurn == first)
					++round;
				//after round number 3 dead players don't participate in the game
				while (gameHeroes[playerTurn]->getNumberOfCreatures()==0 && round >=3){
					++playerTurn;
					if (playerTurn >= gameHeroSize)
						playerTurn =0;
					if (playerTurn == first)
						++round;
				}
				specialSkill=0;//reset
				dailyGold = 0;//reset
				break;

			case 7:
				//saves all of the information of the current game and deletes all of the memory
				writeGameLog(playerTurn,first,round,dailyGold,specialSkill,numberOfLivePlayers,
						numOfWarrior,numOfThief,numOfNacromancer,gameHeroSize,gameHeroes);
				for (int i=gameHeroSize-1;i>=0;--i){
					delete gameHeroes[i];
					gameHeroes[i] = NULL;
				}
				delete[] gameHeroes;
				gameHeroes = NULL;
				break;

			default:
				cout << "Please choose a valid option." << endl;
				break;
		}
	}
	return 0;
}

//writes all of the information of the game into a log file after exit
void writeGameLog(int playerTurn,int first,int round,int dailyGold,int specialSkill,int numberOfLivePlayers,
		int numOfWarrior,int numOfThief,int numOfNacromancer,int gameHeroSize,Hero* hero[]){

	//game log
	ofstream gameLog ("game/gameLog.txt");

	gameLog << "PlayerTurn:" << playerTurn << endl;
	gameLog << "FirstPlayerToPLay:" << first << endl;
	gameLog << "RoundNumber:" << round << endl;
	gameLog << "GotDailyGold:" << dailyGold << endl;
	gameLog << "UsedSpecialSkill:" << specialSkill << endl;
	gameLog << "NumberOfLivePlayers:" << numberOfLivePlayers << endl;
	gameLog << "NumberOfWarriors:" << numOfWarrior << endl;
	gameLog << "NumberOfThieves:" << numOfThief << endl;
	gameLog << "NumberOfNacromancers:" << numOfNacromancer << endl;
	gameLog << "TotalNumberOfHeroes:" << gameHeroSize << endl;
	gameLog << "Players:" << endl;

	//heroes log
	for (int i=0;i<gameHeroSize;i++){
		gameLog << "PlayerNumber:" << i << endl;
		gameLog << "PlayerName:" << hero[i]->getHeroName() << endl;
		gameLog << "PlayerType:" << hero[i]->getHeroType() << endl;
		hero[i]->writeInfo();
	}
	gameLog.close();

}

//creates the heros of the new game according to the user parameters and all of the required directories
void createNewGame(Hero** gameHeroes,int numOfWarrior,int numOfThief,int numOfNacromancer){

	//removes previous game files
	DIR *dir = opendir("game");
	if (dir){
		system("rm -r game");
	}
	closedir(dir);

	dir = opendir("HeroesOfTheGame");
	if (dir){
		system("rm -r HeroesOfTheGame");
	}
	closedir(dir);

	//creates new game
	bool validName = false;
	string heroName = "";
	string destination = "HeroesOfTheGame/";
	int index = 0;
	if(mkdir("game",S_IRWXU | S_IRWXG | S_IRWXO) != 0){
		throw OpenFolderError();
	}
	if (mkdir("HeroesOfTheGame",S_IRWXU | S_IRWXG | S_IRWXO) != 0){
		throw OpenFolderError();
	}

	for (int i=0;i<numOfWarrior;i++){
		cout << "Please insert warrior number " << i+1 << " name:" << endl;
		while (true != validName){
			try{
				cin >> heroName;
				destination = "HeroesOfTheGame/";
				destination += heroName;
				Warrior* warrior = new Warrior(heroName);
				gameHeroes[index] = warrior;
				++index;
				if (mkdir(destination.c_str(),S_IRWXU | S_IRWXG | S_IRWXO)!= 0){
					throw OpenFolderError();
				}
				validName = true;
			}
			catch(Exception& e){
				e.handle();
			}
		}
		validName = false;
	}

	for (int i=0;i<numOfThief;i++){
		cout << "Please insert thief number " << i+1 << " name:" << endl;
		while (true != validName){
			try{
				cin >> heroName;
				destination = "HeroesOfTheGame/";
				destination += heroName;
				Thief* theif = new Thief(heroName);
				gameHeroes[index] = theif;
				++index;
				if (mkdir(destination.c_str(),S_IRWXU | S_IRWXG | S_IRWXO)!= 0){
					throw OpenFolderError();
				}
				validName = true;
			}
			catch (Exception& e){
				e.handle();
			}
		}
		validName = false;
	}

	for (int i=0;i<numOfNacromancer;i++){
		cout << "Please insert necromancer number " << i+1 << " name:" << endl;
		while (true != validName){
			try{
				cin >> heroName;
				destination = "HeroesOfTheGame/";
				destination += heroName;
				Necromancer* nacro = new Necromancer(heroName);
				gameHeroes[index] = nacro;
				++index;
				if (mkdir(destination.c_str(),S_IRWXU | S_IRWXG | S_IRWXO)!= 0){
					throw OpenFolderError();
				}
				validName = true;
			}
			catch (Exception& e){
				e.handle();
			}
		}
		validName = false;
	}
	index=0; //reset

}
