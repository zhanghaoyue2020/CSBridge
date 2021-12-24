#include<iostream>
#include<string>
using namespace std;

void printName() {
	string firstN, middleN, lastN;
	cin >> firstN >> middleN >> lastN;
	middleN = middleN[0];
	cout << lastN << ", " << firstN << " " << middleN << "." << endl;
}

void main() {
	printName();
}