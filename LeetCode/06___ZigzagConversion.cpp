#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	string* strArr = new string[numRows];
	string str = "";
	int strArrIndex;
	//	0			0			0		
	//	1		5	1		5	1
	//	2	4		2	4		2
	//	3			3			3
	for (int i = 0; i < s.size(); i++) {
		strArrIndex = i % (2 * (numRows - 1));
		if (strArrIndex >= numRows) {
			strArrIndex = 2 * (numRows - 1) - strArrIndex;
		}
		strArr[strArrIndex].push_back(s[i]);
	}
	for (int i = 0; i < numRows; i++) {
		str += strArr[i];
	}
	return str;
}

int main() {
	cout << convert("PAYPALISHIRING", 4) << endl;
	cout << convert("A", 1) << endl;
}