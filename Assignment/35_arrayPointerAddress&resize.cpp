#include<iostream>
#include<array>
using namespace std;

void resizeArray(int*& outArr, int outArrPhysicalSize, int initialArrSize) {
	int* newArr;
	newArr = new int[outArrPhysicalSize];
	for (int i = 0; i < initialArrSize; i++) {
		newArr[i] = outArr[i];
	}
	delete[] outArr;
	outArr = newArr;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	//frame
	int* posArr;
	int posArrSize,posArrPhysicalSize;
	//initialization
	posArr = new int[1];
	posArrSize = 0;
	posArrPhysicalSize = 1;
	for (int i = 0; i < arrSize; i++) {
		if (posArrSize == posArrPhysicalSize) {
			resizeArray(posArr, 2 * posArrPhysicalSize, posArrPhysicalSize);
			posArrPhysicalSize *= 2;
		}
		if (arr[i] > 0) {
			posArr[posArrSize] = arr[i];
			posArrSize++;
		}
		else {
			continue;
		}
	}
	outPosArrSize = posArrSize;
	return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	//frame
	int* posArr;
	int posArrSize, posArrPhysicalSize;
	//initialization
	posArr = new int[1];
	posArrSize = 0;
	posArrPhysicalSize = 1;
	for (int i = 0; i < arrSize; i++) {
		if (posArrSize == posArrPhysicalSize) {
			int* newPosArr;
			newPosArr = new int[posArrPhysicalSize * 2];
			for (int i = 0; i < posArrPhysicalSize; i++) {
				newPosArr[i] = posArr[i];
			}
			delete[] posArr;
			posArr = newPosArr;
			posArrPhysicalSize *= 2;
		}
		if (arr[i] > 0) {
			posArr[posArrSize] = arr[i];
			posArrSize++;
		}
		else {
			continue;
		}
	}
	*outPosArrSizePtr = posArrSize;
//	outPosArrSizePtr = &posArrSize;
	return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	//frame
	int* posArr;
	int posArrSize, posArrPhysicalSize;
	//initialization
	posArr = new int[1];
	posArrSize = 0;
	posArrPhysicalSize = 1;
	for (int i = 0; i < arrSize; i++) {
		if (posArrSize == posArrPhysicalSize) {
			int* newPosArr;
			newPosArr = new int[posArrPhysicalSize * 2];
			for (int i = 0; i < posArrPhysicalSize; i++) {
				newPosArr[i] = posArr[i];
			}
			delete[] posArr;
			posArr = newPosArr;
			posArrPhysicalSize *= 2;
		}
		if (arr[i] > 0) {
			posArr[posArrSize] = arr[i];
			posArrSize++;
		}
		else {
			continue;
		}
	}
	outPosArrSize = posArrSize;
	delete[] outPosArr;
	outPosArr = posArr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	//frame
	int* posArr;
	int posArrSize, posArrPhysicalSize;
	//initialization
	posArr = new int[1];
	posArrSize = 0;
	posArrPhysicalSize = 1;
	for (int i = 0; i < arrSize; i++) {
		if (posArrSize == posArrPhysicalSize) {
			int* newPosArr;
			newPosArr = new int[posArrPhysicalSize * 2];
			for (int i = 0; i < posArrPhysicalSize; i++) {
				newPosArr[i] = posArr[i];
			}
			delete[] posArr;
			posArr = newPosArr;
			posArrPhysicalSize *= 2;
		}
		if (arr[i] > 0) {
			posArr[posArrSize] = arr[i];
			posArrSize++;
		}
		else {
			continue;
		}
	}
	*outPosArrSizePtr = posArrSize;
	delete[] *outPosArrPtr;
	*outPosArrPtr = posArr;
}

void main1() {
	int arr[11] = { 3, -1, -3, 0, 6, 4, 23, 5, 9, 2, 3 };
	int posArrSize;
	int* posArr = getPosNums1(arr, 11, posArrSize);
	for (int i = 0; i < posArrSize; i++) {
		cout << posArr[i] << " ";
	}
	cout << endl;
}
void main2() {
	int arr[6] = { 3, -1, -3, 0, 6, 4 };
	int posArrSize;
	int* posArr = getPosNums2(arr, 6, &posArrSize);
	for (int i = 0; i < posArrSize; i++) {
		cout << posArr[i] << " ";
	}
	cout << endl;
}
void main3() {
	int arr[6] = { 3, -1, -3, 0, 6, 4 };
	int posArrSize;
	int* posArr = new int[1];
	getPosNums3(arr, 6, posArr, posArrSize);
	for (int i = 0; i < posArrSize; i++) {
		cout << posArr[i] << " ";
	}
	cout << endl;
}
void main4() {
	int arr[6] = { 3, -1, -3, 0, 6, 4 };
	int posArrSize;
	int* posArr = new int[1];
	getPosNums4(arr, 6, &posArr, &posArrSize);
	for (int i = 0; i < posArrSize; i++) {
		cout << posArr[i] << " ";
	}
	cout << endl;
}
int main() {
	main1();
	main2();
	main3();
	main4();
}