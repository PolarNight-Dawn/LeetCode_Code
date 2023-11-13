#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-12, 下午5:00.
//

class Solution {
public:
    int minDistance583(std::string word1, std::string word2) {
        int w1 = word1.size();
        int w2 = word2.size();
        std::vector<std::vector<int>> dp(w2 + 1, std::vector<int>(w1 + 1, 0));

        for (int i = 1; i <= w2; i++) dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j <= w1; j++) dp[0][j] = dp[0][j - 1] + 1;

        for (int i = 1; i <= w2; i++) {
            for (int j = 1; j <= w1; j++) {
                if (word2[i - 1] == word1[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[w2][w1];
    }
};

int main() {
    std::string word1 = "leetcode";
    std::string word2 = "etco";

    Solution sol;
    std::cout << sol.minDistance583(word1, word2);

    return 0;
}