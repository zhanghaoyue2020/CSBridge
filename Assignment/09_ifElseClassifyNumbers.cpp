#include<iostream>
using namespace std;

int main() {

	double weightInPounds, heightInInches;
	double weight, height;
	double result;

	cout << "Please enter weight(in pounds): ";
	cin >> weightInPounds;
	cout << "Please enter height(in inches): ";
	cin >> heightInInches;

	weight = weightInPounds * 0.453592;
	height = heightInInches * 0.0254;

	result = weight / height / height;

	if (result < 18.5) cout << "The weight status is : Underweight" << endl;
	else if (result < 25) cout << "The weight status is : Normal" << endl;
	else if (result < 30) cout << "The weight status is : Overweight" << endl;
	else cout << "The weight status is : Obese" << endl;
	
	return 0;
}