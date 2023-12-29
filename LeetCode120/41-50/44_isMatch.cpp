#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-20.
//

class Solution {
public:
    bool isMatch2(std::string s, std::string p) {
        int len1 = s.size();
        int len2 = p.size();
        std::vector<std::vector<bool>> dp(len1 + 1, std::vector<bool>(len2 + 1, false));

        dp[0][0] = 1;
        for (int j = 1; j < len2 + 1; j++) {
            if (dp[0][j - 1] && p[j -1] == '*') {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[len1][len2];
    }
};

int main44() {
    std::string s = "adceb";
    std::string p = "*a*b";

    Solution sol;
    std::cout << sol.isMatch2(s, p);

    return 0;
}