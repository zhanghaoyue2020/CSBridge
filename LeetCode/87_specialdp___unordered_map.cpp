#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> mp;
bool isScramble(string s1, string s2) {
    int size = s1.size();
    if (s2.size() != size) {
        return false;
    }
    if (s1 == s2) {
        return true;
    }
    if (size == 1) {
        return false;
    }
    string key = s1 + " " + s2;
    if (mp.find(key) != mp.end()) {
        return mp[key];
    }
    for (int i = 1; i < size; i++) {
        bool withoutswap = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
        if (withoutswap) {
            return true;
        }

        bool withswap = isScramble(s1.substr(0, i), s2.substr(size - i)) && isScramble(s1.substr(i), s2.substr(0, size - i));
        if (withswap) {
            return true;
        }
    }
    return mp[key] = false;
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