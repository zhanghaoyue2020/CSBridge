# include<iostream>
# include<vector>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	vector<int> intVec;
	int size;
	for (; x; ) {
		intVec.push_back(x % 10);
		x /= 10;
	}
	size = intVec.size();
	//	size = 5
	//	0		1				5-1-1	5-1-0
	//	0		1		2		3		4
	for (int i = 0; i < size / 2; i++) {
		if (intVec[i] != intVec[size - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << isPalindrome(1234567899) << endl << endl;
	cout << isPalindrome(322) << endl << endl;
	cout << isPalindrome(-212) << endl << endl;
}