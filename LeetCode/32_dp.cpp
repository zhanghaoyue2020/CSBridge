#include<iostream>
#include<vector>
using namespace std;

int longestValidParentheses(string s) {
    int substrSize = 0;
    vector<int> dp(s.length(), 0);
    //  case1:..4444()
    //          6 = 4 + 2
    //  case2:..(4444)
    //           | index = i - 1 - 4;
    //          6 = 4 + 2
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                //  dp[i] = dp[i - 2] + 2   if i - 2 >= 0
                //  dp[i] = 2               if i - 2 < 0
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                //i:        size of before sequence
                //dp[i-1]:  size of before well formed parenthese
                //  dp[i] = dp[i - 1] + dp[i - 2 - dp[i - 1]] + 2   if (i - 2 - dp[i - 1]) >= 0
                //  dp[i] = dp[i - 1] + 2                           if (i - 2 - dp[i - 1]) < 0
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - 2 - dp[i - 1]] : 0) + 2;
            }
        }
        //  check substrSize;
        //  substrSize = substrSize if it's larger
        //  substrSize = dp[i]      if it's larger
        substrSize = substrSize > dp[i] ? substrSize : dp[i];
    }
    for (vector<int>::iterator it = dp.begin(); it != dp.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;
    return substrSize;
}

int main() {
    cout << longestValidParentheses(")(((((()())()()))()(()))(") << endl;
    cout << longestValidParentheses(")()())") << endl;
    cout << longestValidParentheses("") << endl;
}