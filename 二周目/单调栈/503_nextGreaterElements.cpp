#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

//
// Created by polarnight on 23-11-15, 下午3:29.
//

class Solution {
public:
    std::vector<int> nextGreaterElements503(std::vector<int> &nums) {
        std::stack<int> sta;
        std::vector<int> res(nums.size(), -1);

        int cnt = 0;
        for (int i = 0; i < 2 * nums.size(); i++) {
            if (i >= nums.size()) cnt = i % nums.size();
            else cnt = i;
            while (!sta.empty() && nums[cnt] > nums[sta.top()]) {
                res[sta.top()] = nums[cnt];
                sta.pop();
            }
            sta.push(cnt);
        }
        return res;
    }
};

int main503() {
    std::vector<int> nums = {1, 2, 3, 4, 3};

    Solution sol;
    std::vector<int> res = sol.nextGreaterElements503(nums);

    for (auto &vec: res) {
        std::cout << vec << " ";
    }
    std::cout << std::endl;

    return 0;
}