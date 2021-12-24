#include<iostream>
using namespace std;
#include <cmath>

int main() {

	int n, digit,tempNum;

	cout << "Enter decimal number:" << endl;
	cin >> n;

	tempNum = n;
	digit = 0;
	while (tempNum > 0) {
		digit++;
		tempNum /= 2;
	}
	if (n == pow(2, digit))
		digit++;
	cout << "The number of bits of binary representation id " << digit << endl;

	cout << "The binary representation of " << n << " is ";
	while (digit > 0) {
		digit--;
		tempNum = pow(2, digit);
		if (n >= tempNum) {
			cout << "1";
			n -= tempNum;
		}
		else {
			cout << "0";
		}
	}
	cout << endl;

	return 0;
}