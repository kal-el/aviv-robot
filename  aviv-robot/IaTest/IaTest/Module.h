#include "ClassConsts.h"
#define COCKPIT 1
#define LEGS 2
#define ARMS 3

class Module{
private:
	int type,energyBonus,speedBonus,shieldBonus,accuracyBonus;
	unsigned int classmask;
	string name,description;
public:
	Module();
	Module(string name,int type,unsigned int classmask,string description,int energyBonus=0,
		int speedBonus=0,int shieldBonus=0,int accuracyBonus=0);
	~Module();
	int getType();
	int getEnergyBonus();
	int getSpeedBonus();
	int getAccuracyBonus();
	int getShieldBonus();
	string getName();
	string getDescription();
	bool isForClass(unsigned int classconst);
};

Module::Module(){
	
}


Module::Module(string name,int type,unsigned int classmask,string description,int energyBonus,
		int speedBonus,int shieldBonus,int accuracyBonus){
	this->type = type;
	this->classmask = classmask;
	this->name = name;
	this->description = description;
	this->energyBonus = energyBonus;
	this->speedBonus = speedBonus;
	this->shieldBonus = shieldBonus;
	this->accuracyBonus = accuracyBonus;
}

Module::~Module(){}

int Module::getType(){
	return this->type;
}

int Module::getEnergyBonus(){
	return this->energyBonus;
}

int Module::getShieldBonus(){
	return this->shieldBonus;
}

int Module::getSpeedBonus(){
	return this->speedBonus;
}

int Module::getAccuracyBonus(){
	return this->accuracyBonus;
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