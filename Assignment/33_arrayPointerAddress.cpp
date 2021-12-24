#include<iostream>
#include<array>
using namespace std;

void oddsKeepEvensFlip1(int*& arr, int arrSize);
void oddsKeepEvensFlip2(int arr[], int arrSize);

void main1() {
	int* arr = new int[6];
	arr[0] = 5;
	arr[1] = 2;
	arr[2] = 11;
	arr[3] = 7;
	arr[4] = 6;
	arr[5] = 4;
	oddsKeepEvensFlip1(arr, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void main2() {
	int arr[6] = { 5,2,11,7,6,4 };
	oddsKeepEvensFlip2(arr, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	main1();
	main2();
}

void oddsKeepEvensFlip1(int*& arr, int arrSize) {
	int* temp = new int[arrSize];
	int oddInd = 0;
	int evenInd = arrSize - 1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 1) {
			temp[oddInd] = arr[i];
			oddInd++;
		}
		else {
			temp[evenInd] = arr[i];
			evenInd--;
		}
	}	
	delete[] arr;
	arr = temp;
}
void oddsKeepEvensFlip2(int arr[], int arrSize) {
	int* temp = new int[arrSize];
	int oddInd = 0;
	int evenInd = arrSize - 1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 1) {
			temp[oddInd] = arr[i];
			oddInd++;
		}
		else {
			temp[evenInd] = arr[i];
			evenInd--;
		}
	}
	for (int i = 0; i < arrSize; i++) {
		arr[i] = temp[i];
	}
	delete[] temp;
	temp = NULL;
}



// int arr[] ---------transmit a pointer, but it won't return;
// int*& arr ---------transmit a pointer, and it will return;