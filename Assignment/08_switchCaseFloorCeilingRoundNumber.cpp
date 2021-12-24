#include<iostream>
using namespace std;

int main() {

	double realNumber;
	int method;

	cout << "Please enter a real number : " << endl;
	cin >> realNumber;
	cout << "Choose your rounding method : " << endl;
	cout << "1.Floor round" << endl;
	cout << "2.Ceiling round" << endl;
	cout << "3.Round to the nearest whole number" << endl;
	cin >> method;

	if (realNumber >= 0) {
		switch (method) {
		case(1):
			cout << (int)realNumber << endl; break;
		case(2):
			cout << (int)(realNumber + 1) << endl; break;
		case(3):
			if (realNumber - (int)realNumber < 0.5) {
				cout << (int)realNumber << endl; break;
			}
			else {
				cout << (int)(realNumber + 1) << endl; break;
			}
		}
	}
	else {
		switch (method) {
		case(1):
			cout << (int)(realNumber - 1) << endl; break;
		case(2):
			cout << (int)realNumber << endl; break;
		case(3):
			if (realNumber - (int)realNumber >= -0.5) {
				cout << (int)realNumber << endl; break;
			}
			else {
				cout << (int)(realNumber - 1) << endl; break;
			}
		}
	}

	return 0;
}