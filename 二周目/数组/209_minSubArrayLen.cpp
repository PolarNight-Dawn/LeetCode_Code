#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-6.
//

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int len = INT32_MAX;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                sum -= nums[left];
                len = std::min(right - left + 1, len);
                left++;
            }
            right++;
        }

        return len == INT32_MAX ? 0 : len;
    }
};

int main() {
    std::vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    Solution sol;
    std::cout << sol.minSubArrayLen(target, nums);

    return 0;
}