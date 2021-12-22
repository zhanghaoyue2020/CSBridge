#include<iostream>
using namespace std;

const int PENNY_PER_CENT = 1;
const int NICKEL_PER_CENT = 5;
const int DIME_PER_CENT = 10;
const int QUARTER_PER_CENT = 25;
const int CENT_PER_DOLLAR = 100;

int main() {

	int numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies;
	int total, cents, dollars, residue;

	cout << "Please enter your amount in the format of dollars and cents separated by a space :" << endl;
	cin >> dollars >> cents;

	total = dollars * CENT_PER_DOLLAR + cents;
	numberOfQuarters = total / QUARTER_PER_CENT;
	residue = total - numberOfQuarters * QUARTER_PER_CENT;
	numberOfDimes = residue / DIME_PER_CENT;
	residue = residue - numberOfDimes * DIME_PER_CENT;
	numberOfNickels = residue / NICKEL_PER_CENT;
	numberOfPennies = residue - numberOfNickels * NICKEL_PER_CENT;

	cout << dollars << " dollars and " << cents << " cents are :" << endl;
	cout << numberOfQuarters << " quarters, " << numberOfDimes << " dimes, "
		<< numberOfNickels << " nickels and " << numberOfPennies << " pennies" << endl;

	return 0;

}