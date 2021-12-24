#include<iostream>;
using namespace std;

int main() {
	
	int n, largestNum, digit, currentNum;

	cout << "Please enter a positive integer : " << endl;
	cin >> n;

	largestNum = n * n;
	digit = 0;
	while (largestNum > 0) {
		digit++;
		largestNum /= 10;
	}
	if (n * n == pow(10, digit))
		digit++;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			currentNum = (i + 1) * (j + 1);
			cout <<currentNum<<" ";
			for (int k = 0; k < digit; k++) {
				if (currentNum > 0) {
					currentNum /= 10;
				}
				else
					cout<<" ";
			}
		}
		cout << endl;
	}
}