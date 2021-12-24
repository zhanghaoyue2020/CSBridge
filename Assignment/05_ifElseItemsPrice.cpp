#include <iostream>;
using namespace std;

int main() {

	double item1, item2;
	char card;
	double tax;
	double basePrice, discountPrice, finalPrice;


	cout << "Enter price of first item : ";
	cin >> item1;
	cout << "Enter price of second item : ";
	cin >> item2;
	cout << "Does customer have a club card ? (Y/N): ";
	cin >> card;
	cout << "Enter tax rate, e.g.  5.5 for 5.5 % tax : ";
	cin >> tax;

	basePrice = item1 + item2;

	if (item1 < item2)
		discountPrice = item1 / 2 + item2;
	else
		discountPrice = item2 / 2 + item1;

	if (card == 'y')
		discountPrice = discountPrice * 0.9;

	finalPrice = discountPrice * (1 + tax / 100);

	cout << "Base price : " << basePrice << endl;
	cout << "Price after discounts: " << discountPrice << endl;
	cout << "Total price: " << finalPrice << endl;

	return 0;
}