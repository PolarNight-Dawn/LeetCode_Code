#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-10, 下午4:05.
//

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }
};

int main1143() {
    std::string text1 = "abcde";
    std::string text2 = "ace";

    Solution sol;
    std::cout << sol.longestCommonSubsequence(text1, text2);

    return 0;
}