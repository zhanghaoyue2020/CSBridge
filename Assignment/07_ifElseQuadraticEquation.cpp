#include<iostream>
#include <cmath>
using namespace std;

// 0 = wx+b
void linearEquation(double w, double b) {
	double x;
	if (w == 0) {
		if (b == 0) {
			cout << "Infinite solution." << endl;
		}
		else{
			cout << "This equation doesn't have real solution." << endl;
		}
	}
	else {
		x = -b / w;
		cout << "This equation has a single real solution x = " << x << endl;
	}
}
// 0 = w2x^2+w1x+b
void quadraticEquation(double w2, double w1, double b) {
	double x1, x2;
	double judge;
	judge = w1 * w1 - 4 * w2 * b;

	if (w2 == 0) {
		linearEquation(w1, b);
	}
	else {
		if (judge == 0) {
			x1 = -w1 / (2 * w2);
			cout << "This equation has a single real solution x = " << x1 << endl;
		}
		if (judge > 0) {
			judge = sqrt(judge);
			x1 = (-w1 + judge) / (2 * w2);
			x2 = (-w1 - judge) / (2 * w2);
			cout << "This equation has two real solution x1 = " << x1 << ", x2 = " << x2 << endl;
		}
		if (judge < 0) {
			judge = sqrt(-judge);
			x1 = -w1 / (2 * w2);
			x2 = judge / (2 * w2);
			cout << "This equation has two complex solution x1 = " << x1 << "+j" << x2 << ", x2 = " << x1 << "-j" << x2 << endl;
		}
	}
}

int main(){

	double valueA, valueB, valueC;
	double judge, solution1, solution2;

	cout << "Please enter value of a : ";
	cin >> valueA;
	cout << "Please enter value of b : ";
	cin >> valueB;
	cout << "Please enter value of c : ";
	cin >> valueC;
	quadraticEquation(valueA, valueB, valueC);

	return 0;
}