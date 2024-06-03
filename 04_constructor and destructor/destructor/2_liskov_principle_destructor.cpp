#include<iostream>
using namespace std;

class monster {
public:
	monster() {
		cout << "monster class's constructor" << endl;
	}
	~monster() {
		cout << "monster class's destructor" << endl;
	}
};

class monster_a : public monster{
public:
	monster_a() {
		cout << "monster_a class's constructor" << endl;
	}
	~monster_a() {	//this destructor does not run --> child class can substitute parent class, but parent class is still used. 
					        //Thus, during deletion, parent class's destructor is called not child class's destructor.
		cout << "monster_a class's destructor" << endl;
	}
};

int main() {
	monster* forest_monster = new monster_a();
	delete forest_monster;

	return 0;
}
