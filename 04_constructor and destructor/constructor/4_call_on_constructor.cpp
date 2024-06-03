#include<iostream>
using namespace std;

class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
	cout << "basic attack: damage - 10 hp" << endl;
}

class monster_a :public monster, character {
private:
	int location[2];
public:
	monster_a() : monster_a(10, 10){  //call other constructor using initializer list
		cout << "monster_a class's constructor" << endl;
		//monster_a(10, 10); nameless object --> does not work as intended
	}
	monster_a(int x, int y) : location { x, y }{
		cout << "add a parameter to monster_a class's constructor" << endl;
	}
	void show_location() {
		cout << "location: [" << location[0] << ", " << location[1] << "]" << endl;
	}
};

int main() {
	monster_a forest_monster;
	forest_monster.show_location();
	
	return 0;
}
