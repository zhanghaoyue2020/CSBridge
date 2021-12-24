#include<iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {

	int year, startingDay;

	cout << "Please entry the year and the starting day:" << endl;
	cin >> year >> startingDay;
	printYearCalender(year, startingDay);
}

int printMonthCalender(int numOfDays, int startingDay) {
	int day = 0;
	cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
	for (int i = 0; ; i++) {
		for (int j = 0; j < 7; j++) {
			if ((i == 0) && (j < startingDay-1)&&(startingDay !=8)) {
				cout << "\t"; 
				continue;
			}
			day++;
			cout<<day<<"\t";
			if (day == numOfDays) {
				cout << endl;
				return j + 1;
			}
		}
		cout << endl;
	}
}

bool isLeapYear(int year) {
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 == 0)
		return true;
	else
		return false;
}

void printYearCalender(int year, int startingDay) {
	int FirstDay;
	cout << endl << "January " << year << endl;
	FirstDay = printMonthCalender(31, startingDay);
	cout << endl << "February " << year << endl;
	if(isLeapYear(year)==1)
		FirstDay = printMonthCalender(29, FirstDay + 1);
	else
		FirstDay = printMonthCalender(28, FirstDay + 1);
	cout << endl << "March " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
	cout << endl << "April " << year << endl;
	FirstDay = printMonthCalender(30, FirstDay + 1);
	cout << endl << "May " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
	cout << endl << "June " << year << endl;
	FirstDay = printMonthCalender(30, FirstDay + 1);
	cout << endl << "July " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
	cout << endl << "August " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
	cout << endl << "September " << year << endl;
	FirstDay = printMonthCalender(30, FirstDay + 1);
	cout << endl << "October " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
	cout << endl << "November " << year << endl;
	FirstDay = printMonthCalender(30, FirstDay + 1);
	cout << endl << "December " << year << endl;
	FirstDay = printMonthCalender(31, FirstDay + 1);
}