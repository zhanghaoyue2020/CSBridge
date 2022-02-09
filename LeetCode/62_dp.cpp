#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<long long>> dp(m, vector<long long>(n, 1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else if (i - 1 >= 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j - 1 >= 0) {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    cout << uniquePaths(10, 10) << endl;
    cout << uniquePaths(51, 9) << endl;
    cout << uniquePaths(1, 2) << endl;
    cout << uniquePaths(1, 1) << endl;
}