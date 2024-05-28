#include<iostream>
using namespace std;

//Implicit cast
int main() {
	float float_value = 1.5f;	//Original Data

	double double_value = float_value;	//Numeric Promotion: no data leak
	int int_value = float_value;	//Numeric conversion: data leak could occur

	cout << "float_value: " << float_value << endl;
	cout << "double_value: " << double_value << endl;
	cout << "int_value: " << int_value << endl;

	return 0;
}
