# include<iostream>
using namespace std;

int main(){
	
	int num, print;

	cout << "please enter a positive integer:";
	cin >> num ;

	cout << endl;
	cout << "use a while loop" << endl;

	int i = 1;
	while (i <= num) {
		print = 2 * i;
		cout << print <<endl;
		i++;
	}

	cout << endl;
	cout << "use a for loop" << endl;

	for (int j = 0; j < num; j++) {
		print = 2 * (j+1);
		cout << print << endl;
	}

	return 0;

}