#include<iostream>
#include<array>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
	int arr1[4] = { 2,-1,3,10 };
	cout << sumOfSquares(arr1, 4) << endl;
	cout << isSorted(arr1, 4) << endl;
	int arr2[4] = { 2,3,5,10 };
	cout << isSorted(arr2, 4) << endl;
}

int sumOfSquares(int arr[], int arrSize) {
	int currSum, currTerm;
	if (arrSize == 1) {
		currSum = 0;
		currTerm = arr[0] * arr[0];
		return currSum + currTerm;
	}
	else {
		currSum = sumOfSquares(arr + 1, arrSize - 1);
		currTerm = arr[0] * arr[0];
		return currSum + currTerm;
	}
}

bool isSorted(int arr[], int arrSize) {
	bool rest, currTerm;
	if (arrSize == 1) {
		rest = true;
		currTerm = true;
		return rest && currTerm;
	}
	else {
		rest = isSorted(arr + 1, arrSize - 1);
		if (arr[0] < arr[1]) {
			currTerm = true;
		}
		else {
			currTerm = false;
		}
		return rest && currTerm;
	}
}