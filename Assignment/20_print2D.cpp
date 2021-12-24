#include<iostream>
using namespace std;

void pritShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
int main() {
	int m, n;
	char symbol;

	cout << "Please entry the lines of triangle, the shifted spaces and the symbol" << endl;
	cin >> m >> n >> symbol;
	pritShiftedTriangle(m, n, symbol);
	cout << "\nPlease entry the numbers of triangles on the tree and the symbol" << endl;
	cin >> n >> symbol;
	printPineTree(n, symbol);

	return 0;
}

void pritShiftedTriangle(int n, int m, char symbol) {
	int row = n;
	int column = m + (2 * n - 1);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if ((j < m) || (i < -j + (m + n - 1)) || (i < j - (m + n - 1)))
				cout << " ";
			else
				cout << symbol;
		}
		cout << endl;
	}
}

void printPineTree(int n, char symbol) {
	for (int k = 0; k < n; k++) {
		int row = k + 2;
		int column = k + 2 + n;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if ((i < -j + n) || (i < j - n))
					cout << " ";
				else
					cout << symbol;
			}
			cout << endl;
		}
	}
}
