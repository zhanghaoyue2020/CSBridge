# include<iostream>
# include<vector>
using namespace std;

bool isMatch(string s, string p) {
	int sSize = s.length();
	int pSize = p.length();
	vector<vector<bool>>dp(sSize + 1, vector<bool>(pSize + 1, false));
	bool matched;
	//		.	*	a	
	//	a	1	0	0	0
	//	b	1	0	0	0
	//	c	1	0	0	0
	//	d	1	0	0	0
	//	a	1	0	1	0
	//		1	0	0	1
	dp[sSize][pSize] = true;
	for (int i = sSize; i >= 0; i--) {
		for (int j = pSize; j >= 0; j--) {
			matched = s[i] == p[j] || p[j] == '.';
			if ((j + 1 <= pSize && i + 1 <= sSize) && p[j + 1] != '*' && matched) {
				dp[i][j] = dp[i + 1][j + 1];
				cout << "(" << i << ", " << j << ") = " << dp[i][j] << "\tcheckes following sequence" << endl;
			}
			else if (j + 2 <= pSize && p[j + 1] == '*' && dp[i][j + 2] == true) {
				dp[i][j] = true;
				cout << "(" << i << ", " << j << ") = " << dp[i][j] << "\tMatches zero of the preceding element" << endl;
			}
			else if ((j + 1 <= pSize && i + 1 <= sSize) && p[j + 1] == '*' && matched) {
				dp[i][j] = dp[i + 1][j];
				cout << "(" << i << ", " << j << ") = " << dp[i][j] << "\tMatches one or more than one of the preceding element" << endl;
			}
		}
	}
	for (vector<vector<bool>>::iterator it1 = dp.begin(); it1 != dp.end(); ++it1) {
		for (vector<bool>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2) {
			cout << "\t" << (*it2);
		}
		cout << endl;
	}
	return dp[0][0];
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
	str1 = "abcda";
	str2 = ".*a";
	cout << isMatch(str1, str2) << endl << endl;
	str1 = "aaa";
	str2 = ".*.*.*";
	cout << isMatch(str1, str2) << endl;
}