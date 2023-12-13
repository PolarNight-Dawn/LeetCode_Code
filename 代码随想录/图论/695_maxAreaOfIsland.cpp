#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-20, 下午2:58.
//

class Solution {
public:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0,};
    int dfs695(std::vector<std::vector<int>> &grid, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (visited[x][y] || grid[x][y] == 0) return 0;

        int ans = 1;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            ans += dfs695(grid, visited, next_x, next_y);
        }
        return ans;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1)
                    ans = std::max(ans, dfs695(grid, visited, i, j));
            }
        }
        return ans;
    }
};

int main695() {
    std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                          {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    Solution sol;
    std::cout << sol.maxAreaOfIsland(grid);

    return 0;
}