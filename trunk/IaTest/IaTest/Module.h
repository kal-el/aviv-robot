#include "ClassConsts.h"
#define COCKPIT 1
#define LEGS 2
#define ARMS 3

class Module{
private:
	int code,bonus,type;
	unsigned int classmask;
	string name,description;
public:
	Module(int code,int bonus,int type,unsigned int classmask,string name,string description);
	~Module();
	int getCode();
	int getType();
	int getBonus();
	string getName();
	string getDescription();
	bool isForClass(unsigned int classconst);
};

Module::Module(int code,int bonus,int type,unsigned int classmask,string name,string description){
	this->code = code;
	this->bonus = bonus;
	this->type = type;
	this->classmask = classmask;
	this->name = name;
	this->description = description;
}

Module::~Module(){}

int Module::getCode(){
	return this->code;
}

int Module::getType(){
	return this->type;
}

int Module::getBonus(){
	return this->bonus;
}
	
string Module::getName(){
	return this->name;
}

string Module::getDescription(){
	return this->description;
}

/* 
   bitwise AND between input class constant and the module mask to check if
   module is suitable for the input class.
   	
	example: module set for TECH and SOLDIER
	MODULE MASK: 000001001
	we check if is suitable for TECH
	TECH: 000001000
	MASK & TECH = 000001000 = 256 >= 1 OK.
	otherwise, if we check for SNIPER
	SNIPER: 100000000
	MASK & SNIPER = 00000000 = 0 < 1 FAILS.

*/
bool Module::isForClass(unsigned int classconst){
	return (classmask & classconst)>=1;
}