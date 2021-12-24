#include<array>
#include<iostream>
using namespace std;

void reverseArray(int arr[], int arrSize) {
	int temp;
	for (int i = 0; i < arrSize/2; i++) {
		temp = arr[i];
		arr[i] = arr[arrSize - 1 - i];
		arr[arrSize - 1 - i] = temp;
	}
}

void removeOdd(int arr[], int& outArrSize) {
	int arrSize, initialArrSize;
	arrSize = 0;
	initialArrSize = outArrSize;
	for (int i = 0; i < initialArrSize; i++) {
		if (arr[i] % 2 == 0) {
			arr[arrSize] = arr[i];
			arrSize++;
		}
		else {
			continue;
		}
	}
	outArrSize = arrSize;
}

void splitParity(int arr[], int arrSize) {
	int temp;
	int i = 0;
	int j = arrSize - 1;
	for (; i < j; ) {
		//arr[i] is even; arr[j] is even;
		if ((arr[i] % 2 == 0) && (arr[j] % 2 == 0)) {
			temp = arr[j - 1];
			arr[j - 1] = arr[i];
			arr[i] = temp;
			j -= 2;
			continue;
		}
		//arr[i] is even; arr[j] is odd;
		if ((arr[i] % 2 == 0) && (arr[j] % 2 != 0)) {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
			j--;
			continue;
		}
		//arr[i] is odd; arr[j] is even;
		if ((arr[i] % 2 != 0) && (arr[j] % 2 == 0)) {
			i++;
			j--;
			continue;
		}
		//arr[i] is odd; arr[j] is odd;
		if ((arr[i] % 2 != 0) && (arr[j] % 2 != 0)) {
			temp = arr[j];
			arr[j] = arr[i + 1];
			arr[i + 1] = temp;
			i += 2;
			continue;
		}
		cout << "there must be some problem!" << endl;
	}
}

void printArray(int arr[], int arrSize);

int main() {
	int arr1[10] = { 9, 2, 14, 12, -3 };
	int arr1Size = 5;

	int arr2[10] = { 21, 12, 6, 7, 14 };
	int arr2Size = 5;

	int arr3[10] = { 1,2,3,4 };
	int arr3Size = 4;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}

void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}