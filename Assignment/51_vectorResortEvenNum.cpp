#include<iostream>
#include<vector>
using namespace std;

void functionQ5(vector<int> & desk) {
	int size = desk.size();
	int arrSize = size / 2;
	int* arrEven = new int[arrSize];
	int* arrOdd = new int[arrSize];
	int temp;
	for (int i = 0; i < size; i++) {
		temp = desk.back();
		desk.pop_back();
		if (i % 2 != 0) {
			arrOdd[i / 2] = temp;
		}
		else {
			arrEven[i / 2] = temp;
		}
	}
	if (!desk.empty()) {
		cout << "there must be something wrong!" << endl;
	}
	else {
		for (int i = 0; i < arrSize; i++)
			desk.push_back(arrEven[i]);
		for (int i = arrSize-1; i >= 0; i--)
			desk.push_back(arrOdd[i]);
	}
	delete[] arrEven;
	delete[] arrOdd;
}

int main() {
	vector<int> v;
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
	}
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
	functionQ5(v);
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}