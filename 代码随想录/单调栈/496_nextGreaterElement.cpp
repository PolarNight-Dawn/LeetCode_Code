#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-11-15, 下午2:01.
//

class Solution {
public:
    //! 单调栈
    //! \时间复杂度 O(N）+ O(M * N)
    // std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    //     std::stack<int> sta;
    //     std::vector<int> vec(nums2.size(), -1);
    //
    //     for (int i = 0; i < nums2.size(); i++) {
    //         while (!sta.empty() && nums2[i] > nums2[sta.top()]) {
    //             vec[sta.top()] = i - sta.top();
    //             sta.pop();
    //         }
    //         sta.push(i);
    //     }
    //
    //     for (int i = 0; i < nums1.size(); i++) {
    //         auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
    //         int index = std::distance(nums2.begin(), it);
    //         nums1[i] = vec[index] == -1 ? vec[index] : nums2[index + vec[index]];
    //     }
    //     return nums1;
    // }

    //! \优化代码 单调栈 + 哈希
    //! \时间复杂度 O(N + M)
    // std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
    //     std::stack<int> sta;
    //     std::unordered_map<int, int> vec;
    //     std::vector<int> res(nums1.size(), -1);
    //
    //     for (int i = 0; i < nums1.size(); i++) {
    //         vec.insert(std::pair<int, int>(nums1[i], i));
    //     }
    //
    //     for (int i = 0; i < nums2.size(); i++) {
    //         while (!sta.empty() && nums2[i] > nums2[sta.top()]) {
    //             if (vec.find(nums2[sta.top()]) != vec.end()) {
    //                 res[vec[nums2[sta.top()]]] = nums2[i];
    //             }
    //             sta.pop();
    //         }
    //         sta.push(i);
    //     }
    //     return res;
    // }

    //! \随想录二刷
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        unordered_map<int, int> map;
        vector<int> answers(nums1_len, -1);
        stack<int> sta;

        for (int i = 0; i < nums1_len; i++)
            map.emplace(nums1[i], i);

        for (int i = 0; i < nums2_len; i++) {
            while (!sta.empty() && nums2[sta.top()] < nums2[i]) {
                if (map.find(nums2[sta.top()]) != map.end()) answers[map[nums2[sta.top()]]] = nums2[i];
                sta.pop();
            }
            sta.push(i);
        }
        return answers;
    }
};

int main496() {
    std::vector<int> nums1 = {4, 1, 2};
    std::vector<int> nums2 = {1, 3, 4, 2};

    Solution sol;
    std::vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for (auto &vec: res) {
        std::cout << vec << " ";
    }
    std::cout << std::endl;

    return 0;
}