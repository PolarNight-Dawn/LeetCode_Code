#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-20.
//

class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        std::sort(nums1.begin(), nums1.end());
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    for (auto &vec: nums1) {
        std::cout << vec << " ";
    }

    return 0;
}