#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-31.
//

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int curHop = 0;
        int nextHop = 0;

        for (int i = 0; i < nums.size(); i++) {
            nextHop = std::max(i + nums[i], nextHop);
            if (nextHop >= nums.size() - 1) return true;
            if (i == curHop && curHop != nextHop) curHop = nextHop;
            if (i == curHop && curHop == nextHop) break;
        }

        return false;
    }
};

int main55() {
    std::vector<int> nums = {1,1,2,2,0,1,1};

    Solution sol;
    std::cout << sol.canJump(nums);

    return 0;
}