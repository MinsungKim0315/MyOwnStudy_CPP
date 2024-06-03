#include<iostream>
using namespace std;

class monster {
public:
	monster() {
		cout << "monster class's constructor" << endl;
	}
	virtual ~monster() {	//virtual destructor
		cout << "monster class's destructor" << endl;
	}
};

class monster_a : public monster {
public:
	monster_a() {
		cout << "monster_a class's constructor" << endl;
	}
	virtual ~monster_a() {	//virtual destructor
		cout << "monster_a class's destructor" << endl;
	}
};

int main() {
	monster* forest_monster = new monster_a();
	delete forest_monster;

	return 0;
}
