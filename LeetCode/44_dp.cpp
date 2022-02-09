#include<iostream>
#include<vector>
using namespace std;

bool isMatch(string s, string p) {
    int sSize = s.size();
    int pSize = p.size();
    vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));
    bool matched;

    //s = abc, p = ab*c
    dp[sSize][pSize] = true;
    for (int i = sSize; i >= 0; i--) {//index of s
        for (int j = pSize; j >= 0; j--) {//index of p
            matched = s[i] == p[j] || p[j] == '?';
            //("","*c")     
            //("c","*c")    
            //("bc","*c")   
            //("abc","*c")  
            if (j + 1 <= pSize && p[j] == '*' && dp[i][j + 1] == true) {
                dp[i][j] = true;
            }
            //("","*c")     next
            //("bc","*c")   than isMatch("c","*c")
            //("abc","*c")  than isMatch("bc","*c")
            else if (i + 1 <= sSize && p[j] == '*') {
                dp[i][j] = dp[i + 1][j];
            }
            else if (i + 1 <= sSize && j + 1 <= pSize && p[j] != '*' && matched == true) {
                dp[i][j] = dp[i + 1][j + 1];
            }
        }
    }
    for (int i = 0; i < sSize + 1; i++) {
        for (int j = 0; j < pSize + 1; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return dp[0][0];
}

int main() {
    string str1;
    string str2;
    str1 = "a";
    str2 = "a";
    cout << isMatch(str1, str2) << endl << endl;
    str1 = "";
    str2 = "*";
    cout << isMatch(str1, str2) << endl << endl;
    str1 = "abcde";
    str2 = "a?*";
    cout << isMatch(str1, str2) << endl << endl;
    str1 = "abcdaa";
    str2 = "?*a";
    cout << isMatch(str1, str2) << endl << endl;
    str1 = "abc";
    str2 = "ab*c";
    cout << isMatch(str1, str2) << endl;
}