#include<iostream>
using namespace std;

int fib(int n);
int main() {
	int n, result;

	cout << "Please enter a positive integer:";
	cin >> n;
	
	result = fib(n);

	cout << "The " << n << "-th element of the Fibonacci sequence is " << result << endl;

	return 0;
}

int fib(int n) {
	int currentNum = 0;
	int tempStore1 = 1;
	int tempStore2 = 1;

	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if ((n != 1) && (n != 2)) {
		for (int i = 2; i < n; i++) {
			currentNum = tempStore1 + tempStore2;
			tempStore2 = tempStore1;
			tempStore1 = currentNum;
		}
		return currentNum;
	}
	return NULL;
}