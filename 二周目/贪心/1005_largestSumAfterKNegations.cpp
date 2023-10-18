#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-18, 下午3:22.
//

class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        while (k > 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (k == 0) break;
                if (nums[i] <= 0) {
                    nums[i] = -nums[i];
                    k--;
                } else break;
            }
            if (k % 2 != 0) {
                auto min = std::min_element(nums.begin(), nums.end());
                *min = -*min;
            }
            break;
        }

        int sum = 0;
        for (auto &vec : nums) {
            sum += vec;
        }
        return sum;
    }
};

int main() {
    std::vector<int> nums = {-2,9,9,8,4};
    int k = 5;

    Solution sol;
    std::cout << sol.largestSumAfterKNegations(nums, k);

    return 0;
}