#include "Ability.h"
#include "Driver.h"
#include "Module.h"

class Mech{
private:
	int energy,shield,speed,accuracy;
	int shieldBonus,speedBonus,accuracyBonus;
	string name;
	unsigned int currentClass; // driver or module??
	vector<Ability> abilities;
	Module cockpit,legs,arms;
public:
	Mech(string name,int energy,int shield,int speed,int accuracy);
	~Mech();
	void setCockpit(Module c);
	void setLegs(Module l);
	void setArms(Module a);
	void addAbility(Ability a);
	void removeAbility(Ability a);
	vector<Ability> getAbilities();
	int getEnergy();
	int getShield();
	int getSpeed();
	int getAccuracy();
	string getName();
};

Mech::Mech(string name,int energy,int shield,int speed,int accuracy){
	this->name = name;
	this->energy = energy;
	this->shield = shield;
	this->speed = speed;
	this->accuracy = accuracy;
	shieldBonus = 0;
	speedBonus = 0;
	accuracyBonus = 0;
	/* HERE WE SHOULD SET A DEFAULT MODULE FOR COCKPIT, LEGS AND ARMS */
}

Mech::~Mech(){
	delete abilities;
	/*
	delete cockpit;
	delete legs;
	delete arms;
	*/
}

void Mech::setCockpit(Module c){
	if(c.getType()!=COCKPIT) ; // exception??
	else{
		this->cockpit = c;
		// the cockpit sets bonus for shield
		this->shield -= shieldBonus;
		this->shieldBonus = c.getBonus();
		this->shield += shieldBonus;
	}
}

void Mech::setLegs(Module l){
	if(l.getType()!= LEGS) ; // exception??
	else{
		this->legs = l;
		// the legs sets bonus for speed
		this->speed -= speedBonus;
		this->speedBonus = l.getBonus();
		this->speed += speedBonus;
	}
}

void Mech::setArms(Module a){
	if(a.getType()!= ARMS) ; // exception??
	else{
		this->arms = a;
		// the legs sets bonus for speed
		this->accuracy -= accuracyBonus;
		this->accuracyBonus = a.getBonus();
		this->accuracy += accuracyBonus;
	}
}

void Mech::addAbility(Ability a){
	abilities.push_back(a);
}

void Mech::removeAbility(Ability a){
	//BETTER TO CHECK OUT...
	//abilities.erase(a);
}

vector<Ability> Mech::getAbilities(){
	return abilities;
}

int Mech::getEnergy(){
	return energy;
}

int Mech::getAccuracy(){
	return accuracy;
}

int Mech::getShield(){
	return shield;
}

int Mech::getSpeed(){
	return speed;
}