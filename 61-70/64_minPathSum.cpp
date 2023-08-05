#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-5.
//

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                else if (i > 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else if (j > 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{1}};

    Solution sol;
    std::cout << sol.minPathSum(grid);

    return 0;
}