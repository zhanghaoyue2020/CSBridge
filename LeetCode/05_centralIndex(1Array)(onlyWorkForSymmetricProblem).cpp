#include<iostream>
#include<string>
using namespace std;

// these code only work for symmetric problem;
// not symmetric use dp
string longestPalindrome(string s) {
    if (s.length() <= 1) {
        return s;
    }

    int size = s.length();
    int substrSize = 1;
    int substrFrom = 0, substrTo = 0;
    cout << "initialization: " << endl;
    cout << "\tsubstrFrom = " << substrFrom << "\tsubstrTo = " << substrTo << "\tsubstrSize = " << substrSize << endl;

    int newSubstrSize;
    int newSubstrFrom, newSubstrTo;
    for (int i = 0; i < size - 1; i++) {
        cout << "i = " << i << endl;
        newSubstrFrom = i;
        newSubstrTo = i;
        while (newSubstrFrom >= 0 && newSubstrTo < size) {
            if (s[newSubstrFrom] == s[newSubstrTo]) {
                newSubstrFrom--; newSubstrTo++;
            }
            else {
                break;
            }
        }
        newSubstrFrom++;
        newSubstrTo--;
        newSubstrSize = newSubstrTo + 1 - newSubstrFrom;
        cout << "\tsubstrFrom = " << newSubstrFrom << "\tsubstrTo = " << newSubstrTo << "\tsubstrSize = " << newSubstrSize << endl;
        if (newSubstrSize > substrSize) {
            substrFrom = newSubstrFrom;
            substrTo = newSubstrTo;
            substrSize = newSubstrSize;
        }
    }

    for (int i = 0; i < size - 1; i++) {
        cout << "i = (" << i << "," << i + 1 << ")" << endl;
        newSubstrFrom = i;
        newSubstrTo = i + 1;
        while (newSubstrFrom >= 0 && newSubstrTo < size) {
            if (s[newSubstrFrom] == s[newSubstrTo]) {
                newSubstrFrom--; newSubstrTo++;
            }
            else {
                break;
            }
        }
        newSubstrFrom++;
        newSubstrTo--;
        newSubstrSize = newSubstrTo + 1 - newSubstrFrom;
        cout << "\tsubstrStartIndex = " << newSubstrFrom << "\tsubstrEndIndex = " << newSubstrTo << "\tsubstrSize = " << newSubstrSize << endl;
        if (newSubstrSize > substrSize) {
            substrFrom = newSubstrFrom;
            substrTo = newSubstrTo;
            substrSize = newSubstrSize;
        }
    }
    return s.substr(substrFrom, substrSize);
}

int main() {
    string str = "abcbasa";
    string substr = longestPalindrome(str);
    cout << substr << endl;
}