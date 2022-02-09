#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    string str;
    int strStartIndex, strMidIndex;
    for (int i = 0; i < numRows; i++) {
        cout << "i = " << i << endl;
        //  strStartIndex  strMidIndex  strStartIndex   strMidIndex
        //  i=0                         6                              12
        //  i=1                 5       7                     11       13
        //  i=2        4                8          10                  14
        //  i=3                         9                              15
        strStartIndex = i;
        strMidIndex = strStartIndex + 2 * (numRows - 1 - i);
        cout << "\tinitialization:";
        cout << "\tstrStartIndex = " << strStartIndex << "\tstrMidIndex = " << strMidIndex << "\t" << str << endl;
        for (int j = 0; strStartIndex < s.length(); j++) {
            cout << "\tj = " << j;
            str += s[strStartIndex];
            if (i != 0 && i != numRows - 1 && strMidIndex < s.length()) {
                str += s[strMidIndex];
            }
            strStartIndex = strStartIndex + 2 * (numRows - 1);
            strMidIndex = strStartIndex + 2 * (numRows - 1 - i);
            cout << "\t\tstrStartIndex = " << strStartIndex << "\tstrMidIndex = " << strMidIndex << "\t" << str << endl;
        }
    }
    return str;
}

int main() {
    cout << convert("PAYPALISHIRING", 4) << endl;
    cout << convert("A", 1) << endl;
}