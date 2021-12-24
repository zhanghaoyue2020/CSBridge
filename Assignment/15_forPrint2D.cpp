#include<iostream>
using namespace std;

int main() {

	int sum, row, column;

	cout << "Please entry an integer: " << endl;
	cin >> sum;

	row = sum*2;
	column = sum*2 -1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (i < sum) {
				if ((i < column - j) && (i < j + 1))
					cout << "*";
				else
					cout << " ";
			}
			else {
				if ((i < column - j) || (i < j + 1))
					cout << " ";
				else
					cout << "*";
			}
		}
		cout << endl;
	}

	return 0;
}