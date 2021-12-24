#include<iostream>
using namespace std;

int* findMissing(int arr[], int arrSize, int& outResArrSize);

int main() {
	int arr[7]= { 3,1,3,0,6,4,0 };
	int resArrSize;
	int* resArr = findMissing(arr, 7, resArrSize);
	for (int i = 0; i < resArrSize; i++) {
		cout << resArr[i] << " ";
	}
	cout << endl;
}


int* findMissing(int arr[], int arrSize, int& outResArrSize) {
	//frame;
	int* countArr, * resArr;
	int countArrSize, resArrSize, resArrPhysicalSize;
	//initialization;
	countArrSize = arrSize + 1;
	countArr = new int[countArrSize];
	for (int i = 0; i < countArrSize; i++) {
		countArr[i] = 0;
	}
	//count the number;
	for (int i = 0; i < arrSize; i++) {
		countArr[arr[i]]++;
	}
	//create the result;
	resArr = new int[1];
	resArrSize = 0;
	resArrPhysicalSize = 1;
	for (int i = 0; i < countArrSize; i++) {
		if (countArr[i] == 0) {
			if (resArrSize == resArrPhysicalSize) {
				int* newResArr;
				newResArr = new int[resArrPhysicalSize * 2];
				for (int j = 0; j < resArrPhysicalSize + 1; j++) {
					newResArr[j] = resArr[j];
				}
				delete[] resArr;
				resArr = newResArr;
				resArrPhysicalSize *= 2;
			}
			resArr[resArrSize] = i;
			resArrSize++;
		}
		else {
			continue;
		}
	}
	delete[] countArr;
	countArr = NULL;
	outResArrSize = resArrSize;
	return resArr;
}