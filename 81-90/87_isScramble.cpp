#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-19.
//

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        int n = s1.size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>(n + 1, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j])
                    dp[i][j][1] = 1;
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= n; j++) {
                    for (int k = 1; k < len; k++) {
                        bool a = dp[i][j][k] && dp[i + k][j + k][len - k];
                        bool b = dp[i][j + len - k][k] && dp[i + k][j][len - k];
                        if (a || b) dp[i][j][len] = true;
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};

int main() {
    std::string s1 = "great";
    std::string s2 = "rgeat";

    Solution sol;
    std::cout << sol.isScramble(s1, s2);

    return 0;
}