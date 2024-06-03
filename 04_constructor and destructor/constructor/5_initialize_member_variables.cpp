#include<iostream>
#include<string>
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

class monster_b : public monster, character {
private:
	string monster_type;
	int location[2];
	static int total_count;
	const int unique_id;
	player& target;
	int difficult_level;
	char* quiz;
public:
	monster_b(player& attack_target)
		: monster_type("normal"),	//direct initialization
		location{ 0, 0 },			//uniform initialization
		unique_id(++total_count),	//initialization of constant variable
		target(attack_target) {		//initialization of reference variable
		difficult_level = 10;		//copy initialization
		quiz = new char[1024];		//dynamic memory allocation
	};
	~monster_b() {
		delete[]quiz;
		total_count--;
	};

	void set_quiz(const char* new_quiz) { strcpy_s(quiz, 1024, new_quiz); }
	void set_type(string type) { monster_type = type; }
	void set_difficult_level(int level) { difficult_level = level; }
	void set_location(int x, int y) { location[0] = x, location[1] = y; }
	char* get_quiz() { return quiz; }
	string get_type() { return monster_type; }
	int get_difficult_level() { return difficult_level; }
	int get_x_location() { return location[0]; }
	int get_y_location() { return location[1]; }
};

int monster_b::total_count = 0;		//initialization of static variable

int main() {
	player first_player;
	monster_b first_mon(first_player);
	first_mon.set_quiz("four foot in the morning, two throughout the day, and three in the night. What am I?");
	first_mon.set_difficult_level(100);
	first_mon.set_type("riddle monster");
	first_mon.set_location(30, 30);

	monster_b second_mon(first_player);
	second_mon.set_quiz("If a door flips, what is it called?");
	second_mon.set_location(45, 50);

	cout << "[" << first_mon.get_x_location() << ", " << first_mon.get_y_location() << "] first monster(" << first_mon.get_type() << " - " << first_mon.get_difficult_level()
		<< ")'s riddle: " << first_mon.get_quiz() << endl;
	cout << "[" << second_mon.get_x_location() << ", " << second_mon.get_y_location() << "] second monster(" << second_mon.get_type() << " - " << second_mon.get_difficult_level()
		<< ")'s riddle: " << second_mon.get_quiz() << endl;
}
