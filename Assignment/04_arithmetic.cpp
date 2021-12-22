#include<iostream>
using namespace std;

int main() {

	int num1, num2;
	int sum, sub, mul, div, mod;
	double divide;

	cout << "Please enter two positive integers, separated by a space : " << endl;
	cin >> num1 >> num2;

	sum = num1 + num2;
	sub = num1 - num2;
	mul = num1 * num2;
	divide = (double) num1 / (double) num2;
	div = num1 / num2;
	mod = num1 % num2;

	cout << num1 << " + " << num2 << " = " << sum << endl;
	cout << num1 << " - " << num2 << " = " << sub << endl;
	cout << num1 << " * " << num2 << " = " << mul << endl;
	cout << num1 << " / " << num2 << " = " << divide << endl;
	cout << num1 << " div " << num2 << " = " << div << endl;
	cout << num1 << " mod " << num2 << " = " << mod << endl;

	return 0;
}