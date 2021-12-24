# include<iostream>;
using namespace std;

int main() {

	string timeDay;
	int timeHour, timeMin;
	int time;
	double result;

	cout << "Please enter when the call is comming(\"Mo 18 30\" for Monday 6:30 pm) : " << endl;
	cin >> timeDay >> timeHour >> timeMin;
	cout << "Please enter the length of the call in minites :" << endl;
	cin >> time;

	if (timeDay == "Mo" ||timeDay == "Tu" || timeDay == "We" || timeDay == "Th" || timeDay == "Fr") {
		if ((timeHour >= 8) && (timeHour < 18)) {
			result = 0.4 * time;
			cout << "It will cost $" << result << endl;
		}
		else {
			result = 0.25 * time;
			cout << "It will cost $" << result << endl;
		}
	}
	else {
		result = 0.15 * time;
		cout << "It will cost $" << result << endl;
	}

	return 0;
}