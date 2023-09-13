#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

//
// Created by polarnight on 23-9-13, 下午1:57.
//

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
        std::unordered_set<int> res_set;

        for (auto &vec : nums2) {
            if (nums_set.find(vec) != nums_set.end()) res_set.insert(vec);
        }

        std::vector<int> res(res_set.begin(), res_set.end());

        return res;
    }
};

int main() {
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};

    Solution sol;
    std::vector<int> res = sol.intersection(nums1, nums2);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}