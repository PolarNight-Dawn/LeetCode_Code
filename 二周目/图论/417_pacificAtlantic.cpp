#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-20, 下午4:31.
//

class Solution {
public:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs417(std::vector<std::vector<int>> &heights, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (visited[x][y]) return;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= heights.size() || next_y >= heights[0].size()) continue;
            if (heights[x][y] > heights[next_x][next_y]) continue;
            dfs417(heights, visited, next_x, next_y);
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
        std::vector<std::vector<int>> res;

        for (int i = 0; i < m; i++) {
            dfs417(heights, pacific, i, 0);
            dfs417(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs417(heights, pacific, 0, j);
            dfs417(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> heights = {{1, 2, 2, 3, 5},
                                             {3, 2, 3, 4, 4},
                                             {2, 4, 5, 3, 1},
                                             {6, 7, 1, 4, 5},
                                             {5, 1, 1, 2, 4}};

    Solution sol;
    std::vector<std::vector<int>> res = sol.pacificAtlantic(heights);

    for (auto &tmp: res) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}