#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//
// Created by polarnight on 23-5-5.
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 排序
        int n = nums.size();
        int diff = INT_MAX; // 初始差值为无穷大
        int result = 0; // 记录结果
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int threeSum = nums[i] + nums[left] + nums[right];
                int curDiff = abs(threeSum - target); // 计算当前差值
                if (curDiff < diff) {
                    diff = curDiff;
                    result = threeSum;
                }
                if (threeSum < target) {
                    left++;
                } else if (threeSum > target) {
                    right--;
                } else {
                    return result;
                }
            }
        }
        return result;
    }
};

int main16() {
    vector<int> nums = {40,-53,36,89,-38,-51,80,11,-10,76,-30,46,-39,-15,4,72,83,-25,33,-69,-73,-100,-23,-37,-13,-62,-26,-54,36,-84,-65,-51,11,98,-21,49,51,78,-58,-40,95,-81,41,-17,-70,83,-88,-14,-75,-10,-44,-21,6,68,-81,-1,41,-61,-82,-24,45,19,6,-98,11,9,-66,50,-97,-2,58,17,51,-13,88,-16,-77,31,35,98,-2,0,-70,6,-34,-8,78,22,-1,-93,-39,-88,-77,-65,80,91,35,-15,7,-37,-96,65,3,33,-22,60,1,76,-32,22};
    int target = 292;

    Solution sol;
    cout << sol.threeSumClosest(nums, target);

    return 0;
}