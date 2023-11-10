#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-10, 下午5:45.
//

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        int len_s = s.size();
        int len_t = t.size();
        std::vector<std::vector<int>> dp(len_s + 1, std::vector<int>(len_t + 1, 0));

        for (int i = 0; i <= len_t; i++) dp[0][i] = 1;
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_t; j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[len_s][len_t];
    }
};

int main() {
    std::string s = "b";
    std::string t = "abc";

    Solution sol;
    std::cout << sol.isSubsequence(s, t);

    return 0;
}