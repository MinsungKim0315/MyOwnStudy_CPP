#include<iostream>
using namespace std;

class bank {
private:
	int safe;
public:
	bank();
	void use_counter(int _in, int _out);
};
bank::bank() {
	safe = 1000;
	cout << "Initial: " << safe << endl << endl;
}
void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;

	cout << "in: " << _in << endl;
	cout << "out: " << _out << endl;
	cout << "balance: " << safe << endl << endl;
}

int main() {
	bank my_bank;

	my_bank.use_counter(0, 20);
	my_bank.use_counter(50, 0);
	my_bank.use_counter(100, 50);

	return 0;
}
