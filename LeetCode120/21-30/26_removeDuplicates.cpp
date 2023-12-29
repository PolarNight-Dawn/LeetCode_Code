#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-6-23.
//

class Solution {
public:
    // int removeDuplicates(std::vector<int>& nums) {
    //     int len = nums.size();
    //     for (int i = len - 1; i >= 0; i--) {
    //         if (i > 0 && nums[i] == nums[i - 1]) {
    //             nums.erase(nums.begin() + i);
    //         }
    //     }
    //
    //     int k = nums.size();
    //     return k;
    // }

    // 二周目刷题 双指针法 快慢指针
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};

int main26() {
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    int len = k - 1;
    while (len >= 0) {
        std::cout << nums[len--] << " ";
    }
    std::cout << std::endl << k;

    return 0;
}
