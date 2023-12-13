#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//
// Created by polarnight on 23-11-21, 下午2:11.
//

class Solution {
public:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int dfs827(std::vector<std::vector<int>>& grid, int x, int y, int mark) {
        if (grid[x][y] != 1) return 0;

        int ans = 1;
        grid[x][y] = mark;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            ans += dfs827(grid, next_x, next_y, mark);
        }
        return ans;
    }

    int largestIsland(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, int> map;

        int ans = 0, mark = 2, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int tmp = dfs827(grid, i, j, mark);
                    map.insert(std::pair<int, int>(mark, tmp));
                    ans = std::max(ans, tmp);
                    mark++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    std::vector<int> used;
                    for (int z = 0; z < 4; z++) {
                        int next_x = i + direction[z][0];
                        int next_y = j + direction[z][1];
                        if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
                        auto it_map = map.find(grid[next_x][next_y]);
                        auto it_used = std::find(used.begin(), used.end(),grid[next_x][next_y]);
                        if (it_map != map.end() && it_used == used.end()) {
                            area += map[grid[next_x][next_y]];
                            used.push_back(grid[next_x][next_y]);
                        }
                    }
                    ans = std::max(ans, area);
                }
            }
        }
        return ans;
    }
};

int main827() {
    std::vector<std::vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0},
                                          {0, 1, 1, 1, 1, 0, 0},
                                          {0, 1, 0, 0, 1, 0, 0},
                                          {1, 0, 1, 0, 1, 0, 0},
                                          {0, 1, 0, 0, 1, 0, 0},
                                          {0, 1, 0, 0, 1, 0, 0},
                                          {0, 1, 1, 1, 1, 0, 0}};

    Solution sol;
    std::cout << sol.largestIsland(grid);

    return 0;
}