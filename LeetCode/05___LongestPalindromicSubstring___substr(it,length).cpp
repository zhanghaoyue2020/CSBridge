#include<iostream>
#include<string>
using namespace std;


// too expensive and not a resonalble dp mode;
bool isPalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

string longestPalindrome(string s) {
	if (isPalindrome(s)) {
		return s;
	}
	else {
		string s1, s2;
		//1	s[0...n-1]
		s1 = longestPalindrome(s.substr(0, s.size() - 1));
		//2	s[1.....n]
		s2 = longestPalindrome(s.substr(1, s.size() - 1));
		if (s1.size() > s2.size()) {
			return s1;
		}
		else {
			return s2;
		}
	}
}

int main() {
	string str = "abcda";
	string substr = longestPalindrome(str);
	cout << substr << endl;
}