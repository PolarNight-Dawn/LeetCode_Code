//
// Created by polarnight on 24-3-15, 下午9:30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        typedef long long LL;

        vector<vector<int>> tmp(m + 1, vector<int>(n + 1, 0));
        for (auto &p : prices)
            tmp[p[0]][p[1]] = p[2];

        vector<vector<LL>> dp(m + 1, vector<LL>(n + 1, -1));
        function<void(int, int)> dfs = [&] (int x, int y) -> void {
            if (dp[x][y] != -1) return;

            dp[x][y] = tmp[x][y];
            for (int i = x / 2; i > 0; i--) {
                dfs(i, y);
                dfs(x - i, y);
                dp[x][y] = max(dp[x][y], dp[i][y] + dp[x - i][y]);
            }
            for (int j = y / 2; j > 0; j--) {
                dfs(x, j);
                dfs(x, y - j);
                dp[x][y] = max(dp[x][y], dp[x][j] + dp[x][y - j]);
            }
        };
        dfs(m, n);

        return dp[m][n];
    }
};

int main2403152312() {

    int m = 3, n = 5;
    vector<vector<int>> prices = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};

    Solution sol;
    cout << sol.sellingWood(m, n, prices);

    return 0;
}
