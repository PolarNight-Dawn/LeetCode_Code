#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 24-1-25, 下午3:33.
//

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        if (k == 0) ans += nums[0];

        for (int i = 1; i < n; i++) {
            int count = 0, tmp = i;
            while (tmp) {
                tmp = tmp & (tmp - 1);
                count++;
            }
            if (count == k) ans += nums[i];
        }
        return ans;
    }
};

int main240125() {
    vector<int> nums = {5,10,1,5,2};
    int k = 1;

    Solution sol;
    cout << sol.sumIndicesWithKSetBits(nums, k);

    return 0;
}