#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-24, 下午7:02.
//

class Solution {
public:
    int integerBreak(int n) {
       std::vector<int>  dp(n + 1, 0);

       for (int i = 2; i <= n; i++) {
           int max_mul = 0;
           for (int j = 1; j < i; j++) {
               max_mul = std::max(max_mul, std::max(j * (i - j), j * dp[i - j]));
           }
           dp[i] = max_mul;
       }
        return dp[n];
    }
};

int main343() {
    int n = 10;

    Solution sol;
    std::cout << sol.integerBreak(n);

    return 0;
}