#include <iostream>
#include "Mech.h"
using namespace std;

int main(int argc,char **argv){
	Effect *first = new Effect("poison","enemy",-2,"stealth","NULL");
	Effect *second = new Effect("damage","enemy",-2000);
	Ability *ability = new Ability("0001","sputazzata atomica","Una raschata impetuosa",*first,1,SOLDIER|TECH,0.5);
	ability->addEffect(*second);
	printf("%d\n",ability->getEffects().size());
	cout << ability->getDescription() << "\n";
	cout << ability->isForClass(SOLDIER) << "\n";
	cout << ability->isForClass(TECH)<< "\n";
	cout << ability->isForClass(SNIPER)<< "\n";
	Driver *d = new Driver("Giggin o bell",3,4);
	cout << d->getLevels()->stealth_level << "\n";
	d->getLevels()->stealth_level+=10;
	cout << d->getLevels()->stealth_level << "\n";
	system("PAUSE");
	return 0;
}