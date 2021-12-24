#include<iostream>
#include<string>
using namespace std;

bool compareChar(string st1, string st2);

int main() {
	string s1 = "Eleven plus two";
	string s2 = "Twelve plus one";
	string s3 = "Eleven plus one";
	cout << compareChar(s1, s2) << endl;
	cout << compareChar(s1, s3) << endl;
}

bool compareChar(string st1, string st2) {
	int countSt1[26] = { 0 };
	int countSt2[26] = { 0 };
	//count the number;
	for (int i = 0; i < st1.length(); i++) {
		if ((st1[i] - 'A' < 26) && (st1[i] - 'A' >= 0)) {
			countSt1[st1[i] - 'A']++;
		}
		else if ((st1[i] - 'a' < 26) && (st1[i] - 'a' >= 0)) {
			countSt1[st1[i] - 'a']++;
		}
	}	
	for (int i = 0; i < st2.length(); i++) {
		if ((st2[i] - 'A' < 26) && (st2[i] - 'A' >= 0)) {
			countSt2[st2[i] - 'A']++;
		}
		else if ((st2[i] - 'a' < 26) && (st2[i] - 'a' >= 0)) {
			countSt2[st2[i] - 'a']++;
		}
	}
	//compare the count;
	for (int i = 0; i < 26; i++) {
		if (countSt1[i] != countSt2[i]) {
			return false;
		}
	}
	return true;
}