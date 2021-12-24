#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int length;
	int element, sum;
	double result;

	cout << "First style: " << endl;
	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << "Please enter your sequence: " << endl;
	
	sum = 0;
	for (int i = 0; i < length; i++) {
		cin >> element;
		sum += element;
	}

	result = pow(sum, 1 / (double)length);
	cout << "The geometric mean is: " << result << endl;

	cout << endl;

	cout << "Second style: " << endl;
	cout << "Please enter a non-empty sequence of positive"
		<< " integers, each one in a separate line. End your"
		<< " sequence by typing -1:" << endl;
	
	sum = 0;
	length = 0;
	cin >> element;
	while (element != -1) {
		length++;
		sum += element;
		cin >> element;
	}

	result = pow(sum, 1 / (double)length);
	cout << "The geometric mean is: " << result << endl;

	return 0;

}