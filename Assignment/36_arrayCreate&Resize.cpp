#include<iostream>
#include<array>
#include<vector>
using namespace std;

int* createIntArr(int& outArrSize){
	//frame;
	int* arr;
	int arrSize, arrPhysicalSize;
	//inner variable;
	int currTerm;
	//initialization
	arr = new int[1];
	arrSize = 0;
	arrPhysicalSize = 1;
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End you input by typing - 1" << endl;
	cin >> currTerm;
	while (currTerm != -1) {
		if (arrSize == arrPhysicalSize) {
			int* newArr;
			newArr = new int[arrPhysicalSize * 2];
			for (int i = 0; i < arrPhysicalSize; i++) {
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			arrPhysicalSize *= 2;
		}
		arr[arrSize] = currTerm;
		arrSize++;
		cin >> currTerm;
	}
	outArrSize = arrSize;
	return arr;
}

void searchNum(int* arr, int arrSize) {
	//frame
	int* resultArr;
	int resultArrSize, resultArrPhysicalSize;
	int num;
	//initialization
	resultArr = new int[1];
	resultArrSize = 0;
	resultArrPhysicalSize = 1;
	cout << "Please enter a number you want to search" << endl;
	cin >> num;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == num) {
			if (resultArrSize == resultArrPhysicalSize) {
				int* newArr;
				newArr = new int[resultArrPhysicalSize * 2];
				for (int i = 0; i < resultArrPhysicalSize; i++) {
					newArr[i] = resultArr[i];
				}
				delete[] resultArr;
				resultArr = newArr;
				resultArrPhysicalSize *= 2;
			}
			resultArr[resultArrSize] = i+1;
			resultArrSize++;
		}
		else {
			continue;
		}
	}
	if (resultArrSize==0) {
		cout << num << " does not show at all in the sequence." << endl;
	}
	else {
		cout << num << " shows in lines ";
		for (int i = 0; i < resultArrSize; i++) {
			cout << resultArr[i] << " ";
		}
		cout << endl;
	}
}

vector<int> createIntVec() {
	//frame;
	vector<int> intVec;
	//inner variable;
	int currTerm;
	//initialization
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End you input by typing - 1" << endl;
	cin >> currTerm;
	while (currTerm != -1) {
		intVec.push_back(currTerm);
		cin >> currTerm;
	}
	return intVec;
}

void searchNum2(vector<int> intVec) {
	//frame;
	vector<int> resultVec;
	int num, index;
	//initialization;
	index = intVec.size();
	cout << "Please enter a number you want to search" << endl;
	cin >> num;
	while(!intVec.empty()){
		if (intVec.back() == num) {
			resultVec.push_back(index);
			index--;
			intVec.pop_back();
		}
		else {
			index--;
			intVec.pop_back();
		}
	}
	if (resultVec.empty()) {
		cout << num << " does not show at all in the sequence." << endl;
	}
	else {
		cout << num << " shows in lines ";
		while (!resultVec.empty()) {
			cout << resultVec.back() << " ";
			resultVec.pop_back();
		}
		cout << endl;
	}
}

void main1() {
	int arrSize = 0;
	int* arr = createIntArr(arrSize);
	searchNum(arr, arrSize);
}
void main2() {
	vector<int> intVec = createIntVec();
	searchNum2(intVec);
}
int main() {
	main1();
	main2();
}