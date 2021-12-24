#include<iostream>
using namespace std;

const int ARRAY_SIZE = 20;

int minInArray(int arr[], int arrSize);
void createArray(int arr[], int arrSize);

int main() {

	int integers[ARRAY_SIZE];
	int min;

	cout << "Please enter 20 integers separated by a space: " << endl;
	createArray(integers, ARRAY_SIZE);
	
	min = minInArray(integers, ARRAY_SIZE);
	
	cout << "The minimum value is " << min << ", and it is located in the following indices:";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (integers[i] == min)
			cout << " " << i;
	}
}

int minInArray(int arr[], int arrSize) {
	int min = arr[0];
	
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	
	return min;
}

void createArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++)
		cin >> arr[i];
}