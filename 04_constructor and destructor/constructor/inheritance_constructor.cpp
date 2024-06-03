#include<iostream>
using namespace std;

class character {
public:
	character() {
		cout << "character class's constructor" << endl;
	};
};

class monster {
public:
	monster() {
		cout << "monster class's constructor" << endl;
	};
};

class monster_a : public monster, character {
public:
	monster_a() {
		cout << "monster_a class's constructor" << endl;
	};
};

int main() {
	monster_a forest_monster;
	return 0;
}
