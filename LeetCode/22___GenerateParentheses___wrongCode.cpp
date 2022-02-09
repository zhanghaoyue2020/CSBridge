#include<iostream>
#include<vector>
using namespace std;

//typicial error: consider (())(())
vector<string> generateParenthesis(int n) {
	vector<string> parenthesisVec;
	if (n == 1) {
		parenthesisVec.push_back("()");
		return parenthesisVec;
	}
	else {
		vector<string> lastParenthesisVec = generateParenthesis(n - 1);
		string specialStr = "";
		for (int i = 0; i < n - 1; i++) {
			specialStr += "()";
		}
		string tempStr;
		for (vector<string>::iterator it = lastParenthesisVec.begin(); it != lastParenthesisVec.end(); it++) {
			//case1: left add
			tempStr = "()" + (*it);
			if ((*it) != specialStr) {
				parenthesisVec.push_back(tempStr);
			}
			//case2: right add
			tempStr = (*it) + "()";
			parenthesisVec.push_back(tempStr);
			//case3: outside add
			tempStr = "(" + (*it) + ")";
			parenthesisVec.push_back(tempStr);
		}
		return parenthesisVec;
	}
}

int main() {
	vector<string> ans = generateParenthesis(4);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << (*it) << "\t";
	}
	cout << endl;
}