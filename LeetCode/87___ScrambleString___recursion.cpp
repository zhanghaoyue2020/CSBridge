#include<iostream>
#include<vector>
using namespace std;

// Time Limit Exceeded
vector<string> scrambleStrings(string s) {
    vector<string> strArr;
    string currStr1, currStr2;
    vector<string> currStr1Arr, currStr2Arr;
    int currStr1ArrSIze, currStr2ArrSize;
    if (s.size() == 1) {
        strArr.push_back(s);
    }
    else {
        for (int i = 1; i < s.size(); i++) {
            currStr1 = s.substr(0, i);
            currStr2 = s.substr(i);
            currStr1Arr = scrambleStrings(currStr1);
            currStr2Arr = scrambleStrings(currStr2);
            currStr1ArrSIze = currStr1Arr.size();
            currStr2ArrSize = currStr2Arr.size();
            for (int j = 0; j < currStr1ArrSIze; j++) {
                for (int k = 0; k < currStr2ArrSize; k++) {
                    strArr.push_back(currStr1Arr[j] + currStr2Arr[k]);
                    strArr.push_back(currStr2Arr[k] + currStr1Arr[j]);
                }
            }
        }
    }
    return strArr;
}

bool isScramble(string s1, string s2) {
    vector<string> strArr = scrambleStrings(s1);
    for (vector<string>::iterator it = strArr.begin(); it != strArr.end(); it++) {
        cout << *it << "\t";
        if ((*it) == s2) {
            cout << endl;
            return true;
        }
    }
    cout << endl;
    return false;
}


int main() {
    string str1, str2;
    str1 = "abcde";
    str2 = "caebd";
    cout << isScramble(str1, str2) << endl;
    str1 = "great";
    str2 = "rgeat";
    cout << isScramble(str1, str2) << endl;
}