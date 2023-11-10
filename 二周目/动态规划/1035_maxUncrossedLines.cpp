#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-10, 下午4:26.
//

class Solution {
public:
    int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    std::vector<int> nums1 = {1,4,2};
    std::vector<int> nums2 = {1,2,4};

    Solution sol;
    std::cout << sol.maxUncrossedLines(nums1, nums2);

    return 0;
}