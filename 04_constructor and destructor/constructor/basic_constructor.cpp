#include<iostream>
using namespace std;

class character {
public:
	character() {
		cout << "character class's constructor" << endl;
	};
};

int main() {
	character player;

	return 0;
}
