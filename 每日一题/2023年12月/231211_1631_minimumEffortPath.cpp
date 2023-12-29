#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//
// Created by polarnight on 23-12-11, 下午2:29.
//

class Solution {
public:
    // int minimumEffortPath(vector<vector<int>> &heights) {
    //     const int max_val = INT32_MAX;
    //     int m = heights.size(), n = heights[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, max_val));
    //     int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    //
    //     int min_ans = max_val;
    //     function<void(int, int, int)> DFS = [&](int x, int y, int diff) -> void {
    //         if (x == m - 1 && y == n - 1) {
    //             min_ans = min(diff, min_ans);
    //             return;
    //         }
    //         if (dp[x][y] <= diff) return;
    //
    //         dp[x][y] = diff;
    //         for (auto [dx, dy]: direction) {
    //             int next_x = x + dx, next_y = y + dy;
    //             if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
    //             int new_diff = max(diff, abs(heights[next_x][next_y] - heights[x][y]));
    //             if (new_diff >= min_ans) continue;
    //             DFS(next_x, next_y, new_diff);
    //         }
    //     };
    //     DFS(0, 0, 0);
    //     return min_ans == INT32_MAX ? 0 : min_ans;
    // }

    int minimumEffortPath(vector<vector<int>> &heights) {
        const int max_val = INT32_MAX;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dp(m, vector<int>(n, max_val));
        int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto [diff, x, y] = pq.top();
            pq.pop();
            if (x == m - 1 && y == n - 1) return diff;
            if (dp[x][y] <= diff) continue;

            dp[x][y] = diff;
            for (auto [dx, dy]: direction) {
                int next_x = x + dx, next_y = y + dy;
                if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
                int new_diff = max(diff, abs(heights[next_x][next_y] - heights[x][y]));
                pq.emplace(new_diff, next_x, next_y);
            }
        }
        return 0;
    }
};

int main2312111631() {
    vector<vector<int>> heights = {{1, 2, 2},
                                   {3, 8, 2},
                                   {5, 3, 5}};

    Solution sol;
    cout << sol.minimumEffortPath(heights);

    return 0;
}