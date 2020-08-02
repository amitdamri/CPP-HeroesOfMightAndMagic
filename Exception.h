
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

using namespace std;


class Exception {
public:
		Exception(){};
		virtual ~Exception(){};
		virtual void handle() = 0;
};


class PlayerNameError : public Exception {
public:
	PlayerNameError() : Exception() {};
	virtual void handle() {
		cerr << "Error: the player name must be in the given format - 'a'-'z','A'-'Z',0-9 and with maximum of 31 letters." << endl;
		cerr << "Please insert the player name again:" << endl;
	};
};


class PurchaseError : public Exception {
public:
	PurchaseError() : Exception() {};
	virtual void handle() { cerr << "Error: you don't have enough money to buy this amount of the requested creature." << endl; };
};


class AttackingError : public Exception {
public:
	AttackingError() : Exception() {};
	virtual void handle() {
		cerr << "Error: you have chosen creature that doesn't exist in one of the armies." << endl;
		cerr << "Please choose another creature." << endl;
	};
};


class HeroExistenceError : public Exception {
public:
	HeroExistenceError() : Exception() {};
	virtual void handle() { cerr << "Error: hero doens't exist. Please insert hero's name again:" << endl; };
};


class CreatureError : public Exception {
public:
	CreatureError() : Exception() {};
	virtual void handle() { cerr << "Error: you have entered an unknown creature. Please insert creature's name again." << endl; };
};


class ReadFileError : public Exception {
public:
	ReadFileError() : Exception() {};
	virtual void handle() { cerr << "Sorry, Can't reload the game. please try again." << endl; };
};

class OpenFolderError : public Exception {
public:
	OpenFolderError() : Exception() {};
	virtual void handle() { cerr << "Error: can't create the folders please try again." << endl; };
};


class ParamatersError : public Exception {
public:
	ParamatersError() : Exception() {};
	virtual void handle() { cerr << "Error: Can't create the game. You have entered more than 3 heroes of one kind." << endl; };
};




#endif /* EXCEPTION_H_ */
