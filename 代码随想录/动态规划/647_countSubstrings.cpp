#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-13, 下午2:51.
//

class Solution {
public:
    int countSubstrings(std::string s) {
        int len = s.size();
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main647() {
    std::string s = "abc";

    Solution sol;
    std::cout << sol.countSubstrings(s);

    return 0;
}