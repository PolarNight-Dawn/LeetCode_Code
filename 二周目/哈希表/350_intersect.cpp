#include <iostream>
#include <vector>
#include <unordered_map>

//
// Created by polarnight on 23-9-13, 下午2:41.
//

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> res;

        for (auto &vec : nums1) {
            map[vec]++;
        }

        for (auto &vec : nums2) {
            if (map.count(vec)) {
                map[vec]--;
                if (map[vec] >= 0) res.push_back(vec);
            }
        }

        return res;
    }
};

int main() {
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};

    Solution sol;
    std::vector<int> res = sol.intersect(nums1, nums2);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}