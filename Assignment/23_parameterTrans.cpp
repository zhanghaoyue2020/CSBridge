#include<iostream>
#include<cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {

	int num, tempNum, currentNum;
	int outCountDivs1, outSumDivs1, outCountDivs2, outSumDivs2;
	int calling = 0;
	cout << "Please entry a positive integer >=2" << endl;
	cin >> num;
	
	tempNum = 2;
	while (tempNum < num) {
		if (isPerfect(tempNum) == 1) {
			cout << tempNum << " is a perfect number" << endl;
		}
		outCountDivs1 = 0;
		outSumDivs1 = 0;
		analyzeDividors(tempNum, outCountDivs1, outSumDivs1);
		for (int i = tempNum + 1; i < num; i++) {
			outCountDivs2 = 0;
			outSumDivs2 = 0;
			analyzeDividors(i, outCountDivs2, outSumDivs2);
			if ((outSumDivs1 == i) && (outSumDivs2 == tempNum)) {
				cout << "(" << tempNum << "," << i << ") is an amicable pair" << endl;
			}
			calling++;
		}
		tempNum++;
	}
	cout << "tatal calling = " << calling << endl;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	int tempNum;
	tempNum = sqrt(num);
	while (tempNum > 1) {
		if (num % tempNum == 0) {
			if (tempNum != num / tempNum) {
				outCountDivs += 2;
				outSumDivs += tempNum + num / tempNum;
			}
			else {
				outCountDivs++;
				outSumDivs += tempNum;
			}
		}
		tempNum--;
	}
	outCountDivs++;
	outSumDivs++;
}

bool isPerfect(int num) {
	
	int outCountDivs = 0;
	int outSumDivs = 0;

	analyzeDividors(num, outCountDivs, outSumDivs);

	if (outSumDivs == num)
		return true;
	else
		return false;
}