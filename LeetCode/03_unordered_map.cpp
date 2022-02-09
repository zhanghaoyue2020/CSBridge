#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    cout << "generate unordered_map (key,value)" << endl;
    unordered_map<char, int> map;
    int size = s.size();
    int substringFrom = -1;
    int substringLength = 0;
    for (int i = 0; i < size; i++) {
        cout << "i=" << i << ":" << endl;
        if (map.count(s[i]) > 0) {
            substringFrom = max(substringFrom, map[s[i]]);
        }
        map[s[i]] = i;
        cout << "\tpush pair in unordered_map (" << s[i] << "," << i << ")" << endl;
        cout << "\tsubstring start at index = " << substringFrom << endl;
        substringLength = max(substringLength, i - substringFrom);
        cout << "\tlength = " << substringLength << endl;
    }
    return substringLength;
}

int main() {
    string str = "abadc";
    int length = lengthOfLongestSubstring(str);
    cout << length << endl;
}