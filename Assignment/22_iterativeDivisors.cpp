#include<iostream>
#include<cmath>
using namespace std;

void printDivisors(int num, int i);

int main() {
	
	int num;

	cout << "Please enter a positive integer >= 2:" << endl;
	cin >> num;

	printDivisors(num, 1);

	return 0;
}

void printDivisors(int num, int i) {
	if (i > sqrt(num)) {
		return;
	}
	else {
		if (num % i == 0) {
			cout << i << " ";
			printDivisors(num, i + 1);
			if (i != num / i) {
				cout << num / i << " ";
			}
		}
		else {
			printDivisors(num, i + 1);
		}
	}
}