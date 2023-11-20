#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-20, 下午3:27.
//

class Solution{
public:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs1020(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (visited[x][y] || grid[x][y] == 0) return;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            dfs1020(grid, visited, next_x, next_y);
        }
    }

    int numEnclaves(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs1020(grid, visited, i, 0);
            dfs1020(grid, visited, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs1020(grid, visited, 0, j);
            dfs1020(grid, visited, m - 1, j);
        }

        int ans = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1)
                    ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

    Solution sol;
    std::cout << sol.numEnclaves(grid);

    return 0;
}