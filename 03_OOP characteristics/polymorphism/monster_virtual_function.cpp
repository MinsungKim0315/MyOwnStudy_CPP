#include<iostream>
using namespace std;

class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

// Single Inheritance
class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
	cout << "basic attack: damage - 10 hp" << endl;
}

// Multiple Inheritance
class monster_a :public monster, character {	// no access specifier means private
public:
	virtual void attack_special(player target_player) override;
};
void monster_a::attack_special(player target_player) {
	cout << "Entangle attack: damage - 15 hp" << endl;
}

class monster_b :public monster, character {
public:
	virtual void attack_special(player target_player) override;
};
void monster_b::attack_special(player target_player) {
	cout << "fake attack: damage - 0 hp" << endl;

}class monster_c :public monster, character {
public:
	virtual void attack_special(player target_player) override;
};
void monster_c::attack_special(player target_player) {
	cout << "Electric attack: damage - 100 hp" << endl;
}

int main() {
	player player_1;

	monster_a forest_monster;

	monster& mon = forest_monster;
	monster_a& mon_a = forest_monster;

	cout << "parent class reference attack" << endl;
	mon.attack_special(player_1);	//Eventhough it is referring the parent class, child class's overrided function gets called due to virtual function

	cout << "child class reference attack" << endl;
	mon_a.attack_special(player_1);

	cout << "namespace attack" << endl;
	mon_a.monster::attack_special(player_1);
	return 0;
}
