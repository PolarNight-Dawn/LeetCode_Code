#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-11.
//

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n = word1.size();
        int m = word2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }

        return dp[n][m];
    }
};

int main72() {
    std::string word1 = "horse";
    std::string word2 = "ros";

    Solution sol;
    std::cout << sol.minDistance(word1, word2);

    return  0;
}