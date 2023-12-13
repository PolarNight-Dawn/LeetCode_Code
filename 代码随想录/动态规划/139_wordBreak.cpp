#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

//
// Created by polarnight on 23-11-1, 下午2:49.
//

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        std::vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;
        for (int j = 0; j <= s.size(); j++) {
            for (int i = 0; i < j; i++) {
                std::string str = s.substr(i, j - i);
                if (std::find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {
                    dp[j] = dp[i];
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main139() {
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};

    Solution sol;
    std::cout << sol.wordBreak(s, wordDict);

    return 0;
}