#include<iostream>
#include<vector>
using namespace std;

//Time Limit Exceeded
bool isMatch(string s, string p) {
    if (p.size() == 0) {
        return s.size() == 0;
    }
    else {
        //chack'*': s[012],p[*123]
        if (p[0] == '*') {
            //1	'*' Matches zero element	(s[012]=p[123])
            //	return true;
            if (isMatch(s, p.substr(1, p.size() - 1))) {
                return true;
            }
            //2	'*' Matches one element
            //	returen (s[12]==p[*12])?
            else if (s.size() > 0) {
                return isMatch(s.substr(1, s.size() - 1), p);
            }
            //3	not match;
            //	return false;
            else {
                return false;
            }
        }
        //chack current char:   s[012],p[012]
        else {
            //1	match
            //	return (s[12]==p[12])?
            if (s.size() > 0 && (s[0] == p[0] || p[0] == '?')) {
                return isMatch(s.substr(1), p.substr(1));
            }
            //2	not match;
            //	return false;
            else {
                return false;
            }
        }
    }
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
    str1 = "aaa";
    str2 = "*****";
    cout << isMatch(str1, str2) << endl;
}