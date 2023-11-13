#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-13, 下午3:59.
//

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int len = s.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));

        for (int i = len - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][len - 1];
    }
};

int main() {
    std::string s = "abc";

    Solution sol;
    std::cout << sol.longestPalindromeSubseq(s);

    return 0;
}