//
// Created by polarnight on 24-3-14, 下午4:32.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<long long>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] >= nums[i - 1]) {
                nums[i - 1] += nums[i];
                nums.resize(i);
            }
        }
        return nums[0];
    }

    // long long maxArrayValue(vector<int>& nums) {
    //     vector<long long> num(nums.begin(), nums.end());
    //     return maxArrayValue(num);
    // }

    // 优化
    long long maxArrayValue(vector<int>& nums) {
        long long res = nums.back();
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
            res = nums[i] <= res ? res + nums[i] : nums[i];
        return res;
    }
};

int main2403142789() {
    vector<int> nums = {2,3,7,9,3};

    Solution sol;
    cout << sol.maxArrayValue(nums);

    return 0;
}