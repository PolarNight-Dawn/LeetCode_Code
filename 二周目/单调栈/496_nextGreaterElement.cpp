#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

//
// Created by polarnight on 23-11-15, 下午2:01.
//

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::stack<int> sta;
        std::vector<int> vec(nums2.size(), -1);

        for (int i = 0; i < nums2.size(); i++) {
            while (!sta.empty() && nums2[i] > nums2[sta.top()]) {
                vec[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }

        for (int i = 0; i < nums1.size(); i++) {
            auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
            int index = std::distance(nums2.begin(), it);
            nums1[i] = vec[index] == -1 ? vec[index] : nums2[index + vec[index]];
        }
        return nums1;
    }
};

int main() {
    std::vector<int> nums1 = {4,1,2};
    std::vector<int> nums2 = {1,3,4,2};

    Solution sol;
    std::vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }
    std::cout << std::endl;

    return 0;
}