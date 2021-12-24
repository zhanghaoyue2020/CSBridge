#include <iostream>
using namespace std;

int main() {
		
	int num, n;							//<input>: num=6524;
	int currentNum;						//<while>: currentNum=5(325);
	int digit;							//digit=4; 
	int currentDigit, unitCurrentDigit;	//currentDigit=3;unitCurrentDigit=100;
	int oddNum, evenNum;

	  

	cout << "Entry an integer: ";
	cin >> num;
	
	cout << "the numbers from 1 to " << num << " that have more even digits than odd digits:" << endl;
	n = 1;
	while (n < num) {
		
		currentNum = n;
		digit = 0;
		while (currentNum > 0) {
			digit++;
			currentNum /= 10;
		}
		currentNum = n;
		if (currentNum == pow(10, digit))
			digit++;

		currentNum = n;
		oddNum = 0;
		evenNum = 0;
		for (int i = digit; i > 0; i--) {
			unitCurrentDigit = pow(10, i - 1);
			currentDigit = currentNum / unitCurrentDigit;
			if (currentDigit % 2 == 0)
				evenNum++;
			else
				oddNum++;
			currentNum = currentNum - currentDigit * unitCurrentDigit;
		}
		if (evenNum > oddNum)
			cout << n << "\t";
		n++;
	}
}