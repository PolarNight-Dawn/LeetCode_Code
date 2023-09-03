#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-11.
//

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (target > nums[right]) return right + 1;
        if (target < nums[left]) return left;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};

int main35() {
    std::vector<int> nums = {1, 3, 5, 6};

    Solution sol;
    std:: cout << sol.searchInsert(nums, 7);

    return 0;
}