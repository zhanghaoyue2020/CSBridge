#include<iostream>
#include<vector>
using namespace std;

//Time Limit Exceeded
//(T22)
void util(vector<string>& res, int open, int close, string& tmp, int n) {
    //enough open and close
    if (tmp.length() == 2 * n) {
        res.push_back(tmp);
        //        cout << "finished" << endl;
        return;
    }
    //first, generate enough '('
    if (open < n) {
        tmp.push_back('(');
        //        cout << "util(res," << open + 1 << "," << close << ", \"" << tmp << "\",\t" << n << "); " << endl;
        util(res, open + 1, close, tmp, n);
        tmp.pop_back();
    }
    //then, generate enough ')'
    if (close < open) {
        tmp.push_back(')');
        //        cout << "util(res," << open << "," << close + 1 << ", \"" << tmp << "\",\t" << n << "); " << endl;
        util(res, open, close + 1, tmp, n);
        tmp.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp = "";
    util(res, 0, 0, temp, n);
    return res;
}

bool isWellFormed(string s) {
    int size = s.size();
    vector<string> parenthesisVec;
    if (size == 0) {
        return true;
    }
    else if (size % 2 != 0) {
        return false;
    }
    else {
        parenthesisVec = generateParenthesis(size / 2);
        for (vector<string>::iterator it = parenthesisVec.begin(); it != parenthesisVec.end(); it++) {
            if ((*it) == s) {
                return true;
            }
        }
        return false;
    }
}

int longestValidParentheses(string s) {
    int size = s.size();
    string substr;
    int substrSize;
    int ans = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            substrSize = j + 1 - i;
            substr = s.substr(i, substrSize);
            if (isWellFormed(substr)) {
                if (substrSize > ans) {
                    ans = substrSize;
                }
            }
        }
    }
    return ans;
}

int main() {
    cout << "code is similar to problem 22." << endl;
    cout << isWellFormed("(())(())") << endl << endl << endl;
    cout << longestValidParentheses(")(((((()())()()))()(()))(") << endl << endl << endl;
    cout << longestValidParentheses(")()())") << endl;
    cout << longestValidParentheses("") << endl;
}