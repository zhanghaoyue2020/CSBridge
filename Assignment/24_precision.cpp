#include <iostream>
using namespace std;

double eApprox(int n);

int main() {
	cout.precision(30);
	for (int n = 1; n <= 15; n++) {
		cout << "n = " << n << '\t' << eApprox(n) << endl;
	}
	return 0;
}

double eApprox(int n) {
	double sum = 1;
	double add = 0;
	double element = 1;
	for (int i = 1; i <= n; i++) {
		add = 1 /element;
		sum += add;
		element *= (i + 1.0);
	}
	return sum;
}
