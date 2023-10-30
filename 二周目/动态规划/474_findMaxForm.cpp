#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-30, 下午2:57.
//

class Solution {
public:
    int get_zeros_ones(std::string &str, int flag) {
        int ans = 0;
        for (auto &vec : str) {
            if (vec == flag + '0') ans++;
        }
        return ans;
    }

    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector(n + 1, 0));
        for (auto &str : strs) {
            int zero_nums = get_zeros_ones(str, 0);
            int one_nums = get_zeros_ones(str, 1);

            for (int i = m; i >= zero_nums; i--) {
                for (int j = n; j >= one_nums; j--) {
                    dp[i][j] = std::max(dp[i - zero_nums][j - one_nums] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};

int main474() {
    std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    Solution sol;
    std::cout << sol.findMaxForm(strs, m , n);

    return 0;
}