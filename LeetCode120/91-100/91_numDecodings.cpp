#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-21.
//

class Solution {
public:
    int numDecodings(std::string s) {
        // s存在前导零的处理
        if (s[0] == '0') return 0;

        s.insert(s.begin(), ' ');
        int len = s.size();
        std::vector<int> dp(len, 0);

        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            int val = s[i] - '0';
            int val02 = (s[i] - '0') + (s[i - 1] - '0') * 10;
            if (val >= 1 && val <=9) dp[i] = dp[i - 1];
            if (val02 >= 10 && val02 <= 26) dp[i] += dp[i - 2];
        }

        return dp[len - 1];
    }
};

int main91() {
    std::string s = "11106";

    Solution sol;
    std::cout << sol.numDecodings(s);

    return 0;
}