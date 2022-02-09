int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rowSize = obstacleGrid.size();
    int collumnSize = obstacleGrid[0].size();
    vector<vector<long long>> dp(rowSize, vector<long long>(collumnSize, 1));

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < collumnSize; j++) {
            if (obstacleGrid[i][j] == 0) {
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
            else {
                dp[i][j] = 0;
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