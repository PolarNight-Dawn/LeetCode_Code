#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-7.
//

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int len = nums.size();

        for (int i = len - 2; i >= 0; i--) {
            for (int j = len - 1; j > i; j--) {
                if (nums[i] < nums[j]) {
                    int temp;
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    sort(nums.begin()+ i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main31() {
    std::vector<int> nums = {1,2,4,3};

    Solution sol;
    sol.nextPermutation(nums);

    for (auto &vec : nums) {
        std::cout << vec << " ";
    }

    return 0;
}