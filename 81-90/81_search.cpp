#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-16.
//

class Solution {
public:
    bool search02(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right && nums[0] == nums[right]) right--;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                if (target == nums[mid] || target == nums[right]) return true;
                else if (target > nums[mid] && target < nums[right]) left = mid + 1;
                else right = mid - 1;
            } else {
                if (target == nums[left] || target == nums[mid]) return true;
                else if (target > nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    int target = 2;

    Solution sol;
    std::cout << sol.search02(nums, target);
}