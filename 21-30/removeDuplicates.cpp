#include <iostream>
#include <vector>

//
// Created by polarnight on 23-6-23.
//

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
            }
        }

        int k = nums.size();
        return k;
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
