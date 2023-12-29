#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//
// Created by polarnight on 23-12-28, 下午3:31.
//

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> dp(nums);

        long long ans = accumulate(dp.begin(), dp.end(), 0LL);
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[i] = min(dp[i], nums[(i + k) % n]);
            }
            ans = min(ans, static_cast<long long>(k) * x + accumulate(dp.begin(), dp.end(), 0LL));
        }
        return ans;
    }
};

int main2312282735() {
    vector<int> nums = {15,150,56,69,214,203};
    int x = 42;

    Solution sol;
    cout << sol.minCost(nums, x);

    return 0;
}