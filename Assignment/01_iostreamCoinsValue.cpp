#include<iostream>
using namespace std;

const int PENNY_PER_CENT = 1;
const int NICKEL_PER_CENT = 5;
const int DIME_PER_CENT = 10;
const int QUARTER_PER_CENT = 25;
const int CENT_PER_DOLLAR = 100;

int main() {

	int numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies;
	int totalSumOfQuaters, totalSumOfDimes, totalSumOfNickels, totalSumOfPennies;
	int total, cents, dollars;

	cout << "Please	enter number of coins :" << endl;
	cout << "# of quarters :";
	cin >> numberOfQuarters;
	cout << "# of dimes :";
	cin >> numberOfDimes;
	cout << "# of nickels :";
	cin >> numberOfNickels;
	cout << "# of pennies :";
	cin >> numberOfPennies;

	totalSumOfPennies = numberOfPennies * PENNY_PER_CENT;
	totalSumOfNickels = numberOfNickels * NICKEL_PER_CENT;
	totalSumOfDimes = numberOfDimes * DIME_PER_CENT;
	totalSumOfQuaters = numberOfQuarters * QUARTER_PER_CENT;
	total = totalSumOfPennies + totalSumOfNickels + totalSumOfDimes + totalSumOfQuaters;
	cents = total % CENT_PER_DOLLAR;
	dollars = total / CENT_PER_DOLLAR;

	cout << "The total is " << dollars << " dollars and " << cents << " cents " << endl;

	return 0;
}
