#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    int substringFrom = -1;
    int substringLength = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] == s[i]) {
                if (j > substringFrom) {
                    substringFrom = j;
                }
            }
        }
        if (i - substringFrom > substringLength) {
            substringLength = i - substringFrom;
        }
    }
    return substringLength;
}

int main() {
    string str = "abdcdf";
    int length = lengthOfLongestSubstring(str);
    cout << length << endl;
}