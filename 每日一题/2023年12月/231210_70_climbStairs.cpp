#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-12-10, 下午3:29.
//

class Solution {
public:
    // int climbStairs(int n) {
    //     vector<int> dp(n + 1, 1);
    //
    //     for (int i = 2; i <= n; i++)
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //
    //     return dp[n];
    // }

    // 空间优化 空间复杂度为O(1)
    int climbStairs(int n) {
        int dp[3] = {0, 1, 2};

        for (int i = 3; i <= n; i++) {
            int tmp = dp[2];
            dp[2] = dp[1] + dp[2];
            dp[1] = tmp;
        }
        return n <= 2 ? dp[n] : dp[2];
    }
};

int main23121070() {
    int n = 5;

    Solution sol;
    cout << sol.climbStairs(n);

    return 0;
}