#include<iostream>
#include<vector>
using namespace std;

//dp[3]
//  ( + dp[0] + ) + dp[2] = ()(()) and ()()()
//  ( + dp[1] + ) + dp[1] = (())()
//  ( + dp[2] + ) + dp[0] = ((())) and (()())
//dp[2]
//  ( + dp[0] + ) + dp[1] = ()()
//  ( + dp[1] + ) + dp[0] = (())
//dp[1]
//  ( + dp[0] + ) + dp[0] = ()
//dp[i]
//  ( + dp[j] + ) + dp[i-j-1] = ()
vector<string> generateParenthesis(int n) {
    int size = n;
    vector<vector<string>> dp(size + 1, vector<string>());
    vector<string> left, right;;

    dp[0] = { "" };
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // j + (i - j - 1) === i - 1;
            left = dp[j];
            right = dp[i - j - 1];
            for (int k = 0; k < left.size(); k++) {
                for (int l = 0; l < right.size(); l++) {
                    dp[i].push_back("(" + left[k] + ")" + right[l]);
                }
            }
        }
    }
    return dp[n];
}

int main() {
    vector<string> ans = generateParenthesis(3);
    for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << (*it) << "\t";
    }
    cout << endl;
}