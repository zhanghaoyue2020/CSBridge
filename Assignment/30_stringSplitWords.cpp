#include<iostream>
#include<array>
#include<string>
using namespace std;

bool isNumString(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= '0') && (str[i] <= '9')) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

string replaceNumX(string sentence) {
	string currTerm;
	int startInd = 0;
	int length = 0;
	while (startInd < sentence.length()) {
		length = sentence.find(" ", startInd) - startInd;
		if (length < 0) {
			length = sentence.length() - startInd;
			currTerm = sentence.substr(startInd, length);
			if (isNumString(currTerm)) {
				for (int i = startInd; i < startInd + length; i++) {
					sentence[i] = 'x';
				}
			}
			break;
		}
		if (length == 0) {
			startInd++;
		}
		if (length > 0) {
			currTerm = sentence.substr(startInd, length);
			if (isNumString(currTerm)) {
				for (int i = startInd; i < startInd + length; i++) {
					sentence[i] = 'x';
				}
			}
			startInd += length+1;
		}
	}
	return sentence;
}

int main() {
	string str, newStr;

	cout << "Please enter a line of text:" << endl;
	getline(cin, str);

	newStr = replaceNumX(str);
	cout << newStr << endl;

}