#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void createMapping(int arr[]) {
	int num;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		num = (rand() % 3 + 1);
		arr[i] = num;
	}
}

bool checkPINMapping(int pin[], int enter[], int mapping[]) {
	for (int i = 0; i < 5; i++) {
		if (mapping[pin[i]] == enter[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int pin[5] = { 1,2,3,4,5 };
	//create enter array;
	int mapping[10];
	createMapping(mapping);
	cout << "Please enter your PIN according to the following mapping :" << endl;
	cout << "PIN:	0	1	2	3	4	5	6	7	8	9" << endl;
	cout << "NUM:";
	for (int i = 0; i < 10; i++) {
		cout << "\t" << mapping[i];
	}
	cout << endl;
	//create enter array;
	int enter[5];
	for (int i = 0; i < 5; i++) {
		cin >> enter[i];
	}	
	bool result = checkPINMapping(pin, enter,mapping);
	cout << result;

}