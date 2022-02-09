#include<iostream>
#include<string>
using namespace std;


bool isPalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

string longestPalindrome(string s) {
	int size = s.size();
	string newSubstr;
	int newSubstrSize;
	string substr = "";
	int substrSize = 0;
	if (size == 0) {
		return substr;
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				newSubstrSize = j + 1 - i;
				newSubstr = s.substr(i, newSubstrSize);
				cout << "(" << i << "," << j << ") newSubstr = " << newSubstr << endl;
				if (isPalindrome(newSubstr)) {
					if (newSubstrSize > substrSize) {
						substr = newSubstr;
						substrSize = newSubstrSize;
						cout << "(" << i << "," << j << ") substr = " << substr << endl;
					}
				}
			}
		}
		return substr;
	}
}

int main() {
	string str = "abcba";
	string substr = longestPalindrome(str);
	cout << substr << endl;
}