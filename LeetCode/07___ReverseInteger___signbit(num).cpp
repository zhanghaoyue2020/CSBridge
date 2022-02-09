#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// not accepted
int reverse(int x) {
	vector<int> intVec;
	int ans = 0;
	int digit = 0;
	int xSignbit = signbit(x / 1.0);
	for (; x != 0; digit++) {
		intVec.push_back(x % 10);
		x /= 10;
	}
	for (vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
		digit--;
		ans = ans + (*it) * pow(10, digit);
	}
	if (signbit(ans / 1.0) == xSignbit) {
		return ans;
	}
	else {
		return 0;
	}
}

int main() {
	cout << reverse(1534236469) << endl;
	cout << reverse(-321) << endl;
	cout << reverse(-210) << endl;
}