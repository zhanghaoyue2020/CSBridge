#include<iostream>
#include<vector>
using namespace std;

//  (1,0)   (2,0)   (3,0)   (3,1)   (3,2)   (3,3)
//                  (2,1)   (3,1)   (3,2)   (3,3)
//                          (2,2)   (3,2)   (3,3)
//          (1,1)   (2,1)   (3,1)   (3,2)   (3,3)
//                          (2,2)   (3,2)   (3,3)
void util(vector<string>& res, int open, int close, string& tmp, int n) {
    //enough open and close
    if (tmp.length() == 2 * n) {
        res.push_back(tmp);
        cout << "finished" << endl;
        return;
    }
    //first, generate enough '('
    if (open < n) {
        tmp.push_back('(');
        cout << "util(res," << open + 1 << "," << close << ", \"" << tmp << "\",\t" << n << "); " << endl;
        util(res, open + 1, close, tmp, n);
        tmp.pop_back();
    }
    //then, generate enough ')'
    if (close < open) {
        tmp.push_back(')');
        cout << "util(res," << open << "," << close + 1 << ", \"" << tmp << "\",\t" << n << "); " << endl;
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

int main() {
    vector<string> ans = generateParenthesis(3);
    for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << (*it) << "\t";
    }
    cout << endl;
}