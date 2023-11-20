#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-18, 下午4:45.
//

class Solution {
public:
    int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    void dfs200(std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (visited[x][y] || grid[x][y] == '0') return;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            dfs200(grid, visited, next_x, next_y);
        }
    }

    int numIslands(std::vector<std::vector<char>> &grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs200(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
};

int main200() {
    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                          {'1', '1', '0', '1', '0'},
                                          {'1', '1', '0', '0', '0'},
                                          {'0', '0', '0', '0', '0'}};

    Solution sol;
     std::cout << sol.numIslands(grid);

    return 0;
}
