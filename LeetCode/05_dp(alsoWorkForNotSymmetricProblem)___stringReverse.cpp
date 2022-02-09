#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longest_common_substring(string str1, string str2) {
    int str1Size = str1.size();
    int str2Size = str2.size();
    vector<vector<int>>dp(str1Size + 1, vector<int>(str2Size + 1, 0));
    string subStr;
    int subStrSize;
    //          a   b   c   b   d
    //      0   0   0   0   0   0
    //  b   0   0   1   0   1   0
    //  c   0   0   0   2   0   0
    //  d   0   0   0   0   0   1
    //  b   0   0   1   0   1   0
    //  d   0   0   0   0   0   2
    subStrSize = 0;
    for (int i = 0; i <= str1Size; i++) {
        for (int j = 0; j <= str2Size; j++) {
            if (i - 1 >= 0 && j - 1 >= 0 && str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                cout << "(" << i << ", " << j << ") = " << dp[i][j] << "\tchars mached\t" << str1.substr(i - dp[i][j], dp[i][j]) << endl;
                if (dp[i][j] > subStrSize) {
                    subStrSize = dp[i][j];
                    subStr = str1.substr(i - dp[i][j], dp[i][j]);
                }
            }
        }
    }
    for (vector<vector<int>>::iterator it1 = dp.begin(); it1 != dp.end(); it1++) {
        for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
            cout << *it2 << "\t";
        }
        cout << endl;
    }
    return subStr;
}
string longestPalindrome(string s) {
    string sReverse = string(s.rbegin(), s.rend());
    cout << s << "\t" << sReverse << endl;
    cout << "*s.rbegin() = " << *s.rbegin() << endl;
    cout << "*(s.rend() -1) =" << *(s.rend() - 1) << endl;
    cout << "only return common substring of " << s << " and " << sReverse << ", not check Palindrome" << endl;
    return longest_common_substring(s, sReverse);
}

int main() {
    string str = "aacabdacaa";
    string substr = longestPalindrome(str);
    cout << substr << endl << endl;
    longest_common_substring("bcdbd", "abcbd");
}
