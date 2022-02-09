#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int ans = 1;
    long long currNumerator = m + n - 2;
    for (int i = 1; i < min(m, n); i++) {
        ans = ans * currNumerator / i;
        currNumerator--;
    }
    return ans;
}

int main() {
    cout << uniquePaths(10, 10) << endl;
    cout << uniquePaths(51, 9) << endl;
    cout << uniquePaths(1, 2) << endl;
    cout << uniquePaths(1, 1) << endl;
}