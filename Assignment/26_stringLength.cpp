#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str) {
	int length, compdigit;
	length = str.length();
	compdigit = length / 2;
	for (int i = 0; i < compdigit; i++) {
		if (str[i] == str[length - 1 - i]) {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main() {
	string str;
	bool res;
	cout << "Please enter a word : " << endl;
	cin >> str;
	res = isPalindrome(str);
	if (res == 1) {
		cout << str << " is a palindrome.";
	}
	else {
		cout << str << " is not a palindrome.";
	}
	cout << endl;
}