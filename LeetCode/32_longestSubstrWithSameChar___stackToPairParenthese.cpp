#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
	stack<int> st;
	int substrSize = 0, newSubstrSize = 0, lastLeftParentheseIndex = 0;
	for (char c : s) {
		if (c == '(') {
			st.push(lastLeftParentheseIndex);
		}
		else if (c == ')') {
			if (!st.empty()) {
				s[st.top()] = '.';
				s[lastLeftParentheseIndex] = '.';
				st.pop();
			}
		}
		lastLeftParentheseIndex++;
	}
	cout << s << endl;
	//longest substr with same char
	for (char c : s) {
		if (c == '.') {
			substrSize = max(substrSize, ++newSubstrSize);
		}
		else {
			newSubstrSize = 0;
		}
	}
	return substrSize;
}

int main() {
	cout << longestValidParentheses(")(((((()())()()))()(()))(") << endl;
	cout << longestValidParentheses(")()())") << endl;
	cout << longestValidParentheses("") << endl;
}