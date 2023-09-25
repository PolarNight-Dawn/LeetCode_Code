#include <iostream>
#include <vector>
#include <queue>
#include <deque>

//
// Created by polarnight on 23-9-25, 下午2:58.
//

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> dq; // 双端队列，存储元素下标

        for (int i = 0; i < nums.size(); i++) {
            // 如果队列不为空且队首元素已经不在滑动窗口内，将其出队
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // 维护双端队列，保持队首元素为当前窗口的最大值
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i); // 将当前元素下标入队

            // 当窗口完全覆盖k个元素时，将队首元素（最大值）添加到结果中
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};

int main() {
    std::vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    Solution sol;
    std::vector<int> res = sol.maxSlidingWindow(nums, k);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}