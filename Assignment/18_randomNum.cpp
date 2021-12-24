#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
	int smallLimit, largeLimit, num,guess;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
	cout << endl;
	
	srand(time(0));
	num = rand() % 100 + 1;

	smallLimit = 1;
	largeLimit = 100;
	for (int i = 0; ; i++) {
		cout << "Range: [" << smallLimit << "," << largeLimit << "] , Number of guesses left : " << (5 - i)<<endl;
		cout << "Your guess: ";
		cin >> guess;
		if (guess == num) {
			cout << "Congrats! You guessed my number in " << i + 1 << " guesses." << endl; 
			break;
		}
		else {
			if (i== 4) {
				cout << "Out of guesses! My number is " << num <<" !"<< endl;
				break;
			}
			if (guess < num) {
				cout << "Wrong! My number is bigger."<<endl;
				cout << endl;
				smallLimit = guess + 1;
			}
			else {
				cout << "Wring! My number is smaller"<<endl;
				cout << endl;
				largeLimit = guess - 1;
			}
		}
	}

	return 0;
}