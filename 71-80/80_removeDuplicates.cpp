#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-15.
//

class Solution {
public:
    int removeDuplicates02(std::vector<int>& nums) {
        int cnt = 1;
        for (int i = 0; i < nums.size();i++) {
           int j = i + 1;
           while (j < nums.size() && nums[i] == nums[j]) {
               cnt++;
               if (cnt > 2) nums.erase(nums.begin() + j);
               else j++;
           }
           cnt = 1;
        }

        return nums.size();
    }
};

int main() {
    std::vector<int> nums = {0,0,1,1,1,1,2,3,3};

    Solution sol;
    std::cout << sol.removeDuplicates02(nums);

    std::cout << std::endl;
    for (auto &vec :nums) {
        std::cout << vec << " ";
    }

    return 0;
}