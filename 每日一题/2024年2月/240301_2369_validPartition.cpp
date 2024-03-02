//
// Created by polarnight on 24-3-1, 下午3:57.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int> &nums) {
        int n = nums.size();
        vector<bool> dp(n + 1);

        dp[0] = true;
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] && nums[i] == nums[i - 1]) dp[i + 1] = true;
            if (i > 1 && dp[i - 2] && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) dp[i + 1] = true;
            if (i > 1 && dp[i - 2] && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) dp[i + 1] = true;
        }
        return dp[n];
    }
};

int main2403012369() {
    vector<int> nums = {783377, 783378, 783379, 783380, 783381, 783382, 783383, 783384, 783385, 783386, 783387, 783388,
                        14925, 14925, 14925, 190887, 190887, 190887, 444668, 444668, 444668, 444668, 444669, 444670,
                        444671, 444672, 444673, 444674};

    Solution sol;
    cout << sol.validPartition(nums);

    return 0;
}