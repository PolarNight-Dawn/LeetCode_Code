#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-21.
//

class Solution {
public:
    int jump(std::vector<int> &nums) {
        int cnt = 0;
        int hop = 0;
        int maxArea = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int area = i + nums[i];
            maxArea = std::max(maxArea, area);
            if (i == cnt) {
                cnt = maxArea;
                hop++;
            }
        }
        return hop;
    }
};

int main() {
    std::vector<int> nums = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6,
                             8, 8, 4, 4, 2, 0, 3, 8, 5};

    Solution sol;
    std::cout << sol.jump(nums);

    return 0;
}