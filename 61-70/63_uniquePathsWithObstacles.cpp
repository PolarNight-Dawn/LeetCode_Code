#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-5.
//

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) dp[0][0] = 0;
        else dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else if (i > 0) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j];
                } else if (j > 0) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> obstacGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution sol;
    std::cout << sol.uniquePathsWithObstacles(obstacGrid);

    return 0;
}