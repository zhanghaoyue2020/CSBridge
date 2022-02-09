# include<iostream>
using namespace std;

bool isMatch(string s, string p) {
	if (p.size() == 0) {
		return s.size() == 0;
	}
	else {
		//check '*': s[012],p[0*234]
		if (p.size() > 1 && p[1] == '*') {
			//1	'*' Matches zero of the preceding element	(s[012]=p[234])
			//	return true;
			if (isMatch(s, p.substr(2))) {
				return true;
			}
			//2	'*' Matches one of the preceding element
			//	returen (s[12]==p[0*234])?
			else if ((s[0] == p[0] || p[0] == '.') && s.size() > 0) {
				return isMatch(s.substr(1), p);
			}
			//3	not match;
			//	return false;
			else {
				return false;
			}
		}
		//check current char:s[012],p[012]
		else {
			//1	match
			//	return (s[12]==p[12])?
			if ((s[0] == p[0] || p[0] == '.') && s.size() > 0) {
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
	str2 = "a*";
	cout << isMatch(str1, str2) << endl << endl;
	str1 = "abcde";
	str2 = "a.*";
	cout << isMatch(str1, str2) << endl << endl;
	str1 = "abcdaa";
	str2 = ".*a";
	cout << isMatch(str1, str2) << endl << endl;
	str1 = "aaa";
	str2 = ".*.*.*";
	cout << isMatch(str1, str2) << endl;
}