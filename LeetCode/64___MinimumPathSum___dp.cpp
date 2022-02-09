#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int collumnSize = grid[0].size();
    vector<vector<long long>> dp(rowSize, vector<long long>(collumnSize, grid[0][0]));

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < collumnSize; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
            else if (i - 1 >= 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else if (j - 1 >= 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
        }
    }

    for (vector<vector<long long>>::iterator it1 = dp.begin(); it1 != dp.end(); it1++) {
        for (vector<long long>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
            cout << (*it2) << "\t";
        }
        cout << endl;
    }

    return dp[rowSize - 1][collumnSize - 1];
}

int main() {
    vector<vector<int>> obsticalGrid;
    obsticalGrid = { {1,3,1},{1,5,1},{4,2,1} };
    cout << minPathSum(obsticalGrid) << endl;
    obsticalGrid = { {1,2,3},{4,5,6} };
    cout << minPathSum(obsticalGrid) << endl;

}