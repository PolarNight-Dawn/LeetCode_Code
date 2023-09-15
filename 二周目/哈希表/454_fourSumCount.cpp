#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

//
// Created by polarnight on 23-9-15, 下午4:48.
//

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::unordered_map<int, int> map;

        for (auto &vec : nums1) {
            for (auto &tmp : nums2) {
                int sum = vec + tmp;
                map[sum]++;
            }
        }

        int count = 0;
        for (auto &vec : nums3) {
            for (auto &tmp : nums4) {
                int sum = vec + tmp;
                auto it = map.find(0 - sum);
                if (it != map.end()) count += map[0 - sum];
            }
        }

        return count;
    }
};

int main() {
    std::vector<int> nums1 = {-1,-1};
    std::vector<int> nums2 = {-1,1};
    std::vector<int> nums3 = {-1,1};
    std::vector<int> nums4 = {1,-1};

    Solution sol;
    std::cout << sol.fourSumCount(nums1, nums2, nums3, nums4);

    return 0;
}