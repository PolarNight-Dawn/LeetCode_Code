#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-24, 下午3:59.
//

class Solution {
public:
    // int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    // int dfs(std::vector<std::vector<int>> &grid, int x, int y, int ans) {
    //     if (x == grid.size() - 1 && y == grid[0].size() - 1) return ans;
    //
    //     for (int i = 0; i < 4; i++) {
    //         int next_x = x + direction[i][0];
    //         int next_y = y + direction[i][1];
    //         if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
    //         if (grid[x][y] == 1 && grid[next_x][next_y] == 0) ans++;
    //         ans = dfs(grid, next_x, next_y, ans);
    //     }
    //     return ans;
    // }
    //
    // int islandPerimeter(std::vector<std::vector<int>>& grid) {
    //     int ans = 0;
    //     int m = grid.size(), n = grid[0].size();
    //
    //     for (int i = 0; i < m; i++) {
    //         if (grid[i][0] == 1) ans++;
    //         if (grid[i][n - 1] == 1) ans++;
    //     }
    //
    //     for (int j = 0; j < n; j++) {
    //         if (grid[0][j] == 1) ans++;
    //         if (grid[m - 1][j] == 1) ans++;
    //     }
    //
    //     ans = dfs(grid, 0, 0, ans);
    //
    //     return ans;
    // }

    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    int dfs(int x, int y, std::vector<std::vector<int>> &grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 1;
        if (grid[x][y] == 2) return 0;

        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            res += dfs(next_x, next_y, grid, n, m);
        }
        return res;
    }

    int islandPerimeter(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0, 0},
                                          {1, 1, 1, 0},
                                          {0, 1, 0, 0},
                                          {1, 1, 0, 0}};

    Solution sol;
    std::cout << sol.islandPerimeter(grid);

    return 0;
}