#include<iostream>
using namespace std;

int main() {
	
	int num;

	cout << "Enter decimal number:" << endl;
	cin >> num;

	while (num >= 1000) {
		cout << "M";
		num -= 1000;
	}

	while (num >= 500) {
		cout << "D";
		num -= 500;
	}

	while (num >= 100) {
		cout << "C";
		num -= 100;
	}

	while (num >= 50) {
		cout << "L";
		num -= 50;
	}	
	
	while (num >= 10) {
		cout << "X";
		num -= 10;
	}

	while (num >= 5) {
		cout << "V";
		num -= 5;
	}

	while (num >= 1) {
		cout << "I";
		num --;
	}

	cout << endl;
	
	return 0;
}