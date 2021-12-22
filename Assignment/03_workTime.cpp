#include<iostream>
using namespace std;

const int MINUTES_PER_HOUR = 60;
const int HOUR_PER_DAY = 24;

int main() {

	int workDaysJohn, workHoursJohn, workMinutesJohn;
	int workDaysBill, workHoursBill, workMinutesBill;
	int days, hours, minutes;
	int tempHours, tempMinutes;
	int carriedOver;

	cout << "Please	enter the number of days John has worked : ";
	cin >> workDaysJohn;
	cout << "Please enter the number of hours John has worked : ";
	cin >> workHoursJohn;
	cout << "Please enter the number of minutes John has worked : ";
	cin >> workMinutesJohn;
	cout << "Please enter the number of days Bill has worked : ";
	cin >> workDaysBill;
	cout << "Please	enter the number of hours Bill has worked : ";
	cin >> workHoursBill;
	cout << "Please enter the number of minutes Bill has worked : ";
	cin >> workMinutesBill;

	tempMinutes = workMinutesJohn + workMinutesBill;
	carriedOver = tempMinutes / MINUTES_PER_HOUR;
	minutes = tempMinutes - carriedOver * MINUTES_PER_HOUR;
	tempHours = workHoursJohn + workHoursBill + carriedOver;
	carriedOver = tempHours / HOUR_PER_DAY;
	hours = tempHours - carriedOver * HOUR_PER_DAY;
	days = workDaysJohn + workDaysBill + carriedOver;

	cout << "The total time both of them worked together is : " << days << " days " 
		<< hours << " hours and " << minutes << " minutes" << endl;

	return 0;

}