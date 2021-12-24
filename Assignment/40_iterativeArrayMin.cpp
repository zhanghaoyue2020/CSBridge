#include<iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;
	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	cout << res1 << " " << res2 << endl; //should both be -9
	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
	cout << res3 << " " << res4 << endl; //should both be 3
	return 0;
}

int minInArray1(int arr[], int arrSize) {
	int currMin, currTerm;
	if (arrSize == 1) {
		currTerm = arr[0];
		currMin = currTerm;
		return currMin;
	}
	else {
		currMin = minInArray1(arr, arrSize - 1);
		currTerm = arr[arrSize - 1];
		if ( currMin < currTerm) {
			return currMin;
		}
		else {
			currMin = currTerm;
			return currMin;
		}
	}
}

int minInArray2(int arr[], int low, int high) {
	int currMin, currTermL,currTermH;
	if ((low==high)||(low+1==high)) {
		currTermL = arr[low];
		currTermH = arr[high];
		if (currTermL < currTermH) {
			currMin = currTermL;
			return currMin;
		}
		else {
			currMin = currTermH;
			return currMin;
		}
	}
	else {
		currMin = minInArray2(arr, low+1, high-1);
		currTermL = arr[low];
		currTermH = arr[high];
		if (currMin < currTermL && currMin < currTermH) {
			return currMin;

		}
		else if (currTermL < currTermH) {
			currMin = currTermL;
			return currMin;
		}
		else {
			currMin = currTermH;
			return currMin;
		}
	}
}