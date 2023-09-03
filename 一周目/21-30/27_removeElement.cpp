#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-6-24.
//

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        int k = nums.size();
        return k;
    }
};

int main27() {
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    Solution sol;
    int k = sol.removeElement(nums,val);

    int len = k - 1;
    while (len >= 0) {
        std::cout << nums[len--];
    }
    std::cout << std::endl << k;

     return 0;
}