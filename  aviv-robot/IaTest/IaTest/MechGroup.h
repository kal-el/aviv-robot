#include "Mech.h"

class MechGroup{
private:
	vector<Mech> members;
	bool player;
public:
	MechGroup();
	~Mechgroup();
	Mech getMember(int number);
	Mech removeMember(int number);

};